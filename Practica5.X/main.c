#include <xc.h> //esta linea siempre debe ir
#define _XTAL_FREQ 4000000 //definimos el cristal

void main(void) {
    //configuro los puertos como salida
    TRISB = 0;
    TRISC = 0;

    TRISD = 0;
    //limpio los puertos 
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;

    while (1) {
        PORTB = 255;// 0xFF 0b11111111
        PORTC = 0;
        PORTD = 0;
        __delay_ms(250);
        PORTB = 0;
        PORTC = 255;
        PORTD = 0;
        __delay_ms(250);
        PORTB = 0;
        PORTC = 0;
        PORTD = 255;
        __delay_ms(250);
    }
}
