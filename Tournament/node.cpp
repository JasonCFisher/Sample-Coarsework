/****************************************************************************
**Program Filename:  node.cpp
**Author:  Jason Fisher
**Date:  2/11/2016
**Description:  node.cpp File for Lab 6
**Input:
**Output:
****************************************************************************/
#include "node.hpp"

//default constructor
Node::Node()
{

}


/***************************************************************************
**Function:  display function for a Node object
**Description:  displays the values in the object
**Parameters:  
**Pre-Condition:
**Post-Condition:
***************************************************************************/
void Node::display()
{
	BasicNode *ptr = head;
	
	if (ptr == NULL)
	{
		std::cout << "empty" << std::endl;
	}

	while (ptr != NULL)
	{
		std::cout << ptr->fighter->getName() << std::endl;
		std::cout << "Strength = ";
		std::cout << ptr->fighter->getStrength() << std::endl;
		std::cout << "Points = ";
		std::cout << ptr->fighter->getPoints() << std::endl << std::endl;
		ptr = ptr->next;
	}
}



