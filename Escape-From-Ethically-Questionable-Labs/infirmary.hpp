/****************************************************************************
**Program Filename:  infirmary.hpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  infirmary.hpp File for Final Project
**Input:
**Output:
****************************************************************************/
#ifndef INFIRMARY_HPP
#define INFIRMARY_HPP
#include "room.hpp"


//Infirmary class - derived from Room
class Infirmary:public Room
{
public:
	Infirmary();


	virtual void special(Character &c);
	virtual void specialText();
	virtual void move(Character &c);
	virtual void moveChoice(Character &c);
	virtual void itemText();
};
#endif