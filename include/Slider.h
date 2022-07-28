#pragma once

#include <SFML/graphics.hpp>
#include <functional>


class Slider
{

public:
	Slider(sf::Vector2f position , std::function<void(float)> cmd, const std::string& name);

	void draw(sf::RenderWindow& window);

	void handleMove(const sf::Vector2f& loc);
	void setCirclePos(sf::Vector2f pos);
	void handlePress(const sf::Vector2f& loc);
	void handleRelease(const sf::Vector2f& loc);
	void setPos(const sf::Vector2f& loc);

	bool contains(const sf::Vector2f& loc);

	float getVolume();

	static const sf::Vector2f m_BarSize;
	static const float m_ButtonSize;
private:
	sf::RectangleShape	m_bar;
	sf::CircleShape		m_button;
	sf::Text			m_name;

	bool				m_isPressed = false;
	float				m_currentVolume = 50.f;

	std::function<void(float)> m_cmd;
	void setVolume();

	void setBar(const sf::Vector2f& pos);
	void setBtn(const sf::Vector2f& pos);
	void setName();
	void activate() { m_cmd(m_currentVolume); }
};