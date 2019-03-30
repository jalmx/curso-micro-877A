#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    TRISB = 0; //configuro como salida
    PORTB = 0; //limpio el puerto B

    while (1) { //comienza while
        PORTB = 0x3F; // 0 
        __delay_ms(400);
        PORTB = 0x03; // 1
        __delay_ms(400);
        PORTB = 0x6D; // 2
        __delay_ms(400);
        PORTB = 0x67; // 3
        __delay_ms(400);
        PORTB = 0x53; // 4
        __delay_ms(400);
        PORTB = 0x76; // 5
        __delay_ms(400);
    }//termina while
}//termina función main
