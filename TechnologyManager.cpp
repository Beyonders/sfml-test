#include "StdAfx.h"
#include "TechnologyManager.h"

/*
	Properties
*/

int TechnologyManager::getComputerLevel()
{ 
	int level = 0;
	int numberOfStartingTechs = 0;
	for(set<Technology*>::iterator it = this->researchedComputerTechs.begin(); it != this->researchedComputerTechs.end(); it++)
	{
		if ((*it)->getTechLevel() > level)
		{
			level = (*it)->getTechLevel();
		}
		if ((*it)->getTechLevel() == 1)
		{
			numberOfStartingTechs++;
		}
	}
	level = (int)(level * 0.8);
	level += this->researchedComputerTechs.size() + 1 - numberOfStartingTechs;
	return min(level, 99);
}

int TechnologyManager::getConstructionLevel()
{
	int level = 0;
	int numberOfStartingTechs = 0;
	for(set<Technology*>::iterator it = this->researchedConstructionTechs.begin(); it != this->researchedConstructionTechs.end(); it++)
	{
		if ((*it)->getTechLevel() > level)
		{
			level = (*it)->getTechLevel();
		}
		if ((*it)->getTechLevel() == 1)
		{
			numberOfStartingTechs++;
		}
	}
	level = (int)(level * 0.8);
	level += this->researchedConstructionTechs.size() + 1 - numberOfStartingTechs;
	return min(level, 99);
}

int TechnologyManager::getForceFieldLevel()
{
	int level = 0;
	int numberOfStartingTechs = 0;
	for(set<Technology*>::iterator it = this->researchedForceFieldTechs.begin(); it != this->researchedForceFieldTechs.end(); it++)
	{
		if ((*it)->getTechLevel() > level)
		{
			level = (*it)->getTechLevel();
		}
		if ((*it)->getTechLevel() == 1)
		{
			numberOfStartingTechs++;
		}
	}
	level = (int)(level * 0.8);
	level += this->researchedForceFieldTechs.size() + 1 - numberOfStartingTechs;
	return min(level, 99);
}

int TechnologyManager::getPlanetologyLevel()
{
	int level = 0;
	int numberOfStartingTechs = 0;
	for(set<Technology*>::iterator it = this->researchedPlanetologyTechs.begin(); it != this->researchedPlanetologyTechs.end(); it++)
	{
		if ((*it)->getTechLevel() > level)
		{
			level = (*it)->getTechLevel();
		}
		if ((*it)->getTechLevel() == 1)
		{
			numberOfStartingTechs++;
		}
	}
	level = (int)(level * 0.8);
	level += this->researchedPlanetologyTechs.size() + 1 - numberOfStartingTechs;
	return min(level, 99);
}

int TechnologyManager::getPropulsionLevel()
{
	int level = 0;
	int numberOfStartingTechs = 0;
	for(set<Technology*>::iterator it = this->researchedPropulsionTechs.begin(); it != this->researchedPropulsionTechs.end(); it++)
	{
		if ((*it)->getTechLevel() > level)
		{
			level = (*it)->getTechLevel();
		}
		if ((*it)->getTechLevel() == 1)
		{
			numberOfStartingTechs++;
		}
	}
	level = (int)(level * 0.8);
	level += this->researchedPropulsionTechs.size() + 1 - numberOfStartingTechs;
	return min(level, 99);
}

int TechnologyManager::getWeaponLevel()
{
	int level = 0;
	int numberOfStartingTechs = 0;
	for(set<Technology*>::iterator it = this->researchedWeaponTechs.begin(); it != this->researchedWeaponTechs.end(); it++)
	{
		if ((*it)->getTechLevel() > level)
		{
			level = (*it)->getTechLevel();
		}
		if ((*it)->getTechLevel() == 1)
		{
			numberOfStartingTechs++;
		}
	}
	level = (int)(level * 0.8);
	level += this->researchedWeaponTechs.size() + 1 - numberOfStartingTechs;
	return min(level, 99);
}

/*
	Constructor
*/

TechnologyManager::TechnologyManager()
	: computerPercentage(20), constructionPercentage(10), forceFieldPercentage(15),
	planetologyPercentage(15), propulsionPercentage(20), weaponPercentage(20)
{
	this->raceModifiers[TechField::COMPUTER] = 1;
	this->raceModifiers[TechField::CONSTRUCTION] = 1;
	this->raceModifiers[TechField::FORCE_FIELD] = 1;
	this->raceModifiers[TechField::PLANETOLOGY] = 1;
	this->raceModifiers[TechField::PROPULSION] = 1;
	this->raceModifiers[TechField::WEAPON] = 1;

	this->updateValues();
}

/*
	Functions
*/

void TechnologyManager::setComputerTechs(set<Technology*>& techs)
{
	this->unresearchedComputerTechs = techs;
	this->researchedComputerTechs.clear();
	for(set<Technology*>::iterator it = techs.begin(); it != techs.end(); it++)
	{
		if ((*it)->getTechLevel() == 1)
		{
			this->researchedComputerTechs.insert(*it);
			this->unresearchedComputerTechs.erase(*it);
		}
	}
}

void TechnologyManager::setConstructionTechs(set<Technology*>& techs)
{
	this->unresearchedConstructionTechs = techs;
	this->researchedConstructionTechs.clear();
	for(set<Technology*>::iterator it = techs.begin(); it != techs.end(); it++)
	{
		if ((*it)->getTechLevel() == 1)
		{
			this->researchedConstructionTechs.insert(*it);
			this->unresearchedConstructionTechs.erase(*it);
		}
	}
}

void TechnologyManager::setForceFieldTechs(set<Technology*>& techs)
{
	this->unresearchedForceFieldTechs = techs;
	this->researchedForceFieldTechs.clear();
	for(set<Technology*>::iterator it = techs.begin(); it != techs.end(); it++)
	{
		if ((*it)->getTechLevel() == 1)
		{
			this->researchedForceFieldTechs.insert(*it);
			this->unresearchedForceFieldTechs.erase(*it);
		}
	}
}

void TechnologyManager::setPlanetologyTechs(set<Technology*>& techs)
{
	this->unresearchedPlanetologyTechs = techs;
	this->researchedPlanetologyTechs.clear();
	for(set<Technology*>::iterator it = techs.begin(); it != techs.end(); it++)
	{
		if ((*it)->getTechLevel() == 1)
		{
			this->researchedPlanetologyTechs.insert(*it);
			this->unresearchedPlanetologyTechs.erase(*it);
		}
	}
}

void TechnologyManager::setPropulsionTechs(set<Technology*>& techs)
{
	this->unresearchedPropulsionTechs = techs;
	this->researchedPropulsionTechs.clear();
	for(set<Technology*>::iterator it = techs.begin(); it != techs.end(); it++)
	{
		if ((*it)->getTechLevel() == 1)
		{
			this->researchedPropulsionTechs.insert(*it);
			this->unresearchedPropulsionTechs.erase(*it);
		}
	}
}

void TechnologyManager::setWeaponTechs(set<Technology*>& techs)
{
	this->unresearchedWeaponTechs = techs;
	this->researchedWeaponTechs.clear();
	for(set<Technology*>::iterator it = techs.begin(); it != techs.end(); it++)
	{
		if ((*it)->getTechLevel() == 1)
		{
			this->researchedWeaponTechs.insert(*it);
			this->unresearchedWeaponTechs.erase(*it);
		}
	}
}

void TechnologyManager::getFieldLevels(map<TechField::Type, int>& fieldLevels)
{
	fieldLevels.clear();
		fieldLevels[TechField::COMPUTER] = this->getComputerLevel();
		fieldLevels[TechField::CONSTRUCTION] = this->getConstructionLevel();
		fieldLevels[TechField::FORCE_FIELD] = this->getForceFieldLevel();
		fieldLevels[TechField::PLANETOLOGY] = this->getPlanetologyLevel();
		fieldLevels[TechField::PROPULSION] = this->getPropulsionLevel();
		fieldLevels[TechField::WEAPON] = this->getWeaponLevel();
}

string TechnologyManager::getFieldProgressString(TechField::Type whichField, float researchPoints)
{
	stringstream progressString;
	int chance = 0;
	float amount = 0;
	float researchedAmount = 0;
	int researchCost = 0;

	switch (whichField)
	{
		case TechField::COMPUTER:
		{
			if (this->whichComputerBeingResearched == NULL)
			{
				return "N/A";
			}
			amount = this->getFieldInvestmentAmount(whichField, researchPoints);
			//Temporarily update the research amount to get accurate chance of discovery
			float oldAmount = this->computerResearchAmount;
			this->computerResearchAmount += amount;
			chance = this->getChanceForDiscovery(whichField);
			this->computerResearchAmount = oldAmount;
			researchedAmount = this->computerResearchAmount;
			researchCost = (int)(this->whichComputerBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::COMPUTER]);
		} break;
		case TechField::CONSTRUCTION:
		{
			if (this->whichConstructionBeingResearched == NULL)
			{
				return "N/A";
			}
			amount = this->getFieldInvestmentAmount(whichField, researchPoints);
			//Temporarily update the research amount to get accurate chance of discovery
			float oldAmount = this->constructionResearchAmount;
			this->constructionResearchAmount += amount;
			chance = this->getChanceForDiscovery(whichField);
			this->constructionResearchAmount = oldAmount;
			researchedAmount = this->constructionResearchAmount;
			researchCost = (int)(this->whichConstructionBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::CONSTRUCTION]);
		} break;
		case TechField::FORCE_FIELD:
		{
			if (this->whichForceFieldBeingResearched == NULL)
			{
				return "N/A";
			}
			amount = this->getFieldInvestmentAmount(whichField, researchPoints);
			//Temporarily update the research amount to get accurate chance of discovery
			float oldAmount = this->forceFieldResearchAmount;
			this->forceFieldResearchAmount += amount;
			chance = this->getChanceForDiscovery(whichField);
			this->forceFieldResearchAmount = oldAmount;
			researchedAmount = this->forceFieldResearchAmount;
			researchCost = (int)(this->whichForceFieldBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::FORCE_FIELD]);
		} break;
		case TechField::PLANETOLOGY:
		{
			if (this->whichPlanetologyBeingResearched == NULL)
			{
				return "N/A";
			}
			amount = this->getFieldInvestmentAmount(whichField, researchPoints);
			//Temporarily update the research amount to get accurate chance of discovery
			float oldAmount = this->planetologyResearchAmount;
			this->planetologyResearchAmount += amount;
			chance = this->getChanceForDiscovery(whichField);
			this->planetologyResearchAmount = oldAmount;
			researchedAmount = this->planetologyResearchAmount;
			researchCost = (int)(this->whichPlanetologyBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::PLANETOLOGY]);
		} break;
		case TechField::PROPULSION:
		{
			if (this->whichPropulsionBeingResearched == NULL)
			{
				return "N/A";
			}
			amount = this->getFieldInvestmentAmount(whichField, researchPoints);
			//Temporarily update the research amount to get accurate chance of discovery
			float oldAmount = this->propulsionResearchAmount;
			this->propulsionResearchAmount += amount;
			chance = this->getChanceForDiscovery(whichField);
			this->propulsionResearchAmount = oldAmount;
			researchedAmount = this->propulsionResearchAmount;
			researchCost = (int)(this->whichPropulsionBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::PROPULSION]);
		} break;
		case TechField::WEAPON:
		{
			if (this->whichweaponBeingResearched == NULL)
			{
				return "N/A";
			}
			amount = this->getFieldInvestmentAmount(whichField, researchPoints);
			//Temporarily update the research amount to get accurate chance of discovery
			float oldAmount = this->weaponResearchAmount;
			this->weaponResearchAmount += amount;
			chance = this->getChanceForDiscovery(whichField);
			this->weaponResearchAmount = oldAmount;
			researchedAmount = this->weaponResearchAmount;
			researchCost = (int)(this->whichweaponBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::WEAPON]);
		} break;
	}

	progressString << fixed;
	progressString.precision(0);
	progressString << researchedAmount << " / " << researchCost;
	progressString << " (" << (amount >= 0 ? " +" : "") << amount << ")";
	if (chance > 0)
	{
		progressString << " " << chance << "%";
	}
			
	return progressString.str();
}

void TechnologyManager::accureResearch(float researchPoints)
{
	this->computerResearchAmount += this->getFieldInvestmentAmount(TechField::COMPUTER, researchPoints);
	this->constructionResearchAmount += this->getFieldInvestmentAmount(TechField::CONSTRUCTION, researchPoints);
	this->forceFieldResearchAmount += this->getFieldInvestmentAmount(TechField::FORCE_FIELD, researchPoints);
	this->planetologyResearchAmount += this->getFieldInvestmentAmount(TechField::PLANETOLOGY, researchPoints);
	this->propulsionResearchAmount += this->getFieldInvestmentAmount(TechField::PROPULSION, researchPoints);
	this->weaponResearchAmount += this->getFieldInvestmentAmount(TechField::WEAPON, researchPoints);
}

float TechnologyManager::getFieldInvestmentAmount(TechField::Type whichField, float researchPoints)
{
	switch (whichField)
	{
		case TechField::COMPUTER:
		{
			if (this->computerPercentage == 0)
			{
				if (this->computerResearchAmount > 0)
				{
					//Lose 10% of total research invested if no research is being invested
					return (this->computerResearchAmount * 0.9f) - this->computerResearchAmount;
				}
				return 0;
			}
			float interest = this->computerResearchAmount * 0.15f;
			float newPoints = (researchPoints * (this->computerPercentage * 0.01f));
			if ((newPoints * 2) < interest)
			{
				//up to 15% interest, but if we contribute less than half the interest, then cap the interest to double the current investment
				interest = newPoints * 2;
			}
			return (newPoints + interest);
		}
		case TechField::CONSTRUCTION:
		{
			if (this->constructionPercentage == 0)
			{
				if (this->constructionResearchAmount > 0)
				{
					//Lose 10% of total research invested if no research is being invested
					return (this->constructionResearchAmount * 0.9f) - this->constructionResearchAmount;
				}
				return 0;
			}
			float interest = this->constructionResearchAmount * 0.15f;
			float newPoints = (researchPoints * (this->constructionPercentage * 0.01f));
			if ((newPoints * 2) < interest)
			{
				//up to 15% interest, but if we contribute less than half the interest, then cap the interest to double the current investment
				interest = newPoints * 2;
			}
			return (newPoints + interest);
		}
		case TechField::FORCE_FIELD:
		{
			if (this->forceFieldPercentage == 0)
			{
				if (this->forceFieldResearchAmount > 0)
				{
					//Lose 10% of total research invested if no research is being invested
					return (this->forceFieldResearchAmount * 0.9f) - this->forceFieldResearchAmount;
				}
				return 0;
			}
			float interest = this->forceFieldResearchAmount * 0.15f;
			float newPoints = (researchPoints * (this->forceFieldPercentage * 0.01f));
			if ((newPoints * 2) < interest)
			{
				//up to 15% interest, but if we contribute less than half the interest, then cap the interest to double the current investment
				interest = newPoints * 2;
			}
			return (newPoints + interest);
		}
		case TechField::PLANETOLOGY:
		{
			if (this->planetologyPercentage == 0)
			{
				if (this->planetologyResearchAmount > 0)
				{
					//Lose 10% of total research invested if no research is being invested
					return (this->planetologyResearchAmount * 0.9f) - this->planetologyResearchAmount;
				}
				return 0;
			}
			float interest = this->planetologyResearchAmount * 0.15f;
			float newPoints = (researchPoints * (this->planetologyPercentage * 0.01f));
			if ((newPoints * 2) < interest)
			{
				//up to 15% interest, but if we contribute less than half the interest, then cap the interest to double the current investment
				interest = newPoints * 2;
			}
			return (newPoints + interest);
		}
		case TechField::PROPULSION:
		{
			if (this->propulsionPercentage == 0)
			{
				if (this->propulsionResearchAmount > 0)
				{
					//Lose 10% of total research invested if no research is being invested
					return (this->propulsionResearchAmount * 0.9f) - this->propulsionResearchAmount;
				}
				return 0;
			}
			float interest = this->propulsionResearchAmount * 0.15f;
			float newPoints = (researchPoints * (this->propulsionPercentage * 0.01f));
			if ((newPoints * 2) < interest)
			{
				//up to 15% interest, but if we contribute less than half the interest, then cap the interest to double the current investment
				interest = newPoints * 2;
			}
			return (newPoints + interest);
		}
		case TechField::WEAPON:
		{
			if (this->weaponPercentage == 0)
			{
				if (this->weaponResearchAmount > 0)
				{
					//Lose 10% of total research invested if no research is being invested
					return (this->weaponResearchAmount * 0.9f) - this->weaponResearchAmount;
				}
				return 0;
			}
			float interest = this->weaponResearchAmount * 0.15f;
			float newPoints = (researchPoints * (this->weaponPercentage * 0.01f));
			if ((newPoints * 2) < interest)
			{
				//up to 15% interest, but if we contribute less than half the interest, then cap the interest to double the current investment
				interest = newPoints * 2;
			}
			return (newPoints + interest);
		}
		default: 
			return 0;
	}
}

int TechnologyManager::getChanceForDiscovery(TechField::Type whichField)
{
	//Only items being currently researched have a chance of being discovered
	switch (whichField)
	{
		case TechField::COMPUTER:
		{
			if (this->computerPercentage > 0 && this->whichComputerBeingResearched != NULL)
			{
				int researchPointsRequired = (int)(this->whichComputerBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::COMPUTER]);
				if (this->computerResearchAmount > researchPointsRequired) //We now have a chance of discovering it
				{
					return (int)(((this->computerResearchAmount - researchPointsRequired) / (researchPointsRequired * 2)) * 100);
				}
			}
		} break;
		case TechField::CONSTRUCTION:
			{
				if (this->constructionPercentage > 0 && this->whichConstructionBeingResearched != NULL)
				{
					int researchPointsRequired = (int)(this->whichConstructionBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::CONSTRUCTION]);
					if (this->constructionResearchAmount > researchPointsRequired) //We now have a chance of discovering it
					{
						return (int)(((this->constructionResearchAmount - researchPointsRequired) / (researchPointsRequired * 2)) * 100);
					}
				}
			} break;
		case TechField::FORCE_FIELD:
			{
				if (this->forceFieldPercentage > 0 && this->whichForceFieldBeingResearched != NULL)
				{
					int researchPointsRequired = (int)(this->whichForceFieldBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::FORCE_FIELD]);
					if (this->forceFieldResearchAmount > researchPointsRequired) //We now have a chance of discovering it
					{
						return (int)(((this->forceFieldResearchAmount - researchPointsRequired) / (researchPointsRequired * 2)) * 100);
					}
				}
			} break;
		case TechField::PLANETOLOGY:
			{
				if (this->planetologyPercentage > 0 && this->whichPlanetologyBeingResearched != NULL)
				{
					int researchPointsRequired = (int)(this->whichPlanetologyBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::PLANETOLOGY]);
					if (this->planetologyResearchAmount > researchPointsRequired) //We now have a chance of discovering it
					{
						return (int)(((this->planetologyResearchAmount - researchPointsRequired) / (researchPointsRequired * 2)) * 100);
					}
				}
			} break;
		case TechField::PROPULSION:
			{
				if (this->propulsionPercentage > 0 && this->whichPropulsionBeingResearched != NULL)
				{
					int researchPointsRequired = (int)(this->whichPropulsionBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::PROPULSION]);
					if (this->propulsionResearchAmount > researchPointsRequired) //We now have a chance of discovering it
					{
						return (int)(((this->propulsionResearchAmount - researchPointsRequired) / (researchPointsRequired * 2)) * 100);
					}
				}
			} break;
		case TechField::WEAPON:
			{
				if (this->weaponPercentage > 0 && this->whichweaponBeingResearched != NULL)
				{
					int researchPointsRequired = (int)(this->whichweaponBeingResearched->getResearchPoints() * COST_MODIFIER * this->raceModifiers[TechField::WEAPON]);
					if (this->weaponResearchAmount > researchPointsRequired) //We now have a chance of discovering it
					{
						return (int)(((this->weaponResearchAmount - researchPointsRequired) / (researchPointsRequired * 2)) * 100);
					}
				}
			} break;
	}
	return 0;
}

void TechnologyManager::setPercentage(TechField::Type whichField, int amount)
{
	int remainingPercentile = 100;
	if (this->computerLocked)
	{
		remainingPercentile -= this->computerPercentage;
	}
	if (this->constructionLocked)
	{
		remainingPercentile -= this->constructionPercentage;
	}
	if (this->forceFieldLocked)
	{
		remainingPercentile -= this->forceFieldPercentage;
	}
	if (this->planetologyLocked)
	{
		remainingPercentile -= this->planetologyPercentage;
	}
	if (this->propulsionLocked)
	{
		remainingPercentile -= this->propulsionPercentage;
	}
	if (this->weaponLocked)
	{
		remainingPercentile -= this->weaponPercentage;
	}

	if (amount >= remainingPercentile)
	{
		if (!this->computerLocked)
		{
			this->computerPercentage = 0;
		}
		if (!this->constructionLocked)
		{
			this->constructionPercentage = 0;
		}
		if (!this->forceFieldLocked)
		{
			this->forceFieldPercentage = 0;
		}
		if (!this->planetologyLocked)
		{
			this->planetologyPercentage = 0;
		}
		if (!this->propulsionLocked)
		{
			this->propulsionPercentage = 0;
		}
		if (!this->weaponLocked)
		{
			this->weaponPercentage = 0;
		}
		amount = remainingPercentile;
	}

	//Now scale
	int totalPointsExcludingSelectedType = 0;
	switch (whichField)
	{
		case TechField::COMPUTER:
			{
				this->computerPercentage = amount;
				remainingPercentile -= this->computerPercentage;
				totalPointsExcludingSelectedType = this->getTotalPercentageExcludingTypeAndLocked(TechField::COMPUTER);
			} break;
		case TechField::CONSTRUCTION:
			{
				this->constructionPercentage = amount;
				remainingPercentile -= this->constructionPercentage;
				totalPointsExcludingSelectedType = this->getTotalPercentageExcludingTypeAndLocked(TechField::CONSTRUCTION);
			} break;
		case TechField::FORCE_FIELD:
			{
				this->forceFieldPercentage = amount;
				remainingPercentile -= this->forceFieldPercentage;
				totalPointsExcludingSelectedType = this->getTotalPercentageExcludingTypeAndLocked(TechField::FORCE_FIELD);
			} break;
		case TechField::PLANETOLOGY:
			{
				this->planetologyPercentage = amount;
				remainingPercentile -= this->planetologyPercentage;
				totalPointsExcludingSelectedType = this->getTotalPercentageExcludingTypeAndLocked(TechField::PLANETOLOGY);
			} break;
		case TechField::PROPULSION:
			{
				this->propulsionPercentage = amount;
				remainingPercentile -= this->propulsionPercentage;
				totalPointsExcludingSelectedType = this->getTotalPercentageExcludingTypeAndLocked(TechField::PROPULSION);
			} break;
		case TechField::WEAPON:
			{
				this->weaponPercentage = amount;
				remainingPercentile -= this->weaponPercentage;
				totalPointsExcludingSelectedType = this->getTotalPercentageExcludingTypeAndLocked(TechField::WEAPON);
			} break;
	}

	if (remainingPercentile < totalPointsExcludingSelectedType)
	{
		int amountToDeduct = totalPointsExcludingSelectedType - remainingPercentile;
		int prevValue;
		if (!this->computerLocked && whichField != TechField::COMPUTER)
		{
			prevValue = this->computerPercentage;
			this->computerPercentage -= (this->computerPercentage >= amountToDeduct ? amountToDeduct : this->computerPercentage);
			amountToDeduct -= (prevValue - this->computerPercentage);
		}
		if (amountToDeduct > 0)
		{
			if (!this->constructionLocked && whichField != TechField::CONSTRUCTION)
			{
				prevValue = this->constructionPercentage;
				this->constructionPercentage -= (this->constructionPercentage >= amountToDeduct ? amountToDeduct : this->constructionPercentage);
				amountToDeduct -= (prevValue - this->constructionPercentage);
			}
		}
		if (amountToDeduct > 0)
		{
			if (!this->forceFieldLocked && whichField != TechField::FORCE_FIELD)
			{
				prevValue = this->forceFieldPercentage;
				this->forceFieldPercentage -= (this->forceFieldPercentage >= amountToDeduct ? amountToDeduct : this->forceFieldPercentage);
				amountToDeduct -= (prevValue - this->forceFieldPercentage);
			}
		}
		if (amountToDeduct > 0)
		{
			if (!this->planetologyLocked && whichField != TechField::PLANETOLOGY)
			{
				prevValue = this->planetologyPercentage;
				this->planetologyPercentage -= (this->planetologyPercentage >= amountToDeduct ? amountToDeduct : this->planetologyPercentage);
				amountToDeduct -= (prevValue - this->planetologyPercentage);
			}
		}
		if (amountToDeduct > 0)
		{
			if (!this->propulsionLocked && whichField != TechField::PROPULSION)
			{
				prevValue = this->propulsionPercentage;
				this->propulsionPercentage -= (this->propulsionPercentage >= amountToDeduct ? amountToDeduct : this->propulsionPercentage);
				amountToDeduct -= (prevValue - this->propulsionPercentage);
			}
		}
		if (amountToDeduct > 0)
		{
			if (!this->weaponLocked && whichField != TechField::WEAPON)
			{
				prevValue = this->weaponPercentage;
				this->weaponPercentage -= (this->weaponPercentage >= amountToDeduct ? amountToDeduct : this->weaponPercentage);
				amountToDeduct -= (prevValue - this->weaponPercentage);
			}
		}
	}

	if (remainingPercentile > totalPointsExcludingSelectedType) //excess points needed to allocate
	{
		int amountToAdd = remainingPercentile - totalPointsExcludingSelectedType;
		if (!this->computerLocked && whichField != TechField::COMPUTER)
		{
			this->computerPercentage += amountToAdd;
			amountToAdd = 0;
		}
		if (amountToAdd > 0)
		{
			if (!this->constructionLocked && whichField != TechField::CONSTRUCTION)
			{
				this->constructionPercentage += amountToAdd;
				amountToAdd = 0;
			}
		}
		if (amountToAdd > 0)
		{
			if (!this->forceFieldLocked && whichField != TechField::FORCE_FIELD)
			{
				this->forceFieldPercentage += amountToAdd;
				amountToAdd = 0;
			}
		}
		if (amountToAdd > 0)
		{
			if (!this->planetologyLocked && whichField != TechField::PLANETOLOGY)
			{
				this->planetologyPercentage += amountToAdd;
				amountToAdd = 0;
			}
		}
		if (amountToAdd > 0)
		{
			if (!this->propulsionLocked && whichField != TechField::PROPULSION)
			{
				this->propulsionPercentage += amountToAdd;
				amountToAdd = 0;
			}
		}
		if (amountToAdd > 0)
		{
			if (!this->weaponLocked && whichField != TechField::WEAPON)
			{
				this->weaponPercentage += amountToAdd;
				amountToAdd = 0;
			}
		}
		if (amountToAdd > 0)
		{
			//All fields are already checked, so have to add the remaining back to the current tech field
			switch (whichField)
			{
				case TechField::COMPUTER:
					this->computerPercentage += amountToAdd;
					break;
				case TechField::CONSTRUCTION:
					this->constructionPercentage += amountToAdd;
					break;
				case TechField::FORCE_FIELD:
					this->forceFieldPercentage += amountToAdd;
					break;
				case TechField::PLANETOLOGY:
					this->planetologyPercentage += amountToAdd;
					break;
				case TechField::PROPULSION:
					this->propulsionPercentage += amountToAdd;
					break;
				case TechField::WEAPON:
					this->weaponPercentage += amountToAdd;
					break;
			}
		}
	}
}

/*
public List<TechField> RollForDiscoveries(Random r, SitRepManager sitRepManager)
		{
			List<TechField> fieldsNeedingNewItems = new List<TechField>();
			//Only items being currently researched have a chance of being discovered, otherwise they degrade (handled in AccureResearch function)
			if (ComputerPercentage > 0)
			{
				if (WhichComputerBeingResearched == null && UnresearchedComputerTechs.Count > 0 && ComputerResearchAmount > 0)
				{
					fieldsNeedingNewItems.Add(TechField.COMPUTER);
				}
				else if (WhichComputerBeingResearched != null)
				{
					//See if it is discovered this turn
					int chance = GetChanceForDiscovery(TechField.COMPUTER);
					if (chance > 0 && (r.Next(100) + 1) < chance) //Eureka!  We've discovered the tech!  +1 is to change from 0-99 to 1-100
					{
						sitRepManager.AddItem(new SitRepItem(Screen.Research, null, null, new Point(), WhichComputerBeingResearched.TechName + " has been discovered."));
						ResearchedComputerTechs.Add(WhichComputerBeingResearched);
						UnresearchedComputerTechs.Remove(WhichComputerBeingResearched);
						ComputerResearchAmount = 0;
						fieldsNeedingNewItems.Add(TechField.COMPUTER);
					}
				}
			}

			if (ConstructionPercentage > 0)
			{
				if (WhichConstructionBeingResearched == null && UnresearchedConstructionTechs.Count > 0 && ConstructionResearchAmount > 0)
				{
					fieldsNeedingNewItems.Add(TechField.CONSTRUCTION);
				}
				else if (WhichConstructionBeingResearched != null)
				{
					//See if it is discovered this turn
					int chance = GetChanceForDiscovery(TechField.CONSTRUCTION);
					if (chance > 0 && (r.Next(100) + 1) < chance) //Eureka!  We've discovered the tech!  +1 is to change from 0-99 to 1-100
					{
						sitRepManager.AddItem(new SitRepItem(Screen.Research, null, null, new Point(), WhichConstructionBeingResearched.TechName + " has been discovered."));
						ResearchedConstructionTechs.Add(WhichConstructionBeingResearched);
						UnresearchedConstructionTechs.Remove(WhichConstructionBeingResearched);
						ConstructionResearchAmount = 0;
						fieldsNeedingNewItems.Add(TechField.CONSTRUCTION);
					}
				}
			}

			if (ForceFieldPercentage > 0)
			{
				if (WhichForceFieldBeingResearched == null && UnresearchedForceFieldTechs.Count > 0 && ForceFieldResearchAmount > 0)
				{
					fieldsNeedingNewItems.Add(TechField.FORCE_FIELD);
				}
				else if (WhichForceFieldBeingResearched != null)
				{
					//See if it is discovered this turn
					int chance = GetChanceForDiscovery(TechField.FORCE_FIELD);
					if (chance > 0 && (r.Next(100) + 1) < chance) //Eureka!  We've discovered the tech!  +1 is to change from 0-99 to 1-100
					{
						sitRepManager.AddItem(new SitRepItem(Screen.Research, null, null, new Point(), WhichForceFieldBeingResearched.TechName + " has been discovered."));
						ResearchedForceFieldTechs.Add(WhichForceFieldBeingResearched);
						UnresearchedForceFieldTechs.Remove(WhichForceFieldBeingResearched);
						ForceFieldResearchAmount = 0;
						fieldsNeedingNewItems.Add(TechField.FORCE_FIELD);
					}
				}
			}

			if (PlanetologyPercentage > 0)
			{
				if (WhichPlanetologyBeingResearched == null && UnresearchedPlanetologyTechs.Count > 0 && PlanetologyResearchAmount > 0)
				{
					fieldsNeedingNewItems.Add(TechField.PLANETOLOGY);
				}
				else if (WhichPlanetologyBeingResearched != null)
				{
					//See if it is discovered this turn
					int chance = GetChanceForDiscovery(TechField.PLANETOLOGY);
					if (chance > 0 && (r.Next(100) + 1) < chance) //Eureka!  We've discovered the tech!  +1 is to change from 0-99 to 1-100
					{
						sitRepManager.AddItem(new SitRepItem(Screen.Research, null, null, new Point(), WhichPlanetologyBeingResearched.TechName + " has been discovered."));
						ResearchedPlanetologyTechs.Add(WhichPlanetologyBeingResearched);
						UnresearchedPlanetologyTechs.Remove(WhichPlanetologyBeingResearched);
						PlanetologyResearchAmount = 0;
						fieldsNeedingNewItems.Add(TechField.PLANETOLOGY);
					}
				}
			}

			if (PropulsionPercentage > 0)
			{
				if (WhichPropulsionBeingResearched == null && UnresearchedPropulsionTechs.Count > 0 && PropulsionResearchAmount > 0)
				{
					fieldsNeedingNewItems.Add(TechField.PROPULSION);
				}
				else if (WhichPropulsionBeingResearched != null)
				{
					//See if it is discovered this turn
					int chance = GetChanceForDiscovery(TechField.PROPULSION);
					if (chance > 0 && (r.Next(100) + 1) < chance) //Eureka!  We've discovered the tech!  +1 is to change from 0-99 to 1-100
					{
						sitRepManager.AddItem(new SitRepItem(Screen.Research, null, null, new Point(), WhichPropulsionBeingResearched.TechName + " has been discovered."));
						ResearchedPropulsionTechs.Add(WhichPropulsionBeingResearched);
						UnresearchedPropulsionTechs.Remove(WhichPropulsionBeingResearched);
						PropulsionResearchAmount = 0;
						fieldsNeedingNewItems.Add(TechField.PROPULSION);
					}
				}
			}

			if (WeaponPercentage > 0)
			{
				if (WhichWeaponBeingResearched == null && UnresearchedWeaponTechs.Count > 0 && WeaponResearchAmount > 0)
				{
					fieldsNeedingNewItems.Add(TechField.WEAPON);
				}
				else if (WhichWeaponBeingResearched != null)
				{
					//See if it is discovered this turn
					int chance = GetChanceForDiscovery(TechField.WEAPON);
					if (chance > 0 && (r.Next(100) + 1) < chance) //Eureka!  We've discovered the tech!  +1 is to change from 0-99 to 1-100
					{
						sitRepManager.AddItem(new SitRepItem(Screen.Research, null, null, new Point(), WhichWeaponBeingResearched.TechName + " has been discovered."));
						ResearchedWeaponTechs.Add(WhichWeaponBeingResearched);
						UnresearchedWeaponTechs.Remove(WhichWeaponBeingResearched);
						WeaponResearchAmount = 0;
						fieldsNeedingNewItems.Add(TechField.WEAPON);
					}
				}
			}

			UpdateValues();

			return fieldsNeedingNewItems;
		}
*/

int TechnologyManager::getTotalPercentageExcludingTypeAndLocked(TechField::Type techField)
{
	int total = 0;

	if (!this->computerLocked && techField != TechField::COMPUTER)
	{
		total += this->computerPercentage;
	}
	if (!this->constructionLocked && techField != TechField::CONSTRUCTION)
	{
		total += this->constructionPercentage;
	}
	if (!this->forceFieldLocked && techField != TechField::FORCE_FIELD)
	{
		total += this->forceFieldPercentage;
	}
	if (!this->planetologyLocked && techField != TechField::PLANETOLOGY)
	{
		total += this->planetologyPercentage;
	}
	if (!this->propulsionLocked && techField != TechField::PROPULSION)
	{
		total += this->propulsionPercentage;
	}
	if (!this->weaponLocked && techField != TechField::WEAPON)
	{
		total += this->weaponPercentage;
	}

	return total;
}

void TechnologyManager::updateValues()
{
	//After researching or obtaining a technology, update all values
	this->fuelRange = 3;
	this->roboticControls = 2;
	this->industryWasteRate = 1.0f;
	this->industryCleanupPerBC = 2;
	this->maxTerraformPop = 0;
	this->terraformCost = 6;
	this->cloningCost = 20;
	this->factoryCost = 10;
	this->factoryDiscount = 10;
	this->highestPlanetaryShield = 0;
	Technology* bestArmor = NULL;
	Technology* bestBattleComputer = NULL;
	Technology* bestMissile = NULL;
	Technology* bestShield = NULL;
	Technology* bestECM = NULL;
	int bestScanner = 0;
	for(set<Technology*>::iterator it = this->researchedPropulsionTechs.begin(); it != this->researchedPropulsionTechs.end(); it++)
	{
		if ((*it)->getFuelRange() > this->fuelRange)
		{
			this->fuelRange = (*it)->getFuelRange();
		}
	}
	for(set<Technology*>::iterator it = this->researchedComputerTechs.begin(); it != this->researchedComputerTechs.end(); it++)
	{
		if ((*it)->getRoboticControl() > this->roboticControls)
		{
			this->roboticControls = (*it)->getRoboticControl();
			this->factoryCost = this->roboticControls * 5;
		}
		if ((*it)->getBattleComputer() > 0 && (bestBattleComputer == NULL || bestBattleComputer->getBattleComputer() < (*it)->getBattleComputer()))
		{
			bestBattleComputer = (*it);
		}
		if ((*it)->getEcm() > 0 && (bestECM == NULL || bestECM->getEcm() < (*it)->getEcm()))
		{
			bestECM = (*it);
		}
		if ((*it)->getSpaceScanner() > bestScanner)
		{
			bestScanner = (*it)->getSpaceScanner();
		}
	}
	switch (bestScanner)
	{
		case 0:
			this->fleetRadarRange = 0;
			this->planetRadarRange = 3;
			this->showEnemyETA = false;
			this->radarExplorePlanets = false;
			break;
		case Technology::DEEP_SPACE_SCANNER:
			this->fleetRadarRange = 1;
			this->planetRadarRange = 5;
			this->showEnemyETA = false;
			this->radarExplorePlanets = false;
			break;
		case Technology::IMPROVED_SPACE_SCANNER:
			this->fleetRadarRange = 2;
			this->planetRadarRange = 7;
			this->showEnemyETA = true;
			this->radarExplorePlanets = false;
			break;
		case Technology::ADVANCED_SPACE_SCANNER:
			this->fleetRadarRange = 3;
			this->planetRadarRange = 9;
			this->showEnemyETA = true;
			this->radarExplorePlanets = true;
			break;
	}
	for(set<Technology*>::iterator it = this->researchedConstructionTechs.begin(); it != this->researchedConstructionTechs.end(); it++)
	{
		if ((*it)->getIndustrialWaste() / 100.0f < this->industryWasteRate)
		{
			this->industryWasteRate = (*it)->getIndustrialWaste() / 100.0f;
		}
		if ((*it)->getIndustrialTech() < this->factoryDiscount)
		{
			this->factoryDiscount = (*it)->getIndustrialTech();
		}
		if ((*it)->getArmor() > 0 && (bestArmor == NULL || bestArmor->getArmor() < (*it)->getArmor()))
		{
			bestArmor = (*it);
		}
	}
	for(set<Technology*>::iterator it = this->researchedForceFieldTechs.begin(); it != this->researchedForceFieldTechs.end(); it++)
	{
		if ((*it)->getPlanetaryShield() > this->highestPlanetaryShield)
		{
			this->highestPlanetaryShield = (*it)->getPlanetaryShield();
		}
		if ((*it)->getShield() > 0 && (bestShield == NULL || bestShield->getShield() < (*it)->getShield()))
		{
			bestShield = (*it);
		}
	}
	//Convert FactoryDiscount to a decimal for less math later on
	this->factoryDiscount *= 0.1f;
	for(set<Technology*>::iterator it = this->researchedPlanetologyTechs.begin(); it != this->researchedPlanetologyTechs.end(); it++)
	{
		if ((*it)->getEcoCleanup() > this->industryCleanupPerBC)
		{
			this->industryCleanupPerBC = (*it)->getEcoCleanup();
		}
		if ((*it)->getEnrichment() == Technology::SOIL_ENRICHMENT)
		{
			this->hasSoilEnrichment = true;
		}
		if ((*it)->getEnrichment() == Technology::ADV_SOIL_ENRICHMENT)
		{
			this->hasAdvancedSoilEnrichment = true;
		}
		if ((*it)->getEnrichment() == Technology::ATMOSPHERIC_TERRAFORMING)
		{
			this->hasAtmosphericTerraform = true;
		}
		if ((*it)->getTerraforming() > this->maxTerraformPop)
		{
			this->maxTerraformPop = (*it)->getTerraforming();
		}
		if ((*it)->getTerraformCost() < this->terraformCost)
		{
			this->terraformCost = (*it)->getTerraformCost();
		}
		if ((*it)->getCloning() < this->cloningCost)
		{
			this->cloningCost = (*it)->getCloning();
		}
	}

	for(set<Technology*>::iterator it = this->researchedWeaponTechs.begin(); it != this->researchedWeaponTechs.end(); it++)
	{
		if ((*it)->getWeaponType() == Technology::MISSILE_WEAPON && (bestMissile == NULL || bestMissile->getMaximumWeaponDamage() < (*it)->getMaximumWeaponDamage()))
		{
			bestMissile = (*it);
		}
	}

	//Now add up the cost for missile base this turn
	/* Missile base cost is broken down as following:
		* Battle Scanner and Subspace Interdictor are free
		* Armor = 60% of Large Ship Cost, 1/2 HP of Large Ship HP
		* Missiles = 540% of base cost, 3 missiles fired per base, +1 speed and double range
		* Shields = 61% of Large Ship Cost
		* Battle Computers = 61% of Large Ship Cost
		* ECM = 62% of Large Ship Cost
		* Base Slab (Construction Tech Level 1) = 120 BC
		* */

	map<TechField::Type, int> techLevels;
	techLevels[TechField::FORCE_FIELD] = this->getForceFieldLevel();
	techLevels[TechField::WEAPON] = this->getWeaponLevel();
	techLevels[TechField::PROPULSION] = this->getPropulsionLevel();
	techLevels[TechField::COMPUTER] = this->getComputerLevel();
	techLevels[TechField::CONSTRUCTION] = this->getConstructionLevel();
	techLevels[TechField::PLANETOLOGY] = this->getPlanetologyLevel();

	//Factor in Slab's base price of 120, minus minizaturation
	int levelDifference = techLevels[TechField::CONSTRUCTION];
	if (levelDifference > 50)
	{
		levelDifference = 50; //Cap the miniaturization at 50 levels
	}
	this->missileBaseCost = 120 * (powf(0.5, (levelDifference / 10.0)));
	if (bestArmor != NULL)
	{
		Equipment armor(bestArmor, false);
		this->missileBaseCost += armor.getCost(techLevels, 2) * 0.6f;
	}
	if (bestMissile != NULL)
	{
		Equipment missile(bestMissile, false);
		this->missileBaseCost += missile.getCost(techLevels, 2) * 5.4f;
	}
	if (bestBattleComputer != NULL)
	{
		Equipment battleComputer(bestBattleComputer, false);
		this->missileBaseCost += battleComputer.getCost(techLevels, 2) * 0.61f;
	}
	if (bestECM != NULL)
	{
		Equipment ecm(bestECM, false);
		this->missileBaseCost += ecm.getCost(techLevels, 2) * 0.62f;
	}
	//Since shields don't work in nebulaes, doesn't make sense to build shields
	this->missileBaseCostInNebula = this->missileBaseCost; 
	if (bestShield != NULL)
	{
		Equipment shield(bestShield, false);
		this->missileBaseCost += shield.getCost(techLevels, 2) * 0.61f;
	}
}