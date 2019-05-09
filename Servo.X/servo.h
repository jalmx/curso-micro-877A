#define PERIODO 2000 //2mS
#define INCREMENTO 1
#define MINIMO 42
#define MAXIMO 86


int position1(unsigned char const angule) {

    int time = angule <= 0 ? MINIMO : angule >= MAXIMO ? MAXIMO : ((angule * 0.233333333333333) + 42);

    for (char i = 0; i < 50; i++) {
        SERVO1 = 1;
        for (int j = 0; j < time; j++)
            __delay_us(1);

        SERVO1 = 0;
        for (int j = 0; j < (PERIODO - time); j++)
            __delay_us(1);
    }

    return time;
}

//por cada SERVO que se quiera agregar, se debe agregar un 
// #define SERVO#
//copiar la función y colocar el nuevo servo
int position2(unsigned char const angule) {

    int time = angule <= 0 ? MINIMO : angule >= MAXIMO ? MAXIMO : ((angule * 0.233333333333333) + 42);

    for (char i = 0; i < 50; i++) {
        SERVO2 = 1;
        for (int j = 0; j < time; j++)
            __delay_us(1);

        SERVO2 = 0;
        for (int j = 0; j < (PERIODO - time); j++)
            __delay_us(1);
    }

    return time;
}