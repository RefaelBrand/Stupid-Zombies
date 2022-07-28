#include "Pictures.h"

namespace fs = std::filesystem;


namespace Resources {

	Pictures::Pictures()
	{
		try {
			loadPictures();
		}
		catch (std::exception&)
		{
			throw std::exception("load pics failed!");
		}
	}

	Pictures* Pictures::getInstance()
	{
		static Pictures m_pictures;
		return &m_pictures;
	}

	const sf::Texture* Pictures::getPic(PicName pic)
	{
		if (m_pics.find(pic) == m_pics.end())	throw std::exception("get pic: pic not found!");
		return &(m_pics[pic]);
	}

	void Pictures::loadPictures()
	{
		try {
			m_pics[PicName::START]				.loadFromFile("start.jpg");
			m_pics[PicName::BACKGROUND1]		.loadFromFile("background1.jpg");
			m_pics[PicName::BACKGROUND2]		.loadFromFile("background2.jpg");
			m_pics[PicName::BARREL]				.loadFromFile("barrel.png");
			//m_pics[PicName::BOX_VANISH]		.loadFromFile("boxVanish.png");
			m_pics[PicName::BULLET]				.loadFromFile("bullet.png");
			m_pics[PicName::BRICK]				.loadFromFile("brick.png");
			m_pics[PicName::CANNON]				.loadFromFile("cannon.png");
			m_pics[PicName::CANNON_BASE]		.loadFromFile("base_cannon.png");
			m_pics[PicName::DES_BOX]			.loadFromFile("des_box.png");
			m_pics[PicName::EXPLOTION]			.loadFromFile("explosion.png");
			m_pics[PicName::TNT]				.loadFromFile("TNT.png");
			m_pics[PicName::UN_DES_BOX]			.loadFromFile("un_des_box.png");
			m_pics[PicName::ZOMBIE_IDLE]		.loadFromFile("heads.png");
			m_pics[PicName::ZOMBIE_Rhand]		.loadFromFile("rightHand.png");
			m_pics[PicName::ZOMBIE_RFOOT]		.loadFromFile("RightFoot.png");
			m_pics[PicName::ZOMBIE_LFOOT]		.loadFromFile("LeftFoot.png");
			m_pics[PicName::ZOMBIE_Lhand]		.loadFromFile("leftHand.png");
			m_pics[PicName::ZOMBIE_BODY]		.loadFromFile("body.png");
			m_pics[PicName::PLAY_BUTTON]		.loadFromFile("playButton.png");
			m_pics[PicName::BUTTON]				.loadFromFile("Button.png");
			m_pics[PicName::LOST]				.loadFromFile("lost.jpg");
		}
		catch (std::exception& e)
		{
			throw std::exception("failed to load picture");
		}
	}

}