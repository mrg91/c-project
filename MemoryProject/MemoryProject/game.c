/*
 * game.c
 *
 * Created: 19/04/2018 09:21:10
 *  Author: marega
 */ 

#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int lower = 1;
int upper = 8;
int tracker = 0;

int Value[upper+1] = { 11111110,11111101,11111011,11110111,11101111,11011111,10111111,01111111 }
void init() { 
	DDRB = 0x00;
	DDRA = 0xff;
	
}


void createSeq(int* a, int size) {
	int i;
	srand(time(0));
	for(i = 0; i<size; i++) 
	int randomIndex = rand() %8 ; 
       a[i] = Value[randomIndex]; //rand()%upper + lower;
}

bool compare(int* Seq, int* UserSeq, int size) { //, int BtnUser) {
	int BtnUsr
	while (PINB == 0xff) {
		 BtnUsr = 0;
	}
	BtnUsr = PINB;
	if (Seq[tracker] == BtnUsr) {
		addUserSequence(UserSeq,BtnUsr, size);
		return true;
	}
	return false;
}

void addUserSequence(int* tab, int value, int size) {
	if (tracker < size) {
		tab[tracker] = value;
		tracker++;
		}
}