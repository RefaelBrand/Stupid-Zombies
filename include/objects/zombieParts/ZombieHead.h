#pragma once
#include "SimpleObj.h"
#include "Animatable.h"
#include "ZombieBodyPart.h"

class Zombie;
class ZombieHead :public ZombieBodyPart, public Animatable
{

public:
	ZombieHead(Zombie* zombie,shared_ptr<b2World> world, sf::Vector2f pos, float rotation = 0);
	virtual ~ZombieHead() {};
	 
	void update()override;
	
	static const float m_radius;
	b2Joint* setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef)override;
	virtual void hit() override;
};