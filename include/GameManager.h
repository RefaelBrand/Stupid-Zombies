#pragma once

#include <memory>

#include "Menu.h"
#include "Manager.h"
#include "LevelMenu.h"
#include "LevelManager.h"
#include "SettingsMenu.h"

//	has a stage menu and manager
class GameManager : public Manager
{
protected:
	SettingsMenu m_settingsMenu;

public:
	GameManager(sf::RenderWindow& window);

	void runSettings();

	void run(unsigned level) override;
	void runManager(unsigned level) override;
	
};