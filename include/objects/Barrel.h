#pragma once

#include "SimpleObj.h"

class Barrel : public SimpleObj
{
private:

	
public:
	Barrel(shared_ptr<b2World> world,const sf::Vector2f& pos, float rotation);
	virtual ~Barrel() {};
	virtual std::type_index getType()const override { return typeid(*this); }
	virtual void hit() override;
};