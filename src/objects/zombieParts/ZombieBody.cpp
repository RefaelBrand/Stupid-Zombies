#include "ZombieBody.h"
#include "Pictures.h"

const sf::Vector2f ZombieBody::m_size = sf::Vector2f{ 46,86 };

ZombieBody::ZombieBody(Zombie* zombie,shared_ptr<b2World> world, sf::Vector2f pos, float rotation)
	:SimpleObj(world, Utils::setDef(pos,rotation, b2_dynamicBody, (uintptr_t)zombie),
		m_size,rp::getInstance()->getPic(Resources::PicName::ZOMBIE_BODY))
{
	auto shape = Utils::setShape(m_size);
	m_body->CreateFixture(&shape, 1.f);
}

void ZombieBody::hit()
{
}
