#include "ZombieLeftFoot.h"
#include "Pictures.h"

const sf::Vector2f  ZombieLeftFoot::m_size  = { 48,36 };


ZombieLeftFoot::ZombieLeftFoot(Zombie* zombie, shared_ptr<b2World> world, sf::Vector2f pos, float rotation)
	:ZombieBodyPart(zombie,world,
		Utils::setDef(pos,rotation, b2_dynamicBody, (uintptr_t)this),
		m_size,
		rp::getInstance()->getPic(Resources::PicName::ZOMBIE_LFOOT))
{
	auto shape = Utils::setShape(m_size);
	m_body->CreateFixture(&shape, 1.f);
}

b2Joint* ZombieLeftFoot::setJoint(const Myaabb& bodyAABB, b2WeldJointDef& jointDef)
{
	Myaabb leftFootAABB(((b2PolygonShape*)m_body->GetFixtureList()->GetShape())->m_vertices);

	jointDef.bodyB = m_body;
	jointDef.localAnchorA = bodyAABB.RightButtom + b2Vec2{ -0.25,0.05f };
	jointDef.localAnchorB = leftFootAABB.LeftTop;

	jointDef.stiffness = 0.f;

	return (m_joint = m_world->CreateJoint(&jointDef));
}

void ZombieLeftFoot::hit()
{
	ZombieBodyPart::detach();
}


