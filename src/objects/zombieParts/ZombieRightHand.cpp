#include "ZombieRightHand.h"
#include "Pictures.h"

const sf::Vector2f ZombieRightHand::m_size = { 22,75 };


ZombieRightHand::ZombieRightHand(Zombie* zombie, shared_ptr<b2World> world, sf::Vector2f pos, float rotation)
	:ZombieBodyPart(zombie,world, Utils::setDef(pos,rotation, b2_dynamicBody, (uintptr_t)this),
		m_size,rp::getInstance()->getPic(Resources::PicName::ZOMBIE_Rhand))
{
	auto shape = Utils::setShape(m_size);
	m_body->CreateFixture(&shape, 1.f);
}

b2Joint* ZombieRightHand::setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef)
{
	Myaabb rightHandAABB(((b2PolygonShape*)m_body->GetFixtureList()->GetShape())->m_vertices);

	jointDef.bodyB = m_body;
	jointDef.localAnchorA = bodyAABB.RightTop - b2Vec2{ 0.2f,0.05f };
	jointDef.localAnchorB = rightHandAABB.LeftTop - b2Vec2{ 0.f,0.05f };
	jointDef.stiffness = 0.5f;

	return (m_joint = m_world->CreateJoint(&jointDef));
	
}

void ZombieRightHand::hit()
{
	ZombieBodyPart::detach();
}

