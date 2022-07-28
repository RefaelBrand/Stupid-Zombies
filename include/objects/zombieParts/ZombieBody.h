#pragma once
#include "SimpleObj.h"
#include "ZombieBodyPart.h"

class Zombie;
class ZombieBody : public SimpleObj
{
	friend class Zombie;

private:
	ZombieBody(Zombie* zombie,shared_ptr<b2World> world, sf::Vector2f pos, float rotation = 0);
	virtual ~ZombieBody() {};
	 

	b2Body* getBody() { return m_body; }

	static const sf::Vector2f m_size;

public:
	virtual std::type_index getType()const override { return typeid(*this); }
	virtual void hit() override;
};
