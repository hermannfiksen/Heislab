#include "order.h"


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



bool queue_is_full(Queue *q){
    return (q->size == MAX_SIZE);
}

bool queue_is_empty(Queue *q){
    return (q->size == 0);
}

void add_to_queue(Queue *q, Order order){
    if (queue_is_full(q)){
        //gjør no greier her kall en interupt eller no dette skal ikke skje
    }
    if (q->head == -1){
        q->head = 0;
    }
    q->tail =  (q->tail + 1) % MAX_SIZE;
    q->arr[q->tail] = order;
    q->size++;
}

Order get_next_order(Queue *q){
    if(queue_is_empty(q)){
        //Dette kan skje det må vi håndtere kanskjen returnere nada.
    }
    Order current_order = q->arr[q->head];
    return current_order;
}
void remove_order(Queue *q){
    if(queue_is_empty(q) == 0){
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    }else{
        q->head = -1;
        q->tail = -1;
    }
}
