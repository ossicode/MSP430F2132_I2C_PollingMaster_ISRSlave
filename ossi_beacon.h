/*
 * ossibeacon.h
 *
 *  Created on: 2012. 12. 22.
 *      Author: OSSI
 */

#ifndef OSSIBEACON_H_
#define OSSIBEACON_H_

#include "msp430f2132.h"
#include "ossitypes.h"
#include "clock.h"
#include "system.h"
#include "util.h"
#include "debug.h"

/*
 * OSSI Beacon Pin Settings
 */

#define EXTWDT_PORT 				(2)
#define EXTWDT_PIN 					(BIT2)

#define ADC10_PIN_2_0		        (BIT0)
#define ADC10_PIN_2_1              	(BIT1)

#define I2C_SDA_PIN 				(BIT1)
#define I2C_SCL_PIN 				(BIT2)

#define UART_TXD_PIN				(BIT4)
#define UART_RXD_PIN				(BIT5)

#define PA_ON_PORT					(3)
#define PA_ON_PIN					(BIT6)

#define PA_FAULT_PORT				(2)
#define PA_FAULT_PIN				(BIT5)

#define BEACON_CWCONTROL_PORT		(3)
#define BEACON_CWCONTROL_PIN		(BIT3)

#define BEACON_CE_PORT				(3)
#define BEACON_CE_PIN				(BIT7)

#define BEACON_SLE_PORT				(2)
#define BEACON_SLE_PIN				(BIT3)

#define BEACON_SDATA_PORT			(2)
#define BEACON_SDATA_PIN			(BIT4)

#define BEACON_SCLK_PORT			(1)
#define BEACON_SCLK_PIN				(BIT0)

#define BEACON_MUXOUT_PORT			(1)
#define BEACON_MUXOUT_PIN			(BIT1)

#define BEACON_TXCLK_PORT			(1)
#define BEACON_TXCLK_PIN			(BIT2)

#define BEACON_DATA_PORT			(1)
#define BEACON_DATA_PIN				(BIT3)

#define LED_PORT 					(3)
#define LED_PIN 					(BIT0)



#endif /* OSSIBEACON_H_ */
