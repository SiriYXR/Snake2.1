#include"class.h"
#include"functions.h"


bool Snake::IsDead()
{
	int isdeath[2] = { 0 };
	DeadFrom _resualt[2] = { live };
	for (int i = 0; i < numofsnake; i++)
	{
		Node* t;
		t = m_nodeHead[i]->next;
		t = t->next;
		while (t != m_nodeTail[i])
		{
			if (m_nodeHead[i]->next->x + m_direction[m_nodeHead[i]->next->direction].x == t->x && m_nodeHead[i]->next->y + m_direction[m_nodeHead[i]->next->direction].y == t->y)
			{
				isdeath[i] = 1;
					_resualt[i] = death;
			}
			t = t->next;
		}

		if (numofsnake > 1)
		{
			if (i == 0)
			{
				t = m_nodeHead[1]->next;
				while (t != m_nodeTail[1])
				{
					if (m_nodeHead[i]->next->x + m_direction[m_nodeHead[i]->next->direction].x == t->x && m_nodeHead[i]->next->y + m_direction[m_nodeHead[i]->next->direction].y == t->y)
					{
						isdeath[i] = 1;
						_resualt[i] = death;
					}
					t = t->next;
				}
			}
			else
			{
				t = m_nodeHead[0]->next;
				while (t != m_nodeTail[0])
				{
					if (m_nodeHead[i]->next->x + m_direction[m_nodeHead[i]->next->direction].x == t->x && m_nodeHead[i]->next->y + m_direction[m_nodeHead[i]->next->direction].y == t->y)
					{
						isdeath[i] = 1;
						_resualt[i] = death;
					}
					t = t->next;
				}
			}
		}

		//³ö½çËÀÍö
		if (m_nodeHead[i]->next->x + m_direction[m_nodeHead[i]->next->direction].x < 0 || m_nodeHead[i]->next->x + m_direction[m_nodeHead[i]->next->direction].x + 20>500 || m_nodeHead[i]->next->y + m_direction[m_nodeHead[i]->next->direction].y < 0 || m_nodeHead[i]->next->y + m_direction[m_nodeHead[i]->next->direction].y + 20>500)
		{
			isdeath[i] = 1;
			_resualt[i] = death;
		}
	}
	if (numofsnake > 1)
	{
		if (_resualt[1] != live && _resualt[0] == live)
		{
			result = P1win;
		}
		else if (_resualt[1] == live && _resualt[0] != live)
		{
			result = P2win;
		}
	}
	else
	{
		if(m_iScores[0]>m_iHistoryscores)
			result = NewHistory;
	}

	if (isdeath[1] || isdeath[0])
	{
		music->mu_Dead();
		status = isdead;
		return true;
	}
	else
		return false;
}

bool Snake::IsEat()
{
	for (int j = 0; j < numofsnake; j++)
	{
		for (int i = 0; i < m_AppleNumeMax; i++)
		{
			if (m_nodeHead[j]->next->x == m_food[i].x&&m_nodeHead[j]->next->y == m_food[i].y)
			{
				m_food[i].z = 0;
				Push_back(j);
				music->mu_Eat();
				return true;
			}
		}
	}
	return false;
}