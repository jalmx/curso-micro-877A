#include "config.h"
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

    lcdInit(); //inicializo la LCD
    
    while (1) {
//        lcdClear(); //clean display
//        lcdSetCursor(1, 1);
//        lcdPrint("Welcome to");
//        lcdSetCursor(2, 1);
//        lcdPrint("Micro ;)");
//        __delay_ms(2000);
//        lcdClear();
//        lcdSetCursor(1, 5);
//        lcdPrint("CBTIS 85");
//        lcdSetCursor(2, 5);
//        lcdPrint("RULES");
//        lcdSetCursor(1,15);
//        lcdPrint(":D");
//        lcdSetCursor(2,15);
//        lcdPrint("<3");
//        __delay_ms(2000);
        
        lcdClear();
        float f = 3.1416;
        char flotante[16];//array
        sprintf(flotante, "Float = %.4f", f);
        lcdSetCursor(1, 1);
        lcdPrint(flotante);
        
        char entero[16];
        int a = 56;
        sprintf(entero, "Integer = %d", a);
        lcdSetCursor(2, 1);
        lcdPrint(entero);
        __delay_ms(2000);
        
        lcdClear();
        lcdSetCursor(1,1);
        lcdPrint("35");
        __delay_ms(2000);
    }
}