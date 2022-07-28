#include "LevelLoader.h"

#include <iostream>
#include <exception>

#include "World.h"

LevelLoader::LevelLoader(World& world)
	: m_world(world)
{
	m_stage = m_level = 1;
}

void LevelLoader::loadLevel(unsigned stage, unsigned level)
{
	m_stage = stage;
	m_level = level;

	m_world.clear(); // clear all objects in m_world

	std::string path =
		"S" + std::to_string(stage) + "L" + std::to_string(level) + ".txt";

	std::cout << "the path is: " << path << std::endl;

	loadFile(path.c_str());
}

void LevelLoader::nextLevel()
{
	m_level++;

	try
	{
		loadLevel(m_stage, m_level);
	}
	catch (std::exception e)
	{
		// we wanna do something nice here...
		std::cout << e.what() << std::endl;
		exit(1);
	}
}

void LevelLoader::replay()
{
	try
	{
		loadLevel(m_stage, m_level);
	}
	catch (std::exception e)
	{
		// we wanna do something nice here...
		std::cout << e.what() << std::endl;
		exit(1);
	}
}

void LevelLoader::loadFile(const char* path)
{
	std::ifstream	input;
	std::string		objName;
	sf::Vector2f	position;
	float			rotation;

	input.open(path);
	
	if (!input.is_open())
	{
		throw std::exception(
			("Can not open file in stage " + std::to_string(m_stage) + " level number " + std::to_string(m_level)).c_str());
	}

	while (!input.eof())
	{
		input >> objName;

		if (objName[0] == '#')
		{
			char temp[1000];
			input.getline(temp, 1000);
			continue;
		}

		input >> position.x >> position.y;
		input >> rotation;
		
		createObj(objName, position, rotation);
		std::cout << "created obj: " << objName << " " << position.x << " " << position.y << std::endl;
	}

	input.close();
}

void LevelLoader::createObj(const std::string& objName, const sf::Vector2f& position, const float& rotation)
{
	if (objName == "Barrel")			{ m_world.createObj<Barrel>				(position, rotation);	return; }
	if (objName == "Brick")				{ m_world.createObj<Brick>				(position, rotation);	return; }
	if (objName == "DestroyableBox")	{ m_world.createObj<DestroyableBox>		(position, rotation);	return; }
	if (objName == "TNT")				{ m_world.createObj<TNT>				(position, rotation);	return; }
	if (objName == "UnDestroyableBox")	{ m_world.createObj<UnDestroyableBox>	(position, rotation);	return; }
	if (objName == "Zombie")			{ m_world.createZombie					(position, rotation);	return; }
	
	// set BulletsCount:
	if (objName == "BulletsCount")		{m_world.setBulletsCount				(position.x);			return; }

	/*shouldn't get here*/
	throw(std::exception(std::string("Unkown object type in lvl file, object type is: " + objName).c_str()));
}