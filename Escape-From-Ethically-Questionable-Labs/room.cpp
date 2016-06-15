/****************************************************************************
**Program Filename:  room.cpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  room.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "room.hpp"

//default constructor
Room::Room()
{
	name = " ";
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
**Function:  assignP
**Description:  sets values for pointers to Rooms
**Parameters:  Room *i, Room *r, Room *g, Room *k, Room *e
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Room::assignP(Room *i, Room *r, Room *g, Room *k, Room *e)
{
	inf = i;
	rac = r;
	gen = g;
	ken = k;
	ex = e;
}


/***************************************************************************
**Function:  search
**Description:  checks if room item has already been found and gives choice  
**to add it to inventory if not
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Room::search(Character& c)
{
	if (bItem == true)
	{
		itemText();

		int choice = 0;
		while ((choice != 1) && (choice !=2))
		{
			std::cout << "Would you like to take " << item << " ?" << std::endl;
			std::cout << "1  Yes" << std::endl;
			std::cout << "2  No" << std::endl;
			std::cin >> choice;

			if (choice == 1)
			{
				c.addItem(item);
				bItem = false;
			}
			if ((choice != 1) && (choice !=2))
			{
				std::cout << "Invalid Selection" << std::endl;
			}
		}
	}

	else
	{
		std::cout << "There is nothing else of use in this room.";
		std::cout << std::endl << std::endl;
	}


}


/***************************************************************************
**Function:  liveHamster
**Description:  outputs if hamster still loose in room  
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Room::liveHamster()
{
	std::cout << "It occurs to you that it may not be the best idea in the world " << std::endl;
	std::cout << "to start poking around a room that contains a GIANT MUTANT " << std::endl;
	std::cout << "HAMSTER that will probably rip your face off if you disturb it.  " << std::endl;
	std::cout << "Maybe you should deal with that first." << std::endl << std::endl;
}


/***************************************************************************
**Function:  loseText
**Description:  outputs if counter runs out  
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Room::lostText()
{
	std::cout << "You hear a faint noise behind you.  Turning to look, you see " << std::endl;
	std::cout << "a huge mass of hamstery death charging toward you and you realize " << std::endl;
	std::cout << "that you've pushed your luck too far.  So it ends." << std::endl << std::endl;
	std::cout << "You have died.  Please try again." << std::endl;
}


/***************************************************************************
**Function:  solution
**Description:  show solution 
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Room::solution()
{
	std::cout << "1st deal with your hangover." << std::endl;
	std::cout << "2nd search Infirmary and add Tranquilizer to inventory." << std::endl;
	std::cout << "3rd go to the Racquetball Court and search.  Add the Raquetball " << std::endl;
	std::cout << "    to your inventory." << std::endl;
	std::cout << "4th go to the Genetics Lab and use the Tranquilizer to " << std::endl;
	std::cout << "    get rid of the hamster." << std::endl;
	std::cout << "5th search the Genetics Lab and add Behemoth to your inventory." << std::endl;
	std::cout << "6th go to the Kennels and use the Racquetball to trap the hamster." << std::endl;
	std::cout << "7th search the Kennels and add the Cat to your inventory." << std::endl;
	std::cout << "8th go to the exit and try to get past the hamster.  If you have the " << std::endl;
	std::cout << "    Cat and Behemoth in your inventory, you will be given the option to " << std::endl;
	std::cout << "    create a giant mutant cat.  Select that option and you will win." << std::endl << std::endl;
}

//getName
std::string Room::getName()
{
	return name;
}

//getItem
std::string Room::getItem()
{
	return item;
}

//getBItem
bool Room::getBItem()
{
	return bItem;
}

//getBRoom
bool Room::getBRoom()
{
	return bRoom;
}

//getInf
Room* Room::getInf()
{
	return inf;
}

//getRac
Room* Room::getRac()
{
	return rac;
}

//getGen
Room* Room::getGen()
{
	return gen;
}

//getKen
Room* Room::getKen()
{
	return ken;
}

//getEx
Room* Room::getEx()
{
	return ex;
}