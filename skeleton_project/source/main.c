#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "start.h"

//potesielt ikke nødvendig
#include "order.h"
#include "movement.h"
#include "queue.h"
#include "door.h"
#include "utilities.h"


int main(){
    elevio_init();
    printf("===Starting elevetor ===\n");
    printf("Press the stop button on the elevator panel to exit\n");
    
    start_init(); 


    return 0;
}




















/*
    while(1){
        int floor = elevio_floorSensor();
    
        if(floor == 0){
            elevio_motorDirection(DIRN_UP);
        }
        
        if(floor == N_FLOORS-1){
            elevio_motorDirection(DIRN_DOWN);
        }


        for(int f = 0; f < N_FLOORS; f++){
            for(int b = 0; b < N_BUTTONS; b++){
                int btnPressed = elevio_callButton(f, b);
                elevio_buttonLamp(f, b, btnPressed);
            }
        }

        if(elevio_obstruction()){
            elevio_stopLamp(1);
        } else {
            elevio_stopLamp(0);
        }
        
        if(elevio_stopButton()){
            elevio_motorDirection(DIRN_STOP);
            break;
        }
        
    
        nanosleep(&(struct timespec){0, 20*1000*1000}, NULL); 
        //EGET TEST OMRÅDE
    }
    */