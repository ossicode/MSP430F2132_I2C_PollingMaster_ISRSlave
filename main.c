/*
 * main.c
 */

#include "ossibeacon.h"
#include "printf.h"
#include "adc10.h"
#include "i2c.h"

#define ADC_BUF_SIZE 8
#define ADC_BUF_SIZE2 16

uint8_t beaconData[64]={0};

uint8_t TxData[9] = {0,3,3,7,3,3,7,0,9};
uint8_t generalCall[1]={0};
uint8_t RxData[8] = {0};


void main(void) {
	
	WDTCTL = WDTPW + WDTHOLD;		// Stop watchdog timer
	// default: MCLK = SMCLK = DCO ~ 1.2MHz
	// set DCO speed to calibrated 1MHz
//	BCSCTL1 = CALBC1_8MHZ;
//	DCOCTL = CALDCO_8MHZ;
	clock_setup();
	clock_dividerSetup(MCLK_DIVIDED_BY_1, SMCLK_DIVIDED_BY_1, ACLK_DIVIDED_BY_1);
	// TODO: Internal Capacitor VS External Capacitor???
	//	BCSCTL3 |= XCAP_0;
	// general IO init
	// set unused pins!!!
	P1DIR = 0xFF & ~(BIT1+BIT2); // ADF7012 TXCLK output is high. Beware!!! Why??
	P1OUT = 0x00;
	P3DIR = 0xFF & ~(BIT1+BIT2+BIT3+BIT5);
	P3OUT = 0x00;
	P2DIR = 0xFF & ~(BIT0+BIT1+BIT5);
	P2OUT = 0x00;

	adc10_portSetup(ADC10_PIN_2_0 + ADC10_PIN_2_1);

	uart_setup_9600();
	uart_init();
	IE2 &= ~UCA0RXIE;
	IE2 &= ~UCA0TXIE;

	i2c_portSetup();
	IO_DIRECTION(EXTWDT,OUTPUT);
	IO_SET(EXTWDT,LOW);

	IO_DIRECTION(LED,OUTPUT);
	IO_SET(LED,LOW);


//	TA0CCTL0 |= CCIE;
	volatile uint8_t i;

	_EINT();
//     i2c Slave
	 i2c_slaveInit(0x49, 64, beaconData);
	 i2c_slaveStart();

	while(1)
	{

//    	volatile uint8_t i;
//    	for(i = 0 ; i < 255 ; i++)
//    	{
//    	TxData[0]= 1;
//		TxData[1]= i;
//		i2c_masterWrite(0x50, 2, TxData);
//		i2c_masterRead(0x50, 1, RxData);
//    	}

//		i2c_generalCall();
//		i2c_masterWrite(0x50, 1, TxData);
////		i2c_masterRead(0x50, 1, RxData);
//		i2c_masterRead(0x50, 4, RxData);
//		TxData[0]= 0;
//		TxData[1]= 123;
//		i2c_masterWrite(0x50, 2, TxData);
//		i2c_masterRead(0x50, 1, RxData);
//
//		TxData[0]= 32;
//		TxData[1]= 200;
//		i2c_masterWrite(0x50, 2, TxData);
//		i2c_masterRead(0x50, 1, RxData);
//
//		TxData[0]= 10;
//		TxData[1]= 77;
//		i2c_masterWrite(0x50, 2, TxData);
//		i2c_masterRead(0x50, 1, RxData);
//
//		// last address
//		TxData[0]= 63;
//		TxData[1]= 77;
//		i2c_masterWrite(0x50, 2, TxData);
//		i2c_masterRead(0x50, 1, RxData);
//
//		// last address write overflow ignore
//		TxData[0]= 63;
//		TxData[1]= 77;
//		TxData[2]= 88;
//		i2c_masterWrite(0x50, 3, TxData);
//		i2c_masterRead(0x50, 1, RxData);
//
//		// first again
//		TxData[0]= 0;
//		TxData[1]= 123;
//		i2c_masterWrite(0x50, 2, TxData);
//		i2c_masterRead(0x50, 1, RxData);
//
//		// last address read overflow 0xFF
//		TxData[0]= 63;
//		i2c_masterWrite(0x50, 1, TxData);
//		i2c_masterRead(0x50, 8, RxData);

	    __bis_SR_register(LPM3_bits + GIE);

	}
}


//#pragma vector=ADC10_VECTOR
//__interrupt void ADC10_ISR(void)
//{
//	// It's very important to stop conversion right after ISR is entered to avoid corrupted data or sequence.
//	// TODO: compare this method to polling ADC10BUSY flag
//	ADC10CTL0 &= ~ENC;
//	__bic_SR_register_on_exit(LPM3_bits);        // Clear LPM3_bits from 0(SR)
//}
