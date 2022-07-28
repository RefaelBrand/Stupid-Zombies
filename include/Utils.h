#pragma once

#include "box2d/box2d.h"
#include "SFML/Graphics.hpp"
#include "ButtonType.h"

class AnimationVec;

namespace Utils
{
	const float METER = 100.f; //100 pixles = meter

	const float RADIAN = 57.2957795f; 
	const float DEGREE = 0.01745329f;
	const unsigned int  FRAMERATE_LINIT = 60; 

	const unsigned WIN_W = 1900;
	const unsigned WIN_H = 1010;
	const sf::Vector2f VIEW_POS = {0,-(float)WIN_H};

	const sf::View VIEW = sf::View({(float)WIN_W/2,-(float)WIN_H/2 }, {(float)WIN_W,(float)WIN_H}); //shifted view cuz box2d...
	const sf::View DEF_VIEW = sf::View({(float)WIN_W/2,(float)WIN_H/2 }, {(float)WIN_W,(float)WIN_H}); //shifted back the view cuz sfml...

	const sf::Vector2f BOARD_SIZE = { 1500,900 };

	const auto  BUTTON_SIZE = sf::Vector2f(200,125);
	const auto  STAGE_SIZE = sf::Vector2f(200,200);

	const auto NUM_OF_LEVELS = 4;

	const float BULLET_SPEED = 20;
	// animation time


	const float animationTimeTNT = 1.15f;
	const float animationTimeZombieIdle = 1;
	const float animationTimeBox = 2;



	// life expectency
	const auto bulletEx  = sf::Time(sf::seconds(5));
	const auto explosionEx = sf::Time(sf::seconds(animationTimeTNT));
	const auto zombieDyingEx = sf::Time(sf::seconds(4));

	// cols and rows for pictures rects
	const auto ZOMBIE_IDLE_COLROW = sf::Vector2i(6,1);
	const auto ZOMBIE_DYE_COLROW = sf::Vector2i(8,1);
	const auto TNT_EXPLD_COLROW = sf::Vector2i(8,8);
	const auto BUTTON_COLROW = sf::Vector2i(4,1);


	b2Vec2 sfSizeToB2Size(const sf::Vector2f& size);
	float sfSizeToB2Size(float size);


	sf::Vector2f coordsToPixles(const b2Vec2& vec);

	b2Vec2 pixlesToCoords(const sf::Vector2f& vec);

	float radianToDegree(float angle);
	float degreeToRadian(float angle);

	b2PolygonShape setShape(sf::Vector2f size);
	b2CircleShape setShape(float size);

	void convertVector(const sf::Vector2f points[], b2Vec2 arr[], int size);

	b2BodyDef setDef(const sf::Vector2f& position, float rotation,b2BodyType type, uintptr_t Ud);

	// positions 
	const sf::Vector2f SOUNDFX_SLIDER_POS = { WIN_W / 2 , WIN_H/4};
	const sf::Vector2f MUSIC_SLIDER_POS = { WIN_W / 2 , 2*WIN_H/4};
	const sf::Vector2f EXIT_BUTTON_POS = { WIN_W / 2 , 3*WIN_H/4};


	//AnimationVec getButtonPicVector(ButtonType type);
	
}


