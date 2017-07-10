#include"class.h"
#include"functions.h"


//根据属性值绘画
void Snake::render(Picture& picture)
{
	if (status == nogame)
	{
		rend_Nogame(picture);
	}

	if (status == choice)
	{
		rend_Choice(picture,_choice);
	}

	if (status != nogame && status != choice)
	{
		rend_map(picture);
		rend_Food(picture);
		rend_Snake(picture);

		music->rend_MUlogo(picture);
		if ( numofsnake == 1)
			rend_MainFace_one(m_iScores[0], m_iHistoryscores, status, picture);
		else if (numofsnake == 2)
			rend_MainFace_two(m_iScores, status, picture);
	}

	if (status == isdead)
	{
		rend_IsDead(picture,result,numofsnake, m_iScores);
		if (m_iScores[0] > m_iHistoryscores&&numofsnake == 1)
			saveHistory(m_iScores[0]);
	}
}

void Snake::rend_Snake(Picture& picture)
{
	Node* p;
	for (int i = 0; i < numofsnake; i++)
	{
		p = m_nodeHead[i]->next;
		while (p != m_nodeTail[i])
		{
			if (p == m_nodeHead[i]->next)
			{
				switch (p->direction)
				{
				case 1:
					picture.PUTimage_head_A(20 + p->x, 20 + p->y);
					break;
				case 2:
					picture.PUTimage_head_S(20 + p->x, 20 + p->y);
					break;
				case 3:
					picture.PUTimage_head_D(20 + p->x, 20 + p->y);
					break;
				case 4:
					picture.PUTimage_head_W(20 + p->x, 20 + p->y);
					break;
				default:
					break;
				}
			}
			else if (p == m_nodeTail[i]->prev)
			{
				switch (p->direction)
				{
				case 1:
					picture.PUTimage_tail_A(20 + p->x, 20 + p->y);
					break;
				case 2:
					picture.PUTimage_tail_S(20 + p->x, 20 + p->y);
					break;
				case 3:
					picture.PUTimage_tail_D(20 + p->x, 20 + p->y);
					break;
				case 4:
					picture.PUTimage_tail_W(20 + p->x, 20 + p->y);
					break;
				default:
					break;
				}
			}
			else
			{
				picture.PUTimage_body(20 + p->x, 20 + p->y);
			}
			p = p->next;
		}
		if (numofsnake>1)
		{
			setcolor(WHITE);
			setfont(20, 0, "楷体");
			setbkmode(TRANSPARENT);
			char str[20];
			sprintf(str, "P%d", i + 1);
			outtextxy(m_nodeHead[i]->next->x, m_nodeHead[i]->next->y, str);
		}
	}
}

void Snake::rend_Food(Picture& picture)
{
	for (int i = 0; i < m_AppleNumeMax; i++)
		picture.PUTimage_food(20 + m_food[i].x, 20 + m_food[i].y);
}