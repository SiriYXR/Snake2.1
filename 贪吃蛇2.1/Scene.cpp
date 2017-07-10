#include"class.h"
#include"functions.h"


int Scene::update()
{
	m_pobj->setStatus(m_status);
	// 非暂停状态才更新
	if (m_status == ismove)
	{
		m_pobj->update();
	}
	getStatus();
	return m_endscene;
}

void Scene::render(Picture& picture)
{
	m_pobj->render(picture);
}

//键盘信息判断
void Scene::onkey(int key)
{

	if (key == VK_SPACE) //按下P键就在播放与暂停之间转换
	{
		if (m_status == ismove)
			m_status = ispause;
		else if (m_status == ispause)
			m_status = ismove;
		else if (m_status == isdead)
		{
			if (m_pobj->getNumofsnak() == 1)
				m_status = oneplayer;
			else
				m_status = twoplayer;
		}
		else if (m_status == nogame)
		{
			m_status = choice;
		}
		else if (m_status == choice)
		{
			if (m_pobj->_choice)
				m_status = oneplayer;
			else
				m_status = twoplayer;
		}
		m_pobj->music->mu_Switch();
	}

	if (key == VK_ESCAPE) //如果是ESC键，就标记为退出场景，VK_ESCAPE是SDK定义的宏
	{
		m_endscene = 1;
		m_pobj->music->mu_Switch();
	}

	if (key == 'v' || key == 'V')
	{
		m_pobj->music->SetSound();
		is_voice = m_pobj->music->IsSound();
	}

	if (m_status == choice)
	{
		if ((key == 'a' || key == 'A') && m_pobj->_choice != true)
			m_pobj->_choice = true;
		if ((key == 'd' || key == 'D') && m_pobj->_choice == true)
			m_pobj->_choice = !true;
		m_pobj->music->mu_Switch();
	}

	if ((key == 'b' || key == 'B')&& m_status != nogame)
	{
		m_status = choice;
		m_pobj->music->mu_Switch();
	}

	m_pobj->setKey(key);
	m_pobj->setStatus(m_status);
}

//鼠标信息判断
void Scene::onmouse(mouse_msg msg)
{

	if (msg.is_left() && msg.is_down())
	{
		if ((int)msg.x > 685 && (int)msg.x < 755 && (int)msg.y>90 && (int)msg.y < 160)
		{
			if (m_status == ismove)
				m_status = ispause;
			else if (m_status == ispause)
				m_status = ismove;
			else if (m_status == isdead)
				if (m_pobj->getNumofsnak() == 1)
					m_status = oneplayer;
				else
					m_status = twoplayer;
			m_pobj->music->mu_Switch();
		}

		if (m_status == nogame && ((int)msg.x > 250 && (int)msg.x < 480 && (int)msg.y>410 && (int)msg.y < 480))
		{
			m_status = choice;
			m_pobj->music->mu_Switch();
		}

		if ((int)msg.x > 715 && (int)msg.x < 735 && (int)msg.y>15 && (int)msg.y < 40)
		{
			m_pobj->music->SetSound();
			is_voice = m_pobj->music->IsSound();
		}

		if (m_status == choice)
		{
			if ((int)msg.x > 120 && (int)msg.x < 350 && (int)msg.y>410 && (int)msg.y < 480)
				m_status = oneplayer;
			else if ((int)msg.x > 440 && (int)msg.x < 670 && (int)msg.y>410 && (int)msg.y < 480)
				m_status = twoplayer;
		}

		if (m_status == ismove|| m_status == ispause || m_status == isdead)
		{
			if ((int)msg.x > 750 && (int)msg.x < 775 && (int)msg.y>15 && (int)msg.y < 40)
				m_status = choice;
		}
	}
	m_pobj->setStatus(m_status);
}

//开局初始化
void Scene::init(int i)
{
	delete m_pobj;
	m_pobj = new Snake;
	m_pobj->music->mu_Switch();
	m_pobj->setNumofsnak(i);
	m_pobj->_getHistory();
	m_status = ismove;
	if (is_voice != m_pobj->music->IsSound())
	{
		m_pobj->music->SetSound();
	}
}

//更新状态
void Scene::getStatus()
{
	m_status = m_pobj->getStatus();
}

//读取m_endscene
int Scene::getEndscene()
{
	return m_endscene;
}

