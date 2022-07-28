#include "Aim.h"

const sf::Vector2f Aim::m_SizeHor = { 15,  3 };
const sf::Vector2f Aim::m_SizeVer = { 3 , 15 };

Aim::Aim()
	:m_hor(m_SizeHor),m_ver(m_SizeVer)
{
	m_hor.setFillColor({ 255,255,255,128 });
	m_ver.setFillColor({ 255,255,255,128 });

	m_hor.setOrigin(m_SizeHor.x / 2, m_SizeHor.y / 2);
	m_ver.setOrigin(m_SizeVer.x / 2, m_SizeVer.y / 2);
}

void Aim::draw(sf::RenderWindow& window) const
{
	window.draw(m_hor);
	window.draw(m_ver);
}

void Aim::setPos(const sf::Vector2f& pos)
{
	m_hor.setPosition(pos);
	m_ver.setPosition(pos);
}
