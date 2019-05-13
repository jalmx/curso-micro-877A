#include <xc.h>
#define _XTAL_FREQ 4000000

#define FREQ_PWM 245
#include "pwm.h"
#include "lcd.h"
#include "adc.h" //debe ser incluido despues de la definición del cristal

char entero[16];

void main(void) {
    TRISB = 255;
    PORTB = 0;
    adcInit();
    lcdInit();
    lcdClear();
    lcdSetCursor(1, 1);
    lcdPrint("Iniciando PWM");
    __delay_ms(10);

    pwmInit1();
    pwmInit2();
    pwmSetDuty1(0);
    pwmSetDuty2(0);

    lcdClear();
    lcdSetCursor(1, 1);
    lcdPrint("Modulo iniciado");
    __delay_ms(100);
    lcdClear();
    unsigned int pwm2 = 0;
    for (;;) {
        unsigned int v = adcRead(0);
        unsigned int m = ((float) v * 100) / 1023;
        pwmSetDuty1(v);
        lcdClear();
        sprintf(entero, "PWM1:%d%%", m);
        lcdSetCursor(1, 1);
        lcdPrint(entero);

        if (RB0 == 1) {
            if (pwm2 < 1024)
                pwmSetDuty2(++pwm2);
        } else if (RB1 == 1) {
            if (pwm2 > 0)
                pwmSetDuty2(--pwm2);
        }
        
        m = ((float) pwm2 * 100) / 1023;
        sprintf(entero, "PWM2:%d%%", m);
        lcdSetCursor(2, 1);
        lcdPrint(entero);
        __delay_ms(50);
    }
}
