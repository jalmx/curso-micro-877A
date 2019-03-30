#include <xc.h>
#define _XTAL_FREQ 4000000

void main() {

    TRISB = 0x03; //pin 0 será entrada
    PORTB = 0; //limpio el puerto B
    TRISC = 0; //configuro
    PORTC = 0; //limpio el puerto C

    while (1) {
        if (RB0 == 1) {
            PORTC = !PORTC;
            __delay_ms(100);
        }//fin del if

        if (RB1 == 1) {
            PORTC = ~PORTC;
            __delay_ms(100);
        }//fin del if
    }
}
