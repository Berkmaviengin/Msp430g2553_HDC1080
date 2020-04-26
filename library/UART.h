/*
 * UART.h
 *
 *  Created on: 24 Nis 2020
 *      Author: Berk Maviengin
 */

#ifndef UART_H_
#define UART_H_

#include <msp430.h>
void Setup_UART();
void UARTSendArray(unsigned char *TxArray, unsigned char ArrayLength);

#endif /* UART_H_ */
