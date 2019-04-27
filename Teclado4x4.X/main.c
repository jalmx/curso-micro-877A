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
                case '6':
                    PORTC = 0xFE; // 5         
                    break;
                case '7':
                    PORTC = 0x23; // 5         
                    break;
                case '8':
                    PORTC = 0xFF; // 5         
                    break;
                case '9':
                    PORTC = 0xF3; // 5         
                    break;
                case 'A':
                    PORTC = 0xFB; // 5         
                    break;
                case 'B':
                    PORTC = 0x5E; // 5         
                    break;
                case 'C':
                    PORTC = 0x3C; // 5         
                    break;
                case 'D':
                    PORTC = 0x4F; // 5         
                    break;
                case 'E':
                    PORTC = 0xFC; // 5         
                    break;
                case 'F':
                    PORTC = 0xF8; // 5         
                    break;
            }
        }
    }
}
