//fyltte på heis, sende hvilken etasje den er i til oreder
#include "driver/elevio.h"
#include "stdbool.h"
#include "door.h"
#include "time.h"

long long time_now();

void go_to_floor(int floor);

void set_floor_light();
void set_current_floor();
bool at_destination(int floor);
void set_floor_light();