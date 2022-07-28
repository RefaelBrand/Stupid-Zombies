#include "ZombieRightFoot.h"
#include "Pictures.h"

const sf::Vector2f ZombieRightFoot::m_size = { 48,36 };


ZombieRightFoot::ZombieRightFoot(Zombie* zombie, shared_ptr<b2World> world, sf::Vector2f pos, float rotation)
	:ZombieBodyPart(zombie,world, Utils::setDef(pos,rotation, b2_dynamicBody, (uintptr_t)this),
		m_size,rp::getInstance()->getPic(Resources::PicName::ZOMBIE_RFOOT))
{
	auto shape = Utils::setShape(m_size);
	m_body->CreateFixture(&shape, 1.f);
}

b2Joint* ZombieRightFoot::setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef)
{
	Myaabb rightFootAABB(((b2PolygonShape*)m_body->GetFixtureList()->GetShape())->m_vertices);

	jointDef.bodyB = m_body;
	jointDef.localAnchorA = bodyAABB.LeftButtom + b2Vec2{ 0.25,0.05f };
	jointDef.localAnchorB = rightFootAABB.RightTop;

	jointDef.stiffness = 0.f;

	return (m_joint = m_world->CreateJoint(&jointDef));
}

void ZombieRightFoot::hit()
{
	ZombieBodyPart::detach();
}
