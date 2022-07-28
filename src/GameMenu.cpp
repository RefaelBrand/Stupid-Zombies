#include "GameMenu.h"


using rpn = Resources::PicName;
using rp = Resources::Pictures;

GameMenu::GameMenu(sf::RenderWindow& window, ActivationFunc play , ActivationFunc settings)
	:Menu(window, rp::getInstance()->getPic(rpn::START))
{

		addButton(ButtonType::PLAY, std::make_unique<ButtonCmd>(0,
			sf::Vector2f(Utils::WIN_W / 2, Utils::WIN_H / 2),
			AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
			play,"PLAY"));

		addButton(ButtonType::SETTINGS, std::make_unique<ButtonCmd>(0,
			sf::Vector2f(Utils::WIN_W - Utils::BUTTON_SIZE.x, Utils::WIN_H - Utils::BUTTON_SIZE.y),
			AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
			settings,"SETTINGS"));

}

