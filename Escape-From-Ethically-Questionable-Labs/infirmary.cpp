/****************************************************************************
**Program Filename:  infirmary.cpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  infirmary.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "infirmary.hpp"

//default constructor
Infirmary::Infirmary()
{
	name = "Infirmary";
	item = "Tranquilizer";
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
void Infirmary::move(Character& c)
{
	c.setLocation(name);
	std::cout << "You are now in the " << c.getLocation() << std::endl;
	if (bRoom == true)
	{
		std::cout << "Consciousness returns to you slowly and painfully.  That was some " << std::endl;
		std::cout << "party.  It seems like there's something you should remember, " << std::endl;
		std::cout << "but you can't think through this hangover.  You crack a bleary " << std::endl;
		std::cout << "eye and realize you're lying on the floor of the infirmary.  " << std::endl;
		std::cout << "Maybe you can find something to deal with this hangover." << std::endl << std::endl;
	}
	else
	{
		std::cout << "This is the infirmary.  Sick people go in here.  Sometimes they " << std::endl;
		std::cout << "even come out again, but that's not guaranteed in a company like " << std::endl;
		std::cout << "this." << std::endl << std::endl;
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
			std::cout << "1  Find something to deal with your hangover."
				<< std::endl;
		}
		std::cout << "2  Look for something useful." << std::endl;
		std::cout << "3  Move to another room." << std::endl;
		std::cout << "4  See the solution." << std::endl;
		std::cin >> choice;

		if ((choice > 4) || (choice < 1))
		{
			std::cout << "Invalid Choice" << std::endl << std::endl;
		}

		if (choice == 1)
		{
			c.decCounter();
			special(c);
		}
		if (choice == 2)
		{
			if (bRoom == true)
			{
				std::cout << "You can't even think of searching the room until your " << std::endl;
				std::cout << "Head stops pounding." << std::endl <<std::endl;
			}
			else
			{
				c.decCounter();
				search(c);
			}
		}
		if (choice == 3)
		{
			if (bRoom == true)
			{
				std::cout << "You can't even think of leaving the room until your " << std::endl;
				std::cout << "Head stops pounding." << std::endl <<std::endl;
				choice = 0;
			}
			else
			{
			c.decCounter();
			moveChoice(c);
			}
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
void Infirmary::moveChoice(Character& c)
{
	bool vChoice = false;
	int mChoice = 0;
	while (vChoice == false)
	{
		std::cout << "Where would you like to go?" << std::endl;
		std::cout << "1  Racquetball Court" << std::endl;
		std::cout << "2  Genetics Lab" << std::endl;
		std::cout << "3  Kennels" << std::endl;
		std::cout << "4  Exit" << std::endl;
		std::cin >> mChoice;

		if (mChoice == 1)
		{
			rac->move(c);
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
void Infirmary::itemText()
{
	std::cout << "While searching through the cabinets, you find a bottle " << std::endl;
	std::cout << "of Doctor Bob Ross's Happy Little Trees Tranquilizer.  You " << std::endl;
	std::cout << "remember that Doctor Ross was trying to create a more relaxing " << std::endl;
	std::cout << "tranquilizer experience and formulated the potion so that the " << std::endl;
	std::cout << "subject would be soothed by hallucinations of peaceful forests " << std::endl;
	std::cout << "and the sound of a soothing voice." << std::endl << std::endl;
}


/***************************************************************************
**Function:  special
**Description:  Executes special action
**Parameters:  Character& c
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Infirmary::special(Character& c)
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
void Infirmary::specialText()
{
	std::cout << "You blearily drag yourself off the floor and stagger over to the " << std::endl;
	std::cout << "medical supplies.  After a brief search, you find a bottle of Dr. " << std::endl;
	std::cout << "Abernathy Montgrave's Improved Hangover Cure and Engine Degreaser. " << std::endl;
	std::cout << "You vaquely remember that Dr. Montgrave's idea of a cold remedy was " << std::endl;
	std::cout << "to remove the patient's sinuses, and you can't imagine what his " << std::endl;
	std::cout << "hangover cure will do or why it would double as an engine degreaser.  " << std:: endl;  
	std::cout << "Oh well.  Anything has to be better than " << std::endl;
	std::cout << "this feeling that the inside of your skull is coated with sandpaper. " << std::endl;
	std::cout << "You close your eyes and take a swig." << std::endl << std::endl;
	std::cout << "The effects are instantaneous and spectacular!  Not only do you feel " << std::endl;
	std::cout << "your head begin to clear but your mouth now tastes minty fresh!  " << std::endl;
	std::cout << "You take a look in the infirmary mirror and find that your hair has " << std::endl;
	std::cout << "is now the color of silver chrome.  Still worth it." << std::endl << std::endl;
	std::cout << "Then it hits you.  Now that your head is clear, you remember the huge " << std::endl;
	std::cout << "party last night to celebrate the perfection of the Behemoth Potion, " << std::endl;
	std::cout << "an unrivaled mad scientific achievement that will turn any creature into " << std::endl;
	std::cout << "a giant mutant beast.  All the employees of Ethically Questionable Labs " << std::endl;
	std::cout << "had been there.  Your last memory of the party is seeing a drunk intern " << std::endl;
	std::cout << "bring in some of the lab hamsters and feeding them some of the Behemoth " << std::endl;
	std::cout << "Potion.  Mother of God..." << std::endl << std::endl << std::endl;
	std::cout << "Welcome player!  Your goal is to get past the giant mutant hamsters and " << std::endl;
	std::cout << "escape from Ethically Questionable Labs.  Of course, hamsters can hear, so " << std::endl;
	std::cout << "you only have a limited number of moves and actions before they find you " << std::endl;
	std::cout << "and turn you into hamster pellets.  Good Luck!" << std::endl << std::endl;
}