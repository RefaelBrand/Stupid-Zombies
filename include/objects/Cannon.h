#pragma once

#include "Bullet.h"
#include "Aim.h"

class World;

class Cannon 
{

private:
	sf::RectangleShape m_base;
	sf::RectangleShape m_cannon;
	Aim m_aim;
	unsigned m_bulletsCount;

public:
	Cannon(const sf::Vector2f& pos, unsigned bullets);

	void draw(sf::RenderWindow& window) const;
	void setBulletsCount(unsigned count);

	void handleMouseMoved(const sf::Vector2f& pos);
	void handleMouseReleased(World& world, const sf::Vector2f& pos);

	bool areBulletsLeft() const { return m_bulletsCount > 0; }
	static const  sf::Vector2f m_BaseSize;
	static const  sf::Vector2f m_CannonSize;
};


