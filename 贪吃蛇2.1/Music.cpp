#include"class.h"
#include"functions.h"

Music::Music()
{
	voice = true;

	//读取音频资源
	mciSendString(TEXT("open 资源\\音乐\\SWITCH.WAV alias SWITCH"), NULL, 0, NULL);
	mciSendString(TEXT("open 资源\\音乐\\EAT.WAV alias EAT"), NULL, 0, NULL);
	mciSendString(TEXT("open 资源\\音乐\\OUTMAP.WAV alias OUTMAP"), NULL, 0, NULL);
}
Music::~Music()
{
	//关闭音频资源
	mciSendString(TEXT("close SWITCH"), NULL, 0, NULL);
	mciSendString(TEXT("close EAT"), NULL, 0, NULL);
	mciSendString(TEXT("close OUTMAP"), NULL, 0, NULL);
}

void Music::SetSound()
{
	voice = !voice;
}

bool Music::IsSound()
{
	return voice;
}

void Music::mu_Eat()
{
	if (IsSound())
	{
		mciSendString(TEXT("close EAT"), NULL, 0, NULL);//关闭音频资源
		mciSendString(TEXT("open 资源\\音乐\\EAT.WAV alias EAT"), NULL, 0, NULL);//读取音频资源（使文件指针回到开头）
		mciSendString(TEXT("play EAT"), NULL, 0, NULL);//播放音频资源
	}
}

void Music::mu_Dead()
{
	if (IsSound())
	{
		mciSendString(TEXT("close OUTMAP"), NULL, 0, NULL);
		mciSendString(TEXT("open 资源\\音乐\\OUTMAP.WAV alias OUTMAP"), NULL, 0, NULL);
		mciSendString(TEXT("play OUTMAP"), NULL, 0, NULL);
	}
}

void Music::mu_Switch()
{
	if (IsSound())
	{
		mciSendString(TEXT("close SWITCH"), NULL, 0, NULL);
		mciSendString(TEXT("open 资源\\音乐\\SWITCH.WAV alias SWITCH"), NULL, 0, NULL);
		mciSendString(TEXT("play SWITCH"), NULL, 0, NULL);
	}
}

void Music::rend_MUlogo(Picture& picture)
{
	if (IsSound())
		picture.PUTimage_isVoice(700, 0);
	else
		picture.PUTimage_noVoice(700, 0);
}
