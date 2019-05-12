#define TMR2PRESCALE 16

#ifndef FREQ_PWM
#define FREQ 5000
#endif

long pmwMaxDuty() {
    return (float) _XTAL_FREQ / (FREQ_PWM * TMR2PRESCALE);
}

void setPR2() {
    PR2 = (_XTAL_FREQ / (FREQ_PWM * 4 * TMR2PRESCALE)) - 1;
}

/**
 * 
 * @param duty range 0 to 1023
 * @return 
 */
void pwmDuty1(unsigned short int duty) {
    if (duty < 1024) {
        duty = ((float) duty / 1023) * pmwMaxDuty();
        CCP1X = duty & 2;
        CCP1Y = duty & 1;
        CCPR1L = duty >> 2;
    }
}

void pwmDuty2(unsigned short int duty) {
    if (duty < 1024) {
        duty = ((float) duty / 1023) * pmwMaxDuty();
        CCP2X = duty & 2;
        CCP2Y = duty & 1;
        CCPR2L = duty >> 2;
    }
}

void pwmInit1() {
    setPR2();
    CCP1M3 = 1;
    CCP1M2 = 1;
#if TMR2PRESCALAR == 1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
#elif TMR2PRESCALAR == 4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
#elif TMR2PRESCALAR == 16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
#endif
    TMR2ON = 1;
    TRISC2 = 0;
}

void pwmInit2() {
    setPR2();
    CCP2M3 = 1;
    CCP2M2 = 1;
#if TMR2PRESCALE == 1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 4
    T2CKPS0 = 1;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 16
    T2CKPS0 = 1;
    T2CKPS1 = 1;
#endif
    TMR2ON = 1;
    TRISC1 = 0;
}