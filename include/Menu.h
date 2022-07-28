#pragma once

#include "Bar.h"
#include "Slider.h"


class Slider;

class Menu
{
protected:
	sf::RenderWindow&		m_window;
	sf::RectangleShape		m_backGround;
	Bar<ButtonType,Button>	m_btnBar;
	Bar<string, Slider>		m_sliderBar;
	bool m_running = true;

	void handelEvents();

	void draw();
	void handleMouseMove   (const sf::Event& ev);
	void handleMousePress  (const sf::Event& ev);
	void handleMouseRelease(const sf::Event& ev);
	void handleKeyPressed(const sf::Event& ev);

	

public:
	Menu(sf::RenderWindow& window,const sf::Texture* pic = nullptr);
	virtual ~Menu(){};
	virtual void run();
	virtual void run(unsigned id){};

	
	virtual void addButton(ButtonType, std::unique_ptr<Button>);

	virtual void addSlider(string type, std::unique_ptr<Slider> slider);
};