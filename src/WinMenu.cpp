#include "WinMenu.h"

#include <iostream>

using rpn = Resources::PicName;
using rp = Resources::Pictures;

WinMenu::WinMenu(sf::RenderWindow& window, ActivationFunc cmd, ActivationFunc settings)
	: Menu(window, NULL)
{
	m_backGround.setTexture(rp::getInstance()->getPic(rpn::BACKGROUND2));

	addButtons(cmd, settings);
}

void WinMenu::addButtons(ActivationFunc cmd, ActivationFunc settings)
{
	addButton(ButtonType::RETRY, std::make_unique<ButtonCmd>(1,
		sf::Vector2f(Utils::WIN_W * 0.5, Utils::WIN_H * 0.333),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		cmd, "Replay"));

	addButton(ButtonType::NEXT, std::make_unique<ButtonCmd>(2,
		sf::Vector2f(Utils::WIN_W * 0.5, Utils::WIN_H * 0.666),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		cmd, "Next Level"));

	// the settings button:
	addButton(ButtonType::SETTINGS, std::make_unique<ButtonCmd>(0,
		sf::Vector2f(Utils::WIN_W - Utils::BUTTON_SIZE.x, Utils::WIN_H - Utils::BUTTON_SIZE.y),
		AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
		settings, "SETTINGS"));
}
