#include "Animations.h"
#include "Pictures.h"
#include "Utils.h"

namespace fs = std::filesystem;


namespace Resources {


	Animations::Animations()
	{
		loadPkgs();
	}


	Animations* Animations::getInstance()
	{
		static Animations m_pictures;
		return &m_pictures;
	}

	AnimationPkg Animations::getPkg(AnimationName name)
	{
		auto pkg = m_pkgs.find(name);
		if (pkg == m_pkgs.end())
			throw	std::exception("animation pkg: not found!");

		return m_pkgs[name];
	}

	void Animations::loadPkgs()
	{
		auto pics = Pictures::getInstance();

		m_pkgs[AnimationName::ZOMBIE] = AnimationPkg
		(
			{
				{Status::IDLE,
				pics->getPic(PicName::ZOMBIE_IDLE),
				Utils::ZOMBIE_IDLE_COLROW,
				sf::Time(sf::seconds(Utils::animationTimeZombieIdle/ Utils::ZOMBIE_IDLE_COLROW.x))},

			}
		);

		m_pkgs[AnimationName::TNT] = AnimationPkg
		(
			{
				{Status::IDLE,
				pics->getPic(PicName::TNT),
				sf::Vector2i(1,1),
				sf::Time(sf::seconds(1.f/29.f))},

				{Status::EXPLODING,
				pics->getPic(PicName::EXPLOTION),
				Utils::TNT_EXPLD_COLROW,
				sf::Time(sf::seconds((float)Utils::animationTimeTNT / (float)(Utils::TNT_EXPLD_COLROW.x* Utils::TNT_EXPLD_COLROW.y)))}

			}
		);

			


			
	}

}