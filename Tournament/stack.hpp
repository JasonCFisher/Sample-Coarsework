/****************************************************************************
**Program Filename:  stack.hpp
**Author:  Jason Fisher
**Date:  2/11/2016
**Description:  stack.hpp File for Lab 6
**Input:
**Output:
****************************************************************************/
#ifndef STACK_HPP
#define STACK_HPP
#include "node.hpp"

class Stack:public Node
{
public:
	Stack();
	virtual void add(Creature *);//add Creature to top of stack
	virtual void move();//dummy because of node
	Creature *remove();
	BasicNode *getHead();
};

#endif