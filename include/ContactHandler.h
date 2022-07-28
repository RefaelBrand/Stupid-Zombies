#pragma once 

#include<map>
#include <typeinfo>
#include <typeindex>
#include <functional>

#include "Barrel.h"
#include "Brick.h"
#include "Bullet.h"
#include "TNT.h"
#include "DestroyableBox.h"
#include "UnDestroyableBox.h"
#include "Zombie.h"
#include "GameObj.h"

using std::map;

using HitFunctionPtr = std::function< void(GameObj&, GameObj&)>;

using Key = std::pair<std::type_index, std::type_index>;

using HitMap = std::map<Key, HitFunctionPtr>;

class ContactHandler : public b2ContactListener
{
private:
	HitMap m_hitMap;
	

	void initializeCollisionMap();
	void lookup(const std::type_index& class1, const std::type_index& class2,
		GameObj& obj1, GameObj& obj2);
public:
	ContactHandler();
	virtual void BeginContact(b2Contact* contact) override;

	static void explotionPush(b2Body* tnt, b2Body* otherBody);
	
	static void notFound							(GameObj& barrel, GameObj& barrel2){};
	static void BarrelWithBarrel					(GameObj& barrel, GameObj& barrel2);
	static void BarrelWithBrick						(GameObj& barrel, GameObj& brick);
	static void BarrelWithBullet					(GameObj& barrel, GameObj& bullet);
	static void BarrelWithDestroyableBox			(GameObj& barrel, GameObj& destroyablebox);
	static void BarrelWithTNT						(GameObj& barrel, GameObj& tnt);
	static void BarrelWithUnDestroyableBox			(GameObj& barrel, GameObj& undestroyablebox);
	static void BarrelWithZombie					(GameObj& barrel, GameObj& zombie);
	static void BarrelWithZombieBodyPart			(GameObj& barrel, GameObj& zombiebodypart);
	static void BrickWithBullet						(GameObj& brick, GameObj& bullet);
	static void BrickWithDestroyableBox				(GameObj& brick, GameObj& destroyablebox);
	static void BrickWithUnDestroyableBox			(GameObj& brick, GameObj& undestroyablebox);
	static void BrickWithZombie						(GameObj& brick, GameObj& zombie);
	static void BrickWithZombieBodyPart				(GameObj& brick, GameObj& zombiebodypart);
	static void BulletWithBullet					(GameObj& bullet, GameObj& bullet2);
	static void BulletWithDestroyableBox			(GameObj& bullet, GameObj& destroyablebox);
	static void BulletWithTNT						(GameObj& bullet, GameObj& tnt);
	static void BulletWithUnDestroyableBox			(GameObj& bullet, GameObj& undestroyablebox);
	static void BulletWithZombie					(GameObj& bullet, GameObj& zombie);
	static void BulletWithZombieBodyPart			(GameObj& bullet, GameObj& zombiebodypart);
	static void DestroyableBoxWithDestroyableBox	(GameObj& destroyablebox, GameObj& destroyablebox2);
	static void DestroyableBoxWithTNT				(GameObj& destroyablebox, GameObj& tnt);
	static void DestroyableBoxWithUnDestroyableBox	(GameObj& destroyablebox, GameObj& undestroyablebox);
	static void DestroyableBoxWithZombie			(GameObj& destroyablebox, GameObj& zombie);
	static void DestroyableBoxWithZombieBodyPart	(GameObj& destroyablebox, GameObj& zombiebodypart);
	static void TNTWithTNT							(GameObj& tnt, GameObj& tnt2);
	static void TNTWithUnDestroyableBox				(GameObj& tnt, GameObj& undestroyablebox);
	static void TNTWithZombie						(GameObj& tnt, GameObj& zombie);
	static void TNTWithZombieBodyPart				(GameObj& tnt, GameObj& zombiebodypart);
	static void UnDestroyableBoxWithUnDestroyableBox(GameObj& undestroyablebox, GameObj& undestroyablebox2);
	static void UnDestroyableBoxWithZombie			(GameObj& undestroyablebox, GameObj& zombie);
	static void UnDestroyableBoxWithZombieBodyPart	(GameObj& undestroyablebox, GameObj& zombiebodypart);
	static void ZombieWithZombie					(GameObj& zombie, GameObj& zombie2);
	static void ZombieWithZombieBodyPart			(GameObj& zombie, GameObj& zombiebodypart);
	static void ZombieBodyPartWithZombieBodyPart	(GameObj& zombiebodypart, GameObj& zombiebodypart2);


};