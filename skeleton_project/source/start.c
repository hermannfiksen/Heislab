#include "start.h"


void start_init(){
    //gå ned til treffer etasje
    int floor = elevio_floorSensor();
    int bottom_floor = at_bottom_floor();
    if (bottom_floor == 0 && floor == -1)
    {
        elevio_motorDirection(DIRN_DOWN);
        while(floor == -1 && elevio_stopButton() != 1){
            floor = elevio_floorSensor();
            nanosleep(&(struct timespec){0, 20*1000*1000}, NULL); 
            continue;
        }
        elevio_motorDirection(DIRN_STOP);

    }
}

int at_bottom_floor(){
    //yay frist func, return 1 if at bottom floor
    int current_floor = elevio_floorSensor();
    if(current_floor == 0){
        return 1;
    }
    else{
        return 0;
    }
}

