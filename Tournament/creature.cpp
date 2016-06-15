/****************************************************************************
**Program Filename:  creature.cpp
**Author:  Jason Fisher
**Date:  2/8/2016
**Description:  creature.cpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#include "creature.hpp"

//default constructor
Creature::Creature()
{
	armor = 0;
	strength = 0;
	startingStrength = 0;
	std::string type = " ";
	std::string name = " ";
	pointTotal = 0;
	team = 0;
	wins = 0;
	losses = 0;
}


//Constructor
Creature::Creature(std::string n, int t)
{
	armor = 0;
	strength = 0;
	startingStrength = 0;
	std::string type = " ";
	std::string name = n;
	pointTotal = 0;
	team = t;
	wins = 0;
	losses = 0;
}

//getStrength function
int Creature::getStrength()
{
	return strength;
}

//getArmor function
int Creature::getArmor()
{
	return armor;
}

//getName function
std::string Creature::getName()
{
	return name;
}


//getType
std::string Creature::getType()
{
	return type;
}

//getPoints
int Creature::getPoints()
{
	return pointTotal;
}

//getTeam
int Creature::getTeam()
{
	return team;
}

//getWins
int Creature::getWins()
{
	return wins;
}

//getLosses
int Creature::getLosses()
{
	return losses;
}

//setWins
void Creature::setWins()
{
	wins++;
}

//setLosses
void Creature::setLosses()
{
	losses++;
}

/***************************************************************************
**Function:  points function for all creatures
**Description:  increases points based on damage done
**Parameters:  int x
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Creature::points(int x)
{
	if (x < 300)//if medusa didn't use stonegaze
	{
		pointTotal += x;
	}

	else//medusa used stonegaze
	{
		pointTotal += 12;//medusa max damage
	}

}