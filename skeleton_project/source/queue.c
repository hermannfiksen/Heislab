#include "queue.h"
Queue order_queue = {.head = -1, .tail = -1, .size = 0};
Queue* queue_pointer = &order_queue;

void elevator_run(){
    // main loop for elevator system
    
    int order_done = 1;
    int waiting = 0;
    long long wait_until = 0;
    Order active_order;

    while(1){
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL); 
        set_current_floor();
        set_button_light(1);
        set_floor_light();
        check_for_orders();
        
        if(stop_hms()){
            break;
        }
        
        //test
        printf("ordersize = %d  \n",order_queue.size);
        //test over
        
        if(time_now() >= wait_until){
            waiting = 0;
        }else{
            waiting = 1;
        }
        if(waiting && elevio_obstruction()){
            wait_until = time_now() + 2000;
        }
        if(!waiting){
            if(order_queue.size == 0){
                elevio_motorDirection(DIRN_STOP);
            }
            
            if(order_done && order_queue.size != 0){
                // check if last order is done & there are orders in queue
                active_order = get_next_order(queue_pointer);
                go_to_floor(active_order.floor);
                order_done = 0;
                
            }
            
            if(!order_done){
                order_done = at_destination(active_order.floor);
                if(order_done){
                    // at destination. remove order
                    remove_order(queue_pointer);
                    elevio_buttonLamp(active_order.floor,active_order.button,0);
                    
                    waiting = 1;
                    wait_until = time_now() + 2000;
                }
            }
            
        }
    }
}



void check_for_orders(){
    //iterates thtrough all buttons and makes a new order object for each pressed button
    for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                if(btnPressed){
                    // when input is registered, make order and send to queue-file
                    Order new_order = {b, f};
                    add_order_to_queue(new_order,queue_pointer);
                    nanosleep(&(struct timespec){0, 20*1000*1000}, NULL); 
                }
            }
        }
}



void add_order_to_queue(Order order, Queue* q){
    if(legal_request(order)){
        add_to_queue(q, order);
    }
}

int legal_request(Order pot_order){
    if(order_queue.size == 0){
        return 1;
    }
    for(int i = order_queue.tail; i != order_queue.head; i = (i + 1)% MAX_SIZE){
        if(order_equal(order_queue.arr[i],pot_order)){
            elevio_doorOpenLamp(1);
            return 0;
        }
    }
    elevio_doorOpenLamp(0);
    return 1;
}

int order_equal(Order order1, Order order2){
    if(order1.button == order2.button && order1.floor == order2.floor){
        return 1;
    }
    return 0;
}


void set_button_light(int value){ 
    //value 1 = on, 0 = off 
    if(order_queue.size > 0){
        for(int i = 0; i < order_queue.size; i++){
            int idx = (order_queue.head + i) % MAX_SIZE;
            elevio_buttonLamp(order_queue.arr[idx].floor, order_queue.arr[idx].button, value); 
        }
    } 
}

