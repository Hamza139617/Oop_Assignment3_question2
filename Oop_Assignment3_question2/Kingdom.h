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
class Warship;
class WarriorLord;
class Sage;



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
	Warship** warship;
	WarriorLord** warriorLord;

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
	
	Kingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain );

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
	Warship** warship;
	WarriorLord** warriorLord;

	Sage** sage;

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


public:
	Aethelgard(const char* filename);




};

