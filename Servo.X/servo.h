/**
 * Se deben definir todos las pines que serán configurados como pwm
 * #define SERVO1 PORTBbits.RB0
 * #define SERVO2 PORTBbits.RB1
 * #define SERVOn PORTX.RXx
 * #include "servo.h"
 */

#define PERIODO 20000 //20mS
#define MINIMO 70
#define MAXIMO 142
#define CONVERT 0.4 // 72/180 convierte el angulo

float convertion(unsigned char angule) {
    return angule <= 0 ? MINIMO : angule >= 180 ? MAXIMO : ((float) angule * CONVERT) + MINIMO;
}

void position1(unsigned char angule) {
    unsigned char time = 0;
    angule = convertion(angule);

    SERVO1 = 1;
    while (time++ < angule)
        __delay_us(1);

    SERVO1 = 0;
    __delay_ms(10);
}

//por cada SERVO que se quiera agregar, se debe agregar un 
// #define SERVO#
//copiar la función y colocar el nuevo servo -> positionX() 

void position2(unsigned char angule) {
    unsigned char time = 0;
    angule = convertion(angule);

    SERVO2 = 1;
    while (time++ < angule)
        __delay_us(1);

    SERVO2 = 0;
    __delay_ms(10);
}

void position3(unsigned char angule) {
    unsigned char time = 0;
    angule = convertion(angule);

    SERVO3 = 1;
    while (time++ < angule)
        __delay_us(1);

    SERVO3 = 0;
    __delay_ms(10);
}
