#include "ZombieBodyPart.h"

ZombieBodyPart::ZombieBodyPart(
	Zombie* zombie, 
	shared_ptr<b2World> world,
	b2BodyDef bodyDef,
	sf::Vector2f size,
	const sf::Texture* pic)

	:SimpleObj(world, bodyDef,size,pic), m_zombie(zombie)
{
}

void ZombieBodyPart::update()
{
	if (m_detachJoint && m_joint != NULL)
	{
		m_world->DestroyJoint(m_joint);
		m_joint = NULL;
	}
	if (m_detachJoint && m_body->GetLinearVelocity() == b2Vec2{0,0})
		m_erased = true;

	SimpleObj::update();
}

void ZombieBodyPart::detach()
{
	if (!m_detachJoint)
	{
		m_body->ApplyLinearImpulseToCenter({ (float)(rand() % 2) ,(float)(rand() % 2) }, false);
		m_detachJoint = true;
	}
}

bool ZombieBodyPart::strongHit()
{
	b2Vec2 g = m_body->GetLinearVelocity();
	return (g.Length() > 55);
}
