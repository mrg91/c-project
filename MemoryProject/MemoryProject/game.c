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
#include <util/delay.h>s
#include "atmega2560_drivers.h"
#include "game.h"
#include "blink.h"
#define taille 8

int lower = 1;
int upper = 8;
int tracker = 0;
int size = 8;
int nb = 1;
int i,j,k,y;
int usrbtn;
int v;
int BtnUsr[taille];

// int Value[upper+1] = { 11111110,11111101,11111011,11110111,11101111,11011111,10111111,01111111 }
	int ValueSeq[8] = { 0b11111110, 0b11111101, 0b11111011, 0b11110111, 0b11101111, 0b11011111, 0b10111111, 0b01111111};
void init() { 
	DDRB = 0x00;
	DDRA = 0xff;
}


void createSeq(int *Seq, int size) {
	int i;
	int randomIndex = 0;
	for(i = 0; i<size; i++) {
		randomIndex = (rand()%8); 
       Seq[i] = ValueSeq[randomIndex]; //rand()%upper + lower;
	} 
	
}

void compare(int *Seq, int *UserSeq, int size, int nb) {
			
		while (i < nb) {
			makeLedBlinking(Seq[i]);
		i++;
			}
		i = 0;
		
		
		for (j = 0; j < nb; j++)
		{
			addvalue(BtnUsr, j);
				}
		
			
			while (k < nb) {

				if (!(Seq[k] == BtnUsr[k]))
				{
					badAnswer();
					end();
					return;	
					}
				else {
					addUserSequence(UserSeq, Seq, BtnUsr[k], size);
					nb++;
					k++;
					compare(Seq,UserSeq,size,nb);
					
				}
			}
	}

void addvalue(int *BtnUsr, int index) {
		
			while (PINB == 0xff) {
				BtnUsr[index] = 0;
			}
			BtnUsr[index] = PINB;
}

void addUserSequence(int *tab, int *Seq, int value, int size) {
	
	if (tracker == size-1) {
		tab[tracker] = value;
		sameSeq(Seq,tab,size);
		return;
	}
	
	if (tracker < size) {
		tab[tracker] = value;
		tracker++;
		return;
	}
	
	
		
	
}

void sameSeq(int *Seq, int *tab, int n) {
	int c;
	int i;
	c = 1;
	for(i=0;i<n;i++){
		if(Seq[i] != tab[i]) {
				c = 0;
		}
	}
	if(c == 1) {
		win();
		end();
		return;
	}
		end();
		return;
	}
	