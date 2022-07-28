#pragma once
#include "SimpleObj.h"
#include "ZombieBodyPart.h"

class Zombie;
class ZombieLeftFoot : public ZombieBodyPart
{


public:

	ZombieLeftFoot(Zombie* zombie, shared_ptr<b2World> world, sf::Vector2f pos, float rotation = 0);
	virtual ~ZombieLeftFoot() {};
	static const sf::Vector2f m_size;
	b2Joint* setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef)override;
	virtual void hit() override;
};