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

    initServos(); //se inician los servos
    setAngule1(0);

    unsigned int servo1, servo2 = 0;
    while (1) {
        lcdClear();
        servo1 = adcRead(0);
        unsigned char angule1 = servo1 * 0.175953079; //angule = adc * (180/1023)
        setAngule1(angule1);

        sprintf(mensaje, "Angule S1:%d", angule1);
        lcdSetCursor(1, 1);
        lcdPrint(mensaje);

        if (RB0 == 1) {
            if (servo2 < 1024)
                setAngule2(++servo2);
        } else if (RB1 == 1) {
            if (servo2 > 0)
                setAngule2(--servo2);
        }
        unsigned char angule2 = servo2 * 0.175953079; //angule = adc * (180/1023)
        setAngule2(angule2);
        sprintf(mensaje, "Angule S2:%d", angule2);
        lcdSetCursor(2, 1);
        lcdPrint(mensaje);

        __delay_ms(50);
    }

}
