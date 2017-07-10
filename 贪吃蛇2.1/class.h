#ifndef CLASS_H
#define CLASS_H

#include"Picture.h"
#include"Music.h"
#include"Snake.h"
#include"Scene.h"

void rend_MainFace_one(const int scores, const int highest_scores, const Status status, Picture& picture);
void rend_MainFace_two(const int scores[], const Status status, Picture& picture);
void rend_IsDead(Picture& picture,DeadFor result, int i, int scores[]);
void rend_map(Picture& picture);
void rend_outgame(Picture& picture);
void rend_Nogame(Picture& picture);
void rend_Choice(Picture& picture,bool i);

#endif CLASS_H