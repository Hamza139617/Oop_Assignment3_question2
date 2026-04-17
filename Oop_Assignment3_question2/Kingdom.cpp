#include "Kingdom.h"


// helper functions

int strLength(const char* s) {

	int i = 0; 
	while (s[i] != '\0') i++;
	return i;

}

bool strEqual(const char* a, const char* b) {

	int i = 0;

	while (a[i] != '\0' && b[i] != '\0') {

		if (a[i] != b[i]) return false;
		i++;

	}

	return (a[i] == '\0' && b[i] == '\0');

}

void copyStr(char* dest, const char* src) {
	int i = 0;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int strToInt(const char* s) {
	int i = 0, num = 0, sign = 1;

	if (s[0] == '-') {
		sign = -1;
		i++;
	}

	while (s[i] != '\0') {
		num - num * 10 + (s[i] - '0');
		i++;
	}

	return num * sign;
}

char* getToken(char* line, int& index) {
	static char token[100];

	int j = 0;

	while (line[index] == ' ' || line[index] == ',')
		index++;

	while (line[index] != ',' && line[index] != '\0') {
		token[j++] = line[index++];
	}

	token[j] = '\0';

	if (line[index] == ',') index++;
	return token;
}


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

Aethelgard::Aethelgard(const char* filename) {

	realmsMax = 10;
	realms = new Kingdom * [realmsMax];

	for (int i = 0; i < realmsMax; i++)
		realms[i] = nullptr;

	ifstream file(filename);

	if (!file) {
		cout << "File not found\n";
		return;
	}

	char line[300];
	int section = 0;

	while (file.getline(line, 300)) {

		if (line[0] == '\0') continue;

		if (strEqual(line, "[KINGDOMS]")) {
			section = 1;
			continue;
		}
		else if (strEqual(line, "[RELATIONS]")) {
			section = 2;
			continue;
		}
		else if (strEqual(line, "[LORDS]")) {
			section = 3;
			continue;
		}
		else if (strEqual(line, "[MILITARY]")) {
			section = 4;
			continue;
		}
		else if (strEqual(line, "[SAGES]")) {
			section = 5;
			continue;
		}
		else if (strEqual(line, "[ASSASSINS]")) {
			section = 6;
			continue;
		}
		else if (strEqual(line, "[CONFIG]")) {
			section = 7;
			continue;
		}

		if (line[0] == '#') continue;

		if (section == 1) {

			if (line[0] == 'R') continue;
			int i = 0;

			int id = strToInt(getToken(line, i));

			char name[100];
			copyStr(name, getToken(line, i));
			int wealth = strToInt(getToken(line, i));
			int tax = strToInt(getToken(line, i));
			int defense = strToInt(getToken(line, i));

			char terrain[50];
			copyStr(terrain, getToken(line, i));

			char* nameCopy = new char[strLength(name) + 1];
			copyStr(nameCopy, name);

			char* terrainCopy = new char[strLength(terrain) + 1];
			copyStr(terrainCopy, terrain);

			if (id == 0)
				realms[id] = new TheSunlandEmpire(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 1)
				realms[id] = new ThePeaksOfFrost(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 2)
				realms[id] = new TheSkyCitadel(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 3)
				realms[id] = new TheCorsairIsles(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 4)
				realms[id] = new TheVerdantExpanse(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 5)
				realms[id] = new TheCrimsonSands(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 6)
				realms[id] = new TheTempestCoast(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 7)
				realms[id] = new TheAzureRiverlands(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 8)
				realms[id] = new TheImperialSeat(id, wealth, defense, tax, nameCopy, terrainCopy);
			else if(id == 9)
				realms[id] = new TheVoidRift(id, wealth, defense, tax, nameCopy, terrainCopy);


		}
		else if (section == 2) {
			// realtions section


		}
		else if (section == 3) {
			// lords section
		}
		else if (section == 4) {
			// footsoldier section
		}
		else if (section == 5) {
			// seges section
		}
		else if (section == 6) {
			// assassins section
		}
		else if (section == 7) {
			// config section
		}

	}

	file.close();

}