#include "AnimationPkg.h"

AnimationPkg::AnimationPkg(const vector<AnimationData>& data)
{
	for (auto &i : data)
		m_map[i._status] =	AnimationVec(i._pic,i._colsRows,i._timeStepInterval);

}

const sf::Texture* AnimationPkg::getTexture(Status status)
{
	return m_map[status].getPic();
}

sf::IntRect AnimationPkg::getNextRect(Status status)
{
	return  m_map[status].getNext();
}

sf::Time AnimationPkg::getTimeInterval(Status status)
{
	return m_map[status].getStepInterval();
}


