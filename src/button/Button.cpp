#include "Button.h"

using rf = Resources::Fonts ;
using rfn = Resources::FontNames ;

void Button::changeStatus(ButtonStatus status)
{
	m_status = status;
	m_shape.setTextureRect(m_pics[(int)status]);
	m_shape.setOutlineThickness(5);

	switch (status)
	{
	case ButtonStatus::STATIC:		m_shape.setOutlineColor({0,255,0,128});			break;
	case ButtonStatus::HIGHLIGHT:	m_shape.setOutlineColor(sf::Color::Yellow);		break;
	case ButtonStatus::CLICKED:		m_shape.setOutlineColor(sf::Color::Green);		break;
	case ButtonStatus::DISABLED:	m_shape.setOutlineColor({ 255,255,255,128 });	break;

	default:
		break;
	}
}

Button::Button(const unsigned& id, const sf::Vector2f& position,
	AnimationVec pics, const string& name)
	:m_id(id),
	m_name(name == ""?std::to_string(id):name, 
		rf::getInstance()->getFont(rfn::DEF)),
	 m_pics(std::move(pics)),m_shape(Utils::BUTTON_SIZE)
{
	m_shape.setTexture(m_pics.getPic());
	m_shape.setTextureRect(m_pics[0]);

	m_shape.setOrigin(0.5f * m_shape.getSize().x, 0.5f * m_shape.getSize().y);
	m_shape.setPosition(position);

	m_name.setCharacterSize(20);
	m_name.setOrigin(m_name.getGlobalBounds().width/2, m_name.getGlobalBounds().height / 2);
	m_name.setPosition(m_shape.getPosition());
}

void Button::handleMove(const sf::Vector2f& loc)
{
	if (m_status == ButtonStatus::DISABLED)	return;

	if (contains(loc))
	{
		if (m_status ==  ButtonStatus::STATIC)
		{
			changeStatus(ButtonStatus::HIGHLIGHT);
			Sounds::getInstance()->getSound(SoundNames::BEEP).play();
		}
	}
	else
	{
		if (m_status != ButtonStatus::STATIC)
		{
			changeStatus(ButtonStatus::STATIC);
			//Sounds::getInstance()->getSound(SoundNames::BEEP).play();
		}
	}
}

void Button::handlePress(const sf::Vector2f& loc)
{
	if (m_status == ButtonStatus::DISABLED)	return;

	if (contains(loc))
	{
		Sounds::getInstance()->getSound(SoundNames::PRESS_CLICK).play();
		changeStatus(ButtonStatus::CLICKED);
	}
}

void Button::handleRelease(const sf::Vector2f& loc)
{
	if (m_status == ButtonStatus::DISABLED)	return;

	if (contains(loc))
	{
		if (m_status == ButtonStatus::CLICKED)
		{
			changeStatus(ButtonStatus::HIGHLIGHT);
			Sounds::getInstance()->getSound(SoundNames::PRESS_CLICK).play();
			activate();
		}
	}
}


bool Button::contains(const sf::Vector2f& loc)
{
	return m_shape.getGlobalBounds().contains(loc);
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_shape);
	window.draw(m_name);

}

void Button::setSize(const sf::Vector2f& size)
{
	sf::Vector2f pos = m_shape.getPosition();

	m_shape.setPosition({ 0,0 });
	m_shape.setSize(size);
	m_shape.setOrigin(0.5f * m_shape.getSize().x, 0.5f * m_shape.getSize().y);
	m_shape.setPosition(pos);

	//m_name.setCharacterSize(m_shape.getSize().x / 2);
	m_name.setPosition(pos);
}

void Button::alignTextTo(Direction dir)
{
	switch (dir)
	{
	case Direction::CENTER: m_name.setPosition(m_shape.getPosition());		break;

	case Direction::TOP:	
		m_name.setPosition({ m_shape.getPosition().x , // x
			m_shape.getPosition().y - (m_shape.getSize().y /2)
			- (m_name.getGlobalBounds().height /2) + 5});//y
		break;

	default:
		break;
	}
}

void Button::enable()
{
	changeStatus(ButtonStatus::STATIC);
}

void Button::disable()
{
	changeStatus(ButtonStatus::DISABLED);
}
