#ifndef  MUSIC_H
#define MUSIC_H

#include"Picture.h"
#include"functions.h"

class Music
{
public:
	Music();
	~Music();

	void SetSound();

	bool IsSound();

	void mu_Eat();

	void mu_Dead();

	void mu_Switch();

	void rend_MUlogo(Picture& picture);
private:
	bool voice;
};

#endif // ! MUSIC_H

