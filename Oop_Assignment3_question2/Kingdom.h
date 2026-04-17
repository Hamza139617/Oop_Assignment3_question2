#pragma once

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
	int wealth;
	float defenseStat;


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

	int lordCount;
	int soldierCount;
	int knightCount;
	int cavalryCount;
	int bRamCount;
	int catapultCount;
	int warshipCount;
	int warriorLordCount;
	int sageCount;

private:


public:
	Kingdom();
	Kingdom(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

	void performAction(); // for collecting the tax and aging the subjects

};

class FrostPeaksKingdom: public Kingdom {

private:
	int coldAttritionModifier; // default value 5 

public:
	FrostPeaksKingdom();

	FrostPeaksKingdom(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

	void applyColdWeather();

};

class ThePeaksOfFrost : public FrostPeaksKingdom {

private:
	

public:

	ThePeaksOfFrost();

	ThePeaksOfFrost(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

};

class VerdantKingdom : public Kingdom {

private:
	int foodSurplusBonus;

public:

	VerdantKingdom();

	VerdantKingdom(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

	void applyFoodBonus();

};

class TheSkyCitadel : public VerdantKingdom {

private:

public:

	TheSkyCitadel();

	TheSkyCitadel(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

};


class TheVerdantExpanse : public VerdantKingdom {

private:

public:
	TheVerdantExpanse();

	TheVerdantExpanse(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);


};

class TheCrimsonSands : public VerdantKingdom {

private:

public:

	TheCrimsonSands();

	TheCrimsonSands(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);


};

class TheAzureRiverlands : public VerdantKingdom {

private:

public:
	TheAzureRiverlands();

	TheAzureRiverlands(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

};

class CoastalKingdom : public Kingdom {

private:
	int navalTradeBonus;
public:

	CoastalKingdom();

	CoastalKingdom(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

	void applyTradeBonus();

};

class TheSunlandEmpire : public CoastalKingdom {

private:

public:
	
	TheSunlandEmpire();

	TheSunlandEmpire(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

};


class  TheCorsairIsles : public CoastalKingdom {


private:

public:

	TheCorsairIsles();

	TheCorsairIsles(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

};

class TheTempestCoast : public CoastalKingdom {

private:

public:

	TheTempestCoast();

	TheTempestCoast(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);


};


class TheImperialSeat : public CoastalKingdom {

private:

public:
	TheImperialSeat();

	TheImperialSeat(int, float, LandedLord, LandlessLord*, FootSoldier*, Knight*, Cavalry*, BatteringRam*, Catapult*, Warship*, WarriorLord*, Sage*);

};

// will be working on the unique realms later 

