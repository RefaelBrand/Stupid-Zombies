#include "SettingsMenu.h"
#include "ButtonCmd.h"


using rpn = Resources::PicName;
using rp = Resources::Pictures;

SettingsMenu::SettingsMenu(sf::RenderWindow& window)
	:Menu(window,rp::getInstance()->getPic(rpn::BACKGROUND1))
{
	
		addButton(ButtonType::EXIT ,std::make_unique<ButtonCmd>(0,
			Utils::EXIT_BUTTON_POS,
			AnimationVec(rp::getInstance()->getPic(rpn::BUTTON), Utils::BUTTON_COLROW),
			[&](unsigned id){m_running = false; }, "exit"));

		addSlider("sound FX",std::make_unique<Slider>(
			Utils::SOUNDFX_SLIDER_POS,
			[](float v) {Resources::Sounds::getInstance()->setSoundsVolume(v); }, "Sound Effects"));

		addSlider("Music Volume", std::make_unique<Slider>(
			Utils::MUSIC_SLIDER_POS,
			[](float v) {Resources::Sounds::getInstance()->setMusicVolume(v); }, "Music Volume"));

		

}
