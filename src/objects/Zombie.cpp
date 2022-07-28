#include "Zombie.h"
#include "Myaabb.h"

Zombie::Zombie( shared_ptr<b2World> world,const sf::Vector2f& pos, float rotation)
	:GameObj(world), m_bod(this, world, pos)
{
	m_bodyParts.push_back(make_unique<ZombieLeftFoot>(this,world, setLfPos()));
	m_bodyParts.push_back(make_unique<ZombieRightFoot>(this,world, setRfpos()));
	m_bodyParts.push_back(make_unique<ZombieLeftHand>(this,world, setLhPos()));
	m_bodyParts.push_back(make_unique<ZombieRightHand>(this,world, setRhPos(),45));
	m_bodyParts.push_back(make_unique<ZombieHead>(this,world, setHeadPos()));
	
	setJoints();
}

Zombie::~Zombie()
{
}

void Zombie::draw(sf::RenderWindow& window) const
{

	m_bod.draw(window);
	for (auto& bodyPart : m_bodyParts)
		bodyPart->draw(window);
}

void Zombie::update()
{
	m_bod.update();
	
	for (auto& bodyPart : m_bodyParts)
		bodyPart->update();

	if (!m_alive && m_timer.getElapsedTime() >= Utils::zombieDyingEx)
		m_erased = true;

	std::erase_if(m_bodyParts, [](auto& b) {return b->isErased(); });
	
}

void Zombie::kill()
{
	if (m_alive)
	{
		Resources::Sounds::getInstance()->getSound(rsn::ZOMBIE_GROWL).play();

		m_alive = false;
		m_timer.restart();

		for (auto& bp : m_bodyParts)
			bp->detach();
	}
}

void Zombie::hit()
{

}



void Zombie::setJoints()
{
	Myaabb bodyAABB(((b2PolygonShape*)m_bod.getBody()->GetFixtureList()->GetShape())->m_vertices);

	b2WeldJointDef jointDef;
	jointDef.bodyA = m_bod.getBody();
	jointDef.collideConnected = false;

	for (auto& bodyPart : m_bodyParts)
		bodyPart->setJoint(bodyAABB, jointDef);

}

sf::Vector2f Zombie::setHeadPos()
{
	return sf::Vector2f(m_bod.getShape().getPosition().x,
						m_bod.getShape().getPosition().y - (ZombieBody::m_size.y/2) 
															- ZombieHead::m_radius);
}

sf::Vector2f Zombie::setLhPos()
{
	
	return sf::Vector2f(m_bod.getShape().getPosition().x - (ZombieBody::m_size.x / 2) - (ZombieLeftHand::m_size.x/2),
						m_bod.getShape().getPosition().y - (ZombieBody::m_size.y / 2));
}

sf::Vector2f Zombie::setRhPos()
{
	return sf::Vector2f(m_bod.getShape().getPosition().x + (ZombieBody::m_size.x / 2),
						m_bod.getShape().getPosition().y - (ZombieBody::m_size.y / 2));
}

sf::Vector2f Zombie::setLfPos()
{
	return sf::Vector2f(m_bod.getShape().getPosition().x - (ZombieBody::m_size.x / 2),
						m_bod.getShape().getPosition().y + (ZombieBody::m_size.y / 2));
}

sf::Vector2f Zombie::setRfpos()
{
	return sf::Vector2f(m_bod.getShape().getPosition().x + ZombieBody::m_size.x/2 - ZombieRightFoot::m_size.x,
						m_bod.getShape().getPosition().y + (ZombieBody::m_size.y / 2));
}
