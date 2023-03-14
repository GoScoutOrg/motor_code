#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>


volatile int timer_expired; 
volatile int irq0_occurred;

void timer_handler(int signal) { timer_expired = 1; } 
void usr1_handler(int signal) { irq0_occurred = 1; }




main() { /* Set timer expired to zero at the beginning */ 
    timer_expired = 0; 
    irq0_occurred = 0; 
    /* Set up the routines to respond to interrupts */ 
    interrupt(SIGUSR1, usr1_handler); 
    interrupt(SIGTERM, timer_handler);

    /* Set up the timer */ 
    timer_set((unsigned int)10000, (unsigned int)10000); 
    timer_on(); 
    /* Loop continuously and respond to interrupts */ 
    while(1) { 
        idle();   
        /* Return from this function after an interrupt */ 
        /* If the timer has expired, clear flag and do something*/ 
        if( timer_expired ) {  
            timer_expired = 0; 
            do_timer_things(); 
        }
        /* If irq0 has occurred, clear flag and do something*/ 
        if( irq0_occurred ) { 
            irq0_occurred = 0; 
            do_irq0_things();
        } 
    } 
        
}