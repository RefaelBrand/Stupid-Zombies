#pragma once

#include "Button.h"
#include "ButtonType.h"

#include<memory>
#include<vector>

using std::pair;
using std::vector;
using std::unique_ptr;
using std::make_unique;

template<typename EnumT , typename T>
class Bar
{
private:
	vector<pair<EnumT,unique_ptr<T>>> m_objs;
	sf::Vector2f m_position = {0,0};  // center
	float m_space = 10;

	void alignObjs();
public:
	Bar(const sf::Vector2f& position = {400 ,-400}, float spacing = 10);

	void add(EnumT type, unique_ptr<T>&& obj);
	T* getObjByType(EnumT type);
	T* getObjById(unsigned id);
	void handleMove(const sf::Vector2f& loc);
	void handlePress(const sf::Vector2f& loc);
	void handleRelease(const sf::Vector2f& loc);

	void draw(sf::RenderWindow& window);
};




template<typename EnumT, typename T>
Bar<EnumT, T>::Bar(const sf::Vector2f& position, float spacing)
	:m_position(position), m_space(spacing)
{
}

template<typename EnumT, typename T>
void Bar<EnumT, T>::add(EnumT type, unique_ptr<T>&& obj)
{
	m_objs.push_back(pair(type,std::move(obj)));
	//alignObjs();
}

template<typename EnumT, typename T>
T* Bar<EnumT, T>::getObjByType(EnumT type)
{
	for (auto& obj : m_objs)
		if (obj.first == type)
			return obj.second.get();

	return nullptr;
}

template<typename EnumT, typename T>
T* Bar<EnumT, T>::getObjById(unsigned id)
{
	for (auto& obj : m_objs)
		if (obj.second->getId() == id)
			return obj.second.get();

	return nullptr;
}

template<typename EnumT, typename T>
void Bar<EnumT, T>::alignObjs()
{
	int i = 0;
	for (auto& obj : m_objs)
		obj.second->setPos({ m_position.x, m_position.y + (i++ * m_space) });
}

template<typename EnumT, typename T>
void Bar<EnumT, T>::handleMove(const sf::Vector2f& loc)
{
	std::for_each(m_objs.begin(), m_objs.end(), [=]
		(pair<EnumT, unique_ptr<T>>& obj) {
			obj.second->handleMove(loc);		});
}

template<typename EnumT, typename T>
void Bar<EnumT, T>::handlePress(const sf::Vector2f& loc)
{
	std::for_each(m_objs.begin(), m_objs.end(), [=]
	(pair<EnumT, unique_ptr<T>>& obj) {
			obj.second->handlePress(loc);		});
}

template<typename EnumT, typename T>
void Bar<EnumT, T>::handleRelease(const sf::Vector2f& loc)
{
	std::for_each(m_objs.begin(), m_objs.end(), [=]
	(pair<EnumT, unique_ptr<T>>& obj) {
			obj.second->handleRelease(loc);		});
}

template<typename EnumT, typename T>
void Bar<EnumT, T>::draw(sf::RenderWindow& window)
{
	for (auto& obj : m_objs)
		obj.second->draw(window);
}
