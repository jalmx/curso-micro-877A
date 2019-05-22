#include "config.h"

void main(void) {
    TRISB = 255;
    TRISC = 0;
    PORTB = 0;
    PORTC = 0;

    while (1) {

        if (RB0 == 1) {
            PORTCbits.RC0 = 1;
            __delay_us(119);
            PORTCbits.RC0 = 0;
            __delay_us(119);
        }
        if (RB1 == 1) {
            PORTCbits.RC0 = 1;
            __delay_us(126);
            PORTCbits.RC0 = 0;
            __delay_us(126);
        }
        if (RB2 == 1) {
            PORTCbits.RC0 = 1;
            __delay_us(142);
            PORTCbits.RC0 = 0;
            __delay_us(142);
        }
        if (RB3 == 1) {
            PORTCbits.RC0 = 1;
            __delay_us(159);
            PORTCbits.RC0 = 0;
            __delay_us(159);
        }
    }

    return;
}
