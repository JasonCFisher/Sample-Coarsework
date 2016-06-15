/****************************************************************************
**Program Filename:  exit.cpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  exit.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "exit.hpp"

//default constructor
Exit::Exit()
{
	name = "Exit";
	item = " ";
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
void Exit::move(Character& c)
{
	c.setLocation(name);
	std::cout << "You are now in the " << c.getLocation() << std::endl;
	if (bRoom == true)
	{
		std::cout << "You open the door to the exit hallway a crack and " << std::endl;
		std::cout << "see one of the hamsters sitting asleep between you " << std::endl;
		std::cout << "and the door.  You'll have to find some way past it to " << std::endl;
		std::cout << "get out." << std::endl << std::endl;
	}
	int choice = 0;
	while ((choice != 3) && (bRoom == true) && (c.getCounter() > c.getMinCounter()))
	{
		//display moves remaining
		std::cout << "You have " << c.getCounter();
		std::cout << " actions remaining." << std::endl << std::endl;

		//display menu
		std::cout << "Would you like to:" << std::endl;
		if (bRoom == true)
		{
			std::cout << "1  Try to get past the hamster."
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
				itemText();
			}
		}
		if (choice == 3)
		{
			c.decCounter();
			moveChoice(c);
		}
		//data validation
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
void Exit::moveChoice(Character& c)
{
	bool vChoice = false;
	int mChoice = 0;
	while (vChoice == false)
	{
		std::cout << "Where would you like to go?" << std::endl;
		std::cout << "1  Infirmary" << std::endl;
		std::cout << "2  Racquetball Court" << std::endl;
		std::cout << "3  Genetics Lab" << std::endl;
		std::cout << "4  Kennels" << std::endl;
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
			ken->move(c);
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
void Exit::itemText()
{
	std::cout << "There is nothing in this room." << std::endl << std::endl;
}


/***************************************************************************
**Function:  special
**Description:  Executes special action if proper inventory item used
**Parameters:  Character& c
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Exit::special(Character &c)
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
		if ((!gen->getBItem()) && (!ken->getBItem()))
		{
			std::cout << c.getLabCoatSize()+1 << "  Create a giant mutant cat to kill the hamster.";
			std::cout << std::endl;
		}
		std::cin >> choice;
		if ((!gen->getBItem()) && (!ken->getBItem()))
		{
			if ((choice < 1) || (choice > c.getLabCoatSize()+1))
			{
				std::cout << "Sorry, that doesn't seem to be a valid choice." << std::endl;
			}
			if (choice == c.getLabCoatSize()+1)
			{
				specialText();
				bRoom = false;
			}
			else
			{
				std::cout << "That probably won't work here.  Maybe you should try " << std::endl;
				std::cout << "something else." << std::endl << std::endl;
			}
		}
		else
		{
			if ((choice < 1) || (choice > c.getLabCoatSize()))
			{
				std::cout << "Sorry, that doesn't seem to be a valid choice." << std::endl;
			}
			else
			{
				std::cout << "That probably won't work here.  Maybe you should try " << std::endl;
				std::cout << "something else." << std::endl << std::endl;
			}
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
void Exit::specialText()
{
	std::cout << "You cross your fingers and pour some of the Behemoth potion " << std::endl;
	std::cout << "onto the ground next to the cat.  The cat laps it up eagerly, " << std::endl;
	std::cout << "thinking that it will be one of your usual, tuna-flavored " << std::endl;
	std::cout << "potions.  You begin to see the effects almost immediately.  " << std::endl;
	std::cout << "The cat gives a low growl as it grows to the size of an enormous " << std::endl;
	std::cout << "lion.  It snarls and launches itself at the panicking hamster.  " << std:: endl;  
	std::cout << "The ensuing battle is short, one-sided, and over in a few moments.  " << std::endl;
	std::cout << "The cat comes back and rubs itself against you, purring and almost " << std::endl;
	std::cout << "knocking you over.  You give your giant mutant cat a few scratches " << std::endl;
	std::cout << "behind the ears." << std::endl << std::endl;
	std::cout << "You leave Ethically Questionable Labs with a mutant " << std::endl;
	std::cout << "cat, your life, and the remains of the Behemoth potion to further your " << std::endl;
	std::cout << "mad scientist goal of world domination.  You vow to find your cat the " << std::endl;
	std::cout << "biggest ball of string in the world!" << std::endl << std::endl;
	std::cout << "Thank you for playing!" << std::endl;
}