#include <xc.h>
#define _XTAL_FREQ 4000000
#include <stdio.h>
#include "pines.h"
#include "lcd.h"

void main() {

    lcdInit();
    
    while (1) {
        lcdClear();
        lcdSetCursor(1, 1);
        lcdPrint("Bienvenido a");
        lcdSetCursor(2, 1);
        lcdPrint("Micro ;)");
        __delay_ms(2000);
        lcdClear();
        lcdSetCursor(1, 1);
        lcdPrint("    CBTIS 85    ");
        lcdSetCursor(2, 1);
        lcdPrint("     RULES     ");
        __delay_ms(2000);
        
        lcdClear();
        float f = 1.414;
        int a = 56;
        char s[16];
        sprintf(s, "Float = %1.2f", f);
        lcdSetCursor(1, 1);
        lcdPrint(s);
        sprintf(s, "Integer = %d", a);
        lcdSetCursor(2, 1);
        lcdPrint(s);
        
        __delay_ms(2000);
    }
}