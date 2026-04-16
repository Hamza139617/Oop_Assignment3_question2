#pragma once

class Entity
{
public:
	int id;
	char* name;
	Entity(int id, const char* name)
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
	~Entity()
	{
		delete[] name;
	}
};

class Person :public Entity
{
public:
	int age;
	bool isAlive;
	Person(int id, const char* name, int age) :Entity(id, name)
	{
		this->age = age;
		isAlive = true;
	}
};

class Asset :public Entity
{
public:
	int hp;
	int maxHp;
	int armor;
	float maintenanceCost;
	Asset(int id, const char* name, int hp, int armor, float maintenanceCost) :Entity(id, name)
	{
		this->hp = hp;
		this->armor = armor;
		this->maintenanceCost = maintenanceCost;
		this->maxHp = hp;
	}
};

class MilitaryUnit :public Asset
{
public:
	int attackPower;
	MilitaryUnit(int id, const char* name, int hp, int armor, float maintenanceCost, int attackPower) :Asset(id, name, hp, armor, maintenanceCost)
	{
		this->attackPower = attackPower;
	}
};

class MeleeUnit :public MilitaryUnit
{
public:
	bool isFrontLine;
	MeleeUnit(int id, const char* name, int hp, int armor, float maintenanceCost, int attackPower, bool isFrontLine) :MilitaryUnit(id, name, hp, armor, maintenanceCost, attackPower)
	{
		this->isFrontLine = isFrontLine;
	}
};

class FootSoldier :public MeleeUnit
{
public:
	FootSoldier(int id, const char* n, int hp, int ar, float mC, int aP) :MeleeUnit(id, n, hp, ar, mC, aP, true)
	{

	}
};

class Knight :public MeleeUnit
{
public:
	bool shieldBlock;
	Knight(int id, const char* n, int hp, int ar, float mC, int aP, bool sB) :MeleeUnit(id, n, hp, ar, mC, aP, true)
	{
		shieldBlock = sB;
	}
};

class MountedUnit :public MilitaryUnit
{
public:
	float chargeMultiplier;
	float terrainPenalty;
	MountedUnit(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP) :MilitaryUnit(id, n, hp, ar, mC, aP)
	{
		chargeMultiplier = cM;
		terrainPenalty = tP;
	}
};

class Cavalry :public MountedUnit
{
public:
	Cavalry(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP) :MountedUnit(id, n, hp, ar, mC, aP, cM, tP)
	{

	}

};

class  SiegeEngine :public Asset
{
public:
	int siegeDamage;
	int speed;
	SiegeEngine(int id, const char* n, int hp, int ar, float mC, int sd, int s) :Asset(id, n, hp, ar, mC)
	{
		siegeDamage = sd;
		speed = s;
	}
};

class BatteringRam :public SiegeEngine
{
public:
	BatteringRam(int id, const char* n, int hp, int armor, float mc, int sd, int s) :SiegeEngine(id, n, hp, armor, mc, sd, s)
	{

	}
};

class Catapult :public SiegeEngine
{
public:
	int aoeDamage;
	int aoeTargets;
	Catapult(int id, const char* n, int hp, int armor, float mc, int sd, int s, int aoed, int aoet) :SiegeEngine(id, n, hp, armor, mc, sd, s)
	{
		aoeDamage = aoed;
		aoeTargets = aoet;
	}

};

class Transport :public Asset
{
public:
	int troopCapacity;
	float knotsSpeed;
	Transport(int id, const char* n, int hp, int ar, float mc, int tCap, float knotS) :Asset(id, n, hp, ar, mc)
	{
		troopCapacity = tCap;
		knotsSpeed = knotS;
	}
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
	Noble(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId) :Person(id, name, age)
	{
		realmIdx = reIdx;
		ambitionStat = amStat;
		diplomacyStat = dipStat;
		fatherId = faId;
		healthMeter = 0.0f;
		childrenIds = nullptr;
		childCount = 0;
	}
	~Noble()
	{
		delete[] childrenIds;
	}
};

class LandedLord :public Noble
{
public:
	int strategyStat;
	LandedLord(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId, int stratStat) : Noble(id, name, age, reIdx, amStat, dipStat, faId)
	{
		this->strategyStat = stratStat;
	}

};

class LandlessLord :public Noble
{
public:
	float assassinationPlotProgress;
	LandlessLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId) :Noble(id, name, age, realmIndx, ambS, dipS, faId)
	{
		assassinationPlotProgress = 0.0f;
	}
};

class Sage :public Person
{
public:
	int healingPower;
	int wisdom;
	Sage(int id, const char* name, int age, int healP, int wise) :Person(id, name, age)
	{
		healingPower = healP;
		wisdom = wise;
	}
};

class Assassin :public Person
{
public:
	int stealthStat;
	int clientIdx;
	Assassin(int id, const char* name, int age, int stealthS, int clientIndx) :Person(id, name, age)
	{
		stealthStat = stealthS;
		clientIdx = clientIndx;
	}
};

class WarriorLord :public Noble, public Knight
{
	int strategyStat;
public:
	WarriorLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId, int stratStat, bool shieldB) :Noble(id, name, age, realmIndx, ambS, dipS, faId), Knight(id, name, 100, 0, 0.0f, 60, shieldB)
	{
		strategyStat = stratStat;
	}
};

class WarShip :public Transport, public SiegeEngine
{
public:
	WarShip(int id, const char* n, int hullHp, int weaponHp, int armor, float maintCost, int troopC, float knotS, int siegeD, int speed) :Transport(id, n, hullHp, armor, maintCost, troopC, knotS), SiegeEngine(id, n, weaponHp, armor, maintCost, siegeD, speed)
	{

	}
	void takeHullDamage(int d)
	{
		Transport::hp -= d;
	}
	void takeWeaponDamage(int d)
	{
		SiegeEngine::hp -= d;
	}
};
