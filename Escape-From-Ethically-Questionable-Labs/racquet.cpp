/****************************************************************************
**Program Filename:  racquet.cpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  racquet.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "racquet.hpp"

//default constructor
Racquet::Racquet()
{
	name = "Racquetball Court";
	item = "Racquetball";
	bItem = true;
	bRoom = true;
	inf = NULL;
	rac = NULL;
	gen = NULL;
	ken = NULL;
	ex = NULL;
}


/***************************************************************************
**Function:  move
**Description:  Moves character from room to room and gives options
**Parameters:  Character& c
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Racquet::move(Character& c)
{
	c.setLocation(name);
	std::cout << "You are now in the " << c.getLocation() << std::endl;
	//entry text for this room does not depend on bRoom
	std::cout << "It's basically a big room.  You can play racquetball in " << std::endl;
	std::cout << "it." << std::endl << std::endl;

	int choice = 0;
	while ((choice != 3) && (c.getCounter() > c.getMinCounter()))
	{
		//display moves remaining
		std::cout << "You have " << c.getCounter();
		std::cout << " actions remaining." << std::endl << std::endl;

		//display menu
		std::cout << "Would you like to:" << std::endl;
		std::cout << "1  Practice your mad racquetball skillz."
				<< std::endl;
		std::cout << "2  Look for something useful." << std::endl;
		std::cout << "3  Move to another room." << std::endl;
		std::cout << "4  See the solution." << std::endl;
		std::cin >> choice;

		if (choice == 1)
		{
			c.decCounter();
			special(c);
		}
		if (choice == 2)
		{
			c.decCounter();	
			search(c);
		}
		if (choice == 3)
		{
			c.decCounter();
			moveChoice(c);
		}

		if ((choice > 4) || (choice < 1))
		{
			std::cout << "Invalid Choice" << std::endl << std::endl;
		}
		if (choice == 4)
		{
			solution();
		}
	}
	//Out of time
	if (c.getCounter() == c.getMinCounter())
	{
		lostText();
		c.decCounter();
	}
}

/***************************************************************************
**Function:  moveChoice
**Description:  Gives options and performs selected action
**Parameters:  Character& c
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Racquet::moveChoice(Character& c)
{
	bool vChoice = false;
	int mChoice = 0;
	while (vChoice == false)
	{
		std::cout << "Where would you like to go?" << std::endl;
		std::cout << "1  Infirmary" << std::endl;
		std::cout << "2  Genetics Lab" << std::endl;
		std::cout << "3  Kennels" << std::endl;
		std::cout << "4  Exit" << std::endl;
		std::cin >> mChoice;

		if (mChoice == 1)
		{
			inf->move(c);
			vChoice = true;
		}
		if (mChoice == 2)
		{
			gen->move(c);
			vChoice = true;
		}
		if (mChoice == 3)
		{
			ken->move(c);
			vChoice = true;
		}
		if (mChoice == 4)
		{
			ex->move(c);
			vChoice = true;
		}

		if (vChoice == false)
		{
			std::cout << "Invalid Selection" << std::endl;
		}
	}
}


/***************************************************************************
**Function:  itemText
**Description:  Displays text description of item in room
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Racquet::itemText()
{
	std::cout << "The only thing in here that may be of use is the " << std::endl;
	std::cout << "ball." << std::endl << std::endl;
}


/***************************************************************************
**Function:  special
**Description:  Executes special action
**Parameters:  Character& c
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Racquet::special(Character& c)
{
	specialText();
	bRoom = false;
}


/***************************************************************************
**Function:  specialText
**Description:  Displays special action text
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Racquet::specialText()
{
	std::cout << "Yeah, you're on today!  You could probably take someone's head " << std::endl;
	std::cout << "off with that thing!  It's a shame that your coworker Chad is " << std::endl;
	std::cout << "probably hamster food now.  You could have won back the $20 you " << std::endl;
	std::cout << "lost in that last game.  Bastard cheated anyway.  You shouldn't " << std::endl;
	std::cout << "even have paid him." << std::endl << std::endl;
}