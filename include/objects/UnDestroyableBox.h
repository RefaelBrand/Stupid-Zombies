#pragma once
#include "SimpleObj.h"


class UnDestroyableBox : public SimpleObj {


private:

public:
	UnDestroyableBox(shared_ptr<b2World> world,sf::Vector2f pos, float rotation);
	virtual ~UnDestroyableBox() {};
	virtual std::type_index getType() const override { return typeid(*this); }
	virtual void hit()  override;
	
};