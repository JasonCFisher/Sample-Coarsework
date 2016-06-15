/****************************************************************************
**Program Filename:  queue.cpp
**Author:  Jason Fisher
**Date:  2/11/2016
**Description:  queue.cpp File for Lab 6
**Input:
**Output:
****************************************************************************/
#include "queue.hpp"

//default constructor
Queue::Queue()
{
	head = NULL;
	end = NULL;
}

/***************************************************************************
**Function:  add function for Queue object
**Description:  adds value to the end of the linked list
**Parameters:  int
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Queue::add(Creature *c)
{
	if (head == NULL)
	{
		head = new BasicNode(c);
		end = head;
	}
	else
	{
		BasicNode *ptr = new BasicNode(c);
		end->next = ptr;
		end = ptr;
	}
}


/***************************************************************************
**Function:  move function for Queue object
**Description:  removes value from the head of the linked list
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Queue::move()
{
	 Creature *rValue;

	if (!head)
	{
		std::cout << "The Queue contains no creatures." << std::endl;
	}

	else
	{
		rValue = head->fighter;
		BasicNode *temp = head;
		head = head->next;
		delete temp;
		
		add(rValue);
	}
}


/***************************************************************************
**Function:  move function for Queue object
**Description:  removes value from the head of the linked list
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Creature* Queue::loss()
{
	Creature *rValue;

	if (!head)
	{
		std::cout << "The Queue contains no creatures." << std::endl;
	}

	rValue = head->fighter;
	BasicNode *temp = head;
	head = head->next;
	delete temp;
	return rValue;
}

//getHead function
Node::BasicNode * Queue::getHead()
{
	return head;
}


/***************************************************************************
**Function:  results function for node
**Description:  Moves survivors into an array and sorts by points
**				Displays top 3 fighters
**				Gives option to display all fighters
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Queue::results(Stack l)
{
	Creature *cArray[100];
	int arraySize = 0;
	BasicNode *temp;

	//display the winning team
	std::cout << "Team " << head->fighter->getTeam() << " has won.";
	std::cout << std::endl << std::endl;

	//move surviving fighters to array
	while (head)
	{
		cArray[arraySize] = head->fighter;
		temp = head;
		head = head->next;
		delete temp;
		arraySize++;
	}

	//Sort array by points
	Creature *tempCreature;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < (arraySize - 1); count++)
		{
			if (cArray[count]->getPoints() < cArray[count+1]->getPoints())
			{
				tempCreature = cArray[count];
				cArray[count] = cArray[count+1];
				cArray[count+1] = tempCreature;
				swap = true;
			}
		}
	} while (swap);

	//move losers to array
	while (l.getHead())
	{
		cArray[arraySize] = l.remove();
		arraySize++;
	}




	//display top 3 creatures
	for (int index = 0; index < 3; index++)
	{
		//display the fighters
		std::cout << "The number " << index+1 << " fighter is:" << std::endl;
		std::cout << cArray[index]->getType() << " " << cArray[index]->getName();
		std::cout << " from team " << cArray[index]->getTeam() << " with ";
		std::cout << cArray[index]->getWins() << " wins, " << cArray[index]->getLosses();
		std::cout << " losses, and ";
		std::cout << cArray[index]->getPoints() << " points." << std::endl << std::endl;
	}

	//Display the remaining fighters
	int order;
	std::cout << "Would you like to see the order of the remaining fighters?" << std::endl;
	std::cout << "1.  Yes" << std::endl;
	std::cout << "2.  No" << std::endl;
	std::cin >> order;

	if (order == 1)
	{
		for (int index = 3; index < arraySize; index++)
		{
			//display the fighters
			std::cout << "The number " << index+1 << " fighter is:" << std::endl;
			std::cout << cArray[index]->getType() << " " << cArray[index]->getName();
			std::cout << " from team " << cArray[index]->getTeam() << " with ";
			std::cout << cArray[index]->getWins() << " wins, " << cArray[index]->getLosses();
			std::cout << " losses, and ";
			std::cout << cArray[index]->getPoints() << " points." << std::endl << std::endl;
		}
	}
}