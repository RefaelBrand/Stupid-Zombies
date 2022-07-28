#pragma once

#include "box2d/box2d.h"
#include<memory>
#include <SFML/Graphics.hpp>
#include <typeindex>
#include "Sounds.h"


using std::string;
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;
using rsn = Resources::SoundNames;

class GameObj
{


protected:
	shared_ptr<b2World> m_world; //keep for destruction;
	bool m_erased = false;

public:
	GameObj(shared_ptr<b2World> world):m_world(world){};
	virtual ~GameObj() = 0{};
	

	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window)const = 0;
	bool isErased()const { return m_erased; };

	virtual std::type_index getType()const = 0;
	virtual void hit() = 0;

	

};
