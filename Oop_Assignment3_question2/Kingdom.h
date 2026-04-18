#pragma once
#include <iostream>
#include <fstream>
using namespace std;
// Forward Declarations

class LandedLord;
class LandlessLord;
class FootSoldier;
class Knight;
class Cavalry;
class BatteringRam;
class Catapult;
class WarShip;
class WarriorLord;
class Sage;
class Assassin;



class Kingdom {

protected:
	int realmId;
	int wealth;
	int defenseStat;
	int baseTaxIncome;
	const char* name;
	const char* terrain;

	LandedLord* currentLord;
	int* heirIds;
	int heirCount;

	LandlessLord** localCourtiers;

	FootSoldier** soldier;
	Knight** knight;
	Cavalry** cavalry;
	BatteringRam** bRam;
	Catapult** catapult;
	WarShip** warship;
	WarriorLord** warriorLord;
	Assassin* assassin;


	Sage** sage;

	int lordMax;
	int soldierMax;
	int knightMax;
	int cavalryMax;
	int bRamMax;
	int catapultMax;
	int shipMax;
	int warriorMax;
	int sageMax;

	int lordCount;
	int soldierCount;
	int knightCount;
	int cavalryCount;
	int bRamCount;
	int catapultCount;
	int shipCount;
	int warriorLordCount;
	int sageCount;

private:


public:

	int& getLordCount() {
		return lordCount;
	}

	int& getSoldierCount() {
		return soldierCount;
	}

	int& getKnightCount() {
		return knightCount;
	}

	int& getCavalryCount() {
		return cavalryCount;
	}
	int getWealth()const;
	int& getBramCount() { return bRamCount; }
	int& getCatapultCount() { return catapultCount; }
	int& getShipCount() { return shipCount; }
	int& getWarriorLordCount() { return warriorLordCount; }
	int& getSageCount() { return sageCount; }
	int getRealmId()const;

	Kingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

	LandedLord*& getCurrentLord() {
		return currentLord;
	}

	LandlessLord**& getLocalLord() {
		return localCourtiers;
	}

	WarriorLord**& getWarrior() {
		return warriorLord;
	}

	FootSoldier**& getFootsoldier() {
		return soldier;
	}

	Knight**& getKnight() {
		return knight;
	}

	Cavalry**& getCavalry() {
		return cavalry;
	}

	Sage**& getSage() {
		return sage;
	}
	BatteringRam**& getBram();
	Catapult**& getCatapult();
	WarShip**& getShip();
	void addLord(LandedLord* l);

	void setWealth(int w);
	void updateCounts(int c, int k, int f, int s);

	void addlocalLord(LandlessLord* l);
	void addKnight(Knight* k);
	void addFootSoldier(FootSoldier* f);
	void addSage(Sage* s);
	void addCavalry(Cavalry* c);
	void addWarrior(WarriorLord* w);
	void addAssassin(Assassin* a);


	void performAction(); // for collecting the tax and aging the subjects

};

class FrostPeaksKingdom: public Kingdom {

private:
	int coldAttritionModifier; // default value 5 

public:
	
	FrostPeaksKingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

	void applyColdWeather();

};

class ThePeaksOfFrost : public FrostPeaksKingdom {

private:
	

public:

	ThePeaksOfFrost(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

};

class VerdantKingdom : public Kingdom {

private:
	int foodSurplusBonus;

public:

	VerdantKingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

	void applyFoodBonus();

};

class TheSkyCitadel : public VerdantKingdom {

private:

public:

	

	TheSkyCitadel(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

};


class TheVerdantExpanse : public VerdantKingdom {

private:

public:

	TheVerdantExpanse(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);


};

class TheCrimsonSands : public VerdantKingdom {

private:

public:
	TheCrimsonSands(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);


};

class TheAzureRiverlands : public VerdantKingdom {

private:

public:
	
	TheAzureRiverlands(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

};

class CoastalKingdom : public Kingdom {

private:
	int navalTradeBonus;
public:

	CoastalKingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

	void applyTradeBonus();

};

class TheSunlandEmpire : public CoastalKingdom {

private:

public:

	TheSunlandEmpire(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

};


class  TheCorsairIsles : public CoastalKingdom {


private:

public:

	TheCorsairIsles(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

};

class TheTempestCoast : public CoastalKingdom {

private:

public:

	TheTempestCoast(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);


};


class TheImperialSeat : public CoastalKingdom {

private:

public:

	TheImperialSeat(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

};

class TheVoidRift : public Kingdom {

private:
	int threatLevel;

public:

	TheVoidRift(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain);

};

class Aethelgard {
	
private:

	Kingdom** realms;
	int realmsMax;
	

	int** Relations;

	LandedLord** Lord;
	
	LandlessLord** localCourtiers;

	FootSoldier** soldier;
	Knight** knight;
	Cavalry** cavalry;
	BatteringRam** bRam;
	Catapult** catapult;
	WarShip** warship;
	WarriorLord** warriorLord;

	Sage** sage;
	Assassin** assassin;

	int landedLordMax;
	int lordMax;
	int soldierMax;
	int knightMax;
	int cavalryMax;
	int bRamMax;
	int catapultMax;
	int shipMax;
	int warriorMax;
	int sageMax;
	int assassinMax;


public:
	Aethelgard(const char* filename);
	float totalDamage(int attack, int strat);
	float applyDamage(float damage, int& unitNum, int unitHp);
	void sageHeal(Kingdom& kingdom, float inFootDmg, int& footNum);
	float siegeDmg(Kingdom& kingdom);
	float cavDmg(Kingdom& kingdom, int snapCount);
	float kntDmg(Kingdom& kingdom, int snapKnight, int snapWarriorLord);
	float footDmg(int snapCount, int footAttackPower);
	void oneHour(int& attackerC, int& attackerK, int& attackerF,int&attackerS, int& defenderC, int& defenderK, int& defenderF,int&defenderS, int atkCHp, int atkKHp, int atkFHp, int defCHp, int defKHp, int defFHp, Kingdom& attacker, Kingdom& defender, int atkStrat, int defStrat);
	void startWarCaller();
	void startWar(Kingdom& attacker, Kingdom& defender);

	// your area mr Usama 
	




























	// hamza area


	void  economicDispatch();
	void aggingMortalityUpdates();
	void geopolitcialDecay();





















	
};

