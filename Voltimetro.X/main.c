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
    TRISA = 255;//entradas ADC
    PORTA = 0;//limpio el puerto A
    adcInit(); //inicio el ADC
    
    lcdInit(); //inicio la LCD
    lcdClear(); //limpio la pantalla
    lcdSetCursor(1, 1); //me coloco en la posición 1,1
    lcdPrint("Voltimetro");
    lcdSetCursor(2, 1);
    lcdPrint("Cargando...");
    __delay_ms(500);

    lcdClear();
    lcdSetCursor(1, 1);
    lcdPrint("Voltaje");

    for (;;) {
        float volt = (5 * (float) adcRead(0)) / 1023;
        char mensaje[16];
        sprintf(mensaje, "%.6fV", volt);
        lcdSetCursor(2,1);
        lcdPrint(mensaje);
        __delay_ms(10);
    }//termina for
}//termina función main
