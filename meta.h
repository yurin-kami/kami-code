#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define w 3
#define h 3
void revive(char borad[w][h], int W, int H);
void displayborad(char borad[w][h], int W, int H);
void PlayerMove(char borad[w][h], int W, int H);
void computerGo(char borad[w][h], int W, int H);
char ifWin(char borad[w][h], int W, int H);
int ifFull(char borad[w][h], int W, int H);
