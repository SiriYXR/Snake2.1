#include"class.h"
#include"functions.h"

//更新位置等相关属性
int Snake::update()
{
	update_food();
	if (status == ismove)
		update_station();
	update_direction();
	IsEat();

	return 0;
}

//更新按键信息
void Snake::setKey(int _key)
{
	key = _key;
}

void Snake::setNumofsnak(int i)
{
	numofsnake = i;
}

//更新状态
void Snake::setStatus(Status _status)
{
	status = _status;
}

//读取状态
Status Snake::getStatus()
{
	return status;
}

//更新速度
int Snake::update_speed(int i)
{
	if (m_Accelerate[i])
	{
		m_Accelerate[i] = false;
		return 0;
	}
	else
		return m_iSpeedmax - (m_iScores[i] / 10);
}

//更新食物
void Snake::update_food()
{
	Node* p;
	int n, _x, _y;
	for (int i = 0; i < m_AppleNumeMax; i++)
	{
		if (m_food[i].z == 0)
		{
			_x = m_food[i].x = myrand(25);
			m_food[i].y = myrand(25);

			if (_x == 40)
				_x = 460;
			else
				_x -= 20;

			while (1)
			{
				n = 0;
				for (int k = 0; k < numofsnake; k++)
				{
					p = m_nodeHead[k]->next;
					while (p != m_nodeTail[k])
					{
						if (p->x == m_food[i].x&&p->y == m_food[i].y)
							n = 1;
						p = p->next;
					}
				}

				for (int j = 0; j < 5; j++)
				{
					if (i != j)
					{
						if (m_food[j].x == m_food[i].x&&m_food[j].y == m_food[i].y)
							n = 1;
					}
				}

				if (n == 0)
					break;
				if (m_food[i].x == 460)
					m_food[i].x = 40;
				if (_x == m_food[i].x)
					m_food[i].y += 20;
				if (m_food[i].y == 460)
					m_food[i].y = 40;

				m_food[i].x += 20;
			}
			m_food[i].z = 1;
		}
	}
}

//更新蛇头方向
void Snake::update_direction()
{

	switch (key)
	{
	case 'w':
		if (m_nodeHead[0]->next->direction == 4)
			m_Accelerate[0] = true;
		if ((m_nodeHead[0]->next->direction != 2) && (m_nodeHead[0]->next->x != m_nodeHead[0]->next->next->x) && (m_nodeHead[0]->next->y - 20 != m_nodeHead[0]->next->next->y))
		{
			m_nodeHead[0]->next->direction = 4;
			speed[0] = 0;
			update_station();
		}
		break;
	case 's':
		if (m_nodeHead[0]->next->direction == 2)
			m_Accelerate[0] = true;
		if ((m_nodeHead[0]->next->direction != 4) && (m_nodeHead[0]->next->x != m_nodeHead[0]->next->next->x) && (m_nodeHead[0]->next->y + 20 != m_nodeHead[0]->next->next->y))
		{
			m_nodeHead[0]->next->direction = 2;
			speed[0] = 0;
			update_station();
		}
		break;
	case 'a':
		if (m_nodeHead[0]->next->direction == 1)
			m_Accelerate[0] = true;
		if ((m_nodeHead[0]->next->direction != 3) && (m_nodeHead[0]->next->x - 20 != m_nodeHead[0]->next->next->x) && (m_nodeHead[0]->next->y != m_nodeHead[0]->next->next->y))
		{
			m_nodeHead[0]->next->direction = 1;
			speed[0] = 0;
			update_station();
		}
		break;
	case 'd':
		if (m_nodeHead[0]->next->direction == 3)
			m_Accelerate[0] = true;
		if ((m_nodeHead[0]->next->direction != 1) && (m_nodeHead[0]->next->x + 20 != m_nodeHead[0]->next->next->x) && (m_nodeHead[0]->next->y != m_nodeHead[0]->next->next->y))
		{
			m_nodeHead[0]->next->direction = 3;
			speed[0] = 0;
			update_station();
		}
		break;
	default:
		break;
	}

	if (numofsnake > 1)
	{
		switch (key)
		{
		case  '8':
			if (m_nodeHead[1]->next->direction == 4)
				m_Accelerate[1] = true;
			if ((m_nodeHead[1]->next->direction != 2) && (m_nodeHead[1]->next->x != m_nodeHead[1]->next->next->x) && (m_nodeHead[1]->next->y - 20 != m_nodeHead[1]->next->next->y))
			{
				m_nodeHead[1]->next->direction = 4;
				speed[1] = 0;
				update_station();
			}
			break;
		case '5':
			if (m_nodeHead[1]->next->direction == 2)
				m_Accelerate[1] = true;
			if ((m_nodeHead[1]->next->direction != 4) && (m_nodeHead[1]->next->x != m_nodeHead[1]->next->next->x) && (m_nodeHead[1]->next->y + 20 != m_nodeHead[1]->next->next->y))
			{
				m_nodeHead[1]->next->direction = 2;
				speed[1] = 0;
				update_station();
			}
			break;
		case '4':
			if (m_nodeHead[1]->next->direction == 1)
				m_Accelerate[1] = true;
			if ((m_nodeHead[1]->next->direction != 3) && (m_nodeHead[1]->next->x - 20 != m_nodeHead[1]->next->next->x) && (m_nodeHead[1]->next->y != m_nodeHead[1]->next->next->y))
			{
				m_nodeHead[1]->next->direction = 1;
				speed[1] = 0;
				update_station();
			}
			break;
		case '6':
			if (m_nodeHead[1]->next->direction == 3)
				m_Accelerate[1] = true;
			if ((m_nodeHead[1]->next->direction != 1) && (m_nodeHead[1]->next->x + 20 != m_nodeHead[1]->next->next->x) && (m_nodeHead[1]->next->y != m_nodeHead[1]->next->next->y))
			{
				m_nodeHead[1]->next->direction = 3;
				speed[1] = 0;
				update_station();
			}
			break;
		default:
			break;
		}
	}

	key = 0;
}

//更新蛇位置
void Snake::update_station()
{

	if (speed[0] > update_speed(0))
		speed[0] = 0;
	if (speed[1] > update_speed(1))
		speed[1] = 0;

	Node* t;
	for (int i = 0; i < numofsnake; i++)
	{
		if (speed[i] == 0)
		{
			if (IsDead())
				break;
			t = m_nodeHead[i]->next;
			t->x += m_direction[t->direction].x;
			t->y += m_direction[t->direction].y;
			mid_direction[num1[i]] = t->direction;
			t = t->next;
			while (t != m_nodeTail[i])
			{
				num2[i] *= -1;
				num1[i] += num2[i];
				if (t->next != m_nodeTail[i])
				{
					t->x += m_direction[t->direction].x;
					t->y += m_direction[t->direction].y;
					mid_direction[num1[i]] = t->direction;
					num2[i] *= -1;
					num1[i] += num2[i];
					t->direction = mid_direction[num1[i]];
					num2[i] *= -1;
					num1[i] += num2[i];
					t = t->next;
				}
				else
				{
					num2[i] *= -1;
					num1[i] += num2[i];
					t->x += m_direction[t->direction].x;
					t->y += m_direction[t->direction].y;
					t->direction = mid_direction[num1[i]];
					t = t->next;
				}
			}
		}
		speed[i]++;
	}
}