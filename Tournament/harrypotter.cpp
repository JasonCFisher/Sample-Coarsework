/****************************************************************************
**Program Filename:  harrypotter.cpp
**Author:  Jason Fisher
**Date:  2/9/2016
**Description:  harrypotter.cpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#include "creature.hpp"

/***************************************************************************
**Function:  Default constructor for harrypotter object
**Description:  
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
HarryPotter::HarryPotter()
{
	armor = 0;
	strength = 10;
	startingStrength = 10;
	reviveStrength = 20;
	type = "Harry Potter";
	name = " ";
	team = 0;
	wins = 0;
	losses = 0;
	pointTotal = 0;
	rCounter = 0;
}

/***************************************************************************
**Function:  Constructor for harrypotter object
**Description:  Allows assignment of name
**Parameters:  std::string n
**Pre-Condition:
**Post-Condition:
***************************************************************************/
HarryPotter::HarryPotter(std::string n, int t)
{
	armor = 0;
	strength = 10;
	startingStrength = 10;
	reviveStrength = 20;
	type = "Harry Potter";
	name = n;
	team = t;
	wins = 0;
	losses = 0;
	pointTotal = 0;
	rCounter = 0;
}


/***************************************************************************
**Function:  attack function for harrypotter object
**Description:  returns an attack result from 2 to 12
**Parameters:  int opp
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int HarryPotter::attack(int opp)
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
**Function:  defend function for harrypotter object
**Description:  returns an defense result from 2 to 12
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
int HarryPotter::defend()
{
	return rand() % 11 + 2;//%11 should return a number from 0 to 10
}


/***************************************************************************
**Function:  applyDamage function for harrypotter object
**Description:  applies damage to barbarians strength
**Parameters:  int damage
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void HarryPotter::applyDamage(int damage)
{
	if (damage > 0)
	{
		strength -= damage;
	}

	if ((strength <= 0) && (rCounter == 0) && (damage < 300))
	{
		strength = 20;
		rCounter++;
	}
}


/***************************************************************************
**Function:  recoverHealth function for harrypotter object
**Description:  recovers strength after fight
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void HarryPotter::recoverHealth()
{
	int recovery;
	if (rCounter == 0)//if harry has not resurrected
	{	
		recovery = rand() % (startingStrength/2) + 1;//should be 1 to 5
		strength += recovery;
		std::cout << name << " recovered " << recovery << " strength!";
		std::cout << std::endl;

		if (strength > startingStrength)//strength cannot be > startingStrength
		{
			strength = startingStrength;
		}
	}

	else//harry has resurrected
	{
		recovery = rand() % (reviveStrength/2) + 1;//should be 1 to 10
		strength += recovery;
		std::cout << name << " recovered " << recovery << " strength!";
		std::cout << std::endl;

		if (strength > reviveStrength)//strength cannot be > reviveStrength
		{
			strength = reviveStrength;
		}
	}
}