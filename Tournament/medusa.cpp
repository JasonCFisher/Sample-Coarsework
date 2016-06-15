/****************************************************************************
**Program Filename:  medusa.cpp
**Author:  Jason Fisher
**Date:  2/8/2016
**Description:  medusa.cpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#include "creature.hpp"

/***************************************************************************
**Function:  Default constructor for medusa object
**Description:  
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Medusa::Medusa()
{
	armor = 3;
	strength = 8;
	startingStrength = 8;
	type = "Medusa";
	name = " ";
	pointTotal = 0;
	team = 0;
	wins = 0;
	losses = 0;
}


/***************************************************************************
**Function:  Constructor for medusa object
**Description:  Allows assignment of name
**Parameters:  std::string n
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Medusa::Medusa(std::string n, int t)
{
	armor = 3;
	strength = 8;
	startingStrength = 8;
	type = "Medusa";
	name = n;
	pointTotal = 0;	
	team = t;
	wins = 0;
	losses = 0;
}


/***************************************************************************
**Function:  attack function for Medusa object
**Description:  returns an attack result from 2 to 12
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int Medusa::attack(int opp)
{
	int mDamage;

	if (opp == 1)//if opponent is a vampire
	{
		int charm = rand() % 2;//50% chance
		if (charm ==0)
		{
			return 0;
		}
	}

	mDamage = rand() % 11 + 2;//%11 should return a number from 0 to 10

	if (mDamage == 12)
	{
		std::cout << "Opponent has been turned to stone!" << std::endl;
		return 500;
	}
	else
	{
		return mDamage;
	}
}


/***************************************************************************
**Function:  defend function for medusa object
**Description:  returns an defense result from 1 to 6
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int Medusa::defend()
{
	return rand() % 6 + 1;//%6 should return a number from 0 to 5
}


/***************************************************************************
**Function:  applyDamage function for medusa object
**Description:  applies damage to medusa's strength
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Medusa::applyDamage(int damage)
{
	if (damage > 0)
	{
		strength -= damage;
	}
}


/***************************************************************************
**Function:  recoverHealth function for medusa object
**Description:  recovers strength after fight
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Medusa::recoverHealth()
{
	int recovery = rand() % (startingStrength/2) + 1;//should be 1 to 4
	strength += recovery;
	std::cout << name << " recovered " << recovery << " strength!";
	std::cout << std::endl;

	if (strength > startingStrength)//strength cannot be > startingStrength
	{
		strength = startingStrength;
	}
}