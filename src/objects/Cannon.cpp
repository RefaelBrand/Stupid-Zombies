#include "Cannon.h"
#include "World.h"

const  sf::Vector2f Cannon::m_BaseSize = { 100,100 };
const  sf::Vector2f Cannon::m_CannonSize = { 138,160 };

Cannon::Cannon(const sf::Vector2f& pos,unsigned bullets)
	:m_base(m_BaseSize),m_cannon(m_CannonSize),m_bulletsCount(bullets)
{
	m_cannon.setOrigin({ m_CannonSize.x / 2,m_CannonSize.y - 10});
	m_base.setOrigin(m_BaseSize.x / 2, m_BaseSize.y / 2);
	m_base.setPosition(pos);
	m_cannon.setPosition(pos);

	auto pics  = Resources::Pictures::getInstance();
	m_base.setTexture(pics->getPic(Resources::PicName::CANNON_BASE));
	m_cannon.setTexture(pics->getPic(Resources::PicName::CANNON));
}


void Cannon::draw(sf::RenderWindow& window) const
{
	//m_aim.draw(window);
	window.draw(m_cannon);
	window.draw(m_base);
	
}

void Cannon::setBulletsCount(unsigned count)
{
	m_bulletsCount = count;
}

void Cannon::handleMouseMoved(const sf::Vector2f& pos)
{
	auto disX = pos.x - m_cannon.getPosition().x;
	auto disY = pos.y - m_cannon.getPosition().y;
	auto m = disY / disX;

	m_cannon.setRotation(Utils::radianToDegree(atan(m))+90);
	//m_aim.setPos(pos);
}


void Cannon::handleMouseReleased(World& world, const sf::Vector2f& pos)
{
	if (m_bulletsCount == 0) return;

	auto disX = pos.x - m_cannon.getPosition().x;
	auto disY = pos.y - m_cannon.getPosition().y;

	world.createBullet(m_cannon.getPosition(), Utils::pixlesToCoords({ disX,disY }));
	m_bulletsCount--;
}

