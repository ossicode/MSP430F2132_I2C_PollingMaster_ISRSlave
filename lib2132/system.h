/*
 * setup2132.h
 *
 *  Created on: 2012. 12. 19.
 *      Author: OSSI
 */

#ifndef SETUP2132_H_
#define SETUP2132_H_

#include "ossi_beacon.h"

// System IO Define
//#define LED_PORT 3
//#define LED_PIN 0
//
//#define EXTWDT_PORT 2
//#define EXTWDT_PIN 2

void IO_setup(void);
void ext_wdt_setup(void);

void ext_wdt_rst(void);

#endif /* SETUP2132_H_ */
