//holder styr på køen og sender neste etasje mål til movement
#pragma once
#include "order.h"
#define MAX_SIZE 10

Order order_queue[10] = {0, 5}; //a static array with room for all buttons beeing pressed at the same time
Order *p_currentOrder = &order_queue[0];// pointer to first object in queue

void set_button_light(int floor, ButtonType button, int value);

int legal_request(Order pot_order);

void add_order_to_queue(Order order);

int order_equal(Order order1, Order order2);

void reorder_queue(); //for fun senere