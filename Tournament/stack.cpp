/****************************************************************************
**Program Filename:  stack.cpp
**Author:  Jason Fisher
**Date:  2/11/2016
**Description:  stack.cpp File for Lab 6
**Input:
**Output:
****************************************************************************/
#include "stack.hpp"

//Stack default constructor
Stack::Stack()
{
	head = NULL;
}


/***************************************************************************
**Function:  add function for Stack object
**Description:  adds value to the end of the linked list
**Parameters:  int
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Stack::add(Creature *x)
{
	if (head == NULL)
	{
		head = new BasicNode(x);
	}
	else
	{
		BasicNode *ptr = head;
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}

		ptr->next = new BasicNode(x);
	}
}





/***************************************************************************
**Function:  move function for Stack object
**Description:  removes Creature from the end of the linked list and 
**displays stats
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
Creature* Stack::remove()
{
	BasicNode *nextPtr;
	BasicNode *previousPtr;
	Creature *rValue;//store the value in last node for return

	if (!head)
	{
		std::cout << "The Stack contains no creatures." << std::endl;
		rValue = NULL;
		return rValue;
	}

	else if (head->next == NULL)
	{
		rValue = head->fighter;
		head = NULL;
		return rValue;
	}

	else
	{
		nextPtr = head;

		while(nextPtr->next != NULL)
		{
			previousPtr = nextPtr;
			nextPtr = nextPtr->next;
		}
		rValue = nextPtr->fighter;

		previousPtr->next = nextPtr->next;
		delete nextPtr;
		return rValue;
	}
}

//getHead function
Node::BasicNode * Stack::getHead()
{
	return head;
}

void Stack::move()
{
	std::cout << "This is a dummy function";
}
