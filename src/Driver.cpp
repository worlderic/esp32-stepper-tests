/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include "DRV8834.h"
#include "A4988.h"
#include "DRV8825.h"

const int DIR = 14;
const int STEP = 12;

#define MOTOR_STEPS 200

// microstep control for DRV8834
//#define M0 2
//#define M1 3
//DRV8834 stepper(MOTOR_STEPS, DIR, STEP, M0, M1);

// microstep control for A4988
// #define MS1 10
// #define MS2 11
// #define MS3 12
// A4988 stepper(MOTOR_STEPS, DIR, STEP, MS1, MS2, MS3);

// microstep control for DRV8825
// same pinout as A4988, different pin names, supports 32 microsteps
#define MODE0 2
#define MODE1 3
#define MODE2 13
DRV8825 stepper(MOTOR_STEPS, DIR, STEP, MODE0, MODE1, MODE2);

void setup() {
    /*
     * Set target motor RPM.
     */
    stepper.setRPM(100);
    stepper.setMicrostep(2); // make sure we are in full speed mode
}

void loop() {
    /*
     * The easy way is just tell the motor to rotate 360 degrees at 1rpm
     */
    /*
    stepper.rotate(360);
    delay(2000);
    stepper.rotate(-360);
    delay(2000);
    */
    stepper.rotate(360);
    while(1);

}

