#include "AnimationVec.h"
#include "Pictures.h"




AnimationVec::AnimationVec(const sf::Texture* pic, sf::Vector2i colsRows, sf::Time stepTime)
	:m_pic(pic),m_stepTime(stepTime)
{
	int width = pic->getSize().x / colsRows.x;
	int height = pic->getSize().y / colsRows.y;
	

	for (int row = 0; row < colsRows.y; row++)
		for (int col = 0; col < colsRows.x; col++)
			m_rects.push_back({ col*width,row*height,width,height });
		
}

sf::IntRect AnimationVec::getNext()
{
	static bool firstTime = true;

	if(m_rects.empty())
		return sf::IntRect(0,0,0,0); // check for empty

	if (!firstTime) m_it++;			//	on first time dont iterate
	else firstTime = false;

	if (m_it >= m_rects.size())	m_it = 0;	// make it cyclic

	return  (*this)[m_it]; // using operator []
}
