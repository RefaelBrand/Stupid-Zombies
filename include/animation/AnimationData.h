#pragma once

#include "Status.h"
#include <SFML/graphics.hpp>

struct AnimationData
{
	Status _status;
	const sf::Texture* _pic;
	sf::Vector2i _colsRows;
	sf::Time _timeStepInterval;
};