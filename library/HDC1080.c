/*
 * HDC1080.c
 *
 *  Created on: 24 Nis 2020
 *      Author: Berk Maviengin
 */
#include "HDC1080.h"

uint8_t RxBuffer[2];

uint8_t HDC1080_DEVICE_ADDRESS       =  0x40;
uint8_t HDC1080_CONFIGURATION        =  0x02;
uint8_t HDC1080_RESERVED_BITS        =  0x00;

uint8_t HDC1080_TEMP_READ            =  0x00;
uint8_t HDC1080_HUM_READ             =  0x01;


float HDC1080_readTemperature()
{
    double temperature;
    uint16_t temp;
    I2C_write(1, &HDC1080_TEMP_READ);
    __delay_cycles(20000);

    I2C_read(2, RxBuffer);
    temp = (((unsigned int)RxBuffer[0] <<8 | RxBuffer[1]));
    temperature = (double)(temp)/(65536)*165-40;
    float ftemperature = (float)temperature;
    return ftemperature;
}
float HDC1080_readHumidity()
{
    double humidity;
    uint16_t hum;
    I2C_write(1, &HDC1080_HUM_READ);
    __delay_cycles(20000);
    //Receive process
    I2C_read(2, RxBuffer);
    hum = (((unsigned int)RxBuffer[0] <<8 | RxBuffer[1]));
    humidity = (double)(hum)/(65536)*100;
    float fhumidity = (float)humidity;
    return fhumidity;

}


void HDC1080_setconfig(uint8_t REG)
{
    I2C_write(1,&HDC1080_CONFIGURATION);
    I2C_write(1,&REG);
    I2C_write(1,&HDC1080_RESERVED_BITS);
    __delay_cycles(20000);
}

void HDC1080_init()
{
    I2C_init(HDC1080_DEVICE_ADDRESS);
}
