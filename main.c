#include <msp430.h> 
#include <stdint.h>
#include "library/UART.h"
#include "library/HDC1080.h"
#include "library/float_to_string.h"

/**
 * main.c
 */

uint8_t setConfigParams;

float Temperature;
float Humidity;
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	BCSCTL1 = CALBC1_1MHZ; // Set DCO to 1MHz
	DCOCTL = CALDCO_1MHZ; // Set DCO to 1MHz
	Setup_UART();
	
	HDC1080_init();

	setConfigParams= HDC1080_SWRST | HDC1080_DISABLE_HEATER | HDC1080_READ_SEQUENCE | HDC1080_BATTERY_VOLTAGE_HIGH
	                 | HDC1080_TEMP_RESOLUTION_14BIT |HDC1080_HUM_RESOLUTION_14BIT;

	HDC1080_setconfig(setConfigParams);


	while(1)
	{
	    Humidity   = HDC1080_readHumidity();
	    Temperature =HDC1080_readTemperature();

	    char temp[10];
	    char hum[10];
	    float_to_string(Temperature, temp, 2);
	    float_to_string(Humidity, hum, 2);

	    UARTSendArray("Temp:", 5);
	    UARTSendArray(temp,5);
	    UARTSendArray("(C)\n", 4);
	    UARTSendArray("Hum:", 4);
	    UARTSendArray(hum,5);
	    UARTSendArray("(%RH)\n\n", 7);
	    __delay_cycles(2000000);

	}
}






