/*
 * blink.c
 *
 * Created: 19/04/2018 09:20:34
 *  Author: marega
 */ 
 #ifndef F_CPU
#define F_CPU 10000000UL // 10 MHz clock speed
#endif


#include <avr/io.h>
#include <util/delay.h>

#include "blink.h"

void start() {
	
	DDRA = 0xFF; //makes PORTC as Output

while(1) //infinite loop
{
	
	PORTA = 0xFF; //Turns ON All LEDs
	_delay_ms(500); //½ second delay
	PORTA = 0x00; //Turns OFF All LEDs
	_delay_ms(500); //½ second delay
	startGame++;
	
	PORTA = 0FF;
	return 0;
}
	
}
void badAnswer() {
	
}
void win() 
{
	int i;
	DDRA = 0xFF;
	int winGame = 0;
	while(1)
	{
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
		return 0;
	}			

}
void end() {

}
void makeLedBlinking(int a) {
	_delay_ms(1000); //½ second delay
	PORTA = a;
	_delay_ms(1000); //½ second delay
	PORTA = 0xff;
	_delay_ms(1000); //½ second delay
}
