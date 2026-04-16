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
	LandlessLord** localCourtiers;

	FootSoldier** soldier;
	Knight** knight;
	Cavalry** cavalry;
	BatteringRam** bRam;
	Catapult** catapult;
	Warship** warship;
	WarriorLord** warriorLord;

	Sage** sage;

private:


public:


};

class FrostPeaksKingdom: public Kingdom {

private:
	int coldAttritionModifier; // default value 5 

public:
	void applyColdWeather();

};

class ThePeaksOfFrost : public FrostPeaksKingdom {

private:
	

public:
	

};

class VerdantKingdom : public Kingdom {

private:
	int foodSurplusBonus;

public:
	void applyFoodBonus();

};

class TheSkyCitadel : public VerdantKingdom {

private:

public:
};


class TheVerdantExpanse : public VerdantKingdom {

private:

public:

};

class TheCrimsonSands : public VerdantKingdom {

private:

public:


};

class TheAzureRiverlands : public VerdantKingdom {

private:

public:


};

class CoastalKingdom : public Kingdom {

private:
	int navalTradeBonus;
public:
	void applyTradeBonus();

};

class TheSunlandEmpire : public CoastalKingdom {

private:

public:


};


class  TheCorsairIsles : public CoastalKingdom {


private:

public:


};

class TheTempestCoast : public CoastalKingdom {

private:

public:


};


class TheImperialSeat : public CoastalKingdom {

private:

public:


};

// will be working on the unique realms later 

