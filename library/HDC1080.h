/*
 * HDC1080.h
 *
 *  Created on: 24 Nis 2020
 *      Author: Berk Maviengin
 */

#ifndef HDC1080_H_
#define HDC1080_H_

#include <msp430.h>
#include "I2C.h"

#define HDC1080_SWRST                   0x80

#define HDC1080_ENABLE_HEATER           0x20
#define HDC1080_DISABLE_HEATER          0x00

#define HDC1080_READ_SEPARATELY         0x00
#define HDC1080_READ_SEQUENCE           0x10

#define HDC1080_BATTERY_VOLTAGE_LOW     0x08
#define HDC1080_BATTERY_VOLTAGE_HIGH    0x00

#define HDC1080_TEMP_RESOLUTION_14BIT   0x00
#define HDC1080_TEMP_RESOLUTION_11BIT   0x04

#define HDC1080_HUM_RESOLUTION_14BIT    0x00
#define HDC1080_HUM_RESOLUTION_11BIT    0x01
#define HDC1080_HUM_RESOLUTION_18BIT    0x02

float HDC1080_readTemperature();
float HDC1080_readHumidity();
void HDC1080_setconfig(uint8_t REG);
void HDC1080_init();



#endif /* HDC1080_H_ */
