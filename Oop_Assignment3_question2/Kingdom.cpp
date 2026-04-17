#include "Kingdom.h"

Kingdom::Kingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): name(nameOne), terrain(terrain) {

	this->realmId = realmId;
	this->wealth = wealth;
	this->defenseStat = defenseStat;
	this->baseTaxIncome = baseTaxInocome;


	 lordMax = 20;
	 soldierMax = 20;
	 knightMax = 20;
	 cavalryMax = 20;
	 bRamMax = 20;
	 catapultMax = 20;
	 shipMax = 20;
	 warriorMax = 20;
	 sageMax = 20;

	 lordCount = 0;
	 soldierCount = 0;
	 knightCount = 0;
	 cavalryCount = 0;
	 bRamCount = 0;
	 catapultCount = 0;
	 shipCount = 0;
	 warriorLordCount = 0;
	 sageCount = 0;

	LandedLord* currentLord = nullptr;
	int* heirIds = nullptr;
	int heirCount = 0;
	int heirMax = 20;

	LandlessLord** localCourtiers = nullptr;

	FootSoldier** soldier = nullptr;
	Knight** knight = nullptr;
	Cavalry** cavalry = nullptr;
	BatteringRam** bRam = nullptr;
	Catapult** catapult = nullptr;
	Warship** warship = nullptr;
	WarriorLord** warriorLord = nullptr;

	Sage** sage = nullptr;



}



FrostPeaksKingdom::FrostPeaksKingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain) : Kingdom( realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {
	coldAttritionModifier = 5;
}

ThePeaksOfFrost::ThePeaksOfFrost(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain) : FrostPeaksKingdom( realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

VerdantKingdom::VerdantKingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): Kingdom( realmId, wealth, defenseStat, baseTaxInocome, nameOne,  terrain)  {}

TheSkyCitadel::TheSkyCitadel(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain) : VerdantKingdom( realmId, wealth, defenseStat, baseTaxInocome, nameOne,  terrain) {}

TheVerdantExpanse::TheVerdantExpanse(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): VerdantKingdom( realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

TheCrimsonSands::TheCrimsonSands(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain) : VerdantKingdom(realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

TheAzureRiverlands::TheAzureRiverlands(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): VerdantKingdom(realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

CoastalKingdom::CoastalKingdom(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): Kingdom(realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

TheSunlandEmpire::TheSunlandEmpire(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): CoastalKingdom( realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

TheCorsairIsles::TheCorsairIsles(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): CoastalKingdom(realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

TheTempestCoast::TheTempestCoast(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): CoastalKingdom(realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

TheImperialSeat::TheImperialSeat(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): CoastalKingdom(realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}


TheVoidRift::TheVoidRift(int realmId, int wealth, int defenseStat, int baseTaxInocome, const char* nameOne, const char* terrain): Kingdom(realmId, wealth, defenseStat, baseTaxInocome, nameOne, terrain) {}

