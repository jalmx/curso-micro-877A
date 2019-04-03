// DEFINICIÓN DEL PUERTO Y LOS PINES,
//COPIAR ESTA SECCIÓN
//#define KEYPAD_PORT PORTB
//#define KEYPAD_TRIS TRISB
//#define ROW1 RB0
//#define ROW2 RB1
//#define ROW3 RB2
//#define ROW4 RB3
//#define COL1 RB4
//#define COL2 RB5
//#define COL3 RB6
//#define COL4 RB7
////////////////////////////////////////////////////////////////////
char const keyPadMatrix[] = {
    '1', '2', '3',
    '4', '5', '6',
    '7', '8', '9',
    '*', '0', '#',
    0xFF
};

char key, old_key;

//void init_IO(void);
void kbdInit();
int kbdGetC();

void kbdInit() {
    KEYPAD_TRIS = 0xF0; //Use PORTB for Keypad
    KEYPAD_PORT = 0x00;
}

int kbdGetC() {
    // This routine returns the first key found to be pressed during the scan.
    char key = 0, row;

    for (row = 0b00000001; row < 0b00010000; row <<= 1) {
        { // turn on row output
            ROW1 = (row & 0x0001) >> 0;
            ROW2 = (row & 0x0002) >> 1;
            ROW3 = (row & 0x0004) >> 2;
            ROW4 = (row & 0x0008) >> 3;
            __delay_ms(1);
        }
        // read colums - break when key press detected
        if (COL1)break;
        key++;
        if (COL2)break;
        key++;
        if (COL3)break;
        key++;
        if (COL4)break;
        key++;
    }
    ROW1 = 0;
    ROW2 = 0;
    ROW3 = 0;
    ROW4 = 0;
    if (key != old_key) {
        old_key = key;
        return keyPadMatrix[ key ];
    } else
        return keyPadMatrix[ 0x0C ];
}
