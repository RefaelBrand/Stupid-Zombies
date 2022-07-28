#include "LevelManager.h"

#include <fstream>
#include <iostream>

using Rp = Resources::Pictures;
using Rpn = Resources::PicName;

LevelManager::LevelManager(sf::RenderWindow& window)
	:Manager(make_unique<WinMenu>(window, [&](unsigned id) {runManager(id); }, [&](unsigned id) { runSettings(); }), NULL)
	, m_settingsMenu(window)
	, m_window(window)
	, m_world(window)
	, m_lvlLoader(m_world)
	, m_backGround(sf::Vector2f(Utils::WIN_W, Utils::WIN_H))
	, m_isRunning(true)
	, m_currnetLevel(0)
{
	//saveData(1);
}

void LevelManager::run(unsigned level)
{
	if (level > Utils::NUM_OF_LEVELS)
		return;

	m_currnetLevel = level;
	m_isRunning = true;
	bool isWin = false, isLoss = false;

	m_lvlLoader.loadLevel(1, level);
	runLevel(isWin, isLoss);
	while (isLoss) // run the level again.
	{
		lost();
		m_lvlLoader.loadLevel(1, level);
		runLevel(isWin, isLoss);
	}

	// if the player won the game:
	if (isWin)
	{
		setLevelLimit();
		m_window.setView(Utils::DEF_VIEW);
		m_menu->run();
	}
}

void LevelManager::runManager(unsigned id)
{
	m_window.setView(Utils::VIEW);

	if (id == 2)
		m_currnetLevel++;
	run(m_currnetLevel);
}

void LevelManager::runSettings()
{
	m_settingsMenu.run();
}

void LevelManager::runLevel(bool& isWin, bool& isLoss)
{
	//temp:
	m_backGround.setTexture(rp::getInstance()->getPic(Rpn::BACKGROUND2));
	m_backGround.setPosition(m_backGround.getPosition().x, -(float)Utils::WIN_H);

	runLoop(isWin, isLoss);
}

void LevelManager::runLoop(bool& isWin, bool& isLoss)
{
	 sf::Vector2f loc;

	 isWin = isLoss = false;
	 m_window.setView(Utils::VIEW);

	while (m_window.isOpen() && m_isRunning && !WinOrLoss(isWin, isLoss))
	{
		// The 3 actions
		m_window.clear();
		m_window.draw(m_backGround);
		m_world.draw();
		m_window.display();

		if (auto ev = sf::Event{}; m_window.pollEvent(ev))
		{

			switch (ev.type)
			{

			case sf::Event::Closed: m_window.close(); break;

			case sf::Event::KeyPressed:
				handleKeyPressed(ev);
				break;

			case sf::Event::MouseButtonPressed:
				loc = m_window.mapPixelToCoords({ ev.mouseButton.x, ev.mouseButton.y });
				break;

			case sf::Event::MouseButtonReleased:
				if (ev.mouseButton.button == sf::Mouse::Button::Left)
					m_world.handleMouseReleased(m_window.mapPixelToCoords({ ev.mouseButton.x, ev.mouseButton.y }));
				break;

			case sf::Event::MouseMoved:
				loc = m_window.mapPixelToCoords({ ev.mouseMove.x ,ev.mouseMove.y });
				handleMouseMove(ev, loc);
				break;

			default:
				break;
			}
		}
	}
	if (m_isRunning == false)
		isLoss = false;
}

bool LevelManager::WinOrLoss(bool& isWin, bool& isLoss)
{		

	if (m_world.isWin() && !isWin && !isLoss)
	{
		isWin = true;
		isLoss = false;

		m_timer.restart();
		return false;
	}

	if (m_world.isLoss() && !isLoss && !isWin)
	{
		isWin = false;
		isLoss = true;

		m_timer.restart();
		return false;
	}

	if (m_timer.getElapsedTime() > Utils::bulletEx && (isLoss || isWin))
	{
		if (m_world.isWin())
		{
			isWin = true;
			isLoss = false;
		}
		return true;
	}

	return false; // continue running the game.
}

void LevelManager::setLevelLimit() const
{
	unsigned LevelLimit = readData();

	if ((m_currnetLevel +1) > LevelLimit) // open one more level
	{
		if ((m_currnetLevel + 1) <= Utils::NUM_OF_LEVELS)
			saveData(m_currnetLevel + 1);
	}
}

void LevelManager::handleKeyPressed(sf::Event& ev)
{
	// only the key esc ends the level
	switch (ev.key.code)
	{
	case sf::Keyboard::Key::Escape:	m_isRunning = false;
		m_window.setView(Utils::DEF_VIEW);
		m_world.clear();
		break;


	default:
		break;
	}
}

void LevelManager::handleMouseMove(sf::Event& ev, sf::Vector2f& loc)
{
	m_world.handleMouseMoved(loc);
}

unsigned LevelManager::readData() const
{
	unsigned limit;

	std::ifstream input;
	input.open("levelLimit.txt");

	if (!input.is_open())
	{
		std::ofstream output("levelLimit.txt");
		output << "1\n";
		//throw std::exception("Can not open the LevelLimit file for input");
	}

	input >> limit;

	input.close();

	return limit;
}

void LevelManager::saveData(unsigned levelLimit) const
{
	std::ofstream output;

	output.open("levelLimit.txt");

	if (!output.is_open())
	{
		throw std::exception("Can not open the LevelLimit file for output");
	}

	output << levelLimit << std::endl;

	output.close();
}

void LevelManager::lost() const
{
	m_window.setView(Utils::DEF_VIEW);

	sf::RectangleShape lostPic;

	lostPic.setTexture(rp::getInstance()->getPic(Rpn::LOST));
	lostPic.setSize({ Utils::WIN_W, Utils::WIN_H });
	m_window.clear();
	m_window.draw(lostPic);
	m_window.display();
	sf::sleep(sf::seconds(2));

	m_window.setView(Utils::VIEW);
}


