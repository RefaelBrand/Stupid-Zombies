#include "Animatable.h"


Animatable::Animatable(const AnimationPkg& pkg, sf::Shape& shape)
	:m_pkg(pkg),m_shape(shape)
{
	changeStatus(Status::IDLE);
}



void Animatable::update()
{
	if (m_animTimer.getElapsedTime() < m_pkg.getTimeInterval(m_status))
		return;

	//else
	m_animTimer.restart();
	m_shape.setTextureRect(m_pkg.getNextRect(m_status));
}

void Animatable::changeStatus(Status status)
{
	m_status = status;
	m_shape.setTexture(m_pkg.getTexture(m_status));
	m_shape.setTextureRect(m_pkg.getNextRect(m_status));
}
