
#include <Stepper.h>
#include "const.h"

int revolutions_per_blind = 8;
int max_steps = steps_per_revolution*revolutions_per_blind;
int steps_per_increment = steps_per_revolution*turn_precision;
int steps = 0;

void open_blinds();
void close_blinds();
void step_open_blinds();
void step_close_blinds();

void open_blinds(Stepper motor){
    if (steps < max_steps){
        motor.step(max_steps - steps);
        steps = max_steps;
    }
}

void close_blinds(Stepper motor){
    if (steps > 0){
        motor.step(-steps);
        steps = 0;
    }
}

void step_open_blinds(Stepper motor){
    if (steps < max_steps){
        motor.step(steps_per_increment);
        steps += steps_per_increment;
    }
}

void step_close_blinds(Stepper motor){
     if (steps >= steps_per_increment){
        motor.step(-steps_per_increment);
        steps -= steps_per_increment;
    }
}

