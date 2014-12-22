#ifndef PLANET_H
#define PLANET_H

#include "stdafx.h"

struct PlanetType
{
	enum Type { TERRAN = 0, JUNGLE, OCEAN, BADLAND, STEPPE, DESERT, ARCTIC, BARREN, TUNDRA, DEAD, VOLCANIC, TOXIC, RADIATED, NONE };
};
struct OutputType
{
	enum Type { RESEARCH, DEFENSE, INFRASTRUCTURE, ENVIRONMENT, CONSTRUCTION };
};
struct PlanetConstructionBonus
{
	enum Type { ULTRAPOOR, POOR, AVERAGE, RICH, ULTRARICH };
};
struct PlanetEnvironmentBonus
{
	enum Type { HOSTILE, AVERAGE, FERTILE, GAIA };
};
struct PlanetResearchBonus
{
	enum Type { AVERAGE, ARTIFACTS, BEYAAN };
};
struct PlanetAsteroidDensity
{
	enum Type { NONE, LOW, HIGH };
};

using namespace std;

class StarSystem;
class Empire;

class Planet
{
private:
	static const string NONE;
	static const string RADIATED;
	static const string TOXIC;
	static const string VOLCANIC;
	static const string DEAD;
	static const string TUNDRA;
	static const string BARREN;
	static const string ARCTIC;
	static const string DESERT;
	static const string STEPPE;
	static const string BADLANDS;
	static const string OCEANIC;
	static const string JUNGLE;
	static const string TERRAN;

	StarSystem *whichSystem;
	PlanetType::Type planetType;
	string planetTypeString;
	Empire *owner;
	int ownerID;
	string name;

	float factoryInvestments; //Amount of BCs spent to determine if we need to refit or not
	float baseInvestments; //Amount of BCs spent to determine if we need to upgrade or not
	float shieldProjectRevenues;
	float terraformProjectRevenues;
	float terraformPop;
	int populationMax;
	float population;
	//Ship *shipBeingBuilt; //TODO: Add ship when it's implemented
	//TravelNode *relocateToSystem; //TODO: Add relocateToSystem and TransferSystem when they're implemented
	//TravelNode *transferSystem;
	//int amountToTransfer;

	float waste;
	float factories;
	int bases;
	float nextBaseInvestment;
	int shieldLevel;
	float reserves;

	float shipConstructionAmount;
	float amountLostToRefitThisTurn;
	float amountOfBuildingsThisTurn;
	float amountOfBCGeneratedThisTurn;
	float amountOfRPGeneratedThisTurn;
	float amountOfWasteCleanupNeeded;
	float terraformProjectInvestment;
	float extraPopulationCloned;
	float amountLostToUpgradeThisTurn;
	float amountOfBaseInvestmentThisTurn;
	float amountToInvestInShield;

	PlanetConstructionBonus::Type constructionBonus;
	PlanetEnvironmentBonus::Type environmentBonus;
	PlanetResearchBonus::Type researchBonus;
	PlanetAsteroidDensity::Type asteroidDensity;

	int researchAmount;
	int defenseAmount;
	int infrastructureAmount;
	int environmentAmount;
	int constructionAmount;

	bool infrastructureLocked;
	bool environmentLocked;
	bool researchLocked;
	bool defenseLocked;
	bool constructionLocked;

	void setValues(string name, string type, int maxPop, StarSystem system, Empire empire);
	int getPointsExcludingSelectedTypeAndLockedTypes(OutputType::Type type);
	float calculateRaceGrowth(Race race);
public:
	StarSystem* getStarSystem() { return this->whichSystem; };
	PlanetType::Type getPlanetType() { return this->planetType; };
	string getPlanetTypeString() { return this->planetTypeString; };
	string getName() { return this->name; };
	int getOwnerID() { return this->ownerID; };
	float getWaste() { return this->waste; };
	int getPopulationMax() { return this->populationMax; };
	//Ship* getShipBeingBuilt() { return this->shipBeingBuilt; }; //TODO: Add ship when it's implemented
	//TravelNode* getRelocateToSystem() { return this->relocateToSystem; }; //TODO: Add relocateToSystem and TransferSystem when they're implemented
	//TravelNode* getTransferSystem() { return this->transferSystem; };
	//int getTransferAmount() { return this->transferAmount; };

	int getColonyRequirement();
	float getTotalPopulation();
	float getTotalMaxPopulation();
	float getShipConstructionLength();

	float getShipConstructionAmount() { return this->shipConstructionAmount; };
	float getAmountLostToRefitThisTurn() { return this->amountLostToRefitThisTurn; };
	float getAmountOfBuildingsThisTurn() { return this->amountOfBuildingsThisTurn; };
	float getAmountOfBCGeneratedThisTurn() { return this->amountOfBCGeneratedThisTurn; };
	float getAmountOfRPGeneratedThisTurn() { return this->amountOfRPGeneratedThisTurn; };
	float getAmountOfWasteCleanupNeeded() { return this->amountOfWasteCleanupNeeded; };
	float getTerraformProjectInvestment() { return this->terraformProjectInvestment; };
	float getExtraPopulationCloned() { return this->extraPopulationCloned; };
	float getAmountLostToUpgradeThisTurn() { return this->amountLostToUpgradeThisTurn; };
	float getAmountOfBaseInvestmentThisTurn() { return this->amountOfBaseInvestmentThisTurn; };
	float getAmountToInvestInShield() { return this->amountToInvestInShield; };

	string getInfrastructureStringOutput();
	string getResearchStringOutput();
	string getDefenseStringOutput();
	string getEnvironmentStringOutput();
	string getConstructionStringOutput();

	int getResearchAmount() { return this->researchAmount; };
	int getDefenseAmount() { return this->defenseAmount; };
	int getInfrastructureAmount() { return this->infrastructureAmount; };
	int getEnvironmentAmount() { return this->environmentAmount; };
	int getConstructionAmount() { return this->constructionAmount; };

	bool getInfrastructureLocked() { return this->infrastructureLocked; };
	bool getEnvironmentLocked() { return this->environmentLocked; };
	bool getResearchLocked() { return this->researchLocked; };
	bool getDefenseLocked() { return this->defenseLocked; };
	bool getConstructionLocked() { return this->constructionLocked; };

	Planet(string name, string type, int maxPop, Empire owner, StarSystem system);
	Planet(string name, StarSystem system);

	void setHomeworld(Empire owner);

	void setOutputAmount(OutputType::Type outputType, int amount, bool forceChange);
	void setCleanup();
	void updatePlanet();
	//Ship checkIfShipBuilt(int& amount);
	void updateOutputs(); //After the Empire class updates the planet's production, this is called to update values
	float getRacePopulation(Race whichRace);
	void addRacePopulation(Race whichRace, float amount);
	void removeRacePopulation(Race whichRace, float amount);
	void removeRace(Race whichRace);
	void colonize(Empire whichEmpire);
};

#endif