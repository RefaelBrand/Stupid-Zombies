#include "Controller.h"
#include "Pictures.h"

#include "ButtonCmd.h"

using Rp = Resources::Pictures;
using Rpn = Resources::PicName;

Controller::Controller()
	:m_window(sf::VideoMode(Utils::WIN_W, Utils::WIN_H), "Stupid Zombies")
	, Manager(make_unique<GameMenu>(m_window, [&](unsigned id){ runManager(); }, [&](unsigned id){ runSettings(); })
	,make_unique<GameManager>(m_window))
	, m_settingsMenu(m_window)
{
	m_window.setFramerateLimit(Utils::FRAMERATE_LINIT);

}

void Controller::runSettings()
{
	m_settingsMenu.run();
}

void Controller::run()
{
	Resources::Sounds::getInstance()->stopMusics();
	Resources::Sounds::getInstance()->getMusic(Resources::MusicNames::BG1).play();

	Manager::run();
}



