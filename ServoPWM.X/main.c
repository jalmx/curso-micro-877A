#include "config.h"
#include "lcd.h"
#include "adc.h"
#include "servo_pwm.h"

char mensaje[16];

void main(void) {
    lcdInit();
    adcInit();
    lcdClear();
    lcdSetCursor(1, 1);
    lcdPrint("Configurando");
    lcdSetCursor(2, 1);
    lcdPrint("Servos");
    __delay_ms(500);
    
    initServos();
    pwmSetDuty1(0);
    
    while (1) {
        lcdClear();
        unsigned int servo1 = adcRead(0);
        pwmSetDuty1(servo1);
        
        sprintf(mensaje, "PWM1:%d", servo1);
        lcdSetCursor(1, 1);
        lcdPrint(mensaje);
        __delay_ms(50);
    }

}
