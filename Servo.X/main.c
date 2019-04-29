#include "config.h"
#include "adc.h"
#include "pwm.h"

void main(void) {
    TRISB = 255;
    PORTB = 0;
    
    adcInit();
    pwmInit1(2000);
    
    for(;;){
        
    }
}
