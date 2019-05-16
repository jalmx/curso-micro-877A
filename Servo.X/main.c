#include "config.h"
#include "lcd.h"
#include "adc.h"

#define SERVO1 PORTBbits.RB0
#define SERVO2 PORTBbits.RB1
#include "servo.h"

char mensaje[16];

void print(unsigned int const valor1, unsigned int const valor2) {
    lcdClear();
    lcdSetCursor(1, 1);
    sprintf(mensaje, "Angule 1: %d", valor1);
    lcdPrint(mensaje);
    lcdSetCursor(2, 1);
    sprintf(mensaje, "Angule 2: %d", valor2);
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

    unsigned int angulo1 = 0, angulo1Old = 0, adc = 0, adcOld = 0;
    unsigned char angule2 = 0;
    print(angulo1, 0);
    __delay_ms(10);

    for (;;) {

        if (PORTCbits.RC0 && angulo1 < 180) {
            angulo1++;
            __delay_ms(150);
        } else if (PORTCbits.RC1 && angulo1 > 0) {
            angulo1--;
            __delay_ms(150);
        }

        if (angulo1 != angulo1Old) {
            print(angulo1, angule2);
            position1(angulo1); //
            angulo1Old = angulo1;
        }

        adc = adcRead(0);
        if (adc != adcOld) {
            angule2 = adc * 0.175953079; // adc * (180/1023)
            print(angulo1, angule2);
            position2(angule2);//asigno el angulo al Servo 2
            adcOld = angule2;
        }

        __delay_ms(50);
    }
}
