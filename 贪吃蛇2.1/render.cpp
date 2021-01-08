#include"class.h"
#include"functions.h"


//打印主界面
void rend_MainFace_one(const int scores, const int highest_scores, const Status status, Picture& picture)
{
	setfillcolor(EGERGB(0xfb, 0xf8, 0xf1));
	bar(0, 0, 20, 540);
	bar(520, 0, 540, 540);
	bar(0, 0, 540, 20);
	bar(0, 520, 540, 540);

	picture.PUTimage_back(750,15);

	if (status == isdead)
		picture.PUTimage_start(685, 90);
	else if (status == ispause)
		picture.PUTimage_continu(685, 90);
	else if (status == ismove)
		picture.PUTimage_pause(685, 90);

	picture.PUTimage_preasent_scores(530, 90);
	picture.PUTimage_highest_scores(530, 180);
	picture.PUTimage_information(530, 300);

	setcolor(WHITE);
	setfont(40, 0, "楷体");
	setbkmode(TRANSPARENT);
	char str1[20], str2[20];
	sprintf(str1, "%d", scores);
	outtextxy(570, 115, str1);
	sprintf(str2, "%d", highest_scores);
	outtextxy(615, 205, str2);
}

//绘制双人场景界面
void rend_MainFace_two(const int scores[], const Status status, Picture& picture)
{
	setfillcolor(EGERGB(0xfb, 0xf8, 0xf1));
	bar(0, 0, 20, 540);
	bar(520, 0, 540, 540);
	bar(0, 0, 540, 20);
	bar(0, 520, 540, 540);

	picture.PUTimage_back(750, 15);

	if (status == isdead)
		picture.PUTimage_start(685, 90);
	else if (status == ispause)
		picture.PUTimage_continu(685, 90);
	else if (status == ismove)
		picture.PUTimage_pause(685, 90);
	picture.PUTimage_information_two(530, 300);

	picture.PUTimage_preasent_scoresP1(530, 90);
	picture.PUTimage_preasent_scoresP2(530, 180);

	setcolor(WHITE);
	setfont(40, 0, "楷体");
	setbkmode(TRANSPARENT);
	char str1[20], str2[20];
	sprintf(str1, "%d", scores[0]);
	outtextxy(580, 115, str1);
	sprintf(str2, "%d", scores[1]);
	outtextxy(580, 205, str2);
}

//开始游戏界面
void rend_Nogame(Picture& picture)
{
	picture.PUTimage_intogame(0, 0);
	picture.PUTimage_switch_startgame(250, 410);
}

//选择界面
void rend_Choice(Picture& picture, bool i)
{
	picture.PUTimage_intogame(0, 0);
	picture.PUTimage_switch_oneplayer(120, 410);
	picture.PUTimage_switch_twoplayer(440, 410);

	if (i)
		picture.PUTimage_director(53, 420);
	else
		picture.PUTimage_director(378, 420);
}

//打印死亡界面
void rend_IsDead(Picture& picture,DeadFor result,int i,int scores[])
{
	picture.PUTimage_bar(20, 20);
	picture.PUTimage_gameover(140, 150);

	if (result == P1win)
	{
		setcolor(WHITE);
		setfont(48, 0, "楷体");
		setbkmode(TRANSPARENT);
		char str[20];
		sprintf(str, "玩家1获胜！");
		outtextxy(155, 350, str);
	}
	else if (result == P2win)
	{
		setcolor(WHITE);
		setfont(48, 0, "楷体");
		setbkmode(TRANSPARENT);
		char str[20];
		sprintf(str, "玩家2获胜！");
		outtextxy(155, 350, str);
	}
	else if (result == Draw&&i>1)
	{
		if (scores[0] == scores[1])
		{
			setcolor(WHITE);
			setfont(48, 0, "楷体");
			setbkmode(TRANSPARENT);
			char str[20];
			sprintf(str, "平局！");
			outtextxy(210, 350, str);
		}
		else if (scores[0] > scores[1])
		{
			setcolor(WHITE);
			setfont(48, 0, "楷体");
			setbkmode(TRANSPARENT);
			char str[20];
			sprintf(str, "玩家1获胜！");
			outtextxy(155, 350, str);
		}
		else if (scores[0] < scores[1])
		{
			setcolor(WHITE);
			setfont(48, 0, "楷体");
			setbkmode(TRANSPARENT);
			char str[20];
			sprintf(str, "玩家2获胜！");
			outtextxy(155, 350, str);
		}
	}
	else if (result == NewHistory)
	{
		setcolor(WHITE);
		setfont(48, 0, "楷体");
		setbkmode(TRANSPARENT);
		char str[20];
		sprintf(str, "新纪录！");
		outtextxy(200, 350, str);
	}
}

//打印地图
void rend_map(Picture& picture)
{
	setbkcolor(EGERGB(0xfb, 0xf8, 0xf1));
	picture.PUTimage_map(20, 20);
}

//打印退出画面
void rend_outgame(Picture& picture)
{
	picture.PUTimage_outgame();
}