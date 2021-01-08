#ifndef SCENE_H
#define SCENE_H

#include"functions.h"
#include"Picture.h"
#include"Music.h"
#include"Snake.h"

class Scene
{
public:
	//初始化，参数为对象个数
	Scene();

	~Scene();

	int update();//逻辑更新

	void render(Picture& picture);//渲染图像

	void onkey(int key);//键盘事件判定

	void onmouse(mouse_msg msg);//鼠标事件判定

	void init(int i);//初始化数值

	void getStatus();//获取场景状态

	int getEndscene();//获取结束场景

private:
	Snake* m_pobj;
	int m_cntObj;
	int m_endscene;//是否退出游戏

public:
	Status m_status;
	bool is_voice;
};


#endif // !SCENE_H
