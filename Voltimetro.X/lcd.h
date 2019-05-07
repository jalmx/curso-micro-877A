////Configuración de pines. **Copiar y modificar**

//+++++++++++++++antes debe estar definido el XTAL

//#include <stdio.h> // se debe importar cuando se necesita enviar una variable a la LCD

///////configuración de pines para LCD
//#define LCD_TRIS TRISD //configura el puerto que será el puerto para la LCD
//#define LCD_PORT PORTD // configuro el puerto para los pines de la LCD

//#define RW RD1
//#define RS RD2
//#define EN RD3
//#define D4 RD4
//#define D5 RD5
//#define D6 RD6
//#define D7 RD7
//#include "lcd.h"/////se incluye la lib de la LCD
/////////////////////////////

void lcdPort(char a) {
    if (a & 1)
        D4 = 1;
    else
        D4 = 0;

    if (a & 2)
        D5 = 1;
    else
        D5 = 0;

    if (a & 4)
        D6 = 1;
    else
        D6 = 0;

    if (a & 8)
        D7 = 1;
    else
        D7 = 0;
}

void lcdCmd(char a) {
    RS = 0; // => RS = 0
    lcdPort(a);
    EN = 1; // => E = 1
    __delay_ms(4);
    EN = 0; // => E = 0
}

static void lcdClear(void) {
    lcdCmd(0);
    lcdCmd(1);
}

void lcdSetCursor(char y, char x) {
    char temp, z, yy, row = 0x80;
    
    if (y == 2) 
        row += 64;
    else if (y == 3) 
        row +=20;
    else if (y == 4)
        row += 64+20;
                
    temp = row + x - 1;
    z = temp >> 4;
    yy = temp & 0x0F;
    lcdCmd(z);
    lcdCmd(yy);
}

void lcdInit(void) {
    LCD_TRIS = 0;
    LCD_PORT = 0;
    lcdPort(0x00);
    __delay_ms(20);
    lcdCmd(0x03);
    __delay_ms(5);
    lcdCmd(0x03);
    __delay_ms(11);
    lcdCmd(0x03);
    /////////////////////////////////////////////////////
    lcdCmd(0x02);
    lcdCmd(0x02);
    lcdCmd(0x08);
    lcdCmd(0x00);
    lcdCmd(0x0C);
    lcdCmd(0x00);
    lcdCmd(0x06);
}

void lcdWriteChar(char const a) {
    char temp, y;
    temp = a & 0x0F;
    y = a & 0xF0;
    RS = 1; // => RS = 1
    lcdPort(y >> 4); //Data transfer
    EN = 1;
    __delay_us(40);
    EN = 0;
    lcdPort(temp);
    EN = 1;
    __delay_us(40);
    EN = 0;
}

void lcdPrint(unsigned char const *a) {
    for (int i = 0; a[i] != '\0'; i++)
        lcdWriteChar(a[i]);
}
