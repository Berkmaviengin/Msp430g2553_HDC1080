/*
 * I2C.c
 *
 *  Created on: 24 Nis 2020
 *      Author: Berk Maviengin
 */


#ifndef I2C_H_
#define I2C_H_
#include <msp430.h>
#include <stdint.h>

uint8_t *PTxData;                     // Pointer to TX data
uint8_t *PRxData;                     // Pointer to RX data

uint8_t TxByteCtr;
uint8_t RxByteCtr;

//uint8_t isRx;

void I2C_init(uint8_t slaveAddress);
void I2C_write(uint8_t ByteCtr, uint8_t *TxData);
void I2C_read(uint8_t ByteCtr, volatile uint8_t *RxData);

#endif /* I2C_H_ */
