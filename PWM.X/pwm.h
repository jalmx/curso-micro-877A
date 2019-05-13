#define TMR2PRESCALE 16

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000
#endif

#ifndef FREQ_PWM //Hz
#define FREQ_PWM 245
#endif

void setTMR2(unsigned char const pwm);
void setPR2();

void setPR2() {
    PR2 = (_XTAL_FREQ / (FREQ_PWM * 4 * TMR2PRESCALE)) - 1;
}

void pwmInit1() {
    setPR2();
    setTMR2(1);
}

void pwmInit2() {
    setPR2();
    setTMR2(2);
}

void pwmSetDuty1(unsigned int duty) {
    if (duty > 1023) return;
    duty = ((float) duty / 1023)*(_XTAL_FREQ / (FREQ_PWM * TMR2PRESCALE));
    CCP1X = duty & 0x01; //Store the 1st bit
    CCP1Y = duty & 0x02; //Store the 0th bit
    CCPR1L = duty >> 2; // Store the remining 8 bit
}

void pwmSetDuty2(unsigned int duty) {
    if (duty > 1023) return;

    duty = ((float) duty / 1023)*(_XTAL_FREQ / (FREQ_PWM * TMR2PRESCALE));
    CCP2X = duty & 0x01; //Store the 1st bit
    CCP2Y = duty & 0x02; //Store the 0th bit
    CCPR2L = duty >> 2; // Store the remining 8 bit
}

void setTMR2(unsigned char const pwm) {
    if (pwm == 2) {
        CCP2M3 = 1;
        CCP2M2 = 1; //Configure the CCP2 module 
    } else {
        CCP1M3 = 1;
        CCP1M2 = 1; //Configure the CCP1 module 
    }
    if (TMR2PRESCALE == 1) {
        T2CKPS0 = 0;
        T2CKPS1 = 0;
    } else if (TMR2PRESCALE == 4) {
        T2CKPS0 = 1;
        T2CKPS1 = 0;
    } else {
        T2CKPS0 = 1;
        T2CKPS1 = 1;
    }
    TMR2ON = 1; //Configure the Timer module
    if (pwm == 2)
        TRISC2 = 0;
    else
        TRISC1 = 0; // make port pin on C as output
}