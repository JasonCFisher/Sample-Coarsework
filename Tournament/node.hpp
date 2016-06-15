/****************************************************************************
**Program Filename:  node.hpp
**Author:  Jason Fisher
**Date:  2/11/2016
**Description:  node.hpp File for Lab 6
**Input:
**Output:
****************************************************************************/
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include "creature.hpp"
/*#include "stack.hpp"*/

class Node
{
protected:
	struct BasicNode
	{
		Creature *fighter;
		BasicNode *next;
		BasicNode(Creature *c)
		{
			fighter = c;
			next = NULL;
		}
	};
	BasicNode *head;
public:
	Node();
	virtual void add(Creature *) = 0;
	virtual void move() = 0;
	void display();
};

#endif