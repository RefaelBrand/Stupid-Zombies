#include "GameManager.h"

using Rp = Resources::Pictures;
using Rpn = Resources::PicName;


GameManager::GameManager(sf::RenderWindow& window)
	: Manager(make_unique<LevelMenu>(window, [&](unsigned id) {runManager(id); }, [&](unsigned id) { runSettings(); }),
		make_unique<LevelManager>(window))
	, m_settingsMenu(window)
{
}

void GameManager::runSettings()
{
	m_settingsMenu.run();
}

void GameManager::run(unsigned level)
{
	m_manager->run(level);
}

void GameManager::runManager(unsigned level)
{
	m_manager->run(level);
}
