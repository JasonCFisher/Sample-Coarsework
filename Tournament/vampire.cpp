/****************************************************************************
**Program Filename:  vampire.cpp
**Author:  Jason Fisher
**Date:  2/9/2016
**Description:  vampire.cpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#include "creature.hpp"

/***************************************************************************
**Function:  Default constructor for vampire object
**Description:  
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Vampire::Vampire()
{
	armor = 1;
	strength = 18;
	startingStrength = 18;
	type = "Vampire";
	name = " ";
	pointTotal = 0;
	team = 0;
	wins = 0;
	losses = 0;
}


/***************************************************************************
**Function:  Constructor for vampire object
**Description:  Allows assignment of name
**Parameters:  std::string n
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Vampire::Vampire(std::string n, int t)
{
	armor = 1;
	strength = 18;
	startingStrength = 18;
	type = "Vampire";
	name = n;
	pointTotal = 0;
	team = t;
	wins = 0;
	losses = 0;
}

/***************************************************************************
**Function:  attack function for vampire object
**Description:  returns an attack result from 1 to 12
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int Vampire::attack(int opp)
{
	if (opp == 1)//if opponent is a vampire
	{
		int charm = rand() % 2;//50% chance
		if (charm ==0)
		{
			return 0;
		}
	}

	return rand() % 12 + 1;//%12 should return a number from 0 to 11
}


/***************************************************************************
**Function:  defend function for vampire object
**Description:  returns an defense result from 1 to 6
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int Vampire::defend()
{
	return rand() % 6 + 1;//%6 should return a number from 0 to 5
}


/***************************************************************************
**Function:  applyDamage function for vampire object
**Description:  applies damage to vampires's strength
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Vampire::applyDamage(int damage)
{
	if (damage > 0)
	{
		strength -= damage;
	}
}


/***************************************************************************
**Function:  recoverHealth function for vampire object
**Description:  recovers strength after fight
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Vampire::recoverHealth()
{
	int recovery = rand() % (startingStrength/2) + 1;//should be 1 to 9
	strength += recovery;
	std::cout << name << " recovered " << recovery << " strength!";
	std::cout << std::endl;

	if (strength > startingStrength)//strength cannot be > startingStrength
	{
		strength = startingStrength;
	}
}