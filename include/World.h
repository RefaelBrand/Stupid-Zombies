#pragma once
#include "Barrel.h"
#include "Cannon.h"
#include "Bullet.h"
#include "Zombie.h"
#include "Brick.h"
#include "TNT.h"
#include "DestroyableBox.h"
#include "UnDestroyableBox.h"

#include "ContactHandler.h"

#include<string>
#include<vector>
#include<memory>
#include<algorithm>

using std::string;
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::make_unique;
using std::make_shared;




class World 
{

private:
	sf::RenderWindow& m_window;
	shared_ptr<b2World> m_b2world;
	vector<unique_ptr<GameObj>> m_shapes;
	vector<unique_ptr<Zombie>> m_zombies;

	Cannon m_cannon;

	ContactHandler m_collisionHandler;
	
public:
	World(sf::RenderWindow& window);


	template<typename ObjType>
	void createObj(sf::Vector2f position, float rotation);

	void createZombie(sf::Vector2f position, float rotation);

	template<typename ObjType >
	void createObj(sf::Vector2f position);


	void createBullet(const sf::Vector2f& pos, const b2Vec2& force);
	void draw();
	void update();
	void clear(); // clear all objects
	void handleMouseMoved(sf::Vector2f pos);
	void handleMouseReleased(sf::Vector2f point);

	void setBulletsCount(unsigned count);

	bool isLoss() const;
	bool isWin() const;
};

template<typename ObjType >
 void World::createObj(sf::Vector2f position, float rotation)
{
	m_shapes.push_back(make_unique<ObjType>(m_b2world, position, rotation));
}

template<typename ObjType >
void World::createObj(sf::Vector2f position)
{
	createObj<ObjType>(position, 0);
}


 