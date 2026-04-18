#include "Entity.h"
#include "Kingdom.h"
#include <iostream>


void Aethelgard::economicDispatch() {
	
	for (int i = 0; i < realmsMax; i++) {

		// calling the specific functions over here

		if (realms[i]->getKingdomName() == "FrostPeaksKingdom") {
			FrostPeaksKingdom* realms2 = (FrostPeaksKingdom*)realms[i];
			realms2->applyColdWeather();
		}
		else if (realms[i]->getKingdomName() == "VerdantKingdom") {
			VerdantKingdom* realms2 = (VerdantKingdom*)realms[i];
			realms2->applyFoodBonus();
		}
		else if (realms[i]->getKingdomName() == "CoastalKingdom") {
			CoastalKingdom* realms2 = (CoastalKingdom*)realms[i];
			realms2->applyTradeBonus();
		}

		// calling the common functions over here

		if (realms[i]->getWealth() < 0) {

			realms[i]->setWealth(0);
			for (int j = 0; j < realms[i]->getSoldierCount(); j++) {
				realms[i]->getFootsoldier()[j]->takeCasualty();

			}

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

		if (l->getAge() > 70) l->setHealthMeter(l->getHealthMeter() + 30.0);

		if (l->getAge() >= 100.0) realms[i]->killLandedLord();

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
				realms[i]->setCivilWarTension(realms[i]->getCivilWar() + 30.0);
			}

			if (realms[i]->getWealth() < 0) {
				realms[i]->setCivilWarTension(realms[i]->getCivilWar() + 5.0);
			}

			// if a specific landless lord in the realm is having high ambitions then
			// then increase the civil war tension for any of them
			// having ambitions larger than 50 and break;

			for (int j = 0; j < realms[i]->getLordCount(); j++) {

				if (realms[i]->getLocalLord()[j]->getAmbitionStat() > 50) {
					realms[i]->setCivilWarTension((realms[i]->getLocalLord()[j]->getAmbitionStat() / 10.0));
					break;
				}

			}

			if (realms[i]->getCurrentLord()->getStrategyStat() > 70) {
				realms[i]->setCivilWarTension(realms[i]->getCivilWar() - 3.0);
			}

			if (realms[i]->getCavalryCount() + realms[i]->getSoldierCount() + realms[i]->getKnightCount() > 200) {
				realms[i]->setCivilWarTension(realms[i]->getCivilWar() - 1.0);
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

				for (int s = 0; s < 8; s++) {
					
					if (Relations[i][s] < 0) {
						l->setPlotProgress(l->getAssassinationPlotProgress() + 2);
						break;
					}

				}

				if (realms[i]->getCurrentLord()->getStrategyStat() > 50) l->setPlotProgress(l->getAssassinationPlotProgress() - (realms[i]->getCurrentLord()->getStrategyStat() / 25.0));

				if (realms[i]->getDefenseStat() > 50) l->setPlotProgress(l->getAssassinationPlotProgress() - 1);


				if (l->getAssassinationPlotProgress() < 0) l->setPlotProgress(0);



			}

			if (l->getAssassinationPlotProgress() > 100.0) {
				
				int ageModifier = (realms[i]->getCurrentLord()->getAge() < 40 ? +5 : -5);

				int aPower = l->getAmbitionStat() + (realms[i]->getWealth() / 100);
				int target = realms[i]->getCurrentLord()->getStrategyStat() + (realms[i]->getDefenseStat() / 10) + ageModifier;

				if (aPower > target) {
					// terminate the lord
				}
				else {
					// terminate the plotter
				}

			}

		}



		for (int t = 0; t < assassinMax; t++) {
			if (realms[i]->getRealmId() == assassin[t]->getClientIdx()) { // check if it is the client of any assassin

				for (int k = 0; k < realms[i]->getLordCount(); k++) { // check if the plot is larger then 100

					LandlessLord* l = realms[i]->getLocalLord()[k];

					if (l->getAssassinationPlotProgress() > 100.0) {

						bool checkCrelations = false;
						int worstRelations = Relations[i][0];
						int rival = 0;
						for (int relat = 0; relat < 9; relat++) {

							if (worstRelations < Relations[i][relat]) {
								rival = relat;
								worstRelations = Relations[i][relat];
							}
						}

						if (worstRelations <= -50) {

							LandedLord* targetLord = realms[rival]->getCurrentLord();

							if (targetLord) {

								if (targetLord->getStrategyStat() < assassin[t]->getStealthStat()) {
									// kil target
								}
								else {
									Relations[rival][i] -= 20;
								}

								// finish the assassin
							}

						}

					}

				}

			}
		}

	}


}



