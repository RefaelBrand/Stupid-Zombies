#pragma once

#include "AnimationPkg.h"

class Animatable
{
public:
	Animatable(const AnimationPkg& pkg , sf::Shape& shape);
	virtual ~Animatable() = 0 {};

	void update();

	void changeStatus(Status status);

protected:
	Status m_status = Status::IDLE;
	sf::Clock m_animTimer;

private:
	AnimationPkg m_pkg;
	sf::Shape& m_shape;
	
};