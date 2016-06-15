/****************************************************************************
**Program Filename:  racquet.hpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  racquet.hpp File for Final Project
**Input:
**Output:
****************************************************************************/
#ifndef RACQUET_HPP
#define RACQUET_HPP
#include "room.hpp"


//Racquet class - derived from Room
class Racquet:public Room
{
public:
	Racquet();

	virtual void special(Character &c);
	virtual void specialText();
	virtual void move(Character &c);
	virtual void moveChoice(Character &c);
	virtual void itemText();
};
#endif