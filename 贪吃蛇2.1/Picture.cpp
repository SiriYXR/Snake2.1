#include"class.h"
#include"functions.h"

Picture::Picture()
{
	//初始化，读取图片
	getimage(image_outgame, "资源\\图片\\界面显示\\outgame.jpg", 0, 0);

	getimage(image_start, "资源\\图片\\按钮\\start.jpg", 0, 0);
	getimage(image_pause, "资源\\图片\\按钮\\pause.jpg", 0, 0);
	getimage(image_preasent_scores, "资源\\图片\\界面显示\\preasent_scores.jpg", 0, 0);
	getimage(image_highest_scores, "资源\\图片\\界面显示\\highest_scores.jpg", 0, 0);

	getimage(image_information, "资源\\图片\\界面显示\\information.jpg", 0, 0);
	getimage(image_information_two, "资源\\图片\\界面显示\\information_two.jpg", 0, 0);

	getimage(image_intogame, "资源\\图片\\界面显示\\intogame.jpg", 0, 0);
	getimage(image_continu, "资源\\图片\\按钮\\continu.jpg", 0, 0);

	getimage(image_gameover, "资源\\图片\\界面显示\\gameover.jpg", 0, 0);
	getimage(image_bar, "资源\\图片\\界面显示\\bar.jpg", 0, 0);

	getimage(image_map, "资源\\图片\\界面显示\\map.jpg", 0, 0);

	getimage(image_isVoice, "资源\\图片\\按钮\\isVoice.jpg", 0, 0);
	getimage(image_noVoice, "资源\\图片\\按钮\\noVoice.jpg", 0, 0);
	getimage(image_back, "资源\\图片\\按钮\\back.jpg", 0, 0);

	getimage(image_body, "资源\\图片\\蛇身\\body.jpg", 0, 0);

	getimage(image_head_A, "资源\\图片\\蛇身\\head_A.jpg", 0, 0);
	getimage(image_head_D, "资源\\图片\\蛇身\\head_D.jpg", 0, 0);
	getimage(image_head_W, "资源\\图片\\蛇身\\head_W.jpg", 0, 0);
	getimage(image_head_S, "资源\\图片\\蛇身\\head_S.jpg", 0, 0);

	getimage(image_tail_A, "资源\\图片\\蛇身\\tail_A.jpg", 0, 0);
	getimage(image_tail_D, "资源\\图片\\蛇身\\tail_D.jpg", 0, 0);
	getimage(image_tail_W, "资源\\图片\\蛇身\\tail_W.jpg", 0, 0);
	getimage(image_tail_S, "资源\\图片\\蛇身\\tail_S.jpg", 0, 0);

	getimage(image_food, "资源\\图片\\界面显示\\food.jpg", 0, 0); 

	getimage(image_switch_startgame, "资源\\图片\\按钮\\switch_startgame.jpg", 0, 0);
	getimage(image_switch_oneplayer, "资源\\图片\\按钮\\switch_oneplayer.jpg", 0, 0);
	getimage(image_switch_twoplayer, "资源\\图片\\按钮\\switch_twoplayer.jpg", 0, 0);

	getimage(image_director, "资源\\图片\\界面显示\\director.jpg", 0, 0); 

	getimage(image_preasent_scoresP1, "资源\\图片\\界面显示\\preasent_scoresP1.jpg", 0, 0);
	getimage(image_preasent_scoresP2, "资源\\图片\\界面显示\\preasent_scoresP2.jpg", 0, 0);
}

Picture::~Picture()
{
	//释放图片对象
	delimage(image_outgame);

	delimage(image_start);
	delimage(image_preasent_scores);
	delimage(image_highest_scores);

	delimage(image_information);
	delimage(image_information_two);

	delimage(image_pause);
	delimage(image_intogame);
	delimage(image_continu);

	delimage(image_gameover);
	delimage(image_bar);

	delimage(image_map);

	delimage(image_isVoice);
	delimage(image_noVoice);
	delimage(image_back);

	delimage(image_body);
	delimage(image_head_A);
	delimage(image_head_S);
	delimage(image_head_D);
	delimage(image_head_W);
	delimage(image_tail_A);
	delimage(image_tail_S);
	delimage(image_tail_D);
	delimage(image_tail_W);

	delimage(image_food);

	delimage(image_switch_startgame);
	delimage(image_switch_oneplayer);
	delimage(image_switch_twoplayer);

	delimage(image_director);

	delimage(image_preasent_scoresP1);
	delimage(image_preasent_scoresP2);
}

void Picture::PUTimage_outgame(int x , int y )
{
	putimage(x, y, image_outgame);
}

void Picture::PUTimage_start(int x, int y)
{
	putimage(x, y, image_start);
}

void Picture::PUTimage_pause(int x, int y)
{
	putimage(x, y, image_pause);
}

void Picture::PUTimage_preasent_scores(int x, int y)
{
	putimage(x, y, image_preasent_scores);
}

void Picture::PUTimage_highest_scores(int x, int y)
{
	putimage(x, y, image_highest_scores);
}

void Picture::PUTimage_information(int x, int y)
{
	putimage(x, y, image_information);
}

void Picture::PUTimage_information_two(int x, int y)
{
	putimage(x, y, image_information_two);
}

void Picture::PUTimage_intogame(int x, int y)
{
	putimage(x, y, image_intogame);
}

void Picture::PUTimage_continu(int x, int y)
{
	putimage(x, y, image_continu);
}

void Picture::PUTimage_gameover(int x, int y)
{
	putimage_alphatransparent(NULL, image_gameover, x, y, EGERGB(0x38, 0x2c, 0x20), 255); //同时使用透明和半透明
}

void Picture::PUTimage_bar(int x, int y)
{
	putimage_alphablend(NULL, image_bar,x, y, 130); //半透明度为0x80
}

void Picture::PUTimage_map(int x, int y)
{
	putimage(x, y, image_map);
}

void Picture::PUTimage_isVoice(int x, int y)
{
	putimage(x, y, image_isVoice);
}

void Picture::PUTimage_noVoice(int x, int y)
{
	putimage(x, y, image_noVoice);
}

void Picture::PUTimage_back(int x, int y)
{
	putimage(x, y, image_back);
}

void Picture::PUTimage_body(int x, int y)
{
	putimage(x, y, image_body);
}

void Picture::PUTimage_head_A(int x, int y)
{
	putimage(x, y, image_head_A);
}

void Picture::PUTimage_head_D(int x, int y)
{
	putimage(x, y, image_head_D);
}

void Picture::PUTimage_head_W(int x, int y)
{
	putimage(x, y, image_head_W);
}

void Picture::PUTimage_head_S(int x, int y)
{
	putimage(x, y, image_head_S);
}

void Picture::PUTimage_tail_A(int x, int y)
{
	putimage(x, y, image_tail_A);
}

void Picture::PUTimage_tail_D(int x, int y)
{
	putimage(x, y, image_tail_D);
}

void Picture::PUTimage_tail_W(int x, int y)
{
	putimage(x, y, image_tail_W);
}

void Picture::PUTimage_tail_S(int x, int y)
{
	putimage(x, y, image_tail_S);
}

void Picture::PUTimage_food(int x, int y)
{
	putimage(x, y, image_food);
}

void Picture::PUTimage_switch_startgame(int x, int y)
{
	putimage(x, y, image_switch_startgame);
}

void Picture::PUTimage_switch_oneplayer(int x, int y)
{
	putimage(x, y, image_switch_oneplayer);
}

void Picture::PUTimage_switch_twoplayer(int x, int y)
{
	putimage(x, y, image_switch_twoplayer);
}

void Picture::PUTimage_director(int x, int y)
{
	putimage(x, y, image_director);
}

void Picture::PUTimage_preasent_scoresP1(int x, int y)
{
	putimage(x, y, image_preasent_scoresP1);
}

void Picture::PUTimage_preasent_scoresP2(int x, int y)
{
	putimage(x, y, image_preasent_scoresP2);
}