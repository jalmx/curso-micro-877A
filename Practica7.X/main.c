#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    TRISB = 0x01; //pin 0 será entrada
    PORTB = 0; //limpio el puerto B
    TRISC = 0; //configuro
    PORTC = 0; //limpio el puerto C

    while(1){ //inicia while
        
        if(RB0 == 1){
            PORTC = 1;
            __delay_ms(1);
        }
        PORTC = 0;
    }//termina while
}
