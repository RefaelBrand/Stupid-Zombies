#pragma once


#include "Pictures.h"
#include "Sounds.h"
#include "Fonts.h"
#include "AnimationVec.h"
#include "ButtonStatus.h"
#include "Direction.h"

using namespace Resources;


class Button  {

protected:
	sf::RectangleShape m_shape;
	unsigned m_id;
	sf::Text m_name;
	AnimationVec m_pics;
	void changeStatus(ButtonStatus status);

protected:
	ButtonStatus m_status = ButtonStatus::STATIC;
public:
	Button(const unsigned& id, const sf::Vector2f& position,
		AnimationVec m_pics , const string& name);
	virtual ~Button() {};
	void handleMove(const sf::Vector2f& loc);
	void handlePress(const sf::Vector2f& loc);
	void handleRelease(const sf::Vector2f& loc);
	
	bool contains(const sf::Vector2f& loc);
	virtual void activate() {};
	void draw(sf::RenderWindow& window);
	void setPos(const sf::Vector2f& pos) { m_shape.setPosition(pos); }
	void setSize(const sf::Vector2f& size);
	unsigned getId()const { return m_id; }
	void alignTextTo(Direction dir);
	void enable();
	void disable();
};