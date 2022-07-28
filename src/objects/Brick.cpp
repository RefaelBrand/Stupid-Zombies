#include "Brick.h"

static const sf::Vector2f size = { 100, 20};

Brick::Brick(shared_ptr<b2World> world,  sf::Vector2f pos, float rotation)
	:SimpleObj(world, Utils::setDef(pos,rotation, b2_staticBody, (uintptr_t)this),size,rp::getInstance()->getPic(Resources::PicName::BRICK))
{
	auto shape = Utils::setShape(size);
	m_body->CreateFixture(&shape, 1.f);
}

void Brick::hit()
{
	//Resources::Sounds::getInstance()->getSound(rsn::HIT_BRICK).play();
}
