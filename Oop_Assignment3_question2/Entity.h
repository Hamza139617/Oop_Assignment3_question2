#pragma once

class Entity
{
protected:
	int id;
	const char* name;
public:
	Entity(int id, const char* name);
	//getters
	int getId()const { return id; }
	const char* getName()const { return name; }
};

class Person :public Entity
{
protected:
	int age;
public:
	bool isAlive;
	Person(int id, const char* name, int age);
	int getAge()const { return age; }
};

class Asset :public Entity
{
protected:
	int hp;
	int maxHp;
	int armor;
	float maintenanceCost;
public:
	Asset(int id, const char* name, int hp, int armor, float maintenanceCost);
	int getHp()const { return hp; }
	int getMaxHp()const { return maxHp; }
	int getArmor()const { return armor; }
	int getMaintenanceCost()const { return maintenanceCost; }
};

class MilitaryUnit :public Asset
{
protected:
	int attackPower;
public:
	MilitaryUnit(int id, const char* name, int hp, int armor, float maintenanceCost, int attackPower);
	int getAttackPower()const { return attackPower; }
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
protected:
public:
	bool shieldBlock;
	Knight(int id, const char* n, int hp, int ar, float mC, int aP, bool sB);
};

class MountedUnit :public MilitaryUnit
{
protected:
	float chargeMultiplier;
	float terrainPenalty;
public:
	MountedUnit(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP);
	float getChargeMultiplier()const { return chargeMultiplier; }
	float getTerrainPenalty()const { return terrainPenalty; }
};

class Cavalry :public MountedUnit
{
public:
	Cavalry(int id, const char* n, int hp, int ar, float mC, int aP, float cM, float tP);
};

class  SiegeEngine :public Asset
{
protected:
	int siegeDamage;
	int speed;
public:
	SiegeEngine(int id, const char* n, int hp, int ar, float mC, int sd, int s);
	int getSiegeDamage()const { return siegeDamage; }
	int getSpeed()const { return speed; }
};

class BatteringRam :public SiegeEngine
{
public:
	BatteringRam(int id, const char* n, int hp, int armor, float mc, int sd, int s);
};

class Catapult :public SiegeEngine
{
protected:
	int aoeDamage;
	int aoeTargets;
public:
	Catapult(int id, const char* n, int hp, int armor, float mc, int sd, int s, int aoed, int aoet);
	int getAoeDamage()const { return aoeDamage; }
	int getAoeTargets()const { return aoeTargets; }
};

class Transport :public Asset
{
protected:
	int troopCapacity;
	float knotsSpeed;
public:
	Transport(int id, const char* n, int hp, int ar, float mc, int tCap, float knotS);
	int getTroopCapacity()const { return troopCapacity; }
	float getKnotsSpeed()const { return knotsSpeed; }
};

class Noble :public Person
{
protected:
	int realmIdx;
	int ambitionStat;
	int diplomacyStat;
	float healthMeter;
	int fatherId;
	int* childrenIds;
	int childCount;
public:
	Noble(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId);
	int getRealmIdx()const { return realmIdx; }
	int getAmbitionStat()const { return ambitionStat; }
	int getDiplomacyStat()const { return diplomacyStat; }
	float getHealthMeter()const { return healthMeter; }
	int getFatherId()const { return fatherId; }
	int* getChildrenIds()const { return childrenIds; }
	int getChildCount()const { return childCount; }
};

class LandedLord :public Noble
{
protected:
	int strategyStat;
public:
	LandedLord(int id, const char* name, int age, int reIdx, int amStat, int dipStat, int faId, int stratStat);
	int getStrategyStat()const { return strategyStat; }
};

class LandlessLord :public Noble
{
protected:
	float assassinationPlotProgress;
public:
	LandlessLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId);
	float getAssassinationPlotProgress()const {
		return assassinationPlotProgress;
	}
};

class Sage :public Person
{
protected:
	int healingPower;
	int wisdom;
public:
	Sage(int id, const char* name, int age, int healP, int wise);
	int getHealingPower()const { return healingPower; }
	int getWisodm()const { return wisdom; }
};

class Assassin :public Person
{
protected:
	int stealthStat;
	int clientIdx;
public:
	Assassin(int id, const char* name, int age, int stealthS, int clientIndx);
	int getStealthStat()const { return stealthStat; }
	int getClientIdx()const { return clientIdx; }
};

class WarriorLord :public Noble, public Knight
{
protected:
	int strategyStat;
public:
	WarriorLord(int id, const char* name, int age, int realmIndx, int ambS, int dipS, int faId, int stratStat, bool shieldB);
	int getStrategyStat()const { return strategyStat; }
};

class WarShip :public Transport, public SiegeEngine
{
public:
	WarShip(int id, const char* n, int hullHp, int weaponHp, int armor, float maintCost, int troopC, float knotS, int siegeD, int speed);
	void takeHullDamage(int d);
	void takeWeaponDamage(int d);
};
