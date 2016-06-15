/************************************************************
**Author:  Jason Fisher
**Date:  11/28/2015
**Description:  Assignment 10 - Library.cpp
************************************************************/

#include <iostream>
#include "Library.hpp"

/************************************************************
**Description:  Default constructor will set currentDate to 
**zero
************************************************************/
Library::Library()
{
	currentDate = 0;
}


/*************************************************************
**Description:  Adds pointer to Book to holdings vector
**
*************************************************************/
void Library::addBook(Book* b)
{
	holdings.push_back(b);
}


/*************************************************************
**Description:  Adds pointer to Patron to members vector
**
*************************************************************/
void Library::addPatron(Patron* p)
{
	members.push_back(p);
}


/**************************************************************
**Description:  Return pointer for book object that contains
**parameter in idCode.  Return NULL if no book found.
**************************************************************/
Book* Library::getBook(std::string bID)
{
	int size = holdings.size();
	Book *ptr = NULL;//initialize pointer to book to NULL
	
	for (int count = 0; count < size; count++)
		if ((holdings.at(count))->getIdCode() == bID)
			ptr = holdings.at(count);//Assign pointer to book to corresponding object

	return ptr;
}


/*****************************************************************
**Description:  Return pointer for Patron object that contains 
**parameter in idNum.  Return NULL if no Patron found.
*****************************************************************/
Patron* Library::getPatron(std::string pID)
{
	int size = members.size();
	Patron *ptr = NULL;//initialize pointer to Patron to NULL

	for (int count = 0; count < size; count++)
		if ((members.at(count))->getIdNum() == pID)
			ptr = members.at(count);//Assign pointer to Patron to corresponding object

	return ptr;
}


/**********************************************************************
**Description:  Checks getBook, getPatron, and location.  Return based 
**on results.  Else, update relevant Book and Patron fields
**********************************************************************/
std::string Library::checkOutBook(std::string pID, std::string bID)
{
	if (getBook(bID) == NULL)
		return "book not found";

	else if (getPatron(pID) == NULL)
		return "patron not found";

	else if (getBook(bID)->getLocation() == CHECKED_OUT)//if location is CHECKED_OUT
		return "book already checked out";

	else if ((getBook(bID)->getLocation()) == ON_HOLD_SHELF && (getBook(bID)->getRequestedBy() != getPatron(pID)))//if location is ON_HOLD_SHELF & book was requested by another Patron
		return "book on hold by other patron";

	else
	{
		getBook(bID)->setCheckedOutBy(getPatron(pID));//update Book checkedOutBy
		getBook(bID)->setDateCheckedOut(currentDate);//update Book dateCheckedOut
		getBook(bID)->setLocation(CHECKED_OUT);//update Book location
		if (getBook(bID)->getRequestedBy() == getPatron(pID))//update Book requestedBy if necessary
			getBook(bID)->setRequestedBy(NULL);
		getPatron(pID)->addBook(getBook(bID));//update Patron checkedOutBooks
		return "check out successful";
	}
}


/**************************************************************************
**Description:  Checks getBook and location.  Return based on results.
**Else, update relevant Book and Patron fields.
**************************************************************************/
std::string Library::returnBook(std::string bID)
{
	if (getBook(bID) == NULL)
		return "book not found";

	else if ((getBook(bID)->getLocation() == ON_SHELF) || (getBook(bID)->getLocation() == ON_HOLD_SHELF))
		return "book already in library";

	else
	{
		getBook(bID)->getCheckedOutBy()->removeBook(getBook(bID));//*Book finds *Patron through getCheckedOutBy(), *Patron calls removeBook w/ (*Book)
		if (getBook(bID)->getRequestedBy() != NULL)//If the book was requested by another Patron
			getBook(bID)->setLocation(ON_HOLD_SHELF);//set location to on hold shelf
		else
			getBook(bID)->setLocation(ON_SHELF);//otherwise, set location to on shelf
		getBook(bID)->setCheckedOutBy(NULL);//set checkedOutBy to NULL
		return "return successful";
	}
}


/********************************************************************************
**Description:  Checks getBook, getPatron, and location.  Return based 
**on results.  Else, update relevant Book fields
********************************************************************************/
std::string Library::requestBook(std::string pID, std::string bID)
{
	if (getBook(bID) == NULL)
		return "book not found";

	else if (getPatron(pID) == NULL)
		return "patron not found";

	else if (getBook(bID)->getRequestedBy() != NULL)//If the book was requested by another Patron
		return "book already on hold";

	else
	{
		getBook(bID)->setRequestedBy(getPatron(pID));//update requestedBy
		if (getBook(bID)->getLocation() == ON_SHELF)//if the book location is on shelf
			getBook(bID)->setLocation(ON_HOLD_SHELF);//set location to on hold shelf
		return "request successful";
	}
}


/*********************************************************************************
**Description:  Take amount paid as parameter.  Check getPatron and return based
**on result.  Else, update fineAmount.
*********************************************************************************/
std::string Library::payFine(std::string pID, double payment)
{
	if (getPatron(pID) == NULL)
		return "patron not found";

	else
	{
		getPatron(pID)->amendFine(-payment);
		return "payment successful";
	}
}


/*********************************************************************************
**Description:  Increment currentDate.  Use amendFine to increase each Patron's
**fineAmount by 0.10 for each overdue Book.
*********************************************************************************/
void Library::incrementCurrentDate()
{
	currentDate++;//increment currentDate

	int size = members.size();//set size to size of members vector

	for (int count = 0; count < size; count++)//for each element in the members vector
	{
		int s = members.at(count)->getCheckedOutBooks().size();//set s to size of checkedOutBooks vector

		for (int index = 0; index < s; index++)//for each element in the checkedOutBooks vector
		{
			if ((currentDate - (members.at(count)->getCheckedOutBooks().at(index)->getDateCheckedOut())) > 21)//if currentDate - dateCheckedOut > 21
				members.at(count)->amendFine(0.10);//use amendFine to increase fineAmount by 0.10
		}
	}
}