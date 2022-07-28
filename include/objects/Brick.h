#pragma once
#include "SimpleObj.h"


class Brick : public SimpleObj
{

private:
	
public:
	Brick(shared_ptr<b2World> world,sf::Vector2f pos, float rotation);
	virtual ~Brick() {};
	virtual std::type_index getType()const override { return typeid(*this); }
	virtual void hit() override;
};