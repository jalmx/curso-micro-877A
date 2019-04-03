#include <xc.h>
#define _XTAL_FREQ 4000000

void main() {
    TRISB = 0;
    PORTB = 0;
    
    int tabla = 2;
    
    while(1){    
        
        for(int x = 1; x <= 10; x++){
            int resultado = tabla * x;
            PORTB = resultado;
            __delay_ms(300);
        }//termina el for
    }//termina while
}
