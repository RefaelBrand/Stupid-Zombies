#include "ContactHandler.h"

#include <iostream>

ContactHandler::ContactHandler()
{
	initializeCollisionMap();
}

void ContactHandler::BeginContact(b2Contact* contact)
{
	auto obj1 = (GameObj*)contact->GetFixtureA()->GetBody()->GetUserData().pointer;
	auto obj2 = (GameObj*)contact->GetFixtureB()->GetBody()->GetUserData().pointer;


	lookup(obj1->getType(),obj2->getType() ,*obj1, *obj2);

	std::cout << obj1->getType().name() << " with" << obj2->getType().name() << std::endl;

}

void ContactHandler::lookup(const std::type_index& class1, const std::type_index& class2,
											GameObj& obj1, GameObj& obj2)
{
	auto mapEntry = m_hitMap.find(Key(class1, class2));

	if (mapEntry != m_hitMap.end())
		(mapEntry->second)(obj1, obj2);
	else if((mapEntry = m_hitMap.find(Key(class2, class1))) != m_hitMap.end())
			(mapEntry->second)(obj2, obj1);
	
	//else do nothing
			
}


void ContactHandler::initializeCollisionMap()
{
	m_hitMap[Key(typeid(Barrel), typeid(Barrel))]  						= BarrelWithBarrel;
	m_hitMap[Key(typeid(Barrel), typeid(Brick))]  						= BarrelWithBrick;
	m_hitMap[Key(typeid(Barrel), typeid(Bullet))]  						= BarrelWithBullet;
	m_hitMap[Key(typeid(Barrel), typeid(DestroyableBox))]  				= BarrelWithDestroyableBox;
	m_hitMap[Key(typeid(Barrel), typeid(TNT))]  						= BarrelWithTNT;
	m_hitMap[Key(typeid(Barrel), typeid(UnDestroyableBox))]  			= BarrelWithUnDestroyableBox;
	m_hitMap[Key(typeid(Barrel), typeid(Zombie))]  						= BarrelWithZombie;
	m_hitMap[Key(typeid(Barrel), typeid(ZombieBodyPart))]  				= BarrelWithZombieBodyPart;
	m_hitMap[Key(typeid(Brick), typeid(Bullet))]  						= BrickWithBullet;
	m_hitMap[Key(typeid(Brick), typeid(DestroyableBox))]  				= BrickWithDestroyableBox;
	m_hitMap[Key(typeid(Brick), typeid(UnDestroyableBox))]  			= BrickWithUnDestroyableBox;
	m_hitMap[Key(typeid(Brick), typeid(Zombie))]  						= BrickWithZombie;
	m_hitMap[Key(typeid(Brick), typeid(ZombieBodyPart))]			 	= BrickWithZombieBodyPart;
	m_hitMap[Key(typeid(Bullet), typeid(Bullet))]  						= BulletWithBullet;
	m_hitMap[Key(typeid(Bullet), typeid(DestroyableBox))]  				= BulletWithDestroyableBox;
	m_hitMap[Key(typeid(Bullet), typeid(TNT))]  						= BulletWithTNT;
	m_hitMap[Key(typeid(Bullet), typeid(UnDestroyableBox))]  			= BulletWithUnDestroyableBox;
	m_hitMap[Key(typeid(Bullet), typeid(Zombie))]  						= BulletWithZombie;
	m_hitMap[Key(typeid(Bullet), typeid(ZombieBodyPart))]  				= BulletWithZombieBodyPart;
	m_hitMap[Key(typeid(DestroyableBox), typeid(DestroyableBox))]  		= DestroyableBoxWithDestroyableBox;
	m_hitMap[Key(typeid(DestroyableBox), typeid(TNT))]  				= DestroyableBoxWithTNT;
	m_hitMap[Key(typeid(DestroyableBox), typeid(UnDestroyableBox))]  	= DestroyableBoxWithUnDestroyableBox;
	m_hitMap[Key(typeid(DestroyableBox), typeid(Zombie))]  				= DestroyableBoxWithZombie;
	m_hitMap[Key(typeid(DestroyableBox), typeid(ZombieBodyPart))]  		= DestroyableBoxWithZombieBodyPart;
	m_hitMap[Key(typeid(TNT), typeid(TNT))]  							= TNTWithTNT;
	m_hitMap[Key(typeid(TNT), typeid(UnDestroyableBox))]  				= TNTWithUnDestroyableBox;
	m_hitMap[Key(typeid(TNT), typeid(Zombie))]  						= TNTWithZombie;
	m_hitMap[Key(typeid(TNT), typeid(ZombieBodyPart))]  				= TNTWithZombieBodyPart;
	m_hitMap[Key(typeid(UnDestroyableBox), typeid(UnDestroyableBox))]   = UnDestroyableBoxWithUnDestroyableBox;
	m_hitMap[Key(typeid(UnDestroyableBox), typeid(Zombie))]  			= UnDestroyableBoxWithZombie;
	m_hitMap[Key(typeid(UnDestroyableBox), typeid(ZombieBodyPart))]  	= UnDestroyableBoxWithZombieBodyPart;
	m_hitMap[Key(typeid(Zombie), typeid(Zombie))]  						= ZombieWithZombie;
	m_hitMap[Key(typeid(Zombie), typeid(ZombieBodyPart))]  				= ZombieWithZombieBodyPart;
	m_hitMap[Key(typeid(ZombieBodyPart), typeid(ZombieBodyPart))]  		= ZombieBodyPartWithZombieBodyPart;


}

void ContactHandler::BarrelWithBarrel(GameObj& barrel, GameObj& barrel2)
{
	
		((Barrel&)barrel).hit();
		((Barrel&)barrel2).hit();

}
void ContactHandler::BarrelWithZombieBodyPart(GameObj& barrel, GameObj& zombieBodyPart)
{
	if (((SimpleObj&)barrel).strongHit())
	{
		((Barrel&)barrel).hit();
		((ZombieBodyPart&)zombieBodyPart).hit();
	}
}

void ContactHandler::BarrelWithBrick(GameObj& barrel, GameObj& brick)
{
	((Barrel&)barrel).hit();
	((Brick&)brick).hit();

}
void ContactHandler::BarrelWithBullet(GameObj& barrel, GameObj& bullet)
{
	((Barrel&)barrel).hit();
	((Bullet&)bullet).hit();
	
}
void ContactHandler::BarrelWithDestroyableBox(GameObj& barrel, GameObj& destroyablebox)
{
	((Barrel&)barrel).hit();
	((DestroyableBox&)destroyablebox).hit();

}
void ContactHandler::BarrelWithTNT(GameObj& barrel, GameObj& tnt)
{
	TNT& castTnt = ((TNT&)tnt);
	Barrel& castBarrel = ((Barrel&)tnt);

	if (castTnt.isExploding())
	{
		explotionPush(castTnt.getBody(), castBarrel.getBody());
	}
	else
	{
		((Barrel&)barrel).hit();
		((TNT&)tnt).hit();
	}


}
void ContactHandler::BarrelWithUnDestroyableBox(GameObj& barrel, GameObj& undestroyablebox)
{
	((Barrel&)barrel).hit();
	((UnDestroyableBox&)undestroyablebox).hit();
}
void ContactHandler::BarrelWithZombie(GameObj& barrel, GameObj& zombie)
{
	((Barrel&)barrel).hit();
	((Zombie&)zombie).hit();
}

void ContactHandler::BrickWithBullet(GameObj& brick, GameObj& bullet)
{
	((Brick&)brick).hit();
	((Bullet&)bullet).hit();
}
void ContactHandler::BrickWithDestroyableBox(GameObj& brick, GameObj& destroyablebox)
{
	((Brick&)brick).hit();
	((DestroyableBox&)destroyablebox).hit();
}

void ContactHandler::BrickWithUnDestroyableBox(GameObj& brick, GameObj& undestroyablebox)
{
	((Brick&)brick).hit();
	((UnDestroyableBox&)undestroyablebox).hit();
}
void ContactHandler::BrickWithZombie(GameObj& brick, GameObj& zombie)
{
	((Brick&)brick).hit();
	((Zombie&)zombie).hit();
}

void ContactHandler::BrickWithZombieBodyPart(GameObj& brick, GameObj& zombiebodypart)
{

	if (((SimpleObj&)zombiebodypart).strongHit())
	{

		((Brick&)brick).hit();
		std::cout << "hit BrickWithZombieBodyPart\n";
		((ZombieBodyPart&)zombiebodypart).hit();
	}
}

void ContactHandler::BulletWithBullet(GameObj& bullet, GameObj& bullet2)
{
	((Bullet&)bullet).hit();
	((Bullet&)bullet2).hit();
}
void ContactHandler::BulletWithDestroyableBox(GameObj& bullet, GameObj& destroyablebox)
{
	((Bullet&)bullet).hit();
	((DestroyableBox&)destroyablebox).hit();
}
void ContactHandler::BulletWithTNT(GameObj& bullet, GameObj& tnt)
{
	((Bullet&)bullet).hitExplosion();

	((TNT&)tnt).explode();
}
void ContactHandler::BulletWithUnDestroyableBox(GameObj& bullet, GameObj& undestroyablebox)
{
	((Bullet&)bullet).hit();
	((UnDestroyableBox&)undestroyablebox).hit();
}
void ContactHandler::BulletWithZombie(GameObj& bullet, GameObj& zombie)
{
	((Bullet&)bullet).hit();
	((Zombie&)zombie).hit();
}

void ContactHandler::BulletWithZombieBodyPart(GameObj& bullet, GameObj& zombiebodypart)
{
	((Bullet&)bullet).hit();
	((ZombieBodyPart&)zombiebodypart).hit();
}

void ContactHandler::DestroyableBoxWithDestroyableBox(GameObj& destroyablebox, GameObj& destroyablebox2)
{
	((DestroyableBox&)destroyablebox).hit();
	((DestroyableBox&)destroyablebox2).hit();
}
void ContactHandler::DestroyableBoxWithTNT(GameObj& destroyablebox, GameObj& tnt)
{
	TNT& castTnt = ((TNT&)tnt);

	if (castTnt.isExploding())
		explotionPush(castTnt.getBody(), ((DestroyableBox&)destroyablebox).getBody());
	else
	{
		((DestroyableBox&)destroyablebox).hit();
		((TNT&)tnt).hit();
	}
	

}
void ContactHandler::DestroyableBoxWithUnDestroyableBox(GameObj& destroyablebox, GameObj& undestroyablebox)
{
	((DestroyableBox&)destroyablebox).hit();
	((UnDestroyableBox&)undestroyablebox).hit();
}
void ContactHandler::DestroyableBoxWithZombie(GameObj& destroyablebox, GameObj& zombie)
{
	((DestroyableBox&)destroyablebox).hit();
	((Zombie&)zombie).hit();
}

void ContactHandler::DestroyableBoxWithZombieBodyPart(GameObj& destroyablebox, GameObj& zombiebodypart)
{
	((DestroyableBox&)destroyablebox).hit();
	if (((SimpleObj&)destroyablebox).strongHit())
		((ZombieBodyPart&)zombiebodypart).hit();
}

void ContactHandler::TNTWithTNT(GameObj& tnt, GameObj& tnt2)
{
	TNT& castTnt = ((TNT&)tnt);
	TNT& castTnt2 = ((TNT&)tnt2);

	if (castTnt.isExploding() || castTnt2.isExploding())
	{
		castTnt.explode();
		castTnt2.explode();
	}
	else
	{
		castTnt.hit();
		castTnt2.hit();
	}
	
}
void ContactHandler::TNTWithUnDestroyableBox(GameObj& tnt, GameObj& undestroyablebox)
{
	if (((TNT&)tnt).isExploding())
		explotionPush(((TNT&)tnt).getBody(), ((UnDestroyableBox&)undestroyablebox).getBody());
	else
	{
		((TNT&)tnt).hit();
		((UnDestroyableBox&)undestroyablebox).hit();
	}
}
void ContactHandler::TNTWithZombie(GameObj& tnt, GameObj& zombie)
{

	if (((TNT&)tnt).isExploding())
		((Zombie&)zombie).kill();
	else
	{
		((TNT&)tnt).hit();
		((Zombie&)zombie).hit();
	}
}

void ContactHandler::TNTWithZombieBodyPart(GameObj& tnt, GameObj& zombiebodypart)
{
	TNT& castTnt = ((TNT&)tnt);
	ZombieBodyPart& castZbp = ((ZombieBodyPart&)zombiebodypart);

	if (castTnt.isExploding())
	{
		explotionPush(castTnt.getBody(), castZbp.getBody());
		castZbp.getZombiePtr()->kill();
	}
	else if (castTnt.strongHit() || castZbp.strongHit())
	{
		castZbp.hit();
	}
	
}

void ContactHandler::UnDestroyableBoxWithUnDestroyableBox(GameObj& undestroyablebox, GameObj& undestroyablebox2)
{
	((UnDestroyableBox&)undestroyablebox).hit();
	((UnDestroyableBox&)undestroyablebox).hit();
}
void ContactHandler::UnDestroyableBoxWithZombie(GameObj& undestroyablebox, GameObj& zombie)
{
	((UnDestroyableBox&)undestroyablebox).hit();
	((Zombie&)zombie).hit();
}

void ContactHandler::UnDestroyableBoxWithZombieBodyPart(GameObj& undestroyablebox, GameObj& zombiebodypart)
{
	((UnDestroyableBox&)undestroyablebox).hit();
	if (((SimpleObj&)zombiebodypart).strongHit() && ((SimpleObj&)undestroyablebox).strongHit())
		((ZombieBodyPart&)zombiebodypart).hit();
}

void ContactHandler::ZombieWithZombie(GameObj& zombie, GameObj& zombie2)
{
	

}

void ContactHandler::ZombieWithZombieBodyPart(GameObj& zombie, GameObj& zombiebodypart)
{
	

}

void ContactHandler::ZombieBodyPartWithZombieBodyPart(GameObj& zombiebodypart, GameObj& zombiebodypart2)
{

}

void ContactHandler::explotionPush(b2Body* tnt , b2Body* otherBody)
{
	std::cout << "In function: ContactHandler::explotionPush" << std::endl;
	auto dis = otherBody->GetPosition() - tnt->GetPosition() ;
	dis *= 50.f;
	otherBody->ApplyLinearImpulseToCenter(dis, 1);
}