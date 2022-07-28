#include "Barrel.h"

static const float radius = 50;



Barrel::Barrel(shared_ptr<b2World> world, const sf::Vector2f& pos, float rotation)
	:SimpleObj(world, Utils::setDef(pos,rotation,b2_dynamicBody, (uintptr_t)this), { radius ,radius }, rp::getInstance()->getPic(Resources::PicName::BARREL))
{	
	auto shape = Utils::setShape(radius);
	m_body->CreateFixture(&shape,1.f); //this is set after SimpleObj c-tor init of course
	
}

void Barrel::hit()
{
	if(strongHit())
	Resources::Sounds::getInstance()->getSound(rsn::KNOCK).play();
}

