#include "Slider.h"
#include "Sounds.h"
#include <iostream>

#include "Fonts.h"

using Rf = Resources::Fonts;
using Rfn = Resources::FontNames;

const sf::Vector2f Slider::m_BarSize = { 250, 3 };
const float Slider::m_ButtonSize  = 20;

Slider::Slider(sf::Vector2f position, std::function<void(float)> cmd, const std::string& name)
	: m_bar(m_BarSize),m_button(m_ButtonSize) ,m_cmd(cmd), m_name(name, Rf::getInstance()->getFont(Rfn::DEF), 25)
{
	setBar(position);
	setBtn(position);
	setName();
}

void Slider::handleMove(const sf::Vector2f& loc)
{
	if (m_isPressed)
		setCirclePos(loc);
	
}


void Slider::handlePress(const sf::Vector2f& loc)
{
	if (contains(loc))
		m_isPressed = true;
}

void Slider::handleRelease(const sf::Vector2f& loc)
{
	if (m_isPressed)
	{
		m_isPressed = false;
		Resources::Sounds::getInstance()->getSound(Resources::SoundNames::BEEP).play();
	}
	
}

void Slider::setPos(const sf::Vector2f& loc)
{
	m_bar.setPosition(loc);
	m_button.setPosition(loc);

	setVolume();
}

bool Slider::contains(const sf::Vector2f& loc)
{
	return m_button.getGlobalBounds().contains(loc);
}

float Slider::getVolume()
{
	return m_currentVolume;
}

void Slider::draw(sf::RenderWindow& window)
{
	window.draw(m_bar);
	window.draw(m_button);
	window.draw(m_name);
}

void Slider::setVolume()
{
	m_currentVolume = (100 / m_bar.getGlobalBounds().width) * (m_button.getPosition().x - m_bar.getGlobalBounds().left);
	activate();
}

void Slider::setBar(const sf::Vector2f& pos)
{
	m_bar.setOrigin(0.5f * m_bar.getSize().x, 0.5f * m_bar.getSize().y);
	m_bar.setPosition(pos);

	m_bar.setOutlineThickness(3);
	m_bar.setOutlineColor(sf::Color::Green);
	
}

void Slider::setBtn(const sf::Vector2f& pos)
{
	m_button.setOrigin(m_button.getRadius(), m_button.getRadius());
	m_button.setPosition(pos);

	m_button.setOutlineThickness(2);
	m_button.setOutlineColor(sf::Color::Yellow);
	m_button.setFillColor({255, 215, 0 }); // gold
}

void Slider::setName()
{
	m_name.setOrigin(m_name.getGlobalBounds().width / 2, m_name.getGlobalBounds().height / 2);
	m_name.setPosition(m_bar.getPosition().x, m_bar.getPosition().y - m_button.getRadius() - 25);
	m_name.setOutlineThickness(1);
	m_name.setOutlineColor(sf::Color::Black);
}

void Slider::setCirclePos( sf::Vector2f pos)
{
	pos.y = m_button.getPosition().y; 
	auto lowerBound = m_bar.getPosition().x - m_BarSize.x /2;
	auto upperBound = m_bar.getPosition().x + m_BarSize.x / 2;

	if (pos.x > upperBound)
		pos.x = upperBound;
	else if (pos.x < lowerBound)
		pos.x = lowerBound;

	m_button.setPosition(pos);

	setVolume();
}