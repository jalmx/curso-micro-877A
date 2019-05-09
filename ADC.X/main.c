#include "config.h"
#include "adc.h"

/**
 * 1. Se inicializa el módulo ADC
 * 2. Se elige el canal ADC
 */
void main(void) {
    TRISA = 0xFF; //configuro el PORTA como entrada
    PORTA = 0;
    TRISB = 0;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;

    adcInit();//inicio el ADC

    while(1) {
        PORTB = adcRead(0); //leyendo AN0
        __delay_ms(10);
        PORTC = adcRead(1); // leyendo AN1
        __delay_ms(10);
    }

}
