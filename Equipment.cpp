#include "Equipment.h"

//This stores whether or not the secondary technology item is used, as well as store other useful data for use in space combat
Equipment::Equipment(Technology* whichTech, bool useSecondary)
	: technology(technology), useSecondary(useSecondary)
{ }

string Equipment::getDisplayName()
{
	if (this->technology->getWeaponType() == Technology::MISSILE_WEAPON)
	{
		return this->useSecondary ? 
			this->technology->getTechName() + " x 5" : 
			this->technology->getTechName() + " x 2";
	}
	
	return this->useSecondary ? 
		this->technology->getTechSecondaryName() : 
		this->technology->getTechName();
}

string Equipment::getEquipmentName()
{
	return this->useSecondary ? 
		this->technology->getTechName() + "|Sec" : 
		this->technology->getTechName();
}

float Equipment::getCost(const map<TechField::Type, int>& techLevels, int shipSize)
{
	float initialCost = 0;
	if (this->technology->getGenericCost() == 0) //It uses the ship-specific size cost
	{
		switch (shipSize)
		{
			case 0:
				initialCost = this->useSecondary ? 
					this->technology->getSmallSecondaryCost() : 
					this->technology->getSmallCost();
				break;
			case 1:
				initialCost = this->useSecondary ? 
					this->technology->getMediumSecondaryCost() : 
					this->technology->getMediumCost();
				break;
			case 2:
				initialCost = this->useSecondary ? 
					this->technology->getLargeSecondaryCost() : 
					this->technology->getLargeCost();
				break;
			case 3:
				initialCost = this->useSecondary ? 
					this->technology->getHugeSecondaryCost() : 
					this->technology->getHugeCost();
				break;
		}
	}
	else
	{
		if (this->technology->getWeaponType() == Technology::MISSILE_WEAPON)
		{
			initialCost = this->useSecondary ? 
				this->technology->getGenericCost() * 1.5f : 
				this->technology->getGenericCost();
		}
		else
		{
			initialCost = this->useSecondary ? 
				this->technology->getGenericSecondaryCost() : 
				this->technology->getGenericCost();
		}
	}

	int levelDifference = techLevels[this->technology->getTechField()] - this->technology->getTechLevel();
	if (levelDifference < 0)
	{
		levelDifference = 0;
	}
	else if (levelDifference > 50)
	{
		levelDifference = 50; //Cap the miniaturization at 50 levels
	}
	return initialCost * (powf(0.5f, (levelDifference / 10.0f)));
}

float Equipment::getActualCost(const map<TechField::Type, int>& techLevels, int shipSize, float costPerPower)
{
	float cost = this->getCost(techLevels, shipSize);
	return (cost + this->getPower(shipSize) * costPerPower);
}

float Equipment::getSize(const map<TechField::Type, int>& techLevels, int shipSize)
{
	float initialSize = 0;
	if (this->technology->getGenericSize() == 0) //It uses the ship-specific size cost
	{
		switch (shipSize)
		{
			case 0:
				initialSize = this->useSecondary ? 
					this->technology->getSmallSecondarySize() : 
					this->technology->getSmallSize();
				break;
			case 1:
				initialSize = this->useSecondary ? 
					this->technology->getMediumSecondarySize() : 
					this->technology->getMediumSize();
				break;
			case 2:
				initialSize = this->useSecondary ? 
					this->technology->getLargeSecondarySize() : 
					this->technology->getLargeSize();
				break;
			case 3:
				initialSize = this->useSecondary ? 
					this->technology->getHugeSecondarySize() : 
					this->technology->getHugeSize();
				break;
		}
	}
	else
	{
		if (this->technology->getWeaponType() == Technology::MISSILE_WEAPON)
		{
			initialSize = this->useSecondary ? 
				this->technology->getGenericSize() * 1.5f : 
				this->technology->getGenericSize();
		}
		else
		{
			initialSize = this->useSecondary ? 
				this->technology->getGenericSecondarySize() : 
				this->technology->getGenericSize();
		}
	}

	int levelDifference = techLevels[this->technology->getTechField()] - this->technology->getTechLevel();
	if (levelDifference < 0)
	{
		levelDifference = 0;
	}
	else if (levelDifference > 50)
	{
		levelDifference = 50; //Cap the miniaturization at 50 levels
	}

	if (this->technology->getTechField() == TechField::WEAPON) //Weapons enjoy 50% miniauratization rate
	{
		return initialSize * (powf(0.5f, (levelDifference / 10.0f)));
	}
	return initialSize * (powf(0.75f, (levelDifference / 10.0f)));
}

float Equipment::getActualSize(const map<TechField::Type, int>& techLevels, int shipSize, float spacePerPower)
{
	float size = this->getSize(techLevels, shipSize);
	return (size + this->getPower(shipSize) * spacePerPower);
}

float Equipment::getPower(int shipSize)
{
	if (this->technology->getGenericPower() == 0) //It uses the ship-specific size cost
	{
		switch (shipSize)
		{
			case 0:
				return this->useSecondary ? 
					this->technology->getSmallSecondaryPower() : 
					this->technology->getSmallPower();
			case 1:
				return this->useSecondary ? 
					this->technology->getMediumSecondaryPower() : 
					this->technology->getMediumPower();
			case 2:
				return this->useSecondary ? 
					this->technology->getLargeSecondaryPower() : 
					this->technology->getLargePower();
			case 3:
				return this->useSecondary ? 
					this->technology->getHugeSecondaryPower() : 
					this->technology->getHugePower();
		}
	}
	if (this->technology->getWeaponType() == Technology::MISSILE_WEAPON)
	{
		return this->useSecondary ? this->technology->getGenericPower() * 1.5f : this->technology->getGenericPower();
	}
	return this->useSecondary ? this->technology->getGenericSecondaryPower() : this->technology->getGenericPower();
}

int Equipment::getMinDamage()
{
	if (this->technology->getWeaponType() == Technology::MISSILE_WEAPON)
	{
		return this->technology->getMinimumWeaponDamage();
	}
	return this->useSecondary ? this->technology->getMinimumSecondaryWeaponDamage() : this->technology->getMinimumWeaponDamage();
}

int Equipment::getMaxDamage()
{
	if (this->technology->getWeaponType() == Technology::MISSILE_WEAPON)
	{
		return this->technology->getMaximumWeaponDamage();
	}
	return this->useSecondary ? this->technology->getMaximumSecondaryWeaponDamage() : this->technology->getMaximumWeaponDamage();
}

int Equipment::getRange()
{
	if (this->technology->getWeaponType() == Technology::MISSILE_WEAPON)
	{
		return (int)(this->useSecondary ? ((this->technology->getWeaponRange() + 0.1f) * 2) : (this->technology->getWeaponRange() + 1.1f) * 2); //.1f is to compenstate for any float rounding error
	}
	return this->useSecondary ? this->technology->getSecondaryWeaponRange() : this->technology->getWeaponRange();
}