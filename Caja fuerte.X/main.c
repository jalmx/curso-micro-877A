#include "config.h"

#define KEYPAD_PORT PORTB
#define KEYPAD_TRIS TRISB
#define ROW1 RB0
#define ROW2 RB1
#define ROW3 RB2
#define ROW4 RB3
#define COL1 RB4
#define COL2 RB5
#define COL3 RB6
#define COL4 RB7
#include "keypad.h"

#define LCD_TRIS TRISC //configura el puerto que será el puerto para la LCD
#define LCD_PORT PORTC // configuro el puerto para los pines de la LCD

#define RW RC1
#define RS RC2
#define EN RC3
#define D4 RC4
#define D5 RC5
#define D6 RC6
#define D7 RC7
#include "lcd.h"/////se incluye la lib de la LCD

char const pass[] = {'1', '2', '3', '4'};

void main(void) {
    TRISD = 0; //
    PORTD = 0; //control de motor y led
    lcdInit();
    kbdInit();

    do {
        lcdClear();
        lcdSetCursor(1, 1);
        lcdPrint("Bienvenido");
        lcdSetCursor(2, 1);
        lcdPrint("Presionar 0");
        char flag = 1; //
        char passOk = 0; // para saber si la contraseña es correcta
        while (flag) {
            char key = kbdGetKey();

            if (key == '0') {
                lcdClear();
                lcdSetCursor(1, 1);
                lcdPrint("Dar Password");
                char password[4];//delcaraon un array donde voy a guardar la contraseña que de el usuario
                char contador = 0;//para saber cuantos digitos me han dado para la contraseña
                while (contador < 4) {
                    key = kbdGetKey();
                    if (key != 255 && contador < 4) {
                        password[contador++] = key;
                        lcdSetCursor(2, 5 + contador);
                        lcdWriteChar('*');
                    }
                }
                for (char i = 0; i < 4; i++) {
                    passOk = 1;
                    if (pass[i] != password[i]){
                        passOk = 0;
                        break;//rompe el for
                    }
                }
                flag = 0;
                if (passOk) {
                    lcdClear();
                    lcdSetCursor(1, 1);
                    lcdPrint("Abriendo...");
                    PORTD = 255;
                    PORTDbits.RD1 = 0;
                    __delay_ms(200);
                    PORTDbits.RD2 = 0;
                    __delay_ms(200);
                    PORTDbits.RD2 = 1;
                    __delay_ms(200);
                    PORTDbits.RD2 = 0;
                    __delay_ms(200);
                    PORTDbits.RD2 = 1;
                    __delay_ms(200);
                    PORTD = 0;
                    lcdClear();
                    lcdSetCursor(1, 1);
                    lcdPrint("Sea bienvenido");
                    lcdSetCursor(2,1);
                    lcdPrint("Cerrara en 3s");
                    __delay_ms(3000);
                    lcdClear();
                    lcdSetCursor(1, 1);
                    lcdPrint("Cerrando tapa...");
                    PORTD = 255;
                    PORTDbits.RD0 = 0;
                    __delay_ms(200);
                    PORTDbits.RD2 = 0;
                    __delay_ms(200);
                    PORTDbits.RD2 = 1;
                    __delay_ms(200);
                    PORTDbits.RD2 = 0;
                    __delay_ms(200);
                    PORTDbits.RD2 = 1;
                    __delay_ms(200);
                    PORTD = 0;
                } else {
                    lcdClear();
                    lcdSetCursor(1, 1);
                    lcdPrint("Lastima");
                    lcdSetCursor(2, 1);
                    lcdPrint("Margarito");
                    __delay_ms(2000);
                }   
            }
        }

    } while (1);
}
