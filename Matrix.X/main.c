#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    unsigned char const col[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
    unsigned char const smile[] = {0x20, 0x6E, 0xCE, 0xC0, 0xC0, 0xCE, 0x6E, 0x20};
    unsigned char const heart[] = {0x1C, 0x3E, 0x7E, 0xFC, 0xFC, 0x7E, 0x3E, 0x1C};
    unsigned char const f[] = {0xFF, 0xFF, 0x1B, 0x1B, 0x1B, 0x03, 0x03, 0x03};

    TRISB = 0;
    TRISC = 0;
    PORTB = 0;
    PORTC = 0;

    for (char a = 0; a < 20; a++) {
        for (char i = 0; i <= 7; i++) {
            PORTC = ~col[i];
            PORTB = f[i];
            __delay_ms(5);

        }
    }
    for (char a = 0; a < 20; a++) {
        for (char i = 0; i <= 7; i++) {
            PORTC = ~col[i];
            PORTB = smile[i];
            __delay_ms(5);

        }
    }
    for (char a = 0; a < 80; a++) {
        for (char i = 0; i <= 7; i++) {
            PORTC = ~col[i];
            PORTB = heart[i];
            __delay_ms(5);

        }
    }
}
