#include "queue.h"
void set_button_light(int floor, ButtonType button, int value){ 
    //value 1 = on, 0 = off 
    elevio_buttonLamp(floor, button, value);
}

void add_order_to_queue(Order order){
    if(legal_request(order)){
        for(int i = 0;i < 10; i++){
            if(order_queue[i].floor == 5){
                order_queue[i] = order;
            }
        }
    }
}

int legal_request(Order pot_order){
    for(int i = 0; i < 10; i++){
        if(order_equal(order_queue[i],pot_order)){
            return 0;
        }
    }
    return 1;
}

int order_equal(Order order1, Order order2){
    if(order1.button == order2.button && order1.floor == order2.floor){
        return 1;
    }
    return 0;
}