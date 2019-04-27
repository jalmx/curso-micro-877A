#include <xc.h>
#define _XTAL_FREQ 4000000
#include <stdio.h> // se debe importar cuando se necesita enviar una variable a la LCD
/////configuración de pines para LCD
#define LCD_TRIS TRISD //configura el puerto que será el puerto para la LCD
#define LCD_PORT PORTD // configuro el puerto para los pines de la LCD

#define RW RD1
#define RS RD2
#define EN RD3
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7
#include "lcd.h"/////se incluye la lib de la LCD
///////////////////////////
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