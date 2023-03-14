#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>

static int8_t previousPos;
static int32_t currentPos;
static int32_t commandPos;
static int32_t velocity;
static int16_t currentPWM;

static uint16_t workingKP;
static uint16_t workingKV;

//or = 0
static bool s_isServoActive = false;

//redefine this for calibration
#define SERVO_UNITS_SHIFT	8
#define SHIFT_KPKV          4

int main(){

    while(1){
        //instead of this insert timer set up?
        sleep(.003);
        servoInterruptHandler();

    }
}

void servoInterruptHandler(){
    int8_t     newPos, distMoved;
    int32_t    positionError, pwm;

    //read in new position
    //newPos = read in from motor
    distMoved = velocity = newPos - previousPos;
    currentPos    += velocity;
    previousPos    = newPos;


    //calculate pwm 
    positionError  = (commandPos >> SERVO_UNITS_SHIFT) - currentPos;
    pwm            = (workingKP * positionError - workingKV * velocity) >> SHIFT_KPKV;
    currentPWM     = pwm;
}