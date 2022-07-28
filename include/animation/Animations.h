#pragma once

#include <SFML/Graphics.hpp>
#include<string>
#include<vector>
#include<map>

#include "AnimationPkg.h"





namespace Resources
{
	enum class AnimationName {
		ZOMBIE,
		BOX,
		TNT,
		BULLET
	};

	class Animations
	{
	private:

		std::map<AnimationName, AnimationPkg> m_pkgs;
		Animations();
		Animations(Animations&) = delete;
		Animations operator=(Animations&) = delete;
		void loadPkgs();

	public:
		static Animations* getInstance();
		AnimationPkg getPkg(AnimationName name);
	};


}