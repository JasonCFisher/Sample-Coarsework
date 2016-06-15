/****************************************************************************
**Program Filename:  genetics.cpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  genetics.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "genetics.hpp"

//default constructor
Genetics::Genetics()
{
	name = "Genetics Lab";
	item = "Behemoth";
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
void Genetics::move(Character& c)
{
	c.setLocation(name);
	std::cout << "You are now in the " << c.getLocation() << std::endl;
	if (bRoom == true)
	{
		std::cout << "You crack open the door and see one of the hamsters ." << std::endl;
		std::cout << "enjoying a meal of mad scientists.  You'll have to do " << std::endl;
		std::cout << "something about that hamster before you can do anything " << std::endl;
		std::cout << "else in this room." << std::endl << std::endl;
	}
	else
	{
		std::cout << "The hamster is passed out in the middle of the floor." << std::endl;
		std::cout << "That's funny, you never knew that hamsters could snore.  " << std::endl;
		std::cout << "His paws twitch occasionally like he's dreaming about chasing " << std::endl;
		std::cout << "scientists." << std::endl << std::endl;
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
			std::cout << "1  Try to find a way to knock out the hamster."
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
			if (bRoom == true)
			{
				liveHamster();
			}
			else
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
void Genetics::moveChoice(Character& c)
{
	bool vChoice = false;
	int mChoice = 0;
	while (vChoice == false)
	{
		std::cout << "Where would you like to go?" << std::endl;
		std::cout << "1  Infirmary" << std::endl;
		std::cout << "2  Racquetball Court" << std::endl;
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
			rac->move(c);
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
void Genetics::itemText()
{
	std::cout << "You find the bottle of Behemoth lying on the floor" << std::endl;
	std::cout << "where it must have been dropped after the hamsters started" << std::endl;
	std::cout << "mutating.  Hmmm, still a little left..." << std::endl << std::endl;
}


/***************************************************************************
**Function:  special
**Description:  Executes special action if proper inventory item used
**Parameters:  Character& c
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Genetics::special(Character &c)
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
		if (c.getInventory(choice-1) == "Tranquilizer")
		{
			specialText();
			bRoom = false;
			c.removeItem("Tranquilizer");
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
void Genetics::specialText()
{
	std::cout << "You furtively inch into the room just far enough to reach the " << std::endl;
	std::cout << "nearest part of the hamster's food supply and dump the entire " << std::endl;
	std::cout << "bottle of tranquilizer on it.  Then you go back to the door and " << std::endl;
	std::cout << "wait." << std::endl;
	std::cout << "After a few minutes, the hamster works his way over to the doctored " << std::endl;
	std::cout << "food.  He sniffs at it experimentally for a few seconds and then digs " << std:: endl;  
	std::cout << "in.  He's about halfway through when his eyes cross and he keels over " << std::endl;
	std::cout << "onto his back with his paws twitching in the air." << std::endl << std::endl;
}