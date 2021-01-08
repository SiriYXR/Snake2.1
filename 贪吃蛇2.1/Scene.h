#ifndef SCENE_H
#define SCENE_H

#include"functions.h"
#include"Picture.h"
#include"Music.h"
#include"Snake.h"

class Scene
{
public:
	//��ʼ��������Ϊ�������
	Scene();

	~Scene();

	int update();//�߼�����

	void render(Picture& picture);//��Ⱦͼ��

	void onkey(int key);//�����¼��ж�

	void onmouse(mouse_msg msg);//����¼��ж�

	void init(int i);//��ʼ����ֵ

	void getStatus();//��ȡ����״̬

	int getEndscene();//��ȡ��������

private:
	Snake* m_pobj;
	int m_cntObj;
	int m_endscene;//�Ƿ��˳���Ϸ

public:
	Status m_status;
	bool is_voice;
};


#endif // !SCENE_H
