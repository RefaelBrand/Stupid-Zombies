#include "DestroyableBox.h"
#include "Pictures.h"

static const sf::Vector2f size = { 50,50 };

DestroyableBox::DestroyableBox(shared_ptr<b2World> world, sf::Vector2f pos, float rotation)
	:SimpleObj(world, Utils::setDef(pos,rotation, b2_dynamicBody, (uintptr_t)this),size,rp::getInstance()->getPic(Resources::PicName::DES_BOX))
{
	auto shape = Utils::setShape(size);
	m_body->CreateFixture(&shape, 1.f);
}

void DestroyableBox::hit()
{
	if (strongHit())
	{
		Resources::Sounds::getInstance()->getSound(rsn::HIT_BOX).play();
		m_erased = true;
	}
}
