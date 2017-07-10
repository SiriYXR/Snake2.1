#include"class.h"
#include"functions.h"

Music::Music()
{
	voice = true;

	mciSendString(TEXT("open 资源\\音乐\\SWITCH.WAV alias SWITCH"), NULL, 0, NULL);
	mciSendString(TEXT("open 资源\\音乐\\EAT.WAV alias EAT"), NULL, 0, NULL);
	mciSendString(TEXT("open 资源\\音乐\\OUTMAP.WAV alias OUTMAP"), NULL, 0, NULL);
}
Music::~Music()
{
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
		mciSendString(TEXT("close EAT"), NULL, 0, NULL);
		mciSendString(TEXT("open 资源\\音乐\\EAT.WAV alias EAT"), NULL, 0, NULL);
		mciSendString(TEXT("play EAT"), NULL, 0, NULL);
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
