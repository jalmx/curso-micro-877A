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

    while (1) {
        char keypress = kbdGetC();
        if (keypress != 0xFF) {
            char key = keypress;

            if(key == '1'){
                    PORTC = 0x03; // 1;
            }
        }
    }
}
