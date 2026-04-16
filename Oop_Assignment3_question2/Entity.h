#pragma once

class Entity
{
public:
	int id;
	char* name;
	Entity(int id, const char* name);
	~Entity();
};

class Person :public Entity
{
public:
	int age;
	bool isAlive;
	Person(int id, const char* name, int age);
};

class Asset :public Entity
{
public:
	int hp;
	int maxHp;
	int armor;
	float maintenanceCost;
	Asset(int id, const char* name, int hp, int armor, float maintenanceCost);
};

class MilitaryUnit :public Asset
{
public:
	int attackPower;
	MilitaryUnit(int id, const char* name, int hp, int armor, float maintenanceCost, int attackPower);
};

class MeleeUnit :public MilitaryUnit
{
public:
	bool isFrontLine;
	MeleeUnit(int id, const char* name, int hp, int armor, float maintenanceCost, int attackPower, bool isFrontLine);
};

class FootSoldier :public MeleeUnit
{
public:
	FootSoldier(int id, const char* n, int hp, int ar, float mC, int aP);
};

class Knight :public MeleeUnit
{
public:
	bool shieldBlock;
	Knight(int id, const char* n, int hp, int ar, float mC, int aP, bool sB);
};

class MountedUnit :public MilitaryUnit
{
public:
	float chargeMultiplier;
	float terrainPenalty;
	MountedUnit(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP);
};

class Cavalry :public MountedUnit
{
public:
	Cavalry(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP);
};

class  SiegeEngine :public Asset
{
public:
	int siegeDamage;
	int speed;
	SiegeEngine(int id, const char* n, int hp, int ar, float mC, int sd, int s);
};

class BatteringRam :public SiegeEngine
{
public:
	BatteringRam(int id, const char* n, int hp, int armor, float mc, int sd, int s);
};

class Catapult :public SiegeEngine
{
public:
	int aoeDamage;
	int aoeTargets;
	Catapult(int id, const char* n, int hp, int armor, float mc, int sd, int s, int aoed, int aoet);
};

class Transport :public Asset
{
public:
	int troopCapacity;
	float knotsSpeed;
	Transport(int id, const char* n, int hp, int ar, float mc, int tCap, float knotS);
};

class Noble :public Person
{
public:
	int realmIdx;
	int ambitionStat;
	int diplomacyStat;
	float healthMeter;
	int fatherId;
	int* childrenIds;
	int childCount;
	Noble(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId);
	~Noble();
};

class LandedLord :public Noble
{
public:
	int strategyStat;
	LandedLord(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId, int stratStat);

};

class LandlessLord :public Noble
{
public:
	float assassinationPlotProgress;
	LandlessLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId);
};

class Sage :public Person
{
public:
	int healingPower;
	int wisdom;
	Sage(int id, const char* name, int age, int healP, int wise);
};

class Assassin :public Person
{
public:
	int stealthStat;
	int clientIdx;
	Assassin(int id, const char* name, int age, int stealthS, int clientIndx);
};

class WarriorLord :public Noble, public Knight
{
	int strategyStat;
public:
	WarriorLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId, int stratStat, bool shieldB);
};

class WarShip :public Transport, public SiegeEngine
{
public:
	WarShip(int id, const char* n, int hullHp, int weaponHp, int armor, float maintCost, int troopC, float knotS, int siegeD, int speed);
	void takeHullDamage(int d);
	void takeWeaponDamage(int d);
};
