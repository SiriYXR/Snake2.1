#include"class.h"
#include"functions.h"


void mainloop()
{
	Scene scene; //���峡��
	Picture picture;
	int key;

	for (; ege::is_run(); ege::delay_fps(60))//ÿ��60֡�������ȶ�֡�ʿ���
	{
		Sleep(1);
		/*if (scene.m_status == ismove)
			Sleep(scene.update_speed());*/
		fflush(stdin);


		//��ȡ������
		if (ege::kbhit())
		{
			key = ege::getch();
			scene.onkey(key); //���м��̰�����Ϣ���͸�scene	
		}

		//��ȡ������Ϣ
		if (mousemsg())
		{
			mouse_msg msg = getmouse();//���ṹ�������EGEͷ�ļ�������
			scene.onmouse(msg);//������갴����Ϣ���͸�scene	
		}

		//�¿��ֳ�ʼ��
		if (scene.m_status == oneplayer)
		{
			scene.init(1);
		}
		else if(scene.m_status == twoplayer)
		{
			scene.init(2);
		}

		//�߼�����
		if (scene.m_status == ismove)
			if (scene.update()) //���update���ط�0��ʾ������������ʱ�˳���ѭ��
			{
				break;
			}

		if (scene.getEndscene()) //���m_endscene��0��ʾ������������ʱ�˳���ѭ��
		{
			break;
		}
		ege::cleardevice();
		scene.render(picture);//ͼ�����
		
	}
	rend_outgame(picture);
	Sleep(1500);
}