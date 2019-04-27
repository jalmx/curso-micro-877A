/*
 * File:   main.c
 * Author: Xizuth
 *
 * Created on April 24, 2019, 5:26 PM
 */

#define _XTAL_FREQ 4000000

#include <xc.h>
#include "adc.h"

/**
 * 1. Se inicializa el módulo ADC
 * 2. Se elige el canal ADC
 * 3. Esperas la bandera GO/DONE la cual indica que ha terminado
 * 4. Se lee el resulado de ADRESH y ADRESL
 */
void main(void) {
    TRISA = 0xFF;
    PORTB = 0;
    TRISB = 0;
    PORTB = 0;
    TRISC = 0;
    PORTC = 0;

    adcInit();

    for (;;) {
        PORTB = adcRead(0);
        __delay_ms(10);
        PORTC = adcRead(1);
        __delay_ms(10);
    }

}
