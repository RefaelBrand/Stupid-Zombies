#pragma once

#include "Myaabb.h"
#include "SimpleObj.h"
#include <typeindex>
class Zombie;

class ZombieBodyPart : public SimpleObj
{

	friend class Zombie;
protected:
	Zombie* m_zombie;
	bool m_detachJoint = false;
	b2Joint* m_joint = NULL;


public:
	ZombieBodyPart(Zombie* zombie, shared_ptr<b2World> world,
		b2BodyDef bodyDef, sf::Vector2f size, const sf::Texture* pic);

	virtual ~ZombieBodyPart() = 0{};

	virtual void update()override;

	virtual void detach();
	virtual void hit()override =0 ;
	bool isDetached()const { return m_detachJoint;}
	virtual b2Joint* setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef) = 0;
	virtual std::type_index getType()const override { return typeid(ZombieBodyPart); }
	Zombie* getZombiePtr() { return m_zombie; }

	virtual bool strongHit()override;
};