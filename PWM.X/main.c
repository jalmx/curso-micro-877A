#include <xc.h>
#define _XTAL_FREQ 4000000

#include "pwm.h"
#include "adc.h" //debe ser incluido despues de la definición del cristal

void main(void) {
    TRISB = 255;
    PORTB = 0;
    TRISD = 0;
    PORTD = 0;

    adcInit();

    pwmInit1(2000);
    pwmInit2(2000);
    pwmSetDutyCycle1(0);
    pwmSetDutyCycle2(0);
    unsigned int duty1 = 500; //comenzará el duty en 500, casi 50%
    unsigned char const delta = 25; //la variación cada vez que se presione el botón
    pwmSetDutyCycle1(duty1); //cargo el valor del duty a la salida de PWM

    for (;;) {

        if (PORTBbits.RB0 == 1) {
            if (duty1 < 1023) {
                pwmSetDutyCycle1(duty1 += delta);
                PORTDbits.RD0 = 1;
                __delay_ms(100);
                PORTDbits.RD0 = 0;
            }

        } else if (PORTBbits.RB1 == 1) {
            if (duty1 > 0) {
                pwmSetDutyCycle1(duty1 -= delta);
                PORTDbits.RD1 = 1;
                __delay_ms(100);
                PORTDbits.RD1 = 0;
            }
        }
        
        pwmSetDutyCycle2(adcRead(0));
        __delay_ms(10);

    }
}
