/*
 * MemoryProject.c
 *
 * Created: 19/04/2018 09:19:05
 * Author : marega
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>
#include "atmega2560_drivers.h"
#include "blink.h"
#include "game.h"


#define size 8


//void Start_Timer();
//void Stop_Timer();
//void Reset_Timer();

//int size = 8;
int Seq[size];
int UserSeq[size];
int game = 0;
int i = 0;
int f;
//uint32_t state;
// static uint32_t EEMEM sstate;
int  Mytimer;
int nb;

int main(void)
{
	
 //   while (1) 
 //   {
	// Start_Timer();
		
		
	/*while (PINB == 0xff)
	{
		}*/
		
//	Stop_Timer();
//	Mytimer = ~TCCR1B;
//	Reset_Timer();
//	srand(Mytimer);
	//	setup_seed();
	
	init();
	
	//	initrand();
	//	srand(sstate);
//	_delay_ms(1000);
	start();
	_delay_ms(1000);
		srand(time(0));
	createSeq(Seq, size);
	_delay_ms(1000);
		//compare(Seq,UserSeq, size);
	//	while (i < size) {
		//	makeLedBlinking(Seq[i]);
	//	for (int i = 0; i< size; i++) {
			compare(Seq,UserSeq, size, nb);
	//	}
	
		//	i++;
	//	}
	}

/*
  Read random seed from eeprom and write a new random one.
*/
/*
void initrand()
{
        uint32_t state, next_state;
        static uint32_t EEMEM sstate;

        next_state = state = eeprom_read_dword(&sstate);
        srandom(state);

        while (next_state == state)
        next_state = random() + random();
        eeprom_write_dword(&sstate, next_state);
}*/
/*
void Start_Timer(){
	TCCR1B = (1 << CS11);
}

void Stop_Timer(){
	TCCR1B &= ~(1 << CS11);
}

void Reset_Timer(){
	TCNT1 = 0;
}
*/
