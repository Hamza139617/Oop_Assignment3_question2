#include "Kingdom.h"
#include "Entity.h"
#include<iostream>
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
		num = num * 10 + (s[i] - '0');
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
void Kingdom::setWealth(int w)
{
	wealth = w;
}
BatteringRam**& Kingdom::getBram()
{
	return bRam;
}

int Kingdom::getWealth()const { return wealth; }
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
	WarShip** warship = nullptr;
	WarriorLord** warriorLord = nullptr;

	Sage** sage = nullptr;



}

void Kingdom::addLord(LandedLord* l) {

	if (!currentLord) return;

	currentLord = l;
	return;
}

void Kingdom::addlocalLord(LandlessLord* l) {

	if (lordCount < lordMax) {

		localCourtiers[lordCount] = l;
		lordCount++;
		return;

	}
}

void Kingdom::addKnight(Knight* k) {
	if (knightCount < knightMax) {

		knight[knightCount++] = k;
		return;

	}
}

void Kingdom::addCavalry(Cavalry* c) {
	if (cavalryCount < cavalryMax) {
		cavalry[cavalryCount++] = c;
		return;
	}
}

void Kingdom::addFootSoldier(FootSoldier* f) {

	if (soldierCount < soldierMax) {
		soldier[soldierCount++] = f;
		return;
	}

}

void Kingdom::addAssassin(Assassin* a) {

	if (!assassin) return;

	this->assassin = a;

	return;

}

void Kingdom::addSage(Sage* s) {
	if (sageCount < sageMax) {
		sage[sageCount++] = s;
		return;
	}
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

	landedLordMax = 10;
	lordMax = 20;
	warriorMax = 20;

	soldierMax = 9;
	knightMax = 9;
	cavalryMax = 9;
	sageMax = 9;
	assassinMax = 9;
	

	int sageCurrent = 0;
	int soldierCurrent = 0;
	int knightCurrent = 0;
	int cavalryCurrent = 0;

	int landedLordCurrent = 0;
	int lordCurrent = 0;
	int warriorCurrent = 0;
	int assassinCurrent = 0;

	Lord = new LandedLord * [landedLordMax];
	localCourtiers = new LandlessLord * [lordMax];
	warriorLord = new WarriorLord * [warriorMax];

	soldier = new FootSoldier * [soldierMax];
	knight = new Knight * [knightMax];
	cavalry = new Cavalry * [cavalryMax];

	sage = new Sage * [sageMax];
	


	for (int i = 0; i < landedLordMax; i++) {
		Lord[i] = nullptr;
	}

	for (int i = 0; i < lordMax; i++) {
		localCourtiers[i] = nullptr;
	}

	for (int i = 0; i < warriorMax; i++) {
		warriorLord[i] = nullptr;
	}

	for (int i = 0; i < soldierMax; i++) {
		soldier[i] = nullptr;
	}

	for (int i = 0; i < knightMax; i++) {
		knight[i] = nullptr;
	}

	for (int i = 0; i < cavalryMax; i++) {
		cavalry[i] = nullptr;
	}

	for (int i = 0; i < sageMax; i++) {
		sage[i] = nullptr;
	}


	realms = new Kingdom * [realmsMax];
	Relations = new int* [realmsMax];

	for (int i = 0; i < realmsMax; i++)
		Relations[i] = new int[realmsMax];

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

			// the getToken function is basically for getting a specic part of the whole line 

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

			int number;
			static int realmId = 0;

			for (int i = 0; i < 10; i++) {

				for (int j = 0; j < 10; j++) {
					number = strToInt(getToken(line, j));
					Relations[i][j] = number;
				}

			}


		}
		else if (section == 3) {
			// lords section
	
			if (line[0] == 'L') continue;
			int i = 0;

			int lordId = strToInt(getToken(line, i));

			char name[100];

			copyStr(name, getToken(line, i));

			int age = strToInt(getToken(line, i));

			char gender[5];

			copyStr(gender, getToken(line, i));

			char clas[100];

			copyStr(clas, getToken(line, i));

			int rId = strToInt(getToken(line, i));
			int sStat = strToInt(getToken(line, i));
			int aStat = strToInt(getToken(line, i));
			int dstat = strToInt(getToken(line, i));
			int fId = strToInt(getToken(line, i));

			if (strEqual(clas, "LandedLord")) {

				
				Lord[landedLordCurrent] = new LandedLord(lordId, name, age, rId, aStat, dstat, fId, sStat );

				realms[rId]->addLord(Lord[landedLordCurrent]);
				landedLordCurrent++;

			}
			else if (strEqual(clas, "LandlessLord")) {

				// work on the clamp part latter
				localCourtiers[lordCurrent] = new LandlessLord(lordId, name, age, rId, aStat, dstat, fId);
				
				realms[rId]->addlocalLord(localCourtiers[lordCurrent]);
				lordCurrent++;
				

			}
			else if (strEqual(clas, "WarriorLord")) {

				// work on the clamp part latter
				warriorLord[warriorCurrent] = new WarriorLord(lordId, name, age, rId, aStat, dstat, fId, sStat, true);
				
				realms[rId]->addWarrior(warriorLord[warriorCurrent]);

				warriorCurrent++;
			}


		}
		else if (section == 4) {
			// millitary section

			int i = 0;

			if (line[0] == 'R') continue;
			

			int id = strToInt(getToken(line, i));
			char clas[100];
			copyStr(clas, getToken(line, i));
			int count = strToInt(getToken(line, i));
			int bAtt = strToInt(getToken(line, i));
			int bHp = strToInt(getToken(line, i));
			int bSd = strToInt(getToken(line, i));
			int Atarget = strToInt(getToken(line, i));

			if (strEqual(clas, "Knight")) {
				
				knight[knightCurrent] = new Knight(count, knightCurrent, "Unknown", bHp, 20, 20.0, bAtt, true);

				realms[id]->addKnight(knight[knightCurrent++]);

			}
			else if (strEqual(clas, "FootSoldier")) {

				soldier[soldierCurrent] = new FootSoldier(count, soldierCurrent, "Unknown", bHp, 20, 20.0, bAtt);

				realms[id]->addFootSoldier(soldier[soldierCurrent++]);

			}
			else if (strEqual(clas, "Cavalry")) {

				cavalry[cavalryCurrent] = new Cavalry(count,cavalryCurrent, "Unkwown", bHp, 20, 20.0, bAtt, 20.0, 20.0);
				realms[id]->addCavalry(cavalry[cavalryCurrent]);

			}



		}
		else if (section == 5) {
			// seges section

			int i = 0;

			if (line[0] == 'R') continue;

			int rId = strToInt(getToken(line, i));
			char name[100];

			copyStr(name, getToken(line, i));
			int healP = strToInt(getToken(line, i));
			int wisd = strToInt(getToken(line, i));

			sage[sageCurrent] = new Sage(sageCurrent, name, 20, healP, wisd);

			realms[rId]->addSage(sage[sageCurrent++]);

		}
		else if (section == 6) {
			// assassins section

			int i = 0;

			if (line[i] == 'A') continue;

			int aId = strToInt(getToken(line, i));

			char name[100];
			strcpy(name, getToken(line, i));

			int age = strToInt(getToken(line, i));

			int sStat = strToInt(getToken(line, i));
			int cRealm = strToInt(getToken(line, i));

			assassin[assassinCurrent] = new Assassin(assassinCurrent, name, age, sStat, cRealm);

			realms[cRealm]->addAssassin(assassin[assassinCurrent]);
		}
		else if (section == 7) {
			// config section


		}

	}

	file.close();

}
float Aethelgard::totalDamage(int attack, int strategy)
{
	return attack * (1 + strategy / 100.0f);
}

float Aethelgard::applyDamage(float damage, int& unitNum, int unitHp)
{
	float remainingD = damage;

	while (unitNum > 0 && remainingD > 0)
	{
		if (unitHp <= remainingD)
		{
			remainingD -= unitHp;
			unitNum--;
		}
		else
		{
			remainingD = 0;
		}
	}
	return remainingD;
}

void Aethelgard::sageHeal(Kingdom& kingdom, float inFootDmg, int& footNum)
{
	int total = 0;
	for (int i = 0; i < kingdom.getSageCount(); i++)
	{
		total += kingdom.getSage()[i]->getHealingPower();
	}
	int maxRes = (int)(inFootDmg * 0.01f);
	int res = (total < maxRes) ? total : maxRes;
	footNum += res;
}
Catapult**& Kingdom::getCatapult() { return catapult; }
WarShip**& Kingdom::getShip() { return warship; }

float Aethelgard::siegeDmg(Kingdom& kingdom)
{
	float total = 0;
	BatteringRam** ram = kingdom.getBram();
	Catapult** catapult = kingdom.getCatapult();
	WarShip** ship = kingdom.getShip();
	for (int i = 0; i < kingdom.getBramCount(); i++)
	{
		total += ram[i]->getSiegeDamage();
	}

	for (int i = 0; i < kingdom.getCatapultCount(); i++)
	{
		total += catapult[i]->getSiegeDamage();
	}
	for (int i = 0; i < kingdom.getShipCount(); i++)
	{
		total += ship[i]->getSiegeDamage();
	}
	return  total;
}
float Aethelgard::cavDmg(Kingdom& kingdom, int snapCount)
{
	float total = 0;
	Cavalry** cav = kingdom.getCavalry();
	for (int i = 0; i < snapCount; i++)
	{
		total += cav[i]->getAttackPower() * cav[i]->getChargeMultiplier();
	}
	return total;
}

float Aethelgard::kntDmg(Kingdom& kingdom, int snapKnight, int snapWarriorLord)
{
	float total = 0;
	Knight** knt = kingdom.getKnight();
	for (int i = 0; i < snapKnight; i++)
	{
		total += knt[i]->getAttackPower();
	}
	WarriorLord** wl = kingdom.getWarrior();
	for (int i = 0; i < snapWarriorLord; i++)
	{
		total += wl[i]->Knight::getAttackPower();
	}
	return total;

}

float Aethelgard::footDmg(int snapCount, int footAttackPower)
{
	return snapCount * footAttackPower;
}

void Aethelgard::oneHour(int& attackerC, int& attackerK, int& attackerF, int& attackerS, int& defenderC, int& defenderK, int& defenderF, int& defenderS, int atkCHp, int atkKHp, int atkFHp, int defCHp, int defKHp, int defFHp, Kingdom& attacker, Kingdom& defender, int atkStrat, int defStrat)
{
	int saveAttackerC = attackerC;
	int saveAttackerK = attackerK;
	int saveAttackerF = attackerF;
	int saveAttackerS = attackerS;
	int saveAttackerWL = attacker.getWarriorLordCount();

	int saveDefenderC = defenderC;
	int saveDefenderK = defenderK;
	int saveDefenderF = defenderF;
	int saveDefenderS = defenderS;
	int saveDefenderWL = defender.getWarriorLordCount();


	float attackDamageS = siegeDmg(attacker);
	float attackDamageC = cavDmg(attacker, saveAttackerC);
	float attackDamageK = kntDmg(attacker, saveAttackerK, saveAttackerWL);
	float attackDamageF = footDmg(saveAttackerF, 10);

	float defendDamageS = siegeDmg(defender);
	float defendDamageC = cavDmg(defender, saveDefenderC);
	float defendDamageK = kntDmg(defender, saveDefenderK, saveDefenderWL);
	float defendDamageF = footDmg(saveDefenderF, 10);

	float atkStratDmgS = totalDamage(attackDamageS, atkStrat);
	float atkStratDmgC = totalDamage(attackDamageC, atkStrat);
	float atkStratDmgK = totalDamage(attackDamageK, atkStrat);
	float atkStratDmgF = totalDamage(attackDamageF, atkStrat);

	float defStratDmgS = totalDamage(defendDamageS, defStrat);
	float defStratDmgC = totalDamage(defendDamageC, defStrat);
	float defStratDmgK = totalDamage(defendDamageK, defStrat);
	float defStratDmgF = totalDamage(defendDamageF, defStrat);

	float atkCavDmg = atkStratDmgC + atkStratDmgS;
	float defCavDmg = defStratDmgC + defStratDmgS;

	float atkCavSpill = applyDamage(atkCavDmg, defenderC, defCHp);
	float defCavSpill = applyDamage(defCavDmg, attackerC, atkCHp);

	float atkKntDmg = atkStratDmgK + atkCavSpill;
	float defKntDmg = defStratDmgK + defCavSpill;

	float atkKntSpill = applyDamage(atkKntDmg, defenderK, defKHp);
	float defKntSpill = applyDamage(defKntDmg, attackerK, atkKHp);

	float atkFootDmg = atkKntSpill + atkStratDmgF;
	float defFootDmg = defStratDmgF + defKntSpill;

	float atkIncomingFoot = defFootDmg;
	float defIncomingFoot = atkFootDmg;

	applyDamage(atkFootDmg, defenderF, defFHp);
	applyDamage(defFootDmg, attackerF, atkFHp);

	int atkShipLoss = saveAttackerS > 0 ? ((int)(saveAttackerS *0.1) > 1 ? (int)(saveAttackerS *0.1) : 1) : 0;
	int defShipLoss = saveDefenderS > 0 ? ((int)(saveDefenderS *0.1) > 1 ? (int)(saveDefenderS *0.1) : 1) : 0;

	attackerS -= atkShipLoss;
	defenderS -= defShipLoss;

	sageHeal(attacker, atkIncomingFoot, attackerF);
	sageHeal(defender, defIncomingFoot, defenderF);



}
void Kingdom::updateCounts(int c, int k, int f, int s)
{
	cavalryCount = c;
	knightCount = k;
	soldierCount = f;
	shipCount = s;
}
int Kingdom::getRealmId()const { return realmId; }
void Aethelgard::startWar(Kingdom& attacker, Kingdom& defender)
{
	int numAtkC = attacker.getCavalryCount();
	int numAtkK = attacker.getKnightCount();
	int numAtkF = attacker.getSoldierCount();
	int numAtkWL = attacker.getWarriorLordCount();
	int numAtkR = attacker.getBramCount();
	int numAtkS = attacker.getShipCount();

	int numDefC = defender.getCavalryCount();
	int numDefK = defender.getKnightCount();
	int numDefF = defender.getSoldierCount();
	int numDefWL = defender.getWarriorLordCount();
	int numDefR = defender.getBramCount();
	int numDefS = defender.getShipCount();

	int atkCHp = (numAtkC > 0) ? attacker.getCavalry()[0]->getHp() : 0;
	int atkKHp = (numAtkK > 0) ? attacker.getKnight()[0]->getHp() : 0;
	int atkFHp = (numAtkF > 0) ? attacker.getFootsoldier()[0]->getHp() : 0;

	int defCHp = (numDefC > 0) ? defender.getCavalry()[0]->getHp() : 0;
	int defKHp = (numDefK > 0) ? defender.getKnight()[0]->getHp() : 0;
	int defFHp = (numDefF > 0) ? defender.getFootsoldier()[0]->getHp() : 0;

	int atkStrat = (attacker.getCurrentLord() != nullptr) ? attacker.getCurrentLord()->getStrategyStat() : 0;
	int defStrat = (defender.getCurrentLord() != nullptr) ? defender.getCurrentLord()->getStrategyStat() : 0;

	bool end = false;

	for (int i = 1; i <= 24; i++)
	{
		oneHour(numAtkC, numAtkK, numAtkF, numAtkS, numDefC, numDefK, numDefF, numDefS, atkCHp, atkKHp, atkFHp, defCHp, defKHp, defFHp, attacker, defender, atkStrat, defStrat);
		int atkPower = numAtkF * 1 + numAtkC * 5 + numAtkK * 8 + numAtkWL * 10 + numAtkR * 25 + numAtkS * 12;
		int defPower = numDefF * 1 + numDefC * 5 + numDefK * 8 + numDefWL * 10 + numDefR * 25 + numDefS * 12;

		if (atkPower < defPower * 0.5f)
		{
			std::cout << ">>>ROUTED<<<\n";
			Relations[attacker.getRealmId()][defender.getRealmId()] = 0;
			Relations[defender.getRealmId()][attacker.getRealmId()] = 0;
			for (int k = 0; k < 10; k++)
			{
				if (k != attacker.getRealmId() && k != defender.getRealmId())
				{
					Relations[k][attacker.getRealmId()] -= 2;
				}
			}
			end = true;

			attacker.setWealth(attacker.getWealth() * 0.25f);
			break;
		}
		else if (defPower < atkPower * 0.5f)
		{
			std::cout << ">>>CONQUERED<<<" << std::endl;

			Relations[attacker.getRealmId()][defender.getRealmId()] = 0;
			Relations[defender.getRealmId()][attacker.getRealmId()] = -50;
			for (int k = 0; k < 10; k++)
			{
				if (k != attacker.getRealmId() && k != defender.getRealmId())
				{
					Relations[k][attacker.getRealmId()] -= 2;
				}
			}
			defender.setWealth(defender.getWealth() * 0.25f);
			end = true;
			break;
		}


	}
	if (!end)
	{
		std::cout << ">>>STALEMATE<<<" << std::endl;

		Relations[attacker.getRealmId()][defender.getRealmId()] = 0;
		Relations[defender.getRealmId()][attacker.getRealmId()] = 0;

		for (int k = 0; k < 10; k++)
		{
			if (k != attacker.getRealmId() && k != defender.getRealmId())
			{
				Relations[k][attacker.getRealmId()] -= 2;
			}
		}
	}

	attacker.updateCounts(numAtkC, numAtkK, numAtkF,numAtkS);
	defender.updateCounts(numDefC, numDefK, numDefF,numDefS);
}
int TheVoidRift::getThreatLevel()const { return threatLevel; }
void TheVoidRift::incrementThreat()
{
	threatLevel++;
}
void Kingdom::applyCasualties(float  value)
{
	soldierCount = (int)(soldierCount * value);
	cavalryCount = (int)(cavalryCount * value);
	knightCount = (int)(knightCount * value);
	shipCount = (int)(shipCount * value);
	bRamCount = (int)(bRamCount * value);
	warriorLordCount = (int)(warriorLordCount * value);
}

void Aethelgard::phaseVoidRift()
{
	voidRift->incrementThreat();
	if (voidRift->getThreatLevel() >= threatMax)
	{
		int globalPower = 0;
		for (int q = 0; q < 10; q++)
		{
			globalPower += realms[q]->getSoldierCount() * 1 +
				realms[q]->getCavalryCount() * 5 +
				realms[q]->getKnightCount() * 8 +
				realms[q]->getShipCount() * 12 +
				realms[q]->getBramCount() * 25 +
				realms[q]->getWarriorLordCount() * 10;
		}
		int abyssalForce = voidRift->getThreatLevel() * 100;
		if (globalPower >= abyssalForce)
		{
			std::cout << "[ABYSSAL ECLIPSE] Aethelgard survives!\n";
			for (int c = 0; c < 10; c++)
			{
				realms[c]->applyCasualties(0.4f);
			}
		}
		else
		{
			std::cout << "[ABYSSAL ECLIPSE] Aethelgard falls!\n";
			exit(0);
		}
	}
}


void Aethelgard::startWarCaller()
{
	Kingdom* attacker = nullptr;
	Kingdom* defender = nullptr;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (Relations[i][j] <= -80)
			{
				if (realms[i]->getCurrentLord()->getAmbitionStat() > realms[j]->getCurrentLord()->getAmbitionStat())
				{
					attacker = realms[i];
					defender = realms[j];
				}
				else if (realms[i]->getCurrentLord()->getAmbitionStat() < realms[j]->getCurrentLord()->getAmbitionStat())
				{
					attacker = realms[j];
					defender = realms[i];
				}
				else
				{
					if (i < j)
					{
						attacker = realms[i];
						defender = realms[j];
					}
					else
					{
						attacker = realms[j];
						defender = realms[i];
					}
				}
				int atkPower = attacker->getSoldierCount() * 1 + attacker->getCavalryCount() * 5 + attacker->getKnightCount() * 8 + attacker->getWarriorLordCount() * 10 + attacker->getBramCount() * 25 + attacker->getShipCount() * 12;
				if (atkPower == 0)
				{

					Relations[i][j] = 0;
					Relations[j][i] = 0;
				}
				else
				{
					startWar(*attacker, *defender);
				}
			}
		}
	}
}