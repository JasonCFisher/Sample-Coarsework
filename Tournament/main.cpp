/****************************************************************************
**Program Filename:  main.cpp
**Author:  Jason Fisher
**Date:  2/8/2016
**Description:  main.cpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#include "creature.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "node.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>


int main()
{
	unsigned seed;	//random generator seed
	seed = time(0);
	srand(seed);

	
	Queue team1;
	Queue team2;
	Stack losers;
	int teamSize = 0;
	int round = 0;

	std::cout << "Please choose the size of the teams.";
	std::cout << std::endl;
	std::cin >> teamSize;

	//Let user select team1
	std::cout << std::endl;
	std::cout << "Pick creatures for Team 1.";
	std::cout << std::endl;
	for (int count = 0; count < teamSize; count++)
	{
		Creature *creature1;
		int typeChoice = 0;
		std::string nameChoice;


		//let user select creature
		std::cout << std::endl;
		std::cout << "Please select character " << count+1 << std::endl;
		std::cout << "1 Barbarian" << std::endl;
		std::cout << "2 Medusa" << std::endl;
		std::cout << "3 Vampire" << std::endl;
		std::cout << "4 Blue Men" << std::endl;
		std::cout << "5 Harry Potter" << std::endl;
		std::cin >> typeChoice;
		std::cin.ignore();
		std::cout << "Please select a name." << std::endl;
		getline(std::cin, nameChoice);

		if (typeChoice == 1)
		{
			creature1 = new Barbarian(nameChoice, 1);
			team1.add(creature1);
		}
		if (typeChoice == 2)
		{
			creature1 = new Medusa(nameChoice, 1);
			team1.add(creature1);
		}
		if (typeChoice == 3)
		{
			creature1 = new Vampire(nameChoice, 1);
			team1.add(creature1);
		}
		if (typeChoice == 4)
		{
			creature1 = new BlueMen(nameChoice, 1);
			team1.add(creature1);
		}
		if (typeChoice == 5)
		{
			creature1 = new HarryPotter(nameChoice, 1);
			team1.add(creature1);
		}
	}


	//let user select team2
	std::cout << std::endl;
	std::cout << "Pick creatures for Team 2.";
	std::cout << std::endl;
	for (int count = 0; count < teamSize; count++)
	{
		Creature *creature2;
		int typeChoice = 0;
		std::string nameChoice;
		

		//let user select creature2
		std::cout << std::endl;
		std::cout << "Please select character " << count+1 << std::endl;
		std::cout << "1 Barbarian" << std::endl;
		std::cout << "2 Medusa" << std::endl;
		std::cout << "3 Vampire" << std::endl;
		std::cout << "4 Blue Men" << std::endl;
		std::cout << "5 Harry Potter" << std::endl;
		std::cin >> typeChoice;
		std::cin.ignore();
		std::cout << "Please select a name." << std::endl;
		getline(std::cin, nameChoice);

		if (typeChoice == 1)
		{
			creature2 = new Barbarian(nameChoice, 2);
			team2.add(creature2);
		}
		if (typeChoice == 2)
		{
			creature2 = new Medusa(nameChoice, 2);
			team2.add(creature2);
		}
		if (typeChoice == 3)
		{
			creature2 = new Vampire(nameChoice, 2);
			team2.add(creature2);
		}
		if (typeChoice == 4)
		{
			creature2 = new BlueMen(nameChoice, 2);
			team2.add(creature2);
		}
		if (typeChoice == 5)
		{
			creature2 = new HarryPotter(nameChoice, 2);
			team2.add(creature2);
		}
	}


	//display fighters for test
	std::cout << "Members of Team 1:" << std::endl << std::endl;
	team1.display();

	std::cout << std::endl << std::endl;
	std::cout << "Members of Team 2:" << std::endl << std::endl;
	team2.display();

	
	//run tournament
	while(team1.getHead() && team2.getHead())
	{
		round++;//increment round
		while ((team1.getHead()->fighter->getStrength() > 0) && (team2.getHead()->fighter->getStrength() > 0))
		{
			int c1Attack = 0;
			int c2Attack = 0;
			int c1Defend = 0;
			int c2Defend = 0;
			int c1Damage = 0;
			int c2Damage = 0;
		
		
			//creature1 attacks
			c1Attack = team1.getHead()->fighter->attack(team2.getHead()->fighter->getArmor());
		
		
			//creature2 defends
			c2Defend = team2.getHead()->fighter->defend();


			//apply damage
			c2Damage = c1Attack - c2Defend - team2.getHead()->fighter->getArmor();
			if (c2Damage > 0)
			{
				team2.getHead()->fighter->applyDamage(c2Damage);
				team1.getHead()->fighter->points(c2Damage);
			}


			if (team2.getHead()->fighter->getStrength() > 0)//creature2 can't attack if it's dead from creature1 attack
			{
				//creature2 attacks
				c2Attack = team2.getHead()->fighter->attack(team1.getHead()->fighter->getArmor());		

				//creature2 defends
				c1Defend = team1.getHead()->fighter->defend();


				//apply damage
				c1Damage = c2Attack - c1Defend - team1.getHead()->fighter->getArmor();
				if (c1Damage > 0)
				{
					team1.getHead()->fighter->applyDamage(c1Damage);
					team2.getHead()->fighter->points(c1Damage);
				}
			}
		}


		//Display winner, increment wins and losses, move creatures
		if (team1.getHead()->fighter->getStrength() > 0)//team1 creature won
		{
			team1.getHead()->fighter->setWins();//add win to team1 creature
			team2.getHead()->fighter->setLosses();//add loss to team2 creature
			std::cout << "Round " << round << " won by Team 1." << std::endl;
			std::cout << team1.getHead()->fighter->getType() << " " << team1.getHead()->fighter->getName();
			std::cout << " has won." << std::endl;
			//display strength before recovery
			std::cout << team1.getHead()->fighter->getName() << " strength after winning = ";
			std::cout << team1.getHead()->fighter->getStrength() << std::endl;
			//recover strength and display
			team1.getHead()->fighter->recoverHealth();
			std::cout << team1.getHead()->fighter->getName() << " strength after recovery = ";
			std::cout << team1.getHead()->fighter->getStrength() << std::endl;
			//report character 1 point total
			std::cout << "Character 1 " << team1.getHead()->fighter->getName() << " points now = ";
			std::cout << team1.getHead()->fighter->getPoints() << std::endl;

			//move winner to end of Queue and loser to Stack
			team1.move();
			losers.add(team2.loss());
		}
		else if (team2.getHead()->fighter->getStrength() > 0)//team2 creature won
		{
			team2.getHead()->fighter->setWins();//add win to team2 creature
			team1.getHead()->fighter->setLosses();//add loss to team1 creature
			std::cout << "Round " << round << " won by Team 2." << std::endl;
			std::cout << team2.getHead()->fighter->getType() << " " << team2.getHead()->fighter->getName();
			std::cout << " has won." << std::endl;
			//display strength before recovery
			std::cout << team2.getHead()->fighter->getName() << " strength after winning = ";
			std::cout << team2.getHead()->fighter->getStrength() << std::endl;
			//recover strength and display
			team2.getHead()->fighter->recoverHealth();
			std::cout << team2.getHead()->fighter->getName() << " strength after recovery = ";
			std::cout << team2.getHead()->fighter->getStrength() << std::endl;
			//report character 1 point total
			std::cout << "Character 2 " << team2.getHead()->fighter->getName() << " points now = ";
			std::cout << team2.getHead()->fighter->getPoints() << std::endl;

			//move winner to end of Queue and loser to Stack
			team2.move();
			losers.add(team1.loss());
		}



		//display fighters for test
		std::cout << "Members of Team 1:" << std::endl << std::endl;
		team1.display();

		std::cout << std::endl << std::endl;
		std::cout << "Members of Team 2:" << std::endl << std::endl;
		team2.display();

		std::cout << std::endl << std::endl;
		std::cout << "Losers from bottom to top of stack:" << std::endl << std::endl;
		losers.display();
	}

	if (team1.getHead())
	{
		team1.results(losers);
	}

	else if (team2.getHead())
	{
		team2.results(losers);
	}
	

	return 0;
}