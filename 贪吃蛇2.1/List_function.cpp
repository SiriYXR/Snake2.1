#include"class.h"
#include"functions.h"

void Snake::Clear(int i)
{
	while (!empty(i))
		Pop_front(i);
}

bool Snake::Pop_front(int i)
{
	if (m_iSize[i])
	{
		Node* p;
		p = m_nodeHead[i]->next;
		m_nodeHead[i]->next = p->next;
		p->next->prev = m_nodeHead[i];
		delete p;
		m_iSize[i]--;
		return true;
	}
	else
		return false;
}

int Snake::Size(int i)const
{
	return m_iSize[i];
}

bool Snake::empty(int i)const
{
	return Size(i) == 0;
}

void Snake::Push_back(int i)
{
	Node* p = new Node;
	p->direction = m_nodeTail[i]->prev->direction;
	if (m_nodeTail[i]->prev->direction == 1)
	{
		p->x = m_nodeTail[i]->prev->x + 20;
		p->y = m_nodeTail[i]->prev->y;
	}
	else if (m_nodeTail[i]->prev->direction == 2)
	{
		p->x = m_nodeTail[i]->prev->x;
		p->y = m_nodeTail[i]->prev->y - 20;
	}
	else if (m_nodeTail[i]->prev->direction == 3)
	{
		p->x = m_nodeTail[i]->prev->x - 20;
		p->y = m_nodeTail[i]->prev->y;
	}
	else if (m_nodeTail[i]->prev->direction == 4)
	{
		p->x = m_nodeTail[i]->prev->x;
		p->y = m_nodeTail[i]->prev->y + 20;
	}

	p->next = m_nodeTail[i];
	p->prev = m_nodeTail[i]->prev;
	p->prev->next = p;
	m_nodeTail[i]->prev = p;
	m_iSize[i]++;
	m_iScores[i]++;
}