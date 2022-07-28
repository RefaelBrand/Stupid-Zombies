#pragma once

#include <SFML/graphics.hpp>

class Aim
{
private:
	sf::RectangleShape m_hor;
	sf::RectangleShape m_ver;
public:
	Aim();
	void draw(sf::RenderWindow& window)const;
	void setPos(const sf::Vector2f& pos);

	static const sf::Vector2f m_SizeHor;
	static const sf::Vector2f m_SizeVer;
};


