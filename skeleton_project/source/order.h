//skal ta innput so sende videre til queue og sette lys og stoppknapp
//og hovedloop 
#pragma once
#include "driver/elevio.h"
#include <time.h>
#include "queue.h"

typedef struct {
    ButtonType button;
    int floor;
}Order;

Queue order_queue = {.head = -1, .tail = -1, .size = 0};
Queue* queue_pointer = &order_queue;


int stop_hms();

void elevator_run();

void check_for_orders();

