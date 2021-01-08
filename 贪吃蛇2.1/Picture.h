#ifndef PICTURE_H
#define PICTURE_H

#include"functions.h"

class Picture
{
public:
	Picture();
	~Picture();

	//绘制图像
	void PUTimage_outgame(int x = 0, int y = 0);

	void PUTimage_start(int x = 0, int y = 0);
	void PUTimage_pause(int x = 0, int y = 0);
	void PUTimage_preasent_scores(int x = 0, int y = 0);
	void PUTimage_highest_scores(int x = 0, int y = 0);

	void PUTimage_information(int x = 0, int y = 0);
	void PUTimage_information_two(int x = 0, int y = 0);

	void PUTimage_intogame(int x = 0, int y = 0);
	void PUTimage_continu(int x = 0, int y = 0);

	void PUTimage_gameover(int x = 0, int y = 0);
	void PUTimage_bar(int x = 0, int y = 0);

	void PUTimage_map(int x = 0, int y = 0);

	void PUTimage_isVoice(int x = 0, int y = 0);
	void PUTimage_noVoice(int x = 0, int y = 0);
	void PUTimage_back(int x = 0, int y = 0);

	void PUTimage_body(int x = 0, int y = 0);

	void PUTimage_head_A(int x = 0, int y = 0);
	void PUTimage_head_D(int x = 0, int y = 0);
	void PUTimage_head_W(int x = 0, int y = 0);
	void PUTimage_head_S(int x = 0, int y = 0);

	void PUTimage_tail_A(int x = 0, int y = 0);
	void PUTimage_tail_D(int x = 0, int y = 0);
	void PUTimage_tail_W(int x = 0, int y = 0);
	void PUTimage_tail_S(int x = 0, int y = 0);

	void PUTimage_food(int x = 0, int y = 0);

	void PUTimage_switch_startgame(int x = 0, int y = 0);
	void PUTimage_switch_oneplayer(int x = 0, int y = 0);
	void PUTimage_switch_twoplayer(int x = 0, int y = 0);

	void PUTimage_director(int x = 0, int y = 0);

	void PUTimage_preasent_scoresP1(int x = 0, int y = 0);
	void PUTimage_preasent_scoresP2(int x = 0, int y = 0);

private:
	//生成空图片对象
	PIMAGE image_outgame = newimage();

	PIMAGE image_start = newimage();
	PIMAGE image_pause = newimage();
	PIMAGE image_preasent_scores = newimage();
	PIMAGE image_highest_scores = newimage();

	PIMAGE image_information = newimage();
	PIMAGE image_information_two = newimage();

	PIMAGE image_intogame = newimage();
	PIMAGE image_continu = newimage();

	PIMAGE image_gameover = newimage();
	PIMAGE image_bar = newimage();

	PIMAGE image_map = newimage();

	PIMAGE image_isVoice = newimage();
	PIMAGE image_noVoice = newimage();
	PIMAGE image_back = newimage();

	PIMAGE image_body = newimage();

	PIMAGE image_head_A = newimage();
	PIMAGE image_head_D = newimage();
	PIMAGE image_head_W = newimage();
	PIMAGE image_head_S = newimage();

	PIMAGE image_tail_A = newimage();
	PIMAGE image_tail_D = newimage();
	PIMAGE image_tail_W = newimage();
	PIMAGE image_tail_S = newimage();

	PIMAGE image_food = newimage();

	PIMAGE image_switch_startgame = newimage();
	PIMAGE image_switch_oneplayer = newimage();
	PIMAGE image_switch_twoplayer = newimage();

	PIMAGE image_director = newimage();

	PIMAGE image_preasent_scoresP1 = newimage();
	PIMAGE image_preasent_scoresP2 = newimage();
};

#endif PICTURE_H