////Configuración de pines. **Copiar y modificar**
//#define LCD_TRIS TRISD
//#define LCD_PORT PORTD
//
//#define RW RD1
//#define RS RD2
//#define EN RD3
//#define D4 RD4
//#define D5 RD5
//#define D6 RD6
//#define D7 RD7

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

lcdClear() {
    lcdCmd(0);
    lcdCmd(1);
}

void lcdSetCursor(char a, char b) {
    char temp, z, y;
    if (a == 1) {
        temp = 0x80 + b - 1;
        z = temp >> 4;
        y = temp & 0x0F;
        lcdCmd(z);
        lcdCmd(y);
    } else if (a == 2) {
        temp = 0xC0 + b - 1;
        z = temp >> 4;
        y = temp & 0x0F;
        lcdCmd(z);
        lcdCmd(y);
    }
}

void lcdInit() {
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

void lcdWriteChar(char a) {
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

void lcdPrint(unsigned char *a) {
    int i;
    for (i = 0; a[i] != '\0'; i++)
        lcdWriteChar(a[i]);
}
