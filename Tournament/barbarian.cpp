/****************************************************************************
**Program Filename:  barbarian.cpp
**Author:  Jason Fisher
**Date:  2/8/2016
**Description:  barbarian.cpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#include "creature.hpp"

/***************************************************************************
**Function:  Default constructor for barbarian object
**Description:  
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Barbarian::Barbarian()
{
	armor = 0;
	strength = 12;
	startingStrength = 12;
	type = "Barbarian";
	name = " ";
	team = 0;
	wins = 0;
	losses = 0;
}


/***************************************************************************
**Function:  Constructor for barbarian object
**Description:  Allows assignment of name
**Parameters:  std::string n
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Barbarian::Barbarian(std::string n, int t)
{
	armor = 0;
	strength = 12;
	startingStrength = 12;
	type = "Barbarian";
	name = n;
	team = t;
	wins = 0;
	losses = 0;
}


/***************************************************************************
**Function:  attack function for barbarian object
**Description:  returns an attack result from 2 to 12
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int Barbarian::attack(int opp)
{
	if (opp == 1)//if opponent is a vampire
	{
		int charm = rand() % 2;//50% chance
		if (charm ==0)
		{
			return 0;
		}
	}

	return rand() % 11 + 2;//%11 should return a number from 0 to 10
}


/***************************************************************************
**Function:  defend function for barbarian object
**Description:  returns an defense result from 2 to 12
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int Barbarian::defend()
{
	return rand() % 11 + 2;//%11 should return a number from 0 to 10
}


/***************************************************************************
**Function:  applyDamage function for barbarian object
**Description:  applies damage to barbarians strength
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Barbarian::applyDamage(int damage)
{
	if (damage > 0)
	{
		strength -= damage;
	}
}

/***************************************************************************
**Function:  recoverHealth function for barbarian object
**Description:  recovers strength after fight
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Barbarian::recoverHealth()
{
	int recovery = rand() % (startingStrength/2) + 1;//should be 1 to 6
	strength += recovery;
	std::cout << name << " recovered " << recovery << " strength!";
	std::cout << std::endl;

	if (strength > startingStrength)//strength cannot be > startingStrength
	{
		strength = startingStrength;
	}
}