#include "Menu.h"
#include "Utils.h"

Menu::Menu(sf::RenderWindow& window,const sf::Texture* pic)
	:m_window(window), m_backGround({(float)Utils::WIN_W,(float)Utils::WIN_H})
{
	//m_backGround.setOrigin(m_backGround.getSize().x / 2, m_backGround.getSize().y / 2);
	//m_backGround.setPosition(Utils::VIEW_POS);
	m_backGround.setTexture(pic);
}

void Menu::draw()
{
	m_window.draw(m_backGround);
	m_btnBar.draw(m_window);
	m_sliderBar.draw(m_window);
}

void Menu::handleMouseMove(const sf::Event& ev)
{
	auto loc = m_window.mapPixelToCoords({ ev.mouseMove.x, ev.mouseMove.y });
	m_btnBar.handleMove(loc);
	m_sliderBar.handleMove(loc);
}

void Menu::handleMousePress(const sf::Event& ev)
{
	auto loc = m_window.mapPixelToCoords({ ev.mouseButton.x, ev.mouseButton.y });
	m_btnBar.handlePress(loc);
	m_sliderBar.handlePress(loc);
}

void Menu::handleMouseRelease(const sf::Event& ev)
{
	auto loc = m_window.mapPixelToCoords({ ev.mouseButton.x, ev.mouseButton.y });
	m_btnBar.handleRelease(loc);
	m_sliderBar.handleRelease(loc);
}

void Menu::handleKeyPressed(const sf::Event& ev)
{
	switch (ev.key.code)
	{

	case sf::Keyboard::Escape: m_running = false;
		m_window.setView(Utils::DEF_VIEW);
		break;

	default:
		break;
	}
}


void Menu::run()
{
	m_running = true;
	while (m_window.isOpen() && m_running)
	{
		m_window.clear();
		draw();
		m_window.display();

		handelEvents();
	}
}

void Menu::addButton(ButtonType type, std::unique_ptr<Button> btn)
{
	m_btnBar.add( type, std::move(btn) );
}

void Menu::addSlider(string type, std::unique_ptr<Slider> slider)
{
	m_sliderBar.add(type, std::move(slider));
}

void Menu::handelEvents()
{
	if (auto ev = sf::Event{}; m_window.waitEvent(ev))
	{
		switch (ev.type)
		{
			case sf::Event::Closed:					m_window.close();			break;

			case sf::Event::MouseMoved:				handleMouseMove(ev);		break;

			case sf::Event::MouseButtonPressed:		handleMousePress(ev);		break;

			case sf::Event::MouseButtonReleased:	handleMouseRelease(ev);		break;

			case sf::Event::KeyPressed:				handleKeyPressed(ev);		break;

			default:
				break;
		}
	}
}
