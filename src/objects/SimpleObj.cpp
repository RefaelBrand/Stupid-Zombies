#include "SimpleObj.h"

using Utils::radianToDegree;
using Utils::coordsToPixles;
using Utils::pixlesToCoords;

SimpleObj::SimpleObj(shared_ptr<b2World> world, b2BodyDef bodyDef, sf::Vector2f size, const sf::Texture* pic)
	:GameObj(world), m_shape(size), m_pic(pic), m_body(m_world->CreateBody(&bodyDef))
{
	m_shape.setOrigin(size.x / 2, size.y / 2);
	m_shape.setPosition(coordsToPixles(m_body->GetPosition()));
	m_shape.setTexture(pic);
}



SimpleObj::~SimpleObj()
{
	m_world->DestroyBody(m_body);
}

void SimpleObj::update()
{
	m_shape.setPosition(coordsToPixles(m_body->GetPosition()));
	m_shape.setRotation(-radianToDegree(m_body->GetAngle())); // - cuz the convertion of opposite aixises 

}


void SimpleObj::draw(sf::RenderWindow& window)const {

	window.draw(m_shape);
}

bool SimpleObj::strongHit()
{
	b2Vec2 g = m_body->GetLinearVelocity();
	return (g.Length() > 3);
}

