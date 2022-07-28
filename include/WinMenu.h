#pragma once

#include "Menu.h"
#include "ButtonCmd.h"
#include <SFML/graphics.hpp>

class WinMenu : public Menu
{
public:
	WinMenu(sf::RenderWindow& window, ActivationFunc cmd, ActivationFunc settings);

private:
	void addButtons(ActivationFunc cmd, ActivationFunc settings);
};