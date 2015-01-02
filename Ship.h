#ifndef SHIP_H
#define SHIP_H

#include "stdafx.h"

using namespace std;

class Ship
{
private:
	string name;
	int designID;
	Empire* owner;
	int size;
	int whichStyle;

public:
	enum
	{
		SMALL = 0,
		MEDIUM = 1,
		LARGE = 2,
		HUGE = 3,

		WeaponCount = 4,
		SpecialCount = 3,
	};
			   
	string getName() { return this->name; }
	int getDesignID() { return this->designID; }
	Empire* getOwner() { return this->owner; }
	int getSize() { return this->size; }
	int getWhichStyle() { return this->whichStyle; }
	
	Quantity<Equipment*, float> engine;
	int maneuverSpeed;
	Equipment* shield;
	Equipment* armor;
	Equipment* computer;
	Equipment* ecm;
	Quantity<Equipment*, int> weapons[4];
	Equipment* specials[3];

	float getMaintenance();
	int getTotalSpace();
	float getCost();
	float getSpaceUsed();
	float getPowerUsed();
	int getGalaxySpeed();
	int getMaxHitPoints();
	int getBeamDefense();
	int getMissileDefense();
	int getAttackLevel();
	int getShieldLevel();

	Ship();
	Ship(const Ship& shipToCopy);

	void updateEngineNumber();
	void clear(vector<Technology*>& availableArmorTechs, vector<Technology*>& availableEngineTechs);
};

#endif