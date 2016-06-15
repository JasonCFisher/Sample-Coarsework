/****************************************************************************
**Program Filename:  queue.hpp
**Author:  Jason Fisher
**Date:  2/11/2016
**Description:  queue.hpp File for Lab 6
**Input:
**Output:
****************************************************************************/
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "node.hpp"
#include "stack.hpp"

class Queue:public Node
{
private:
	BasicNode *end;

public:
	Queue();
	virtual void add(Creature *c);
	virtual void move();//move creature to the end of the Queue
	Creature* loss();//remove losing creature from Queue
	void results(Stack l);

	BasicNode *getHead();
};
#endif