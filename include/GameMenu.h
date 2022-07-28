#pragma once

#include "Menu.h"
#include "ButtonCmd.h"
#include <SFML/graphics.hpp>

//	first screen menu with on button PLAY
class GameMenu : public Menu
{

public:
	GameMenu(sf::RenderWindow& window , ActivationFunc play, ActivationFunc settings);

};