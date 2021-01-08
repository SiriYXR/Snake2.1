#ifndef HEAD_H
#define HEAD_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#include "./EGE20.08/include/ege.h"
#include "./EGE20.08/include/graphics.h"

#include <mmsystem.h> //�Ƕ�ý�����ģ�飬����֧��16λ��ý��Ӧ�ó���
#pragma comment(lib,"winmm.lib")


enum Status
{
	oneplayer,
	twoplayer,
	choice,
	nogame,
	ispause,
	ismove,
	isdead
};

enum DeadFor
{
	P1win,
	P2win,
	Draw,
	NewHistory
};

enum DeadFrom
{
	live,
	death
};

void mainloop();
int myrand(int m);
int myrand_num(int m);
int getHistory();
void saveHistory(const int scores);

#endif HEAD_H