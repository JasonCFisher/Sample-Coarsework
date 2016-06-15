/****************************************************************************
**Program Filename:  character.hpp
**Author:  Jason Fisher
**Date:  3/3/2016
**Description:  character.hpp File for Final Project
**Input:
**Output:
****************************************************************************/
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Character
{
private:
	std::string location;
	int counter;
	int minCounter;
	std::vector<std::string> labCoat;
	int maxItems;

public:
	Character();
	
	void setLocation(std::string);
	std::string getLocation();
	void decCounter();
	int getCounter();
	int getMinCounter();
	int getMaxItems();
	int getLabCoatSize();
	std::string getInventory(int);

	void removeItem(std::string);
	void addItem(std::string);
};
#endif