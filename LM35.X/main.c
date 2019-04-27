#include "config.h"

#define LCD_TRIS TRISB //configura el puerto que será el puerto para la LCD
#define LCD_PORT PORTB // configuro el puerto para los pines de la LCD

#define RW RB1
#define RS RB2
#define EN RB3
#define D4 RB4
#define D5 RB5
#define D6 RB6
#define D7 RB7

#include "lcd.h"
#include <stdio.h>
#include "adc.h"

void main(void) {
    TRISA = 255;
    PORTA = 0;
    lcdInit();
    __delay_ms(10);
    lcdClear();

    adcInit();
    lcdSetCursor(1, 1);
    lcdPrint("Cargando...");
    lcdSetCursor(2, 1);
    lcdPrint("Temperatura");
    __delay_ms(300);

    lcdClear();

    /**
     * Obteniendo ecuación 
     *         1°C      5000mV
     * adc *  ----- *  --------
     *         10mV    1023bits
     */
    for (;;) {
        float temperatura = ((float) adcRead(0) * 500)/1023;
        lcdSetCursor(1,1);
        lcdPrint("Temperatura");
        
        char mensaje[16];
        sprintf(mensaje, "%.2f C", temperatura);
        lcdSetCursor(2, 1);
        lcdPrint(mensaje);
        __delay_ms(10);
    }
}
