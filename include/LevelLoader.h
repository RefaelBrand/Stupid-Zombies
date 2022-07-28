#pragma once

#include <SFML/Graphics.hpp>

#include <string>
#include <fstream>

class World;

class LevelLoader
{
public:
	LevelLoader() = delete;
	LevelLoader(World& world);

	void loadLevel(unsigned stage, unsigned level);
	void nextLevel();
	void replay();

private:
	World& m_world;

	unsigned m_stage;
	unsigned m_level;

	void loadFile(const char* path);
	void createObj(const std::string& objName, const sf::Vector2f& position, const float& rotation);
};