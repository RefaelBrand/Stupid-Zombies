#pragma once

#include "SimpleObj.h"


class Bullet : public SimpleObj
{

private:
	bool m_wasShot = false;
	sf::Clock m_timer;

public:
	Bullet(shared_ptr<b2World> world, const sf::Vector2f& pos, b2Vec2 force);
	virtual ~Bullet() {};

	void fire(b2Vec2 dirVec);
	void setMass();
	void update()override;
	void updateSpeed();
	virtual std::type_index getType() const override { return typeid(*this); }
	virtual void hit() override;

	static const float m_radius;
};