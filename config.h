/* 
 * File:   config.h
 * Author: sh
 *
 * Created on December 8, 2017, 10:35 AM
 */

#ifndef CONFIG_H
#define	CONFIG_H
#include <xc.h>

#define LED7 _LATA7
#define LED6 _LATA7
#define S4  _RD13

#define 	_ISR_NO_PSV 	__attribute__((__interrupt__, no_auto_psv))
#define DELAY1MS    16000
#define DELAY8MS    128000
#define DELAY10MS   160000
#define DELAY20MS   320000
#define DELAY30MS   480000
#define DELAY50MS   800000
#define DELAY40MS   640000
#define DELAY62_5MS 1000000
#define DELAY170MS  2720000
#define DELAY90MS   1440000
#define DELAY100MS  1600000
#define DELAY400MS  6400000
#define DELAY1000MS 16000000
#define DELAY_TASK1_7 DELAY40MS
#define DELAY_TASK8 DELAY62_5MS
#define DELAY_TASK9 DELAY90MS



#endif	/* CONFIG_H */

