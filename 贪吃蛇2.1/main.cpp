//===============================
//�������ƣ�̰����2.1
//�����ˣ�������
//����ʱ�䣺2017.3.12
//�ϴ��޸�ʱ�䣺2017.3.17 21:34
//�������ڣ�6 ��
//===============================

#include"functions.h"

//���ڳߴ�
#define Win_w 780
#define Win_H 540

int main(void)
{
	ege::setinitmode(ege::INIT_ANIMATION + ege::INIT_WITHLOGO);
	// ͼ�γ�ʼ��
	ege::initgraph(Win_w, Win_H);
	setcaption("̰����2");
	// �������ʼ���������Ҫʹ��������Ļ�
	ege::randomize();
	// ������ѭ��
	mainloop();
	// �رջ�ͼ�豸
	ege::closegraph();

	return 0;
}

