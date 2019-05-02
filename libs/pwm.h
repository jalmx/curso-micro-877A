#define TMR2PRESCALE 4

int FREQ1;
int FREQ2;

void pwmInit1(unsigned int const freq) {
    FREQ1 = freq;
    PR2 = (_XTAL_FREQ / (FREQ1 * 4 * TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet // Makes the PWM work in 5KHZ
    CCP1M3 = 1;
    CCP1M2 = 1; //Configure the CCP1 module 
    T2CKPS0 = 1;
    T2CKPS1 = 0;
    TMR2ON = 1; //Configure the Timer module
    TRISC2 = 0; // make port pin on C as output
}
void pwmInit2(unsigned int const freq) {
    FREQ2 = freq;
    PR2 = (_XTAL_FREQ / (FREQ2 * 4 * TMR2PRESCALE)) - 1; //Setting the PR2 formulae using Datasheet // Makes the PWM work in 5KHZ
    CCP2M3 = 1;
    CCP2M2 = 1; //Configure the CCP2 module 
    T2CKPS0 = 1;
    T2CKPS1 = 0;
    TMR2ON = 1; //Configure the Timer module
    TRISC1 = 0; // make port pin on C as output
}

void pwmSetDutyCycle1(unsigned int duty) {

    duty = ((float) duty / 1023)*(_XTAL_FREQ / (FREQ1 * TMR2PRESCALE)); // On reducing //duty = (((float)duty/1023)*(1/PWM_freq)) / ((1/_XTAL_FREQ) * TMR2PRESCALE);
    CCP1X = duty & 0x01; //Store the 1st bit
    CCP1Y = duty & 0x02; //Store the 0th bit
    CCPR1L = duty >> 2; // Store the remining 8 bit
}

void pwmSetDutyCycle2(unsigned int duty) {

    duty = ((float) duty / 1023)*(_XTAL_FREQ / (FREQ2 * TMR2PRESCALE)); // On reducing //duty = (((float)duty/1023)*(1/PWM_freq)) / ((1/_XTAL_FREQ) * TMR2PRESCALE);
    CCP2X = duty & 0x01; //Store the 1st bit
    CCP2Y = duty & 0x02; //Store the 0th bit
    CCPR2L = duty >> 2; // Store the remining 8 bit
}