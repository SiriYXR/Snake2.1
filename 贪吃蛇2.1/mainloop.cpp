#include"class.h"
#include"functions.h"


void mainloop()
{
	Scene scene; //定义场景
	Picture picture;
	int key;

	for (; ege::is_run(); ege::delay_fps(60))//每秒60帧，用于稳定帧率控制
	{
		Sleep(1);
		/*if (scene.m_status == ismove)
			Sleep(scene.update_speed());*/
		fflush(stdin);


		//读取键盘信
		if (ege::kbhit())
		{
			key = ege::getch();
			scene.onkey(key); //所有键盘按键消息发送给scene	
		}

		//读取数表信息
		if (mousemsg())
		{
			mouse_msg msg = getmouse();//鼠标结构体对象，在EGE头文件中声明
			scene.onmouse(msg);//所有鼠标按键消息发送给scene	
		}

		//新开局初始化
		if (scene.m_status == oneplayer)
		{
			scene.init(1);
		}
		else if(scene.m_status == twoplayer)
		{
			scene.init(2);
		}

		//逻辑更新
		if (scene.m_status == ismove)
			if (scene.update()) //如果update返回非0表示场景结束，这时退出主循环
			{
				break;
			}

		if (scene.getEndscene()) //如果m_endscene非0表示场景结束，这时退出主循环
		{
			break;
		}
		ege::cleardevice();
		scene.render(picture);//图像更新
		
	}
	rend_outgame(picture);
	Sleep(1500);
}