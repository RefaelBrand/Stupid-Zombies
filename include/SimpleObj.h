#pragma once

#include<iostream>
#include "Pictures.h"
#include "GameObj.h"
#include "Utils.h"
#include<vector>


using rp = Resources::Pictures;

class SimpleObj : public GameObj
{
protected:
	sf::RectangleShape m_shape;
	const sf::Texture* m_pic;
	b2Body* m_body;


public:
	SimpleObj(shared_ptr<b2World> world, b2BodyDef bodyDef, sf::Vector2f size,const sf::Texture* pic);

	virtual ~SimpleObj() = 0;
	virtual void update();
	virtual void draw(sf::RenderWindow& window)const override;

	const sf::RectangleShape& getShape() { return m_shape; }

	virtual std::type_index getType()const =0{ return typeid(*this); }

	virtual bool strongHit();
	b2Vec2  getPosition()const { return m_body->GetPosition(); }
	b2Body*  getBody() { return m_body; }
	virtual void hitExplosion() { m_erased = true; }
};