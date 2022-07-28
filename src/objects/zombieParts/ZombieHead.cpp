#include "ZombieHead.h"
#include "Pictures.h"
#include "Animations.h"
#include "Zombie.h"

const float ZombieHead::m_radius = 60;
using aniname = Resources::AnimationName;

ZombieHead::ZombieHead(Zombie* zombie, shared_ptr<b2World> world, sf::Vector2f pos, float rotation)
	:ZombieBodyPart(zombie,world,
		Utils::setDef(pos, rotation, b2_dynamicBody, (uintptr_t)this),
		{ m_radius,m_radius },
		nullptr),
	Animatable(Resources::Animations::getInstance()->getPkg(aniname::ZOMBIE), SimpleObj::m_shape)
{
	auto shape = Utils::setShape(m_radius);
	m_body->CreateFixture(&shape, 1.f);
}

void ZombieHead::update()
{
	ZombieBodyPart::update();

	if(m_zombie->isAlive())
	Animatable::update();

	/*if (m_body->GetAngle() > b2_pi / 2 || m_body->GetAngle() < -b2_pi / 2)
		m_zombie->kill();*/
}

b2Joint* ZombieHead::setJoint(const Myaabb& bodyAABB , b2WeldJointDef& jointDef)
{
	auto headRadius =  m_body->GetFixtureList()->GetShape()->m_radius;
	
	jointDef.bodyB = m_body;
	jointDef.localAnchorA = { 0 , bodyAABB.LeftTop.y };
	jointDef.localAnchorB = { 0 , -headRadius / 2 };
	jointDef.stiffness = 0.5f;

	return (m_joint =  m_world->CreateJoint(&jointDef));
}

void ZombieHead::hit()
{
		ZombieBodyPart::detach();
		m_zombie->kill();
}


