#pragma once

#include <memory>

#include "Menu.h"
#include "ButtonCmd.h"
#include <SFML/graphics.hpp>

class LevelMenu : public Menu
{
private:
	unsigned m_levelLimit;

	void addButtons(ActivationFunc cmd, ActivationFunc settings);
	void renderLockedButtons();
	unsigned readData(); // get levelLimit from file

public:
	LevelMenu(sf::RenderWindow& window , ActivationFunc cmd, ActivationFunc settings);

	//void run(unsigned level) override;
	void run() override;
};