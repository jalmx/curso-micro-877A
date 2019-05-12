#include <xc.h>
#define _XTAL_FREQ 20000000

#define FREQ_PWM 5000
#include "pwm2.h"
#include "lcd.h"
#include "adc.h" //debe ser incluido despues de la definición del cristal

void main(void) {
    TRISB = 255;
    PORTB = 0;
    adcInit();
    lcdInit();
    lcdClear();
    lcdSetCursor(1,1);
    lcdPrint("Iniciando PWM");
    __delay_ms(10);
    
    pwmInit1();
    pwmInit2();
    pwmDuty1(0);
    
    lcdClear();
    lcdSetCursor(1,1);
    lcdPrint("Modulo iniciado");
   // pwmDuty2(0);
    __delay_ms(100);
    lcdClear();
    for (;;) {
        unsigned int v = adcRead(0);
        pwmDuty1(v);
        char entero[16];
        sprintf(entero, "PWM = %d", v);
        lcdClear();
        lcdSetCursor(1, 1);
        lcdPrint(entero);
     //   pwmDuty2(adcRead(0));
        __delay_ms(50);
    }
}
