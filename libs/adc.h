void adcInit() {
    /*
     * ADCON0 Register
     * +---------------------------------------------------------------+
     * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
     * +---------------------------------------------------------------+
     * |      ADCS     |          CSH          |GO/DONE|   -   | ADON  |
     * +---------------------------------------------------------------+
     */

    ADCON0bits.ADCS = 0b01; // set A/D conversion clock = fosc/2
    ADCON0bits.CHS = 0b000; // set all adc channels off
    ADCON0bits.ADON = 0; // a/d module is powered off

    /*
     * ADCON1 Register
     * +---------------------------------------------------------------+
     * |   7   |   6   |   5   |   4   |   3   |   2   |   1   |   0   |
     * +---------------------------------------------------------------+
     * |  ADFM | ADCS2 |   -   |   -   |              PCFG             |
     * +---------------------------------------------------------------+
     */

    ADCON1bits.ADFM = 1; // set right justification for ADRESH
    ADCON1bits.ADCS2 = 1; // set A/D conversion clock = fosc/2
    ADCON1bits.PCFG = 0b0000; // set all pins as adc input    
}

/**
 * 
 * @param adc_channel
 * @param VALUE = 0 -> Int ; 1 -> Float
 * @return Value
 */
int adcRead(char const adcChannel) {
    ADCON0bits.ADON = 1; // turn on a/d module
    ADCON0bits.CHS = adcChannel; // turn on adc channel
    __delay_ms(10); // wait for capacitors to charge up
    ADCON0bits.GO = 1; // begin conversion
    while (ADCON0bits.GO_DONE);// wait for conversion to finish
    
    return (ADRESH << 8) + (ADRESL);
}