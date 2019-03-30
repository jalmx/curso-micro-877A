#include <xc.h>
#define _XTAL_FREQ 4000000

void main() {
    TRISB = 0;
    TRISC = 0;

    PORTB = 0;
    PORTC = 0;

    while (1) {

        for (int x = 0; x <= 2; x++) {
            PORTB = 0xFF;
            PORTC = 0xFF;
            __delay_ms(500);
            PORTB = 0;
            PORTC = 0;
            __delay_ms(500);
        }

        for (int x = 0; x <= 2; x++) {
            PORTB = 0x0C;
            PORTC = 0;
            __delay_ms(500);

            PORTB = 0x0F;
            PORTC = 0;
            __delay_ms(500);

            PORTB = 0x3F;
            PORTC = 0;
            __delay_ms(500);

            PORTB = 0xFF;
            PORTC = 0x00;
            __delay_ms(500);

            PORTB = 0xFF;
            PORTC = 0x03;
            __delay_ms(500);

            PORTB = 0xFF;
            PORTC = 0xFF;
            __delay_ms(500);

            PORTB = 0;
            PORTC = 0;
            __delay_ms(500);

            PORTB = 0xFF;
            PORTC = 0xFF;
            __delay_ms(500);

            PORTB = 0xFF;
            PORTC = 0x03;
            __delay_ms(500);

            PORTB = 0xFF;
            PORTC = 0x00;
            __delay_ms(500);

            PORTB = 0x3F;
            PORTC = 0;
            __delay_ms(500);

            PORTB = 0x0F;
            PORTC = 0;
            __delay_ms(500);

            PORTB = 0x0C;
            PORTC = 0;
            __delay_ms(500);
        }

    }
}
