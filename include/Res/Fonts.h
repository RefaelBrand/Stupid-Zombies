#pragma once

#include <SFML/graphics.hpp>
#include<filesystem>
#include <string>
#include <map>

#include "Utils.h"

using std::string;

const std::string FONT_EXTENTION = ".TTF";

namespace Resources {

	enum class FontNames {
		DEF
	};

	class Fonts {

	private:
		std::map<FontNames, sf::Font> m_fonts;

		Fonts();
		Fonts(Fonts&) = delete;
		Fonts operator=(Fonts&) = delete;

		void loadFonts();
	public:
		static Fonts* getInstance();
		const sf::Font& getFont(FontNames font);

	};


}