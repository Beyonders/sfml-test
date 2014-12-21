#ifndef TECHNOLOGY_H
#define TECHNOLOGY_H

#include <string>

using namespace std;

struct TechField
{
	enum Type 
	{ 
		COMPUTER, 
		CONSTRUCTION, 
		FORCE_FIELD, 
		PLANETOLOGY, 
		PROPULSION, 
		WEAPON 
	};
};

class Technology
{
private:
	int techLevel;
	TechField::Type techField;
	string techName;
	string techSecondaryName; //Used for technologies that are either armor or weapons with heavy weapon variant
	string techDescription;
	
	int roboticControl;
	int battleComputer;
	int ecm;
	int spaceScanner;
	int armor;
	int industrialTech;
	int industrialWaste;
	int groundArmor;
	int repair;
	int shield;
	int personalShield;
	int planetaryShield;
	int missileShield;
	int ecoCleanup;
	int terraforming;
	int terraformCost;
	int colony;
	int cloning;
	int bioWeapon;
	int bioAntidote;
	int enrichment;
	int speed;
	int maneuverSpeed;
	int fuelRange;

	bool reserveFuelTanks;
	bool battleScanner;
	bool hyperSpaceCommunicator;
	bool oracleInterface;
	bool technologyNullifier;
	bool repulsorBeam;
	bool cloakingDevice;
	bool statisField;
	bool blackHoleGenerator;
	bool inertialStabilizer;
	bool energyPulsar;
	bool warpDissipator;
	bool highEnergyFocus;
	bool stargate;
	bool subspaceTeleporter;
	bool ionicPulsar;
	bool subspaceInterdictor;
	bool combatTransporters;
	bool inertialNullifier;
	bool displacementDevice;
	bool antiMissileRockets;
	bool ionStreamProjector;
	bool neutronStreamProjector;

	//Space/Cost/Power requirements for ship.  Generic means ship's size don't matter
	float smallSize;
	float smallCost;
	float smallPower;
	float smallHP; //Armor points for ship

	float smallSecondarySize; //Used for double hulled armor
	float smallSecondaryCost;
	float smallSecondaryPower;
	float smallSecondaryHP;

	float mediumSize;
	float mediumCost;
	float mediumPower;
	float mediumHP;

	float mediumSecondarySize;
	float mediumSecondaryCost;
	float mediumSecondaryPower;
	float mediumSecondaryHP;

	float largeSize;
	float largeCost;
	float largePower;
	float largeHP;

	float largeSecondarySize;
	float largeSecondaryCost;
	float largeSecondaryPower;
	float largeSecondaryHP;

	float hugeSize;
	float hugeCost;
	float hugePower;
	float hugeHP;

	float hugeSecondarySize;
	float hugeSecondaryCost;
	float hugeSecondaryPower;
	float hugeSecondaryHP;

	float genericSize;
	float genericCost;
	float genericPower;

	float genericSecondarySize; //Used for heavy weapons
	float genericSecondaryCost;
	float genericSecondaryPower;

	int weaponType;
	int minimumWeaponDamage;
	int minimumSecondaryWeaponDamage;
	int maximumWeaponDamage;
	int maximumSecondaryWeaponDamage;
	bool shieldPiercing;
	float weaponRange;
	int secondaryWeaponRange;
	int numberOfShots;
	bool streaming;
	int targetingBonus;
	bool enveloping;
	bool dissipating; //Used only for plasma torpedoes
	float missileSpeed;

public:
	enum
	{
		DEEP_SPACE_SCANNER = 1,
		IMPROVED_SPACE_SCANNER = 2,
		ADVANCED_SPACE_SCANNER = 3,

		TITANIUM_ARMOR = 1,
		DURALLOY_ARMOR = 2,
		ZORTRIUM_ARMOR = 3,
		ANDRIUM_ARMOR = 4,
		TRITANIUM_ARMOR = 5,
		ADAMANTIUM_ARMOR = 6,
		NEUTRONIUM_ARMOR = 7,

		BATTLE_SUITS = 1,
		ARMORED_EXOSKELETON = 2,
		POWERED_ARMOR = 3,

		PERSONAL_DEFLECTOR = 1,
		PERSONAL_ABSORPTION = 2,
		PERSONAL_BARRIER = 3,

		AUTOMATED_REPAIR = 1,
		ADVANCED_REPAIR = 2,

		PLANETARY_V_SHIELD = 5,
		PLANETARY_X_SHIELD = 10,
		PLANETARY_XV_SHIELD = 15,
		PLANETARY_XX_SHIELD = 20,

		ZYRO_SHIELD = 1,
		LIGHTNING_SHIELD = 2,

		STANDARD_COLONY = 1,
		BARREN_COLONY = 2,
		TUNDRA_COLONY = 3,
		DEAD_COLONY = 4,
		VOLCANIC_COLONY = 5,
		TOXIC_COLONY = 6,
		RADIATED_COLONY = 7,

		DEATH_SPORES = 1,
		DOOM_VIRUS = 2,
		BIO_TERMINATOR = 3,

		BIO_TOXIN_ANTIDOTE = 1,
		UNIVERSAL_ANTIDOTE = 2,

		SOIL_ENRICHMENT = 1,
		ADV_SOIL_ENRICHMENT = 2,
		ATMOSPHERIC_TERRAFORMING = 3,

		BEAM_WEAPON = 1,
		BOMB_WEAPON = 2,
		BIOLOGICAL_WEAPON = 3,
		MISSILE_WEAPON = 4,
		TORPEDO_WEAPON = 5,
	};

	int getTechLevel() { return this->techLevel; }
	TechField::Type getTechField() { return this->techField; }
	string getTechName() { return this->techName; }
	string getTechSecondaryName() { return this->techSecondaryName; }
	string getTechDescription() { return this->techDescription; }
	int getResearchPoints()
	{
		return this->techLevel * this->techLevel;
	}

	int getRoboticControl() { return this->roboticControl; }
	int getBattleComputer() { return this->battleComputer; }
	int getEcm() { return this->ecm; }
	int getSpaceScanner() { return this->spaceScanner; }
	int getArmor() { return this->armor; }
	int getIndustrialTech() { return this->industrialTech; }
	int getIndustrialWaste() { return this->industrialWaste; }
	int getGroundArmor() { return this->groundArmor; }
	int getRepair() { return this->repair; }
	int getShield() { return this->shield; }
	int getPersonalShield() { return this->personalShield; }
	int getPlanetaryShield() { return this->planetaryShield; }
	int getMissileShield() { return this->missileShield; }
	int getEcoCleanup() { return this->ecoCleanup; }
	int getTerraforming() { return this->terraforming; }
	int getTerraformCost() { return this->terraformCost; }
	int getColony() { return this->colony; }
	int getCloning() { return this->cloning; }
	int getBioWeapon() { return this->bioWeapon; }
	int getBioAntidote() { return this->bioAntidote; }
	int getEnrichment() { return this->enrichment; }
	int getSpeed() { return this->speed; }
	int getManeuverSpeed() { return this->maneuverSpeed; }
	int getFuelRange() { return this->fuelRange; }

	bool isReserveFuelTanks() { return this->reserveFuelTanks; }
	bool isBattleScanner() { return this->battleScanner; }
	bool isHyperSpaceCommunicator() { return this->hyperSpaceCommunicator; }
	bool isOracleInterface() { return this->oracleInterface; }
	bool isTechnologyNullifier() { return this->technologyNullifier; }
	bool isRepulsorBeam() { return this->repulsorBeam; }
	bool isCloakingDevice() { return this->cloakingDevice; }
	bool isStatisField() { return this->statisField; }
	bool isBlackHoleGenerator() { return this->blackHoleGenerator; }
	bool isInertialStabilizer() { return this->inertialStabilizer; }
	bool isEnergyPulsar() { return this->energyPulsar; }
	bool isWarpDissipator() { return this->warpDissipator; }
	bool isHighEnergyFocus() { return this->highEnergyFocus; }
	bool isStargate() { return this->stargate; }
	bool isSubspaceTeleporter() { return this->subspaceTeleporter; }
	bool isIonicPulsar() { return this->ionicPulsar; }
	bool isSubspaceInterdictor() { return this->subspaceInterdictor; }
	bool isCombatTransporters() { return this->combatTransporters; }
	bool isInertialNullifier() { return this->inertialNullifier; }
	bool isDisplacementDevice() { return this->displacementDevice; }
	bool isAntiMissileRockets() { return this->antiMissileRockets; }
	bool isIonStreamProjector() { return this->ionStreamProjector; }
	bool isNeutronStreamProjector() { return this->neutronStreamProjector; }

	float getSmallSize() { return this->smallSize; }
	float getSmallCost() { return this->smallCost; }
	float getSmallPower() { return this->smallPower; }
	float getSmallHP() { return this->smallHP; }

	float getSmallSecondarySize() { return this->smallSecondarySize; }
	float getSmallSecondaryCost() { return this->smallSecondaryCost; }
	float getSmallSecondaryPower() { return this->smallSecondaryPower; }
	float getSmallSecondaryHP() { return this->smallSecondaryHP; }

	float getMediumSize() { return this->mediumSize; }
	float getMediumCost() { return this->mediumCost; }
	float getMediumPower() { return this->mediumPower; }
	float getMediumHP() { return this->mediumHP; }

	float getMediumSecondarySize() { return this->mediumSecondarySize; }
	float getMediumSecondaryCost() { return this->mediumSecondaryCost; }
	float getMediumSecondaryPower() { return this->mediumSecondaryPower; }
	float getMediumSecondaryHP() { return this->mediumSecondaryHP; }

	float getLargeSize() { return this->largeSize; }
	float getLargeCost() { return this->largeCost; }
	float getLargePower() { return this->largePower; }
	float getLargeHP() { return this->largeHP; }

	float getLargeSecondarySize() { return this->largeSecondarySize; }
	float getLargeSecondaryCost() { return this->largeSecondaryCost; }
	float getLargeSecondaryPower() { return this->largeSecondaryPower; }
	float getLargeSecondaryHP() { return this->largeSecondaryHP; }

	float getHugeSize() { return this->hugeSize; }
	float getHugeCost() { return this->hugeCost; }
	float getHugePower() { return this->hugePower; }
	float getHugeHP() { return this->hugeHP; }

	float getHugeSecondarySize() { return this->hugeSecondarySize; }
	float getHugeSecondaryCost() { return this->hugeSecondaryCost; }
	float getHugeSecondaryPower() { return this->hugeSecondaryPower; }
	float getHugeSecondaryHP() { return this->hugeSecondaryHP; }

	float getGenericSize() { return this->genericSize; }
	float getGenericCost() { return this->genericCost; }
	float getGenericPower() { return this->genericPower; }

	float getGenericSecondarySize() { return this->genericSecondarySize; }
	float getGenericSecondaryCost() { return this->genericSecondaryCost; }
	float getGenericSecondaryPower() { return this->genericSecondaryPower; }

	int getWeaponType() { return this->weaponType; }
	int getMinimumWeaponDamage() { return this->minimumWeaponDamage; }
	int getMinimumSecondaryWeaponDamage() { return this->minimumSecondaryWeaponDamage; }
	int getMaximumWeaponDamage() { return this->maximumWeaponDamage; }
	int getMaximumSecondaryWeaponDamage() { return this->maximumSecondaryWeaponDamage; }
	bool getShieldPiercing() { return this->shieldPiercing; }
	float getWeaponRange() { return this->weaponRange; }
	int getSecondaryWeaponRange() { return this->secondaryWeaponRange; }
	int getNumberOfShots() { return this->numberOfShots; }
	bool getStreaming() { return this->streaming; }
	int getTargetingBonus() { return this->targetingBonus; }
	bool getEnveloping() { return this->enveloping; }
	bool getDissipating() { return this->dissipating; }
	float getMissileSpeed() { return this->missileSpeed; }

	Technology(TechField::Type techField, string name, string desc, int level,
		string secondaryName = "",
		//Optional arguments goes here
		int roboticControl = 0,
		int battleComputer = 0,
		bool battleScanner = false,
		int ECM = 0,
		int spaceScanner = 0,
		bool hyperSpaceCommunicator = false,
		bool oracleInterface = false,
		bool technologyNullifier = false,
		int armor = 0,
		bool reserveFuelTanks = false,
		int industrialTech = 10,
		int industrialWaste = 100,
		int groundArmor = 0,
		int repair = 0,
		int shield = 0,
		int personalShield = 0,
		int planetaryShield = 0,
		bool repulsorBeam = false,
		bool cloakingDevice = false,
		int missileShield = 0,
		bool statisField = false,
		bool blackHoleGenerator = false,
		int ecoCleanup = 0,
		int terraforming = 0,
		int terraformCost = 6,
		int colony = 0,
		int cloning = 20,
		int bioWeapon = 0,
		int bioAntidote = 0,
		int enrichment = 0,
		int speed = 0,
		int maneuverSpeed = 0,
		int fuelRange = 0,
		bool inertialstabilizer = false,
		bool energypulsar = false,
		bool warpDissipator = false,
		bool highEnergyFocus = false,
		bool stargate = false,
		bool subSpaceTeleporter = false,
		bool ionicPulsar = false,
		bool subspaceInterdictor = false,
		bool combatTransporters = false,
		bool inertialNullifier = false,
		bool displacementDevice = false,
		bool antiMissileRockets = false,
		bool ionStreamProjector = false,
		bool neutronStreamProjector = false,
		float smallSize = 0,
		float smallCost = 0,
		float smallPower = 0,
		float smallHP = 0,
		float mediumSize = 0,
		float mediumCost = 0,
		float mediumPower = 0,
		float mediumHP = 0,
		float largeSize = 0,
		float largeCost = 0,
		float largePower = 0,
		float largeHP = 0,
		float hugeSize = 0,
		float hugeCost = 0,
		float hugePower = 0,
		float hugeHP = 0,
		float genericSize = 0,
		float genericCost = 0,
		float genericPower = 0,
		float smallSecondarySize = 0,
		float smallSecondaryCost = 0,
		float smallSecondaryPower = 0,
		float smallSecondaryHP = 0,
		float mediumSecondarySize = 0,
		float mediumSecondaryCost = 0,
		float mediumSecondaryPower = 0,
		float mediumSecondaryHP = 0,
		float largeSecondarySize = 0,
		float largeSecondaryCost = 0,
		float largeSecondaryPower = 0,
		float largeSecondaryHP = 0,
		float hugeSecondarySize = 0,
		float hugeSecondaryCost = 0,
		float hugeSecondaryPower = 0,
		float hugeSecondaryHP = 0,
		float genericSecondarySize = 0,
		float genericSecondaryCost = 0,
		float genericSecondaryPower = 0,
		int weaponType = 0,
		int minimumWeaponDamage = 0,
		int minimumSecondaryWeaponDamage = 0,
		int maximumWeaponDamage = 0,
		int maximumSecondaryWeaponDamage = 0,
		bool shieldPiercing = false,
		float weaponRange = 0,
		int secondaryWeaponRange = 0,
		int numberOfShots = 0,
		bool streaming = false,
		int targetingBonus = 0,
		bool enveloping = false,
		bool dissipating = false,
		float missileSpeed = 0
		) : techField(techField), techName(techName), techDescription(desc), techLevel(level),
		techSecondaryName(secondaryName),
		roboticControl(roboticControl), battleComputer(battleComputer), battleScanner(battleScanner),
		ecm(ECM), spaceScanner(spaceScanner), hyperSpaceCommunicator(hyperSpaceCommunicator),
		oracleInterface(oracleInterface), technologyNullifier(technologyNullifier),
		armor(armor), reserveFuelTanks(reserveFuelTanks), industrialTech(industrialTech),
		industrialWaste(industrialWaste), groundArmor(groundArmor), repair(repair),
		shield(shield), personalShield(personalShield), planetaryShield(planetaryShield),
		repulsorBeam(repulsorBeam), cloakingDevice(cloakingDevice), missileShield(missileShield),
		statisField(statisField), blackHoleGenerator(blackHoleGenerator),
		ecoCleanup(ecoCleanup), terraforming(terraforming), terraformCost(terraformCost),
		colony(colony), cloning(cloning), bioWeapon(bioWeapon), bioAntidote(bioAntidote),
		enrichment(enrichment),
		speed(speed), maneuverSpeed(maneuverSpeed), fuelRange(fuelRange), 
		inertialStabilizer(inertialstabilizer), energyPulsar(energypulsar), 
		warpDissipator(warpDissipator), highEnergyFocus(highEnergyFocus), stargate(stargate),
		subspaceTeleporter(subSpaceTeleporter), ionicPulsar(ionicPulsar),
		subspaceInterdictor(subspaceInterdictor), combatTransporters(combatTransporters),
		inertialNullifier(inertialNullifier), displacementDevice(displacementDevice),
		antiMissileRockets(antiMissileRockets), ionStreamProjector(ionStreamProjector),
		neutronStreamProjector(neutronStreamProjector),
		smallSize(smallSize), smallCost(smallCost), smallPower(smallPower), smallHP(smallHP),
		mediumSize(mediumSize), mediumCost(mediumCost), mediumPower(mediumPower), mediumHP(mediumHP),
		largeSize(largeSize), largeCost(largeCost), largePower(largePower), largeHP(largeHP),
		hugeSize(hugeSize), hugeCost(hugeCost), hugePower(hugePower), hugeHP(hugeHP),
		genericSize(genericSize), genericCost(genericCost), genericPower(genericPower),
		smallSecondarySize(smallSecondarySize), smallSecondaryCost(smallSecondaryCost), smallSecondaryPower(smallSecondaryPower), smallSecondaryHP(smallSecondaryHP),
		mediumSecondarySize(mediumSecondarySize), mediumSecondaryCost(mediumSecondaryCost), mediumSecondaryPower(mediumSecondaryPower), mediumSecondaryHP(mediumSecondaryHP),
		largeSecondarySize(largeSecondarySize), largeSecondaryCost(largeSecondaryCost), largeSecondaryPower(largeSecondaryPower), largeSecondaryHP(largeSecondaryHP),
		hugeSecondarySize(hugeSecondarySize), hugeSecondaryCost(hugeSecondaryCost), hugeSecondaryPower(hugeSecondaryPower), hugeSecondaryHP(hugeSecondaryHP),
		genericSecondarySize(genericSecondarySize), genericSecondaryCost(genericSecondaryCost), genericSecondaryPower(genericSecondaryPower),
		weaponType(weaponType), 
		minimumWeaponDamage(minimumWeaponDamage), minimumSecondaryWeaponDamage(minimumSecondaryWeaponDamage),
		maximumWeaponDamage(maximumWeaponDamage), maximumSecondaryWeaponDamage(maximumSecondaryWeaponDamage),
		shieldPiercing(shieldPiercing), weaponRange(weaponRange), secondaryWeaponRange(secondaryWeaponRange),
		numberOfShots(numberOfShots), streaming(streaming), targetingBonus(targetingBonus),
		enveloping(enveloping), dissipating(dissipating), missileSpeed(missileSpeed)
		{ }
};

#endif