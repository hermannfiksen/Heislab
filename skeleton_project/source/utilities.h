#pragma once
#include "order.h"
#include "stdbool.h"
#define MAX_SIZE 10

typedef struct{
    Order arr[MAX_SIZE];
    int head;
    int tail;
} Queue;

void init_queue(Queue *q);

bool queue_is_full(Queue *q);

bool queue_is_empty(Queue *q);

void add_to_queue(Queue *q, Order order);

Order pop_queue(Queue *q);





