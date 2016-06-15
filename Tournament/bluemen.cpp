/****************************************************************************
**Program Filename:  bluemen.cpp
**Author:  Jason Fisher
**Date:  2/9/2016
**Description:  bluemen.cpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#include "creature.hpp"

/***************************************************************************
**Function:  Default constructor for bluemen object
**Description:  
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
BlueMen::BlueMen()
{
	armor = 3;
	strength = 12;
	startingStrength = 12;
	type = "Nac Mac Feegle";
	name = " ";
	pointTotal = 0;
	team = 0;
	wins = 0;
	losses = 0;
}

/***************************************************************************
**Function:  Default constructor for bluemen object
**Description:  Allows assignment of name
**Parameters:  std::string n
**Pre-Condition:
**Post-Condition:
***************************************************************************/
BlueMen::BlueMen(std::string n, int t)
{
	armor = 3;
	strength = 12;
	startingStrength = 12;
	type = "Nac Mac Feegle";
	name = n;
	pointTotal = 0;
	team = t;
	wins = 0;
	losses = 0;
}

/***************************************************************************
**Function:  attack function for bluemen object
**Description:  returns an attack result from 2 to 20
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int BlueMen::attack(int opp)
{
	if (opp == 1)//if opponent is a vampire
	{
		int charm = rand() % 2;//50% chance
		if (charm ==0)
		{
			return 0;
		}
	}

	return rand() % 19 + 2;//%19 should return a number from 0 to 18
}


/***************************************************************************
**Function:  defend function for bluemen object
**Description:  returns an defense result as follows
**				from 3 to 18 if strength is 9 to 12
**				from 2 to 12 if strength is 5 to 8
**				from 1 to 6 if strenth is 1 to 4
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int BlueMen::defend()
{
	if (strength > 8)
	{
		return rand() % 16 + 3;//%16 should return a number from 0 to 15
	}
	else if (strength > 4)
	{
		return rand() % 11 + 2;//%11 should return a number from 0 to 10
	}
	else
	{
		return rand() % 6 + 1;//%6 should return a number from 0 to 5
	}
}


/***************************************************************************
**Function:  applyDamage function for bluemen object
**Description:  applies damage to bluemen strength
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void BlueMen::applyDamage(int damage)
{
	if (damage > 0)
	{
		strength -= damage;
	}
}


/***************************************************************************
**Function:  recoverHealth function for bluemen object
**Description:  recovers strength after fight
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void BlueMen::recoverHealth()
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