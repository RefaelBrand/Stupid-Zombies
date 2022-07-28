#include "Bullet.h"
#include "Sounds.h"

const float Bullet::m_radius = 20;


Bullet::Bullet(shared_ptr<b2World> world, const sf::Vector2f& pos, b2Vec2 force)
	:SimpleObj(
		world, 
		Utils::setDef(pos, 0, b2_dynamicBody, (uintptr_t)this), 
		{m_radius ,m_radius}, rp::getInstance()->getPic(Resources::PicName::BULLET))

{

	auto shape = Utils::setShape(m_radius);
	m_body->CreateFixture(&shape, 1.f); //this is set after SimpleObj c-tor init of course
	m_body->SetBullet(true);
	fire(force);

}
void Bullet::setMass()
{
	auto md = b2MassData();
	md.mass = m_body->GetMass() * 10;
	m_body->SetMassData(&md);
	//m_body->SetGravityScale(0);
}

void Bullet::fire(b2Vec2 dirVec)
{
	dirVec.Normalize();
	dirVec *= Utils::BULLET_SPEED;
	m_body->SetLinearVelocity(dirVec);
	Resources::Sounds::getInstance()->getSound(Resources::SoundNames::SHOTGUN_FIREING).play();
	//m_body->ApplyForceToCenter(Utils::BULLET_SPEED * dirVec, true);
	//m_body->ApplyAngularImpulse(0.03f,true);
	m_wasShot = true;
	m_timer.restart();
}

void Bullet::update()
{
	//updateSpeed();
	SimpleObj::update();
	if(m_wasShot && (m_timer.getElapsedTime() >= Utils::bulletEx))
		m_erased = true;
}

void Bullet::updateSpeed()
{
	b2Vec2 vel = m_body->GetLinearVelocity();
	vel.Normalize();
	vel *= Utils::BULLET_SPEED;
	m_body->SetLinearVelocity(vel);
	m_body->SetFixedRotation(true);
}

void Bullet::hit()
{
	//updateSpeed();//? callback
}
