#include "LevelMenu.h"

#include <iostream>
#include <fstream>

using rpn = Resources::PicName;
using rp = Resources::Pictures;

void LevelMenu::addButtons(ActivationFunc cmd, ActivationFunc settings)
{
	addButton(ButtonType::LEVEL, std::make_unique<ButtonCmd>(1,
		sf::Vector2f(Utils::WIN_W * 0.333, Utils::WIN_H * 0.333),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		cmd, ""));

	addButton(ButtonType::LEVEL, std::make_unique<ButtonCmd>(2,
		sf::Vector2f(Utils::WIN_W * 0.666, Utils::WIN_H * 0.333),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		cmd, ""));

	addButton(ButtonType::LEVEL, std::make_unique<ButtonCmd>(3,
		sf::Vector2f(Utils::WIN_W * 0.333, Utils::WIN_H * 0.666),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		cmd, ""));

	addButton(ButtonType::LEVEL, std::make_unique<ButtonCmd>(4,
		sf::Vector2f(Utils::WIN_W * 0.666, Utils::WIN_H * 0.666),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		cmd, ""));

	// the settings button:
	addButton(ButtonType::SETTINGS, std::make_unique<ButtonCmd>(0,
		sf::Vector2f(Utils::WIN_W - Utils::BUTTON_SIZE.x, Utils::WIN_H - Utils::BUTTON_SIZE.y),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		settings, "SETTINGS"));
}

void LevelMenu::renderLockedButtons()
{
	std::cout << "in function: LevelMenu::renderLockedButtons" << std::endl;
	m_levelLimit = readData();
	for (int i = 1; i <= Utils::NUM_OF_LEVELS; i++)
	{
		if(i <= m_levelLimit)
		{
			m_btnBar.getObjById(i)->enable();
		}
		else
		{
			m_btnBar.getObjById(i)->disable();
		}
	}
}

unsigned LevelMenu::readData()
{
	unsigned limit;
	std::string path = "levelLimit.txt";

	std::ifstream input;
	input.open(path.c_str());

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

LevelMenu::LevelMenu(sf::RenderWindow& window, ActivationFunc cmd, ActivationFunc settings)
	: Menu(window,NULL)
{
	m_backGround.setTexture(rp::getInstance()->getPic(rpn::BACKGROUND2));

	addButtons(cmd, settings);
}

//void LevelMenu::run(unsigned level)
//{
//	m_levelLimit = readData();
//	renderLockedButtons();
//	Menu::run(level);
//}

void LevelMenu::run()
{
	m_levelLimit = readData();
	renderLockedButtons();
	Menu::run();
}
