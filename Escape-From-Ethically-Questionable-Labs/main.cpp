/****************************************************************************
**Program Filename:  main.cpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  main.cpp File for Final Project
**Input:
**Output:
****************************************************************************/
#include "room.hpp"
#include "infirmary.hpp"
#include "racquet.hpp"
#include "genetics.hpp"
#include "kennels.hpp"
#include "exit.hpp"


int main()
{
	int mChoice = 0;
	while (mChoice != 2)
	{
		std::cout << "Would you like to play?" << std::endl;
		std::cout << "1  Yes" << std::endl;
		std::cout << "2  No" << std::endl;
		std::cin >> mChoice;

		if ((mChoice != 1) && (mChoice != 2))
		{
			std::cout << "Invalid Selection." << std::endl << std::endl;
		}
		if (mChoice == 1)
		{
			//initialize objects
			Character p1;
			Room *i1 = new Infirmary();
			Room *r1 = new Racquet();
			Room *g1 = new Genetics();
			Room *k1 = new Kennels();
			Room *e1 = new Exit();

			//assign pointers
			i1->assignP(i1, r1, g1, k1, e1);
			r1->assignP(i1, r1, g1, k1, e1);
			g1->assignP(i1, r1, g1, k1, e1);
			k1->assignP(i1, r1, g1, k1, e1);
			e1->assignP(i1, r1, g1, k1, e1);


			//start game
			i1->move(p1);

			//delete pointers at the end of the game
			delete i1;
			delete r1;
			delete g1;
			delete k1;
			delete e1;
		}
		if (mChoice == 2)
		{
			std::cout << "Goodbye" << std::endl;
		}
	}


	return 0;
}