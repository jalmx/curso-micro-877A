/**
 * Esta librer�a se aplica con un cristal de 4MHz
 */
#define TMR2PRESCALE 16

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000
#endif

#ifndef FREQ_PWM //Hz
#define FREQ_PWM 245
#endif

void setTMR2(unsigned char const pwm);
void setPR2();
void initServos();

void setPR2() {
    PR2 = (_XTAL_FREQ / (FREQ_PWM * 4 * TMR2PRESCALE)) - 1;
}

unsigned int setDuty(unsigned int duty) {
    return ((float) duty / 1023)*(_XTAL_FREQ / (FREQ_PWM * TMR2PRESCALE));
}

void initServos() {
    setPR2();
    setTMR2(1);
    setTMR2(2);
}

void setAngule1(unsigned char angule) {
    unsigned int duty = (angule * 1.3944444) + 251;
    if (duty > 1023) return;
    duty = setDuty(duty);
    CCP1X = duty & 0x01; //Store the 1st bit
    CCP1Y = duty & 0x02; //Store the 0th bit
    CCPR1L = duty >> 2; // Store the remining 8 bit
}

void setAngule2(unsigned char angule) {
    unsigned int duty = (angule * 1.3944444) + 251;
    if (duty > 1023) return;

    duty = setDuty(duty);
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
#if TMR2PRESCALE ==1
    T2CKPS0 = 0;
    T2CKPS1 = 0;
#elif TMR2PRESCALE == 4        
    T2CKPS0 = 1;
    T2CKPS1 = 0;
#else
    T2CKPS0 = 1;
    T2CKPS1 = 1;
#endif
    TMR2ON = 1; //Configure the Timer module
    if (pwm == 2)
        TRISC2 = 0;
    else
        TRISC1 = 0; // make port pin on C as output
}