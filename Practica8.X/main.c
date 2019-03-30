#include <xc.h>
#define _XTAL_FREQ 4000000

void main() {
    TRISB = 0x01; //pin 0 será entrada
    PORTB = 0; //limpio el puerto B
    TRISC = 0; //configuro
    PORTC = 0; //limpio el puerto C

    while (1) {//inicia while
        if (RB0 == 1) {
            while (RB0 == 1) {
            }

            while (RB0 == 0) {
                RC0 = 1;
                __delay_ms(1);
            }

            while (RB0 == 1) {
            }

            RC0 = 0;
        }//fin del if
    }//fin del while
}
