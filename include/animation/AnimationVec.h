#pragma once

#include<vector>
#include<SFML/graphics.hpp>

class AnimationVec
{
	
private:
	const sf::Texture* m_pic = NULL;
	std::vector<sf::IntRect> m_rects;
	size_t m_it = 0;
	sf::Time m_stepTime;

public:
	AnimationVec() = default;
	AnimationVec(const sf::Texture* pic, sf::Vector2i colsRows, sf::Time stepTime = sf::Time(sf::seconds(0)));

	sf::IntRect getNext();
	const sf::Texture* getPic() const { return m_pic; }
	sf::Time getStepInterval()const { return m_stepTime; }


	const sf::IntRect& operator[](size_t i)const
	{
		return m_rects[i % m_rects.size()]; // % to prevent leak and make cyclic
	}
};