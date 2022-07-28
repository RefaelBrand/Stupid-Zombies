#include "TNT.h"
#include "Animations.h"
#include "Sounds.h"

using namespace Resources;


static const sf::Vector2f size = {100, 180};



TNT::TNT(shared_ptr<b2World> world,  sf::Vector2f pos, float rotation)
	:SimpleObj(world, Utils::setDef(pos , rotation, b2_dynamicBody, (uintptr_t)this),size,NULL),
	Animatable(Resources::Animations::getInstance()->getPkg(AnimationName::TNT),SimpleObj::m_shape)
{
	auto shape = Utils::setShape(size);
	m_body->CreateFixture(&shape, 100.f);
	m_body->SetType(b2_staticBody);
}

void TNT::update()
{

	Animatable::update();
	SimpleObj::update();
	
	if (m_status == Status::EXPLODING)
	{
		scaleUpShape();

		if (m_DestroyingTimer.getElapsedTime() >= Utils::explosionEx)
			m_erased = true;
	}
}


void TNT::explode()
{
	if (m_status == Status::EXPLODING)	return;

	changeStatus(Status::EXPLODING);
	//scaleUpShape();
	
	Resources::Sounds::getInstance()->getSound(Resources::SoundNames::EXPLOSION).play();
	m_DestroyingTimer.restart();
}

void TNT::hit()
{
	if(strongHit())
	Resources::Sounds::getInstance()->getSound(rsn::METAL_BOX).play();
}

void TNT::scaleUpShape()
{
	static bool once = true;
	if (!once)
		return;
	once = false;

	auto  size = SimpleObj::m_shape.getSize();
	auto pos = SimpleObj::m_shape.getPosition();

	SimpleObj::m_shape.setSize({ (4)*( size.x) , (4)*( size.x) });
	SimpleObj::m_shape.setPosition(0, 0);
	SimpleObj::m_shape.setOrigin(SimpleObj::m_shape.getSize().x / 2, SimpleObj::m_shape.getSize().y / 2);
	SimpleObj::m_shape.setPosition(pos);

	b2PolygonShape newShape  = Utils::setShape(SimpleObj::m_shape.getSize());
	
	((b2PolygonShape*)m_body->GetFixtureList()->GetShape())->Set(newShape.m_vertices, 4);
	m_body->SetTransform(Utils::pixlesToCoords(pos), 0.f);
	SimpleObj::m_shape.scale({ 3,3 });
}