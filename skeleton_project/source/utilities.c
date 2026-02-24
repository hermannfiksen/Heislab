#include "utilities.h"

void init_queue(Queue *q){
    q->head = -1;
    q->tail = -1;
}

bool queue_is_full(Queue *q){
    return (q->size == MAX_SIZE);
}

bool queue_is_empty(Queue *q){
    return (q->head == -1);
}

void add_to_queue(Queue *q, Order order){
    if (queue_is_full(q)){
        //gjør no greier her kall en interupt eller no dette skal ikke skje
    }
    if (queue_is_empty(q)){
        q->head = 0;
    }
    q->tail =  (q->tail + 1) % MAX_SIZE;
    q->arr[q->tail] = order;
    q->size++;
}

Order pop_queue(Queue *q){
    if(queue_is_empty(q)){
        //Dette kan skje det må vi håndtere kanskjen returnere nada.
    }
    Order current_order = q->arr[q->head];
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    return current_order;
}
