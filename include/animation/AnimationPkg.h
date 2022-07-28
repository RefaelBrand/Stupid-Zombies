#pragma once

#include<map>
#include<vector>
#include<SFML/graphics.hpp>
#include"Status.h"
#include"AnimationVec.h"
#include"AnimationData.h"
#include <tuple>


using std::vector;




class AnimationPkg
{

private:
	std::map<Status, AnimationVec > m_map;

	

public:
	AnimationPkg() = default;
	AnimationPkg(const vector<AnimationData>& data);

	const sf::Texture* getTexture(Status status);
	sf::IntRect getNextRect(Status status);
	sf::Time getTimeInterval(Status status);
};


