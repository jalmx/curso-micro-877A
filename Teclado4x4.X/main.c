#include <xc.h>

#define KEYPAD_PORT PORTB
#define KEYPAD_TRIS TRISB
#define ROW1 RB0
#define ROW2 RB1
#define ROW3 RB2
#define ROW4 RB3
#define COL1 RB4
#define COL2 RB5
#define COL3 RB6
#define COL4 RB7

#define _XTAL_FREQ 4000000
#include "keypad.h"

void main() {
    TRISC = 0;
    PORTC = 0;
    kbdInit();

    PORTC = 0x3F; // cargo el 0 en el display
    __delay_ms(5); //waiting a time before begin to read keypad

    while (1) {

        char keypress = kbdGetC();
        if (keypress != 0xFF) {

            char key = keypress;
            switch (key) {
                case '0':
                    PORTC = 0x3F; // 0         
                    break;
                case '1':
                    PORTC = 0x03; // 1       
                    break;
                case '2':
                    PORTC = 0x6D; // 2         
                    break;
                case '3':
                    PORTC = 0x67; // 3         
                    break;
                case '4':
                    PORTC = 0x53; // 4         
                    break;
                case '5':
                    PORTC = 0x76; // 5         
                    break;
            }
        }
    }
}
