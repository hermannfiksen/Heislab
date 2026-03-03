#define _POSIX_C_SOURCE 200809L
#include "movement.h"

int g_current_floor;

void go_to_floor(int floor){
    int dir = 0;
    if(g_current_floor > floor){
        dir = DIRN_DOWN;
    }
    if(g_current_floor < floor){
        dir = DIRN_UP;
    }
    if (g_current_floor == floor)
    {
        dir = DIRN_STOP;
    }
    
    elevio_motorDirection(dir);
}

bool at_destination(int floor){

    if(elevio_floorSensor() != -1){
        g_current_floor = elevio_floorSensor();
    }

    if(g_current_floor == floor){
        elevio_motorDirection(DIRN_STOP);

        return true;
    }
    return false;
}

void set_floor_light(){
    elevio_floorIndicator(g_current_floor);
}

void set_current_floor(){
    if(elevio_floorSensor() != -1){
        g_current_floor = elevio_floorSensor();
    }
}


long long time_now(){
    struct timespec t;
    clock_gettime(CLOCK_MONOTONIC, &t);
    return (long long)t.tv_sec * 1000LL + t.tv_nsec / 1000000LL;
}