#pragma once
#include "SimpleObj.h"


class DestroyableBox : public SimpleObj
{

private:

public:
	DestroyableBox(shared_ptr<b2World> world, sf::Vector2f pos, float rotation);
	virtual ~DestroyableBox() {};
	virtual std::type_index getType() const override { return typeid(*this); }
	virtual void hit() override;
};