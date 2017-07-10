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

	int update();

	void render(Picture& picture);

	void onkey(int key);

	void onmouse(mouse_msg msg);

	void init(int i);

	void getStatus();

	int getEndscene();

private:
	Snake* m_pobj;
	int m_cntObj;
	int m_endscene;

public:
	Status m_status;
	bool is_voice;
};


#endif // !SCENE_H
