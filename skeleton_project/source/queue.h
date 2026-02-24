//holder styr på køen og sender neste etasje mål til movement
#pragma once
#include "order.h"
#include "utilities.h"
#define MAX_SIZE 11



void set_button_light(int value);

int legal_request(Order pot_order);

void add_order_to_queue(Order order);

int order_equal(Order order1, Order order2);

void reorder_queue(); //for fun senere