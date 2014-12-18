#ifndef PLANET_H
#define PLANET_H

#include "stdafx.h"

enum class PLANET_TYPE { TERRAN = 0, JUNGLE, OCEAN, BADLAND, STEPPE, DESERT, ARCTIC, BARREN, TUNDRA, DEAD, VOLCANIC, TOXIC, RADIATED, NONE };
enum class OUTPUT_TYPE { RESEARCH, DEFENSE, INFRASTRUCTURE, ENVIRONMENT, CONSTRUCTION };
enum class PLANET_CONSTRUCTION_BONUS { ULTRAPOOR, POOR, AVERAGE, RICH, ULTRARICH };
enum class PLANET_ENVIRONMENT_BONUS { HOSTILE, AVERAGE, FERTILE, GAIA };
enum class PLANET_RESEARCH_BONUS { AVERAGE, ARTIFACTS, BEYAAN };
enum class PLANET_ASTEROID_DENSITY { NONE, LOW, HIGH };

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
	PLANET_TYPE planetType;
	string planetTypeString;
	Empire *owner;
	string name;

	float factoryInvestments; //Amount of BCs spent to determine if we need to refit or not
	float baseInvestments; //Amount of BCs spent to determine if we need to upgrade or not
	float shieldProjectRevenues;
	float terraformProjectRevenues;
	float terraformPop;
	int populationMax;
	float population;
	//Ship *shipBeingBuilt; //TODO: Add ship when it's implemented
public:

};

#endif