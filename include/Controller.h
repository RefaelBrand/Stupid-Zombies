#pragma once

#include "SimpleObj.h"
#include "GameManager.h"
#include "SettingsMenu.h"
#include "GameMenu.h"
#include "Manager.h"

class Controller : public Manager
{
private:
	sf::RenderWindow m_window;
	SettingsMenu m_settingsMenu;

public:
	Controller();
	void runSettings();

	void run() override;
};

