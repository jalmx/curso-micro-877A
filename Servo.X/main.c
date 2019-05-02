#include "config.h"
#include "adc.h"

void main(void) {
    TRISB = 255;
    PORTB = 0;
    
    adcInit();
       
    for(;;){
        
    }
}
