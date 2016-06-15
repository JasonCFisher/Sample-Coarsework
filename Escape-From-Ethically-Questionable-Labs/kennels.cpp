/****************************************************************************
**Program Filename:  kennels.cpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  kennels.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "kennels.hpp"

//default constructor
Kennels::Kennels()
{
	name = "Kennels";
	item = "Cat";
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
void Kennels::move(Character& c)
{
	c.setLocation(name);
	std::cout << "You are now in the " << c.getLocation() << std::endl;
	if (bRoom == true)
	{
		std::cout << "Cracking open the door, you see one of the hamsters dozing " << std::endl;
		std::cout << "inside a cage.  The cage door is open, but maybe you could do " << std::endl;
		std::cout << "something about that if you had some way of hitting the door control.";
		std::cout << std::endl << std::endl;
	}
	else
	{
		std::cout << "The hamster snarls and snaps at you as you enter the room, but " << std::endl;
		std::cout << "still can't chew through the bars of the cage." << std::endl << std::endl;
	}
	int choice = 0;
	while ((choice != 3) && (c.getCounter() > c.getMinCounter()))
	{
		//display moves remaining
		std::cout << "You have " << c.getCounter();
		std::cout << " actions remaining." << std::endl << std::endl;

		//display menu
		std::cout << "Would you like to:" << std::endl;
		if (bRoom == true)
		{
			std::cout << "1  Try to trap the hamster in the cage."
				<< std::endl;
		}
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
			if (bRoom == true)
			{
				liveHamster();
			}
			else
			{
				c.decCounter();
				search(c);
			}
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
void Kennels::moveChoice(Character& c)
{
	bool vChoice = false;
	int mChoice = 0;
	while (vChoice == false)
	{
		std::cout << "Where would you like to go?" << std::endl;
		std::cout << "1  Infirmary" << std::endl;
		std::cout << "2  Racquetball Court" << std::endl;
		std::cout << "3  Genetics Lab" << std::endl;
		std::cout << "4  Exit" << std::endl;
		std::cin >> mChoice;

		if (mChoice == 1)
		{
			inf->move(c);
			vChoice = true;
		}
		if (mChoice == 2)
		{
			rac->move(c);
			vChoice = true;
		}
		if (mChoice == 3)
		{
			gen->move(c);
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
void Kennels::itemText()
{
	std::cout << "You hear a plaintive meow.  Following it to one of the " << std::endl;
	std::cout << "smaller cages, you find a cat that the hamster couldn't quite reach. " << std::endl;
	std::cout << "The lab cats have always liked you, because you made your test " << std::endl;
	std::cout << "potions taste like tuna." << std::endl << std::endl;
}


/***************************************************************************
**Function:  special
**Description:  Executes special action if proper inventory item used
**Parameters:  Character& c
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Kennels::special(Character &c)
{
	if (c.getLabCoatSize() == 0)
	{
		std::cout << "You don't have anything to use at the moment.  Maybe you " << std::endl;
		std::cout << "should search some of the rooms." << std::endl << std::endl;
	}
	else
	{
		int choice = 0;
		std::cout << "What would you like to use?" << std::endl;
		for (int count = 0; count < c.getLabCoatSize(); count++)
		{
			std::cout << count+1 << "  " << c.getInventory(count) << std::endl;
		}
		std::cin >> choice;
		if ((choice < 1) || (choice > c.getLabCoatSize()))
		{
			std::cout << "Sorry, that doesn't seem to be a valid choice." << std::endl;
		}
		if (c.getInventory(choice-1) == "Racquetball")
		{
			specialText();
			bRoom = false;
			c.removeItem("Racquetball");
		}
		else
		{
			std::cout << "That probably won't work here.  Maybe you should try " << std::endl;
			std::cout << "something else." << std::endl << std::endl;
		}
	}
}


/***************************************************************************
**Function:  specialText
**Description:  Displays special action text
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Kennels::specialText()
{
	std::cout << "You bounce the ball in your hand for a moment while you judge " << std::endl;
	std::cout << "the distance, then you hurl it at the cage door control.  It " << std::endl;
	std::cout << "hit squarely, and the door slams down!  The trapped hamster " << std::endl;
	std::cout << "launches itself at the bars of the cage, gnawing and clawing " << std::endl;
	std::cout << "at them.  Despite its best efforts, it is firmly trapped.";
	std::cout << std::endl << std::endl;
}