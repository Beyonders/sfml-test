#include "StdAfx.h"

//TODO: save and load logic

float Ship::getMaintenance()
{
	return this->getCost() * 0.02f;
}
		
int Ship::getTotalSpace()
{ 
	int space = 40;
	switch (this->size)
	{
		case MEDIUM: 
			space = 200;
			break;
		case LARGE:
			space = 1000;
			break;
		case HUGE:
			space = 5000;
			break;
	}
	space = (int)(space * (1.0 + (0.02 * this->owner->getTechnologyManager()->getConstructionLevel())));
	return space;
}

float Ship::getCost()
{
	float cost = 6;
	switch (this->size)
	{
		case MEDIUM:
			cost = 36;
			break;
		case LARGE:
			cost = 200;
			break;
		case HUGE:
			cost = 1200;
			break;
	}

	map<TechField::Type, int> fieldLevels;
	this->owner->getTechnologyManager()->getFieldLevels(fieldLevels);
	cost += this->engine.item->getCost(fieldLevels, this->size) * this->engine.count;
	cost += this->armor->getCost(fieldLevels, this->size);
	if (this->shield != NULL)
	{
		cost += this->shield->getCost(fieldLevels, this->size);
	}
	if (this->computer != NULL)
	{
		cost += this->computer->getCost(fieldLevels, this->size);
	}
	if (this->ecm != NULL)
	{
		cost += this->ecm->getCost(fieldLevels, this->size);
	}
	for(int i = 0; i < WeaponCount; i++)
	{
		if (this->weapons[i].item != NULL)
		{
			//Weapon times amount of mounts
			cost += this->weapons[i].item->getCost(fieldLevels, this->size) * this->weapons[i].count;
		}
	}
	for(int i = 0; i < SpecialCount; i++)
	{
		if (this->specials[i] != NULL)
		{
			cost += this->specials[i]->getCost(fieldLevels, this->size);
		}
	}
	return cost;
}
	
float Ship::getSpaceUsed()
{
	float sizeUsed = 0;
	map<TechField::Type, int> fieldLevels;
	this->owner->getTechnologyManager()->getFieldLevels(fieldLevels);
	sizeUsed += this->engine.item->getSize(fieldLevels, this->size) * this->engine.count;
	sizeUsed += this->armor->getSize(fieldLevels, this->size);
	if (this->shield != NULL)
	{
		sizeUsed += this->shield->getSize(fieldLevels, this->size);
	}
	if (this->computer != NULL)
	{
		sizeUsed += this->computer->getSize(fieldLevels, this->size);
	}
	if (this->ecm != NULL)
	{
		sizeUsed += this->ecm->getSize(fieldLevels, this->size);
	}
	for(int i = 0; i < WeaponCount; i++)
	{
		if (this->weapons[i].item != NULL)
		{
			//Weapon times amount of mounts
			sizeUsed += this->weapons[i].item->getSize(fieldLevels, this->size) * this->weapons[i].count;
		}
	}
	for(int i = 0; i < SpecialCount; i++)
	{
		if (this->specials[i] != NULL)
		{
			sizeUsed += this->specials[i]->getSize(fieldLevels, this->size);
		}
	}
	return sizeUsed;
}
	
float Ship::getPowerUsed()
{
	float powerUsed = 0;
	//First, get the maneuver power requirement
	switch (this->size)
	{
		case SMALL:
			powerUsed += this->maneuverSpeed * 2;
			break;
		case MEDIUM:
			powerUsed += this->maneuverSpeed * 15;
			break;
		case LARGE:
			powerUsed += this->maneuverSpeed * 100;
			break;
		case HUGE:
			powerUsed += this->maneuverSpeed * 700;
			break;
	}
	//since engines provide power, do NOT include engines in this total
	//Armor don't use up power, but perhaps in a mod?  For now, don't include armor as well
	if (this->computer != NULL)
	{
		powerUsed += this->computer->getPower(this->size);
	}
	if (this->ecm != NULL)
	{
		powerUsed += this->ecm->getPower(this->size);
	}
	if (this->shield != NULL)
	{
		powerUsed += this->shield->getPower(this->size);
	}
	for(int i = 0; i < WeaponCount; i++)
	{
		if (this->weapons[i].item != NULL)
		{
			powerUsed += this->weapons[i].item->getPower(this->size) * this->weapons[i].count;
		}
	}
	for(int i = 0; i < SpecialCount; i++)
	{
		if (this->specials[i] != NULL)
		{
			powerUsed += this->specials[i]->getPower(this->size);
		}
	}
	return powerUsed;
}
	
int Ship::getGalaxySpeed()
{
	return this->engine.item->getTechnology()->getSpeed();
}
	
int Ship::getMaxHitPoints()
{
	switch (this->size)
	{
		case SMALL:
			return (int)(this->armor->useSecondary ? this->armor->getTechnology()->getSmallSecondaryHP() : this->armor->getTechnology()->getSmallHP());
		case MEDIUM:
			return (int)(this->armor->useSecondary ? this->armor->getTechnology()->getMediumSecondaryHP() : this->armor->getTechnology()->getMediumHP());
		case LARGE:
			return (int)(this->armor->useSecondary ? this->armor->getTechnology()->getLargeSecondaryHP() : this->armor->getTechnology()->getLargeHP());
		case HUGE:
			return (int)(this->armor->useSecondary ? this->armor->getTechnology()->getHugeSecondaryHP() : this->armor->getTechnology()->getHugeHP());
	}
	return 0;
}
	
int Ship::getBeamDefense()
{
	// TODO: Add other equipment that adds to defense, such as cloaking
	return (2 - this->size) + this->maneuverSpeed;
}
	
int Ship::getMissileDefense()
{
	return  ((2 - this->size) + this->maneuverSpeed + (this->ecm == NULL ? 0 : this->ecm->getTechnology()->getEcm()));
}
	
int Ship::getAttackLevel()
{
	//Todo: add battle scanner's +1 if ship has it
	return (this->computer == NULL ? 0 : this->computer->getTechnology()->getBattleComputer());
}
	
int Ship::getShieldLevel()
{
	return (this->shield == NULL ? 0 : this->shield->getTechnology()->getShield());
}

Ship::Ship() 
	: maneuverSpeed(1)
{
}

Ship::Ship(const Ship& shipToCopy)
	: name(shipToCopy.name), designID(shipToCopy.designID), owner(shipToCopy.owner),
	size(shipToCopy.size), whichStyle(shipToCopy.whichStyle),
	engine(shipToCopy.engine), shield(shipToCopy.shield), armor(shipToCopy.armor),
	computer(shipToCopy.computer), ecm(shipToCopy.ecm)
{
	//TODO investigate if old Equipment objects have to be deleted
	for(int i = 0; i < WeaponCount; i++)
	{
		this->weapons[i] = shipToCopy.weapons[i];
	}
	for(int i = 0; i < SpecialCount; i++)
	{
		this->specials[i] = shipToCopy.specials[i];
	}
}

void Ship::updateEngineNumber()
{
	float amountRequired = this->getPowerUsed() / (this->engine.item->getTechnology()->getSpeed() * 10);
	this->engine.count = amountRequired;
}

void Ship::clear(vector<Technology*>& availableArmorTechs, vector<Technology*>& availableEngineTechs)
{
	//Used by ship design screen to clear out everything
	//TODO investigate if old Equipment objects have to be deleted
	for(int i = 0; i < WeaponCount; i++)
	{
		this->weapons[i] = Quantity<Equipment*, int>();
	}
	for (int i = 0; i < SpecialCount; i++)
	{
		this->specials[i] = NULL;
	}

	delete this->armor;
	delete this->engine.item;

	this->ecm = NULL;
	this->computer = NULL;
	this->shield = NULL;
	this->maneuverSpeed = 1;
	this->armor = new Equipment(availableArmorTechs[0], false);
	this->engine = Quantity<Equipment*, float>(new Equipment(availableEngineTechs[0], false), 0);
	this->updateEngineNumber();
}