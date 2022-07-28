#include "Utils.h"
#include "AnimationVec.h"





namespace Utils
{
	float sfSizeToB2Size(float size)
	{
		return (size / METER);
	}


	b2Vec2 sfSizeToB2Size(const sf::Vector2f& size)
	{
		return b2Vec2(size.x / METER, size.y / METER);
	}

	sf::Vector2f coordsToPixles(const b2Vec2& vec)
	{
		return { vec.x * METER, -vec.y * METER };
	}


	b2Vec2 pixlesToCoords(const sf::Vector2f& vec)
	{
		return { vec.x / METER , -vec.y / METER };
	}

	float radianToDegree(float angle)
	{
		return angle * RADIAN;
	}

	float degreeToRadian(float angle)
	{
		return angle * DEGREE;
	}

	b2PolygonShape setShape(sf::Vector2f size)
	{
		b2PolygonShape dynamicBox;
		b2Vec2 b2size = sfSizeToB2Size(size);
		dynamicBox.SetAsBox(b2size.x / 2, b2size.y / 2);

		return dynamicBox;
	}


	void convertVector(const sf::Vector2f points[], b2Vec2 arr[], int size)
	{
		for (int i = 0; i < size; i++)
			arr[i] = pixlesToCoords(points[i]);
	}


	b2CircleShape setShape(float size)
	{
		b2CircleShape shape;
		shape.m_radius = sfSizeToB2Size(size) / 2;

		return shape;
	}

	b2BodyDef setDef(const sf::Vector2f& position, float rotation, b2BodyType type , uintptr_t Ud)
	{
		b2Vec2 pos = pixlesToCoords(position);
		float angle = degreeToRadian(rotation);

		b2BodyDef def;
		def.type = type;
		def.position.Set(pos.x, pos.y);
		def.angle = angle;
		def.userData.pointer = Ud;
		return def;

	}

	/*AnimationVec getButtonPicVector(ButtonType type)
	{
		switch (type)
		{
		case ButtonType::PLAY:
			break;
		case ButtonType::RESUME:
			break;
		case ButtonType::EXIT:
			break;
		case ButtonType::SETTINGS:
			break;
		case ButtonType::RETRY:
			break;
		case ButtonType::NEXT:
			break;
		case ButtonType::LEVEL:
			break;
		case ButtonType::STAGE:
			break;
		default:
			break;
		}
	}*/

	bool outOfBoard(const sf::Vector2f& pos)
	{
		return (
			pos.x < 0 ||
			pos.x > WIN_W ||
			pos.y > 0);
	}
}
