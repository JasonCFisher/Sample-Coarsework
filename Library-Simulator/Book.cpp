/******************************************************************
**Author:  Jason Fisher
**Date:  11/28/2015
**Description:  Assignment 10 - Book.cpp
******************************************************************/

#include <iostream>
#include "Book.hpp"



/*****************************************************************
**Description:  Constructor.  Will take parameters for idCode,
**title, and author.  Initializes checkedOutBy and requestedBy to
**NULL.  location will be set to "on the shelf"
*****************************************************************/
Book::Book(std::string idc, std::string t, std::string a)
{
	idCode = idc;
	title = t;
	author = a;
	checkedOutBy = NULL;
	requestedBy = NULL;
	location = ON_SHELF;
}


int Book::getCheckOutLength()
{
	return CHECK_OUT_LENGTH;
}

std::string Book::getIdCode()
{
	return idCode;
}

std::string Book::getTitle()
{
	return title;
}

std::string Book::getAuthor()
{
	return author;
}

Locale Book::getLocation()
{
	return location;
}

Patron* Book::getCheckedOutBy()
{
	return checkedOutBy;
}

Patron* Book::getRequestedBy()
{
	return requestedBy;
}

int Book::getDateCheckedOut()
{
	return dateCheckedOut;
}


void Book::setLocation(Locale l)
{
	location = l;
}

void Book::setCheckedOutBy(Patron* p)
{
	checkedOutBy = p;
}

void Book::setRequestedBy(Patron* p)
{
	requestedBy = p;
}

void Book::setDateCheckedOut(int d)
{
	dateCheckedOut = d;
}