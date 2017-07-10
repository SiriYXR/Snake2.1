#include"class.h"
#include"functions.h"


Scene::Scene()
{
	m_cntObj = 1;
	m_pobj = new Snake;
	m_endscene = 0;
	m_status = nogame;
	m_pobj->setStatus(m_status);
	is_voice = true;
}

Scene::~Scene()
{
	delete m_pobj;
}