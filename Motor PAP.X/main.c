
#include <xc.h>
#define _XTAL_FREQ 40000

void main(void) {
    char const giros[] = {0x01, 0x02, 0x06, 0x08};

    TRISB = 0;
    PORTB = 0;

    for (;;) {
        
        for(int i = 0; i<= 3; i++){
            PORTB = giros[i];
            __delay_ms(500);

        }
       
    }
}
