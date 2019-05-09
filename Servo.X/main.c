#include "config.h"
#include "lcd.h"
#include "adc.h"

#define SERVO1 PORTBbits.RB0
#define SERVO2 PORTBbits.RB1
#include "servo.h"

char mensaje[16];

void print(int const valor, char const y) {
    lcdSetCursor(y, 1);
    sprintf(mensaje, "Valor: %d", valor);
    lcdPrint(mensaje);
    __delay_ms(10);
}

void main(void) {
    TRISC = 255;
    PORTC = 0;
    TRISB = 0;
    PORTB = 0;

    adcInit();
    lcdInit();

    int angulo = 0;
    print(MINIMO, 1);
    print(angulo, 2);


    for (;;) {

        if (PORTCbits.RC0) {
            angulo++;
            int time = position1(angulo);
            print(time, 1);
            print(angulo, 2);
        } else if (PORTCbits.RC1) {
            angulo--;
            int time = position1(angulo);
            print(time, 1);
            print(angulo, 2);
        }

        unsigned int adc = adcRead(0);
        unsigned char ang = adc * 0.1759530791788856;// adc * (180/1023)
        position2(ang);

    }
}
