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
#include "atmega2560_drivers.h"
#include "blink.h"
#include "game.h"


#define size 8

//int size = 8;
int Seq[size];
int UserSeq[size];
int game = 0;
int i = 0;
int f;
int main(void)
{
 //   while (1) 
 //   {
		
	//	init();
		start();
		createSeq(Seq, size);
		
		while (i < size) {
		//	PORTA =  0b01111111;
		//	_delay_ms(3000);
			f = Seq[i];
			makeLedBlinking(f);
			i++;
		}
		
	/*	for (int i = 0; i <= size; i++) {
			makeLedBlinking(Seq[i]);
			compare(Seq,UserSeq, size);
		}*/
		
		
			
 //   }
}

