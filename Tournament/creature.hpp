/****************************************************************************
**Program Filename:  creature.hpp
**Author:  Jason Fisher
**Date:  2/8/2016
**Description:  creature.hpp File for Assignment 3
**Input:
**Output:
****************************************************************************/
#ifndef CREATURE_HPP
#define CREATURE_HPP
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class Creature
{
protected:
	int armor;
	int strength;
	int startingStrength;
	std::string name;
	std::string type;
	int pointTotal;
	int team;
	int wins;
	int losses;

public:
	Creature();
	Creature(std::string n, int t);
	
	int getStrength();
	int getArmor();
	std::string getType();
	std::string getName();
	int getPoints();
	int getTeam();
	int getWins();
	int getLosses();

	void setWins();
	void setLosses();
	void points(int x);//adds points based on damage done

	virtual int attack(int) = 0;//int IDs defender by armor
	virtual int defend() = 0;
	virtual void applyDamage(int) = 0;
	virtual void recoverHealth() = 0;
};

class Barbarian:public Creature
{
public:
	Barbarian();
	Barbarian(std::string n, int t);

	virtual int attack(int);
	virtual int defend();
	virtual void applyDamage(int);
	virtual void recoverHealth();
};

class Medusa:public Creature
{
public:
	Medusa();
	Medusa(std::string n, int t);

	virtual int attack(int);
	virtual int defend();
	virtual void applyDamage(int);
	virtual void recoverHealth();
};

class Vampire:public Creature
{
public:
	Vampire();
	Vampire(std::string n, int t);

	virtual int attack(int);
	virtual int defend();
	virtual void applyDamage(int);
	virtual void recoverHealth();
};

class BlueMen:public Creature
{
public:
	BlueMen();
	BlueMen(std::string n, int t);

	virtual int attack(int);
	virtual int defend();
	virtual void applyDamage(int);
	virtual void recoverHealth();
};

class HarryPotter:public Creature
{
private:
	int rCounter;
	int reviveStrength;

public:
	HarryPotter();
	HarryPotter(std::string n, int t);

	virtual int attack(int);
	virtual int defend();
	virtual void applyDamage(int);
	virtual void recoverHealth();
};
#endif