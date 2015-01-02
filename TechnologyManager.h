#ifndef TECHNOLOGY_MANAGER_H
#define TECHNOLOGY_MANAGER_H

#include "stdafx.h"

class TechnologyManager
{
private:
	set<Technology*> researchedComputerTechs;
	set<Technology*> researchedConstructionTechs;
	set<Technology*> researchedForceFieldTechs;
	set<Technology*> researchedPlanetologyTechs;
	set<Technology*> researchedPropulsionTechs;
	set<Technology*> researchedWeaponTechs;

	set<Technology*> unresearchedComputerTechs;
	set<Technology*> unresearchedConstructionTechs;
	set<Technology*> unresearchedForceFieldTechs;
	set<Technology*> unresearchedPlanetologyTechs;
	set<Technology*> unresearchedPropulsionTechs;
	set<Technology*> unresearchedWeaponTechs;

	int computerPercentage;
	int constructionPercentage;
	int forceFieldPercentage;
	int planetologyPercentage;
	int propulsionPercentage;
	int weaponPercentage;

	int fuelRange;
	int planetRadarRange;
	int fleetRadarRange;
	bool showEnemyETA;
	bool radarExplorePlanets;
	int roboticControls;
	int factoryCost;
	float factoryDiscount;
	float industryWasteRate;
	int industryCleanupPerBC;
	bool hasAtmosphericTerraform;
	bool hasSoilEnrichment;
	bool hasAdvancedSoilEnrichment;
	int maxTerraformPop;
	int terraformCost;
	int cloningCost;
	float missileBaseCost;
	float missileBaseCostInNebula; //No shields in Nebula, so factor in that (unlike MoO 1)
	int highestPlanetaryShield;

	float getFieldInvestmentAmount(TechField::Type whichField, float researchPoints);
	int getChanceForDiscovery(TechField::Type whichField);
	
	int getTotalPercentageExcludingTypeAndLocked(TechField::Type techField);
	void updateValues();

public:
	enum { COST_MODIFIER = 40 };

	set<Technology*>& getResearchedComputerTechs() { return this->researchedComputerTechs; }
	set<Technology*>& getResearchedConstructionTechs () { return this->researchedConstructionTechs; }
	set<Technology*>& getResearchedForceFieldTechs () { return this->researchedForceFieldTechs; }
	set<Technology*>& getResearchedPlanetologyTechs () { return this->researchedPlanetologyTechs; }
	set<Technology*>& getResearchedPropulsionTechs () { return this->researchedPropulsionTechs; }
	set<Technology*>& getResearchedWeaponTechs () { return this->researchedWeaponTechs; }

	set<Technology*>& getUnresearchedComputerTechs () { return this->unresearchedComputerTechs; }
	set<Technology*>& getUnresearchedConstructionTechs () { return this->unresearchedConstructionTechs; }
	set<Technology*>& getUnresearchedForceFieldTechs () { return this->unresearchedForceFieldTechs; }
	set<Technology*>& getUnresearchedPlanetologyTechs () { return this->unresearchedPlanetologyTechs; }
	set<Technology*>& getUnresearchedPropulsionTechs () { return this->unresearchedPropulsionTechs; }
	set<Technology*>& getUnresearchedWeaponTechs () { return this->unresearchedWeaponTechs; }

	Technology* whichComputerBeingResearched;
	Technology* whichConstructionBeingResearched;
	Technology* whichForceFieldBeingResearched;
	Technology* whichPlanetologyBeingResearched;
	Technology* whichPropulsionBeingResearched;
	Technology* whichweaponBeingResearched;

	float computerResearchAmount;
	float constructionResearchAmount;
	float forceFieldResearchAmount;
	float planetologyResearchAmount;
	float propulsionResearchAmount;
	float weaponResearchAmount;

	int getComputerLevel();
	int getConstructionLevel();
	int getForceFieldLevel();
	int getPlanetologyLevel();
	int getPropulsionLevel();
	int getWeaponLevel();

	bool computerLocked;
	bool constructionLocked;
	bool forceFieldLocked;
	bool planetologyLocked;
	bool propulsionLocked;
	bool weaponLocked;

	int getComputerPercentage() { return this->computerPercentage; }
	int getConstructionPercentage() { return this->constructionPercentage; }
	int getForceFieldPercentage() { return this->forceFieldPercentage; }
	int getPlanetologyPercentage() { return this->planetologyPercentage; }
	int getPropulsionPercentage() { return this->propulsionPercentage; }
	int getWeaponPercentage() { return this->weaponPercentage; }

	//1.25 for poor, 1.00 for average, .80 for good, and .60 for excellent
	map<TechField::Type, float> raceModifiers;

	TechnologyManager();
		
	void setComputerTechs(set<Technology*>& techs);
	void setConstructionTechs(set<Technology*>& techs);
	void setForceFieldTechs(set<Technology*>& techs);
	void setPlanetologyTechs(set<Technology*>& techs);
	void setPropulsionTechs(set<Technology*>& techs);
	void setWeaponTechs(set<Technology*>& techs);

	void getFieldLevels(map<TechField::Type, int>& fieldLevels);
	string getFieldProgressString(TechField::Type whichField, float researchPoints);
	void accureResearch(float researchPoints);

	//List<TechField> RollForDiscoveries(Random r, SitRepManager sitRepManager)
		
	void setPercentage(TechField::Type whichField, int amount);

	int getFuelRange() { return this->fuelRange; }
	int getPlanetRadarRange() { return this->planetRadarRange; }
	int getFleetRadarRange() { return this->fleetRadarRange; }
	bool getShowEnemyETA() { return this->showEnemyETA; }
	bool getRadarExplorePlanets() { return this->radarExplorePlanets; }
	int getRoboticControls() { return this->roboticControls; }
	int getFactoryCost() { return this->factoryCost; }
	float getFactoryDiscount() { return this->factoryDiscount; }
	float getIndustryWasteRate() { return this->industryWasteRate; }
	int getIndustryCleanupPerBC() { return this->industryCleanupPerBC; }
	bool getHasAtmosphericTerraform() { return this->hasAtmosphericTerraform; }
	bool getHasSoilEnrichment() { return this->hasSoilEnrichment; }
	bool getHasAdvancedSoilEnrichment() { return this->hasAdvancedSoilEnrichment; }
	int getMaxTerraformPop() { return this->maxTerraformPop; }
	int getTerraformCost() { return this->terraformCost; }
	int getCloningCost() { return this->cloningCost; }
	float getMissileBaseCost() { return this->missileBaseCost; }
	float getMissileBaseCostInNebula() { return this->missileBaseCostInNebula; } //No shields in Nebula, so factor in that (unlike MoO 1)
	int getHighestPlanetaryShield() { return this->highestPlanetaryShield; }

	// TODO save and load logic
};

#endif