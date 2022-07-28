#pragma once
#include <SFML/Graphics.hpp>
#include<string>
#include<filesystem>
#include<vector>
#include<map>
#include <Windows.h>




using std::string;

const std::string RES_PATH = ".\\resources";
const std::string EXTENTION = ".png";

namespace Resources {

	enum class PicName {
		BRICK,
		BULLET,
		TNT,
		UN_DES_BOX,
		DES_BOX,
		BARREL,
		ZOMBIE_IDLE,
		ZOMBIE_DYE,
		EXPLOTION,
		BOX_VANISH,
		START,
		BACKGROUND1,
		BACKGROUND2,
		CANNON_BASE,
		CANNON,
		ZOMBIE_Lhand,
		ZOMBIE_Rhand,
		ZOMBIE_RFOOT,
		ZOMBIE_LFOOT,
		ZOMBIE_BODY,
		PLAY_BUTTON,
		BUTTON,
		LOST
	};

	class Pictures {

	private:

		std::map<PicName, sf::Texture> m_pics;
		Pictures();
		Pictures(Pictures&) = delete;
		Pictures operator=(Pictures&) = delete;
		void loadPictures();

	public:
		static Pictures* getInstance();
		const sf::Texture* getPic(PicName pic);
	};

}