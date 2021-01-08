#ifndef  MUSIC_H
#define MUSIC_H

#include"Picture.h"
#include"functions.h"

class Music
{
public:
	Music();
	~Music();

	void SetSound();//ÇĞ»»¾²Òô×´Ì¬

	bool IsSound();//ÅĞ¶ÏÊÇ·ñ¾²Òô

	void mu_Eat();//³Ô¶«Î÷ÉùÒô

	void mu_Dead();//ËÀÍöÉùÒô

	void mu_Switch();//°´Å¥ÉùÒô

	void rend_MUlogo(Picture& picture);//»æÖÆ¾²ÒôÍ¼±êÑùÊ½
private:
	bool voice;
};

#endif // ! MUSIC_H

