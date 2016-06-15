/****************************************************************************
**Program Filename:  character.cpp
**Author:  Jason Fisher
**Date:  3/3/2016
**Description:  character.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "character.hpp"

//Default Constructor
Character::Character()
{
	location = " ";
	counter = 25;
	minCounter = 0;
	maxItems = 2;
}


//setLocation
void Character::setLocation(std::string l)
{
	location = l;
}

//getLocation
std::string Character::getLocation()
{
	return location;
}

//decCounter - increments counter
void Character::decCounter()
{
	counter--;
}

//getCounter
int Character::getCounter()
{
	return counter;
}

//getMaxCounter
int Character::getMinCounter()
{
	return minCounter;
}

//getMaxItems
int Character::getMaxItems()
{
	return maxItems;
}

//getLabCoatSize
int Character::getLabCoatSize()
{
	return labCoat.size();
}

//getInventory
std::string Character::getInventory(int x)
{
	return labCoat.at(x);
}


/***************************************************************************
**Function:  addItem
**Description:  adds item to lab coat if lab coat not full
**Parameters:  std::string i
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Character::addItem(std::string i)
{
	if (labCoat.size() < maxItems)
	{
		labCoat.push_back(i);
		std::cout << "Your inventory now contains:" << std::endl;
		for (int count = 0; count < labCoat.size(); count++)
		{
			std::cout << labCoat.at(count) << std::endl;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Your pockets are already bulging with the things you've " << std::endl;
		std::cout << "picked up.  If you try putting anything else in them they'll probably " << std::endl;
		std::cout << "burst like someone's chest in Alien.  Seriously, enough already.  " << std::endl;
		std::cout << "Go use something if you want to pick up more stuff." << std::endl;
	}
}


/***************************************************************************
**Function:  removeItem
**Description:  finds item in inventory and removes
**Parameters:  std::string i
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Character::removeItem(std::string i)
{
	labCoat.erase(find(labCoat.begin(), labCoat.end(), i));

	std::cout << "Your inventory now contains:" << std::endl;
		if (labCoat.size() == 0)
		{
			std::cout << "Nothing." << std::endl;
		}
		for (int count = 0; count < labCoat.size(); count++)
		{
			std::cout << labCoat.at(count) << std::endl;
		}
		std::cout << std::endl;
}