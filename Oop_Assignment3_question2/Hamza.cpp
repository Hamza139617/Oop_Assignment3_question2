#include "Entity.h"
#include "Kingdom.h"
#include <iostream>


void Aethelgard::economicDispatch() {
	
	for (int i = 0; i < realmsMax; i++) {

		// calling the specific functions over here

		if (realms[i]->getKingdomName() == "FrostPeaksKingdom") {
			realms[i]->applyColdWeather();
		}
		else if (realms[i]->getKingdomName() == "VerdantKingdom") {
			realms[i]->applyFoodBonus();
		}
		else if (realms[i]->getKingdomName() == "CoastalKingdom") {
			realms[i]->applyTradeBonus();
		}

		// calling the common functions over here

		if (realms[i]->getWealth() < 0) {

			realms[i]->setWealth(0);
			realms[i]->getFootsoldier()->takeCasualty();

		}
		else {
			int wealth = realms[i]->getWealth() + realms[i]->getBaseTaxIncome() - realms[i]->SUM();
			realms[i]->setWealth(wealth);
		}

	}
}


// agging and mortality updates

void Aethelgard::aggingMortalityUpdates() {

	// this is for the agging and mortality for only the landed lords
	for (int i = 0; i < realmsMax - 1; i++) {

		LandedLord* l = realms[i]->getCurrentLord();

		if (l->getAge() > 70) l->getHealthMeter(l->getHealthMeter() + 30.0);

		if (l->getAge() >= 100.0) l->kill();

		l->setAge(l->getAge() + 1);

	}

}

void Aethelgard::geopolitcialDecay() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			
			if (i != j) {
				
				if (Relations[i][j] > -100) {
					Relations[i][j] -= 1;
				}

			}

		}
	}

}


