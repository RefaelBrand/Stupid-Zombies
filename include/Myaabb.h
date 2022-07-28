#pragma once 
#include "box2d/box2d.h"

class Myaabb
{
public:
	Myaabb(const b2Vec2 vertices[4])
	{
		LeftButtom = vertices[0];
		RightButtom = vertices[1];
		RightTop = vertices[2];
		LeftTop =  vertices[3];

	}

	b2Vec2 LeftButtom;
	b2Vec2 RightButtom;
	b2Vec2 RightTop ;
	b2Vec2 LeftTop;

};