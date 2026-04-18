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




void Aethelgard::shadowTriggers() {

	// tensionsAccumulator

	for (int i = 0; i < realmsMax - 1; i++) {

		if (realms[i]->getCivilWar() < 100.0) {

			

			if (!realms[i]->getCurrentLord()) {
				realms[i]->setCivilTension(realms[i]->getCivilWar() + 30.0);
			}

			if (realms[i]->getWealth() < 0) {
				realms[i]->setCivilWarTension(realms[i]->getCivilWar() + 5.0);
			}

			// if a specific landless lord in the realm is having high ambitions then
			// then increase the civil war tension for any of them
			// having ambitions larger than 50 and break;

			for (int j = 0; j < realms[i]->getLordCount(); j++) {

				if (realms[i]->getLocalLord()[j]->getAmbitionStat() > 50) {
					realms[i]->setCivilTension((realms[i]->getLocalLord()[j]->getAmbitionStat() / 10.0));
					break;
				}

			}

			if (realms[i]->getCurrentLord()->getStrategyStat() > 70) {
				realms[i]->setCivilTension(realms[i]->getCivilWar() - 3.0);
			}

			if (realms[i]->getCavalryCount() + realms[i]->getSoldierCount() + realms[i]->getKnightCount() > 200) {
				realms[i]->setCivilTension(realms[i]->getCivilTension() - 1.0);
			}

		}
		else {

			// if the tension in the country is more than the threshold then the rebellion is going to occur 



		}
		

		// assassination mechanics (the internal coupt )

		for (int j = 0; j < realms[i]->getLordCount(); j++) {

			LandlessLord* l = realms[i]->getLocalLord()[j];

			if (l->getAmbitionStat() > 60.0) {

				l->setPlotProgress(l->getAmbitionStat() + (l->getAmbitionStat() - 60) / 5.0);

				bool checkRelations = false;

			}

		}


	}

}



