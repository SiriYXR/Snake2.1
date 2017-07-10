#ifndef SNAKE_H
#define SNAKE_H

#include"functions.h"
#include"Picture.h"
#include"Music.h"

class Snake
{

public:
	//��ʼ�����������꣬�ٶȷ���͸���ȣ�����IMAGE��
	Snake();

	//�ͷ��������ʱ����
	~Snake();

	//����λ�õ��������
	int update();

	int update_speed(int i);

	void update_food();

	void update_direction();

	void update_station();

	//��������ֵ�滭
	void render(Picture& picture);

	void rend_Snake(Picture& picture);

	void rend_Food(Picture& picture);


	//�ж�
	bool IsDead();

	bool IsEat();

	//����
	void Clear(int i);

	bool Snake::Pop_front(int i);

	void Push_back(int i);

	int Size(int i)const;

	bool empty(int i)const;

	void setStatus(Status status);

	void setNumofsnak(int i);

	int getNumofsnak();

	Status getStatus();

	void setKey(int _key);

	void _getHistory();

private:
	struct Node
	{
		int x, y, direction;
		struct Node* next;
		struct Node* prev;
	};

	struct Direction
	{
		int x, y;
	};

	struct Food
	{
		int x, y, z;
	};

private:
	Node* m_nodeHead[2];
	Node* m_nodeTail[2];
	int m_iSize[2];
	int m_iScores[2];
	int m_iHistoryscores;
	const int m_iSpeedmax = 25;
	const Direction m_direction[5] = { { 0 },{ -20,0 },{ 0,20 },{ 20,0 },{ 0,-20 } };
	Food m_food[5];
	Status status;
	int key;
	const int m_AppleNumeMax = 5;
	bool m_Accelerate[2];

	//ʹnum1��0��1������Ծ
	int  mid_direction[2];
	int num1[2] = { 0 ,0 };
	int num2[2] = { -1 ,-1 };

	int numofsnake = 2;
	int speed[2] = { 0 };
public:
	Music* music;
	bool _choice=true;
	DeadFor result=Draw;
};


#endif // !SNAKE_H
