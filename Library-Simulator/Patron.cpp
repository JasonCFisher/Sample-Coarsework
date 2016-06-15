/********************************************************
**Author:  Jason Fisher
**Date:  11/28/2015
**Description:  Assignment 10 - Patron.cpp
********************************************************/

#include <iostream>
#include <vector>
#include "Patron.hpp"

/********************************************************
**Description:  Constructor.  Takes parameters for idNum
**and name.  Initializes fineAmount to zero.
********************************************************/
Patron::Patron(std::string idn, std::string n)
{
	idNum = idn;
	name = n;
	fineAmount = 0.00;
}


std::string Patron::getIdNum()
{
	return idNum;
}

std::string Patron::getName()
{
	return name;
}

std::vector<Book*> Patron::getCheckedOutBooks()
{
	return checkedOutBooks;
}

double Patron::getFineAmount()
{
	return fineAmount;
}


/**********************************************************************
**Description:  Adds a pointer to the specified book to the
**checkedOutBooks vector
**********************************************************************/
void Patron::addBook(Book* b)
{
	checkedOutBooks.push_back(b);
}


/**********************************************************************
**Description:  Removes the pointer to the specified book from the 
**checkedOutBooks vector
**********************************************************************/
void Patron::removeBook(Book* b)
{
	int size = checkedOutBooks.size();
	
	for (int count = 0; count < size; count++)
		if (checkedOutBooks.at(count) == b)
		{
			checkedOutBooks.erase(checkedOutBooks.begin()+count);
			count--;
			size--;
		}
}


/***********************************************************************
**Description:  Positive argument increases fine amount.  Negative 
**argument decreases fine amount.
***********************************************************************/
void Patron::amendFine(double amount)
{
	fineAmount += amount;
}