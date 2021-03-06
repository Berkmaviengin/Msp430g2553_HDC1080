/*
 * UART.c
 *
 *  Created on: 24 Nis 2020
 *      Author: Berk Maviengin
 */

#include "UART.h"




void Setup_UART() {
  __disable_interrupt();
  P1SEL |= BIT1 + BIT2 ; // P1.1 = RXD, P1.2=TXD
    P1SEL2 |= BIT1 + BIT2 ; // P1.1 = RXD, P1.2=TXD
  IE2 &= ~UCB0RXIE;
  IE2 &= ~UCB0TXIE;
  UCA0CTL1 |= UCSSEL_2; // Use SMCLK
  UCA0BR0 = 104; // Set baud rate to 9600 with 1MHz clock (Data Sheet 15.3.13)
  UCA0BR1 = 0; // Set baud rate to 9600 with 1MHz clock
  UCA0MCTL = UCBRS0; // Modulation UCBRSx = 1
  UCA0CTL1 &= ~UCSWRST; // Initialize USCI state machine
  IE2 |= UCA0RXIE; // Enable USCI_A0 RX interrupt
}
void UARTSendArray(unsigned char *TxArray, unsigned char ArrayLength){

  while(ArrayLength--){ // Loop until StringLength == 0 and post decrement
    while(!(IFG2 & UCA0TXIFG)); // Wait for TX buffer to be ready for new data
    UCA0TXBUF = *TxArray; //Write the character at the location specified py the pointer
    TxArray++; //Increment the TxString pointer to point to the next character
  }
  IFG2 &= ~UCA0TXIFG;                     // Clear USCI_A0 int flag
}
