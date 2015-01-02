#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include "stdafx.h"
#include <map>

using namespace std;

class Equipment
{
private:
	Technology* technology;

public:
	bool useSecondary;

	//This stores whether or not the secondary technology item is used, as well as store other useful data for use in space combat
	Equipment(Technology* whichTech, bool useSecondary);

	Technology* getTechnology() { return this->technology; }
	
	string getDisplayName();
	string getEquipmentName();
	float getCost(map<TechField::Type, int>& techLevels, int shipSize);
	float getActualCost(map<TechField::Type, int>& techLevels, int shipSize, float costPerPower);
	float getSize(map<TechField::Type, int>& techLevels, int shipSize);
	float getActualSize(map<TechField::Type, int>& techLevels, int shipSize, float spacePerPower);
	float getPower(int shipSize);
	int getMinDamage();
	int getMaxDamage();
	int getRange();
};

#endif