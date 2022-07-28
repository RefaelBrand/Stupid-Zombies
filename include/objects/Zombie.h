#pragma once

#include "ZombieBody.h"
#include "ZombieHead.h"
#include "ZombieLeftHand.h"
#include "ZombieRightHand.h"
#include "ZombieRightFoot.h"
#include "ZombieLeftFoot.h"

class Zombie :public GameObj
{
private:

	ZombieBody		m_bod;
	vector<unique_ptr<ZombieBodyPart>> m_bodyParts;
	sf::Clock m_timer;
	bool m_alive = true;

	sf::Vector2f setHeadPos();
	sf::Vector2f setLhPos();
	sf::Vector2f setLfPos();
	sf::Vector2f setRhPos();
	sf::Vector2f setRfpos();

	void setJoints();

public:
	Zombie(shared_ptr<b2World> world, const sf::Vector2f& pos , float rotation = 0);
	~Zombie();
	void draw(sf::RenderWindow& window)const override;
	void update()override;
	virtual std::type_index getType() const override { return typeid(*this); }

	void kill(); 
	bool isAlive()const { return m_alive; };

	virtual void hit() override;
};