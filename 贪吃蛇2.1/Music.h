#ifndef  MUSIC_H
#define MUSIC_H

#include"Picture.h"
#include"functions.h"

class Music
{
public:
	Music();
	~Music();

	void SetSound();//�л�����״̬

	bool IsSound();//�ж��Ƿ���

	void mu_Eat();//�Զ�������

	void mu_Dead();//��������

	void mu_Switch();//��ť����

	void rend_MUlogo(Picture& picture);//���ƾ���ͼ����ʽ
private:
	bool voice;
};

#endif // ! MUSIC_H

