#include "ZombieLeftHand.h"
#include "Pictures.h"

const sf::Vector2f ZombieLeftHand::m_size = { 22,75 };


ZombieLeftHand::ZombieLeftHand(Zombie* zombie, shared_ptr<b2World> world, sf::Vector2f pos, float rotation)
	:ZombieBodyPart(zombie,world, Utils::setDef(pos,rotation, b2_dynamicBody, (uintptr_t)this),
		m_size,rp::getInstance()->getPic(Resources::PicName::ZOMBIE_Lhand))
{
	auto shape = Utils::setShape(m_size);
	m_body->CreateFixture(&shape, 1.f);
}

b2Joint* ZombieLeftHand::setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef)
{
	Myaabb leftHandAABB(((b2PolygonShape*)m_body->GetFixtureList()->GetShape())->m_vertices);

	jointDef.bodyB = m_body;
	jointDef.localAnchorA = bodyAABB.LeftTop + b2Vec2{ 0.15f,0 };
	jointDef.localAnchorB = leftHandAABB.RightTop;
	jointDef.stiffness = 0.5f;

	return (m_joint = m_world->CreateJoint(&jointDef));
}

void ZombieLeftHand::hit()
{
	ZombieBodyPart::detach();
}

