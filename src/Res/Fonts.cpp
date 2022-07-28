#include "Fonts.h"

namespace fs = std::filesystem;


namespace Resources {

	Fonts::Fonts()
	{
		loadFonts();
	}

	void Fonts::loadFonts()
	{
		m_fonts[FontNames::DEF].loadFromFile("ariblk.ttf");
	}

	Fonts* Fonts::getInstance()
	{
		static Fonts m_Fonts;
		return &m_Fonts;
	}

	const sf::Font& Fonts::getFont(FontNames fontName)
	{
		return m_fonts[fontName];
	}

	

}