/*
 * blink.c
 *
 * Created: 19/04/2018 09:20:34
 *  Author: marega
 */ 

#ifndef F_CPU
#define F_CPU 10000000UL // 10 MHz clock speed
#endif

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include "atmega2560_drivers.h"
#include "blink.h"

int valueSe[8] = { 0b11111110, 0b11111101, 0b11111011, 0b11110111, 0b11101111, 0b11011111, 0b10111111, 0b01111111};
int value[10] = { 0b00000000, 0b11111110, 0b11111101, 0b11111011, 0b11110111, 0b11101111, 0b11011111, 0b10111111, 0b01111111, 0b11111111};
int a;

void start() {
	
	DDRA = 0xFF; //makes PORTA as Output
	int startGame = 0;

//while(1) //infinite loop
//{
	for(int i = 0; i < 8; i++)
	{
		PORTA = 0xFF; //Turns ON All LEDs
		_delay_ms(60); //½ second delay
		PORTA = 0x00; //Turns OFF All LEDs
		_delay_ms(60); //½ second delay
		startGame++;
	}
	
	PORTA = 0xFF;
	return;
	
//}	
}

void badAnswer() {
	
	DDRA = 0xFF; //makes PORTA as Output
	int mistake = 0;
	
	for(int i = 0; i < 3; i++)
	{
		PORTA = 0xFF; //Turns ON All LEDs
		_delay_ms(500); //½ second delay
		PORTA = 0x00; //Turns OFF All LEDs
		_delay_ms(500); //½ second delay
		mistake++;
	}
	
	PORTA = 0xFF;
	return;
}


void win() 
{
	int i;
	DDRA = 0xFF;
	
	for (int j = 0; j < 3; j++)
	{
		DDRA = 0xff;
		_delay_ms(200);
		PORTA = 0xff;
		_delay_ms(200);
		PORTA = 0x00;
	}
	
	//while(1)
	//{
		for (i=0; i <= 7; i++)
		{
			PORTA = (1 << i); // Shifting LEDS = 0-7 (left)
			_delay_ms(100);
		}
	
		for (i=7; i >= 0; i--)
		{
			PORTA = (1 << i); // Shifting LEDS = 0-7 (right)
			_delay_ms(100);
		}
		
		PORTA = 0xFF;
		return;
	//}			
}

void end() 
{
		for (int k = 0; k < 3; k++) 
		{
		DDRA = 0xff;
		_delay_ms(200);
		PORTA = 0xff;
		_delay_ms(200);
		PORTA = 0x00;
		}
		for (int j = 0; j < 2; j++) {
		for (int i = 10; i >= 0; i--) {

			PORTA = ~(value[i]); // (Value1[i]);
			_delay_ms(250);
		}
}
}

/* DDRA and makeLedBlink need DDRA, although everything will be initialized by the end
int maikkn(void)
{
	DDRA = 0xFF;
	makeLedBlink(3);
}*/


void makeLedBlinking(int a)
{
	PORTA = 0xFF;
	_delay_ms(1000); //1 second delay
	PORTA = a;
	_delay_ms(1000); //1 second delay
	PORTA = 0xFF;
	_delay_ms(1000); //1 second delay
	return;
}
