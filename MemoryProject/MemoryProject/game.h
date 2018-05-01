#ifndef __game_h__
#define __game_h__

void init();
void createSeq(int *Seq, int size);
void compare(int *Seq, int *UserSeq, int size, int nb);
void addUserSequence(int *tab, int *Seq, int value, int size);
void sameSeq(int *Seq, int *UserSeq, int n);
void addvalue(int *BtnUsr, int index);


#endif 