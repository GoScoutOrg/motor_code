#include <stdio.h>
#include "pwm.h"

int main(){
    enter_velocity();

    return 0;
    
}

void enter_velocity(){
    int input_velocity; 
    
    printf("Enter a velocity: ");
    scanf("%d", &input_velocity);
    printf("given velocity: %d", input_velocity);
    
}

void enter_distance(){
    int input_velocity; 
    int input_distance;
    
    printf("Enter a velocity: ");
    scanf("%d", &input_velocity);

    printf("Enter a distance: ");
    scanf("%d", &input_distance);

    printf("given velocity: %d", input_velocity);
    printf("given distance: %d", input_distance);
    

}