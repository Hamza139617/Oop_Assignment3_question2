#include"Entity.h"

Entity::Entity(int id, const char* name)
{
	this->id = id;
	int len = 0;
	while (name[len] != '\0') len++;
	this->name = new char[len + 1];

	for (int i = 0; i <= len; i++)
	{
		this->name[i] = name[i];
	}
}

Entity::~Entity()
{
	delete[] name;
}

Person::Person(int id, const char* name, int age) :Entity(id, name)
{
	this->age = age;
	isAlive = true;
}

Asset::Asset(int id, const char* name, int hp, int armor, float maintenanceCost) :Entity(id, name)
{
	this->hp = hp;
	this->armor = armor;
	this->maintenanceCost = maintenanceCost;
	this->maxHp = hp;
}

MilitaryUnit::MilitaryUnit(int id, const char* name, int hp, int armor, float maintenanceCost, int attackPower) :Asset(id, name, hp, armor, maintenanceCost)
{
	this->attackPower = attackPower;
}

MeleeUnit::MeleeUnit(int id, const char* name, int hp, int armor, float maintenanceCost, int attackPower, bool isFrontLine) :MilitaryUnit(id, name, hp, armor, maintenanceCost, attackPower)
{
	this->isFrontLine = isFrontLine;
}

FootSoldier::FootSoldier(int id, const char* n, int hp, int ar, float mC, int aP) :MeleeUnit(id, n, hp, ar, mC, aP, true)
{

}

Knight::Knight(int id, const char* n, int hp, int ar, float mC, int aP, bool sB) :MeleeUnit(id, n, hp, ar, mC, aP, true)
{
	shieldBlock = sB;
}

MountedUnit::MountedUnit(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP) :MilitaryUnit(id, n, hp, ar, mC, aP)
{
	chargeMultiplier = cM;
	terrainPenalty = tP;
}

Cavalry::Cavalry(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP) :MountedUnit(id, n, hp, ar, mC, aP, cM, tP)
{

}

SiegeEngine::SiegeEngine(int id, const char* n, int hp, int ar, float mC, int sd, int s) :Asset(id, n, hp, ar, mC)
{
	siegeDamage = sd;
	speed = s;
}

BatteringRam::BatteringRam(int id, const char* n, int hp, int armor, float mc, int sd, int s) :SiegeEngine(id, n, hp, armor, mc, sd, s)
{

}

Catapult::Catapult(int id, const char* n, int hp, int armor, float mc, int sd, int s, int aoed, int aoet) :SiegeEngine(id, n, hp, armor, mc, sd, s)
{
	aoeDamage = aoed;
	aoeTargets = aoet;
}

Transport::Transport(int id, const char* n, int hp, int ar, float mc, int tCap, float knotS) :Asset(id, n, hp, ar, mc)
{
	troopCapacity = tCap;
	knotsSpeed = knotS;
}

Noble::Noble(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId) :Person(id, name, age)
{
	realmIdx = reIdx;
	ambitionStat = amStat;
	diplomacyStat = dipStat;
	fatherId = faId;
	healthMeter = 0.0f;
	childrenIds = nullptr;
	childCount = 0;
}

Noble::~Noble()
{
	delete[] childrenIds;
}

LandedLord::LandedLord(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId, int stratStat) : Noble(id, name, age, reIdx, amStat, dipStat, faId)
{
	this->strategyStat = stratStat;
}

LandlessLord::LandlessLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId) :Noble(id, name, age, realmIndx, ambS, dipS, faId)
{
	assassinationPlotProgress = 0.0f;
}

Sage::Sage(int id, const char* name, int age, int healP, int wise) :Person(id, name, age)
{
	healingPower = healP;
	wisdom = wise;
}

Assassin::Assassin(int id, const char* name, int age, int stealthS, int clientIndx) :Person(id, name, age)
{
	stealthStat = stealthS;
	clientIdx = clientIndx;
}

WarriorLord::WarriorLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId, int stratStat, bool shieldB) :Noble(id, name, age, realmIndx, ambS, dipS, faId), Knight(id, name, 100, 0, 0.0f, 60, shieldB)
{
	strategyStat = stratStat;
}

WarShip::WarShip(int id, const char* n, int hullHp, int weaponHp, int armor, float maintCost, int troopC, float knotS, int siegeD, int speed) :Transport(id, n, hullHp, armor, maintCost, troopC, knotS), SiegeEngine(id, n, weaponHp, armor, maintCost, siegeD, speed)
{

}

void WarShip::takeHullDamage(int d)
{
	Transport::hp -= d;
}

void WarShip::takeWeaponDamage(int d)
{
	SiegeEngine::hp -= d;
}