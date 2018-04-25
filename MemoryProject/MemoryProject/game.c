/*
 * game.c
 *
 * Created: 19/04/2018 09:21:10
 *  Author: marega
 */ 


#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <avr/io.h>
#include "atmega2560_drivers.h"
#include "game.h"
#include "blink.h"

int lower = 1;
int upper = 8;
int tracker = 0;
int size = 8;

// int Value[upper+1] = { 11111110,11111101,11111011,11110111,11101111,11011111,10111111,01111111 }
	int ValueSeq[8] = { 0b11111110, 0b11111101, 0b11111011, 0b11110111, 0b11101111, 0b11011111, 0b10111111, 0b01111111};
void init() { 
	DDRB = 0x00;
	DDRA = 0xff;
	
}


void createSeq(int *Seq, int size) {
	int i;
	int randomIndex = 0;
	srand(time(NULL));
	for(i = 0; i<size; i++) 
	randomIndex = (rand()%8); 
       Seq[i] = ValueSeq[randomIndex]; //rand()%upper + lower;
}

void compare(int *Seq, int *UserSeq, int size) { //, int BtnUser) {
	int BtnUsr;
	BtnUsr = 0;
	while (PINB == 0xff) {
		 BtnUsr = 0;
	}
	BtnUsr = PINB;
	if (Seq[tracker] == BtnUsr) {
		addUserSequence(UserSeq,BtnUsr, size);
		return;
	//	sameSeq(Seq,UserSeq,size);
		//return true;
	}
	else
		badAnswer();
		end();
		return;
//	return false;
}

void addUserSequence(int *tab, int value, int size) {
	if (tracker < size) {
		tab[tracker] = value;
		tracker++;
		return;
		}
	else
	sameSeq(ValueSeq,tab,size);
	return;
	
}

void sameSeq(int *Seq, int *UserSeq, int n) {
	int c;
	int i;
	c = 1;
	for(i=0;i<n;i++){
		if(ValueSeq[i] != UserSeq[i])
		c = 0;
	}
	if(c == 1 && i == n-1) {
		win();
		end();
		return;
	}
	else {
		end();
		return;
		}
	}
	