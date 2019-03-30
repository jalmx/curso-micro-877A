#include <xc.h>

void main(){
   
    TRISBbits.TRISB0 = 0;
    TRISBbits.TRISB1 = 1;
    
    while(1)
        PORTBbits.RB0 = 1;
}