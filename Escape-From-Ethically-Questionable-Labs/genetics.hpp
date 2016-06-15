/****************************************************************************
**Program Filename:  genetics.hpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  genetics.hpp File for Final Project
**Input:
**Output:
****************************************************************************/
#ifndef GENETICS_HPP
#define GENETICS_HPP
#include "room.hpp"


//Genetics class - derived from Room
class Genetics:public Room
{
public:
	Genetics();

	virtual void special(Character &c);
	virtual void specialText();
	virtual void move(Character &c);
	virtual void moveChoice(Character &c);
	virtual void itemText();
};
#endif