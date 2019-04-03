#include <xc.h>

void main() {
    TRISB = 0;
    PORTB = 0;

    int a = 5;
    int b = 2;
    int suma = a + b;

    for (;;) {
        PORTB = suma;
    }

}
