#define TMR2PRESCALE 16

int FREQ1;
int FREQ2;

void setTMR2(char const pwm);
void setPR2(unsigned int const freq);

void pwmInit1(unsigned int const freq) {
    FREQ1 = freq;
    setPR2(freq);
    setTMR2(1);
}

void pwmInit2(unsigned int freq) {
    FREQ2 = freq;
    setPR2(freq);
    setTMR2(2);
}

void pwmSetDutyCycle1(unsigned int duty) {
    if(duty >= 1023) return;
    duty = ((float) duty / 1023)*(_XTAL_FREQ / (FREQ1 * TMR2PRESCALE));
    CCP1X = duty & 0x01; //Store the 1st bit
    CCP1Y = duty & 0x02; //Store the 0th bit
    CCPR1L = duty >> 2; // Store the remining 8 bit
}

void pwmSetDutyCycle2(unsigned int duty) {
    if(duty >= 1023) return;
    
    duty = ((float) duty / 1023)*(_XTAL_FREQ / (FREQ2 * TMR2PRESCALE));
    CCP2X = duty & 0x01; //Store the 1st bit
    CCP2Y = duty & 0x02; //Store the 0th bit
    CCPR2L = duty >> 2; // Store the remining 8 bit
}

void setTMR2(char const pwm) {
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

void setPR2(unsigned int const freq) {
    PR2 = (_XTAL_FREQ / (freq * 4 * TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet;
}
