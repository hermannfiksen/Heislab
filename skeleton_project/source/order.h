//skal ta innput so sende videre til queue og sette lys og stoppknapp
//og hovedloop 
#pragma once
#include "driver/elevio.h"
#include <time.h>

typedef struct {
    ButtonType button;
    int floor;
}Order;

    




int stop_hms();

void elevator_run();

void check_for_orders();

