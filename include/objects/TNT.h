#pragma once
#include "SimpleObj.h"
#include "Animatable.h"


class TNT : public SimpleObj, public Animatable
{

private:
	sf::Clock m_DestroyingTimer;
	void scaleUpShape();
public:
	TNT(shared_ptr<b2World> world,sf::Vector2f pos, float rotation);
	virtual ~TNT() {};
	virtual void update( ) override;
	virtual std::type_index getType() const override { return typeid(*this); }
	 
	void explode();
	bool isExploding()const { return m_status == Status::EXPLODING; }
	virtual void hit() override;
};