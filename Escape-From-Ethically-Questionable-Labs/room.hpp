/****************************************************************************
**Program Filename:  room.hpp
**Author:  Jason Fisher
**Date:  3/6/2016
**Description:  room.hpp File for Final Project
**Input:
**Output:
****************************************************************************/
#ifndef ROOM_HPP
#define ROOM_HPP
#include "character.hpp"

//Room base class
class Room
{
protected:
	std::string name;
	std::string item;
	bool bItem;
	bool bRoom;
	Room *inf;
	Room *rac;
	Room *gen;
	Room *ken;
	Room *ex;

public:
	Room();
	
	virtual void special(Character& c) = 0;
	void search(Character& c);
	virtual void itemText() = 0;
	virtual void move(Character& c) = 0;
	virtual void moveChoice(Character& c) = 0;
	virtual void specialText() = 0;
	void assignP(Room* i, Room* r, Room* g, Room* k, Room* e);
	void liveHamster();
	void lostText();
	void solution();

	std::string getName();
	std::string getItem();
	bool getBItem();
	bool getBRoom();
	Room* getInf();
	Room* getRac();
	Room* getGen();
	Room* getKen();
	Room* getEx();
};

#endif