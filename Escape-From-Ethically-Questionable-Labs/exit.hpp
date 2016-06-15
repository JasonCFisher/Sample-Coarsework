/****************************************************************************
**Program Filename:  exit.hpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  exit.hpp File for Final Project
**Input:
**Output:
****************************************************************************/
#ifndef EXIT_HPP
#define EXIT_HPP
#include "room.hpp"


//Exit class - derived from Room
class Exit:public Room
{
public:
	Exit();

	virtual void special(Character &c);
	virtual void specialText();
	virtual void move(Character &c);
	virtual void moveChoice(Character &c);
	virtual void itemText();
	//void endGame();
};
#endif