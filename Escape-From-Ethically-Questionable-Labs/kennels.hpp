/****************************************************************************
**Program Filename:  kennels.hpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  kennels.hpp File for Final Project
**Input:
**Output:
****************************************************************************/
#ifndef KENNELS_HPP
#define KENNELS_HPP
#include "room.hpp"


//Kennels class - derived from Room
class Kennels:public Room
{
public:
	Kennels();
	
	virtual void special(Character &c);
	virtual void specialText();
	virtual void move(Character &c);
	virtual void moveChoice(Character &c);
	virtual void itemText();
};
#endif