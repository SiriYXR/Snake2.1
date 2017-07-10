#include"class.h"
#include"functions.h"

//初始化，设置坐标，速度方向
Snake::Snake()
{
	speed[0] =0;
	speed[1] = 0;

	num1[0] = 0;
	num2[0] = -1;
	num1[1] = 0;
	num2[1] = -1;

	m_Accelerate[0] = false;
	m_Accelerate[1] = false;

	m_iScores[0] = 0;
	m_iScores[1] = 0;

	music = new Music;
	key = 0;

	for (int i = 0; i < 5; i++)
		m_food[i].z = 0;

	for (int i = 0; i < 2; i++)
	{
		m_nodeHead[i] = new Node;
		m_nodeTail[i] = new Node;
		m_nodeHead[i]->next = m_nodeTail[i];
		m_nodeHead[i]->prev = NULL;
		m_nodeTail[i]->next = NULL;
		m_nodeTail[i]->prev = m_nodeHead[i];
	}

	int s_x[2][3] = { { 180,200,220},{300,280,260} };
	Node* p;
	for (int i = 0; i < 2; i++)
	{
		for (m_iSize[i] = 0; m_iSize[i] < 3; m_iSize[i]++)
		{
			p = new Node;
			if (i == 0)
				p->direction = 1;
			else
				p->direction = 3;
			p->x = s_x[i][m_iSize[i]];
			p->y = 260;
			p->next = NULL;
			if (m_nodeHead[i]->next == m_nodeTail[i])
			{
				m_nodeHead[i]->next = p;
				p->prev = m_nodeHead[i];
				p->next = m_nodeTail[i];
				m_nodeTail[i]->prev = p;
			}
			else
			{
				p->prev = m_nodeTail[i]->prev;
				p->next = m_nodeTail[i];
				m_nodeTail[i]->prev->next = p;
				m_nodeTail[i]->prev = p;
			}
		}
	}
}

//释放这个对象时调用
Snake::~Snake()
{
	for (int i = 0; i < 2; i++)
		Clear(i);

	for (int i = 0; i < 2; i++)
	{
		delete m_nodeHead[i];
		delete m_nodeTail[i];
		m_nodeHead[i] = NULL;
		m_nodeTail[i] = NULL;
	}

	delete music;
}

void Snake::_getHistory()
{
	if (numofsnake == 1)
		m_iHistoryscores = getHistory();
	else
		m_iHistoryscores = 0;
}
