#pragma once

#include "Menu.h"
#include "Manager.h"
#include "World.h"
#include "LevelLoader.h"
#include "WinMenu.h"
#include "SettingsMenu.h"

class LevelManager : public Manager
{

private:
	sf::RenderWindow&	m_window;
	World				m_world;
	LevelLoader			m_lvlLoader;
	sf::RectangleShape	m_backGround;
	SettingsMenu		m_settingsMenu;
	sf::Clock			m_timer; // if the bullets ended.
	bool				m_isRunning;
	unsigned			m_currnetLevel;
	
	void runLevel(bool& isWin, bool& isLoss);
	void runLoop(bool& isWin, bool& isLoss);
	bool WinOrLoss(bool& isWin, bool& isLoss);
	
	void setLevelLimit() const;
	void handleKeyPressed(sf::Event& ev);
	void handleMouseMove(sf::Event& ev, sf::Vector2f& pressLoc);
	unsigned readData() const;
	void saveData(unsigned levelLimit) const;
	void lost() const;


public:
	LevelManager(sf::RenderWindow& window);
	void run(unsigned level) override;
	void runManager(unsigned id) override;

	void runSettings();
};