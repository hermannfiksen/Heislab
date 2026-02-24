#include "order.h"


void elevator_run(){
    // main loop for elevator system
    

    while(1){
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL); 
        check_for_orders();

        if(stop_hms()){
            break;
        }
        //go to etajse
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
                    add_order_to_queue(new_order);
                }
            }
        }
}

int stop_hms(){
    int stop = 0;
    if(elevio_stopButton()){
        stop = 1;
    }
    if(elevio_obstruction()){
        stop = 1;
    }
    return stop;
}
