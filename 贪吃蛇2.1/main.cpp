//===============================
//程序名称：贪吃蛇2.1
//制作人：杨新瑞
//创建时间：2017.3.12
//上次修改时间：2017.3.17 21:34
//制作周期：6 天
//===============================

#include"functions.h"

//窗口尺寸
#define Win_w 780
#define Win_H 540

int main(void)
{
	ege::setinitmode(ege::INIT_ANIMATION + ege::INIT_WITHLOGO);
	// 图形初始化
	ege::initgraph(Win_w, Win_H);
	setcaption("贪吃蛇2");
	// 随机数初始化，如果需要使用随机数的话
	ege::randomize();
	// 程序主循环
	mainloop();
	// 关闭绘图设备
	ege::closegraph();

	return 0;
}

