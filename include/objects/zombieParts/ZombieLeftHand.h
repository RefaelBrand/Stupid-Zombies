#pragma once
#include "SimpleObj.h"
#include "ZombieBodyPart.h"

class Zombie;
class ZombieLeftHand : public ZombieBodyPart
{

public:
	ZombieLeftHand(Zombie* zombie, shared_ptr<b2World> world, sf::Vector2f pos, float rotation = 0);
	virtual ~ZombieLeftHand() {};


	static const sf::Vector2f m_size;

	b2Joint* setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef)override;
	virtual void hit() override;
	
	
};