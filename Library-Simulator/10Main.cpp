#include <iostream>
#include "Library.hpp"
#include <vector>


int main()
{
	//test Book constructor
	Book b1("123", "War and Peace", "Tolstoy");
	Book b2("234", "Moby Dick", "Melville");
	Book b3("345", "Phantom Tollbooth", "Juster");

	/*
	std::cout << "b1 info." << std::endl;
	std::cout << "idCode = " << b1.getIdCode() << std::endl;
	std::cout << "title = " << b1.getTitle() << std::endl;
	std::cout << "author = " << b1.getAuthor() << std::endl;
	std::cout << "checkedOutBy = " << b1.getCheckedOutBy() << std::endl;
	std::cout << "requestedBy = " << b1.getRequestedBy() << std::endl;
	std::cout << "location = " << b1.getLocation() << std::endl;
	std::cout << "checkOutLength = " << b1.getCheckOutLength() << std::endl << std::endl;

	std::cout << "b2 info." << std::endl;
	std::cout << "idCode = " << b2.getIdCode() << std::endl;
	std::cout << "title = " << b2.getTitle() << std::endl;
	std::cout << "author = " << b2.getAuthor() << std::endl;
	std::cout << "checkedOutBy = " << b2.getCheckedOutBy() << std::endl;
	std::cout << "requestedBy = " << b2.getRequestedBy() << std::endl;
	std::cout << "location = " << b2.getLocation() << std::endl << std::endl;

	std::cout << "b3 info." << std::endl;
	std::cout << "idCode = " << b3.getIdCode() << std::endl;
	std::cout << "title = " << b3.getTitle() << std::endl;
	std::cout << "author = " << b3.getAuthor() << std::endl;
	std::cout << "checkedOutBy = " << b3.getCheckedOutBy() << std::endl;
	std::cout << "requestedBy = " << b3.getRequestedBy() << std::endl;
	std::cout << "location = " << b3.getLocation() << std::endl << std::endl;*/

	
	//test Patron constructor
	Patron p1("abc", "Felicity");
	Patron p2("bcd", "Waldo");

	/*
	std::cout << "p1 info after constructor." << std::endl;
	std::cout << "idNum = " << p1.getIdNum() << std::endl;
	std::cout << "name = " << p1.getName() << std::endl;
	std::cout << "fineAmount = " << p1.getFineAmount() << std::endl << std::endl;

	std::cout << "p2 info after constructor." << std::endl;
	std::cout << "idNum = " << p2.getIdNum() << std::endl;
	std::cout << "name = " << p2.getName() << std::endl;
	std::cout << "fineAmount = " << p2.getFineAmount() << std::endl << std::endl;*/


	//test Library constructor
	Library lib;


	//test Library addBook
	lib.addBook(&b1);
	lib.addBook(&b2);
	lib.addBook(&b3);

	/*
	std::cout << "Books in lib." << std::endl;
	std::cout << "b1 title in lib = " << lib.getBook("123")->getTitle() << std::endl;
	std::cout << "b2 title in lib = " << lib.getBook("234")->getTitle() << std::endl;
	std::cout << "b3 title in lib = " << lib.getBook("345")->getTitle() << std::endl;
	std::cout << "no book idCode in lib = " << lib.getBook("678") << std::endl << std::endl;*/


	//test Library addPatron
	lib.addPatron(&p1);
	lib.addPatron(&p2);

	//check out books
	lib.checkOutBook("abc", "123");
	lib.checkOutBook("bcd", "234");
	lib.checkOutBook("bcd", "345");


	//confirm checked out books
	std::cout << "p1 checked out books are now ";
	int size = p1.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("abc")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;

	std::cout << "p2 checked out books are now ";
	size = p2.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("bcd")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;


	//increment time by 24 days - books are 3 days overdue
	for (int i=0; i<24; i++)
         lib.incrementCurrentDate();
	std::cout << "p1 fineAmount is " << p1.getFineAmount() << std::endl;
	std::cout << "p2 fineAmount is " << p2.getFineAmount() << std::endl << std::endl;


	//return b3
	lib.returnBook("345");


	//p1 check out b3
	lib.checkOutBook("abc", "345");
	std::cout << "b3 dateCheckedOut is " << b3.getDateCheckedOut() << std::endl << std::endl;


	//p2 pay 0.60 of fine
	std::cout << lib.payFine("bcd", 0.60) << std::endl;
	std::cout << "p2 fineAmount is " << p2.getFineAmount() << std::endl << std::endl;


	//payFine with junk patron
	std::cout << lib.payFine("efg", 0.60) << std::endl;

	//check books
	std::cout << "p1 checked out books are now ";
	size = p1.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("abc")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;

	std::cout << "p2 checked out books are now ";
	size = p2.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("bcd")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;


	//increment time by 24 days
	for (int i=0; i<24; i++)
         lib.incrementCurrentDate();
	std::cout << "p1 fineAmount is " << p1.getFineAmount() << std::endl;
	std::cout << "p2 fineAmount is " << p2.getFineAmount() << std::endl << std::endl;


	//return b3
	std::cout << lib.returnBook("345") << std::endl;


	//p1 check out b3
	lib.checkOutBook("abc", "345");
	std::cout << "b3 dateCheckedOut is " << b3.getDateCheckedOut() << std::endl << std::endl;

	/*
	std::cout << "Patrons in lib." << std::endl;
	std::cout << "p1 name in lib = " << lib.getPatron("abc")->getName() << std::endl;
	std::cout << "p2 name in lib = " << lib.getPatron("bcd")->getName() << std::endl;
	std::cout << "no Patron idNum in lib = " << lib.getPatron("ghi") << std::endl << std::endl;*/


	/*test Library checkOutBook
	std::cout << "Testing checkOutBook for p1, b1." << std::endl;
	std::cout << lib.checkOutBook("abc", "123") << std::endl;
	std::cout << "Checked out by " << b1.getCheckedOutBy()->getName() << std::endl;
	std::cout << "Date checked out " << b1.getDateCheckedOut() << std::endl;
	std::cout << "Location is now " << b1.getLocation() << std::endl;
	std::cout << "p1 checked out books are now " << p1.getCheckedOutBooks().at(0)->getTitle() << std::endl << std::endl;

	std::cout << "Testing checkOutBook for p2, b2." << std::endl;
	std::cout << lib.checkOutBook("bcd", "234") << std::endl;
	std::cout << "Checked out by " << b2.getCheckedOutBy()->getName() << std::endl;
	std::cout << "Date checked out " << b2.getDateCheckedOut() << std::endl;
	std::cout << "Location is now " << b2.getLocation() << std::endl;
	std::cout << "p2 checked out books are now " << p2.getCheckedOutBooks().at(0)->getTitle() << std::endl << std::endl;

	std::cout << "Testing checkOutBook for p1, b2." << std::endl;
	std::cout << lib.checkOutBook("abc", "234") << std::endl;
	std::cout << "Checked out by " << lib.getBook("234")->getCheckedOutBy()->getName() << std::endl;
	std::cout << "Date checked out " << lib.getBook("234")->getDateCheckedOut() << std::endl;
	std::cout << "Location is now " << lib.getBook("234")->getLocation() << std::endl;
	std::cout << "p1 checked out books are now ";
	int size = p1.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("abc")->getCheckedOutBooks().at(count)->getTitle() << std::endl << std::endl;


	std::cout << "Testing checkOutBook for p1, b3." << std::endl;
	std::cout << lib.checkOutBook("abc", "345") << std::endl;
	std::cout << "Checked out by " << lib.getBook("345")->getCheckedOutBy()->getName() << std::endl;
	std::cout << "Date checked out " << lib.getBook("345")->getDateCheckedOut() << std::endl;
	std::cout << "Location is now " << lib.getBook("345")->getLocation() << std::endl;
	std::cout << "p1 checked out books are now " << std::endl;
	size = p1.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("abc")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;


	std::cout << "Testing requestBook for p2, b3." << std::endl;
	std::cout << lib.requestBook("bcd", "345") << std::endl;
	std::cout << "Requested by " << lib.getBook("345")->getRequestedBy()->getName() << std::endl << std::endl;


	std::cout << "Testing requestBook for p1, b3." << std::endl;
	std::cout << lib.requestBook("abc", "345") << std::endl;
	std::cout << "Requested by " << lib.getBook("345")->getRequestedBy()->getName() << std::endl << std::endl;


	std::cout << "Testing requestBook for p1, junk book." << std::endl;
	std::cout << lib.requestBook("abc", "678") << std::endl << std::endl;


	std::cout << "Testing requestBook for junk patron, b1." << std::endl;
	std::cout << lib.requestBook("efg", "123") << std::endl << std::endl;


	std::cout << "Testing returnBook for junk book." << std::endl;
	std::cout << lib.returnBook("456") << std::endl << std::endl;


	std::cout << "Testing returnBook for b3." << std::endl;
	std::cout << lib.returnBook("345") << std::endl;
	std::cout << "Location is now " << lib.getBook("345")->getLocation() << std::endl;
	std::cout << "p1 checked out books are now " << std::endl;
	size = p1.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("abc")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;


	std::cout << "Testing checkOutBook for p2, b3." << std::endl;
	std::cout << lib.checkOutBook("bcd", "345") << std::endl;
	std::cout << "Checked out by " << lib.getBook("345")->getCheckedOutBy()->getName() << std::endl;
	std::cout << "Date checked out " << lib.getBook("345")->getDateCheckedOut() << std::endl;
	std::cout << "Location is now " << lib.getBook("345")->getLocation() << std::endl;
	std::cout << "Requested by " << lib.getBook("345")->getRequestedBy() << std::endl;
	std::cout << "p2 checked out books are now " << std::endl;
	size = p2.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("bcd")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;


	std::cout << "Testing returnBook for b1." << std::endl;
	std::cout << lib.returnBook("123") << std::endl;
	std::cout << "Location is now " << lib.getBook("123")->getLocation() << std::endl;
	std::cout << "p1 checked out books are now " << std::endl;
	size = p1.getCheckedOutBooks().size();
	for (int count = 0; count < size; count++)
		std::cout << lib.getPatron("abc")->getCheckedOutBooks().at(count)->getTitle() << std::endl;
	std::cout << std::endl;


	std::cout << "Testing returnBook for b1." << std::endl;
	std::cout << lib.returnBook("123") << std::endl << std::endl;


	std::cout << "Testing checkOutBook for p1, junk book." << std::endl;
	std::cout << lib.checkOutBook("bcd", "678") << std::endl << std::endl;


	std::cout << "Testing checkOutBook for junk patron, b1." << std::endl;
	std::cout << lib.checkOutBook("efg", "123") << std::endl << std::endl;


	std::cout << "Testing requestBook for p1, b1." << std::endl;
	std::cout << lib.requestBook("abc", "123") << std::endl << std::endl;


	std::cout << "Testing checkOutBook for p2, b1." << std::endl;
	std::cout << lib.checkOutBook("bcd", "123") << std::endl << std::endl;*/

	/*test Library returnBook
	std::cout << "Testing returnBook for b1." << std::endl;
	std::cout << lib.returnBook("123") << std::endl;
	std::cout << "p1 checked out books should now be empty.  " << lib.getPatron("abc")->getCheckedOutBooks().size() << std::endl;
	std::cout << "b1 location should be 0.  " << lib.getBook("123")->getLocation() << std::endl;
	std::cout << "b1 checkedOutBy should bo 0.  " << lib.getBook("123")->getCheckedOutBy() << std::endl << std::endl;


	/*test Library requestBook
	std::cout << "Testing requestBook for p1, b1." << std::endl;
	std::cout << lib.requestBook("abc", "123") << std::endl;
	std::cout << "Book should be requested by Felicity.  " << lib.getBook("123")->getRequestedBy()->getName() << std::endl;
	std::cout << "Book location should be 1.  " << lib.getBook("123")->getLocation() << std::endl << std::endl;


	//test Patron amendFine
	p1.amendFine(1.23);
	std::cout << "checking amendFine function." << std::endl;
	std::cout << "fineAmount after adding 1.23 = " << p1.getFineAmount() << std::endl;

	p1.amendFine(-0.23);
	std::cout << "fineAmount after subtracting 0.23 = " << p1.getFineAmount() << std::endl << std::endl;


	//test Library payFine
	std::cout << "starting fineAmount = " << lib.getPatron("abc")->getFineAmount() << std::endl;
	std::cout << "paying 0.50.  " << lib.payFine("abc", 0.50) << std::endl;
	std::cout << "fineAmount after payment should be 0.5.  " << lib.getPatron("abc")->getFineAmount() << std::endl << std::endl;


	//test incrementCurrentDate
	std::cout << "Starting date should be 0." << std::endl;
	for (int i=0; i<22; i++)
         lib.incrementCurrentDate();//increment currentDate to 23
	std::cout << "Date should now be 22." << std::endl;
	std::cout << "There should be 1 day of late charges equalling 0.10." << std::endl;
	std::cout << "fineAmount after late charges should be 0.6.  " << lib.getPatron("abc")->getFineAmount() << std::endl << std::endl;*/

	return 0;
}