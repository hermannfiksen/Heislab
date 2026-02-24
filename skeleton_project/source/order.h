//skal ta innput so sende videre til queue og sette lys og stoppknapp
 
#pragma once
#include "driver/elevio.h"
#include <time.h>
#include "stdbool.h"

#define MAX_SIZE 11


typedef struct {
    ButtonType button;
    int floor;
}Order;


int stop_hms();

typedef struct{
    Order arr[MAX_SIZE];
    int head;
    int tail;
    int size;
} Queue;

void init_queue(Queue *q);

bool queue_is_full(Queue *q);

bool queue_is_empty(Queue *q);

void add_to_queue(Queue *q, Order order);

Order get_next_order(Queue *q);

void remove_order(Queue *q);



