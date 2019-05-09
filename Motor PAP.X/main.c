#include <xc.h>
#define _XTAL_FREQ 4000000

void main(void) {
    char const backward[] = {0x01, 0x02, 0x04, 0x08, '\0'}; //secuencia para ir adelante
    char const forward[] = {0x08, 0x04, 0x02, 0x01, '\0'}; //secuencia para reversa
    char const full[] = {0x03, 0x06, 0x0C, 0x09, '\0'}; //secuencia para full, de 45 en 45°
    char const half[] = {0x01, 0x03, 0x02, 0x06, 0x04, 0x0C, 0x08, 0x09, '\0'}; //secuencia de medio paso
    int const TIME = 250; //velocidad del motor
    TRISB = 0;
    TRISC = 255;
    TRISD = 0;
    PORTB = 0;
    PORTC = 0;
    PORTD = 0;

    for (;;) {
        int i = 0;
//char const backward[] = {0x01, 0x02, 0x04, 0x08, '\0'}; //secuencia para ir adelante
        if (PORTCbits.RC0 == 1) {
            while (forward[i] != '\0') {
                PORTD = PORTB = forward[i++];
                __delay_ms(TIME);
            }
            i = 0;
        } else if (PORTCbits.RC1 == 1) {
            while (backward[i] != '\0') {
                PORTD = PORTB = backward[i++];
                __delay_ms(TIME);
            }
            i = 0;
        } else if (PORTCbits.RC2 == 1) {
            while (full[i] != '\0') {
                PORTD = PORTB = full[i++];
                __delay_ms(TIME);
            }
            i = 0;
        } else if (PORTCbits.RC3 == 1) {
            while (half[i] != '\0') {
                PORTB = PORTD = half[i++];
                __delay_ms(TIME);
            }
            i = 0;
        } else {
            PORTB = 0;
        }
    }
}
