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
void init() { 
	DDRB = 0x00;
	DDRA = 0xff;
	
}


void createSeq(int* a, int size) {
	int i;
	srand(time(0));
	for(i = 0; i<size; i++)  
       a[i] = rand()%upper + lower;
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