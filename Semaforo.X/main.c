#include <xc.h>// siempre debe ir
#define _XTAL_FREQ 4000000

void main() {

    TRISB = 0; //configuro el puerto B como salida
    PORTB = 0; //limpio el puerto B

    for(;;){ //for infinito
        
        PORTBbits.RB0 = 1; //ROJO
        PORTBbits.RB1 = 0; //AMBAR
        PORTBbits.RB2 = 0; // VERDE
        __delay_ms(800);
        
        PORTBbits.RB0 = 0; //ROJO
        PORTBbits.RB2 = 1; // VERDE
        __delay_ms(400);
        //PARPADEA EL VERDE
        PORTBbits.RB2 = 0; // VERDE
        __delay_ms(250);
        PORTBbits.RB2 = 1; // VERDE
        __delay_ms(250);
        PORTBbits.RB2 = 0; // VERDE
        __delay_ms(250);
        PORTBbits.RB2 = 1; // VERDE
        __delay_ms(250);
        PORTBbits.RB2 = 0; // VERDE
        __delay_ms(250);
        PORTBbits.RB2 = 1; // VERDE
        __delay_ms(250);
        
        PORTBbits.RB2 = 0; // VERDE
        PORTBbits.RB1 = 1; //AMBAR
        __delay_ms(500);
    }//fin del for
}// termina función main
