/*
 * Author: Norris, Joel
 * Date: Mar 13, 2017
 * File: Book.cpp
 * As a part of the 3110 assignment, this file
 * implements a class Book, which will be sold in 
 * a store
 */

#include "Book.h"

Book::Book(string title, string author, string barcode, double price, int copy, int demand )
	: m_title(title), m_author(author),
	StoreItem(barcode, price, copy, demand) 
{

}

Book::~Book() {
	cout << "Book Destructor called" << endl;
}

string Book::getTitle() const
{
	return m_title;
}

string Book::getAuthor() const
{
	return m_author;
}

// populate the book object w/ data based on incomming string.
// |Book|1009|C++ Programming: From Problem Analysis to Program Design, Fourth Edition|D.S. Malik|Feb 12, 2008|114.95|9|0|
// |Type|barcode|title|author|date|price|copy|demand|
Book* Book::createFromString( const string info ) {

	// parse the string
	stringstream ss(info);
	string data;
	int i = 0;

	while (getline(ss, data, DELIMITER)) {

		//cout << i << " : " << data << endl;

		switch (i) {
			case 0: 	// discard first two pieces of data, the initial |, that starts off each line, then the type, movie or book
			case 1: break;
			case 2: m_barcode	= data; break;
			case 3: m_title		= data; break;
			case 4: m_author	= data; break;
			case 5: m_date		= data; break;
			case 6: m_price		= stod(data); break;
			case 7: m_copy		= stoi(data); break;
			case 8: m_demand	= stoi(data); break;
		}

		++i;	// iterator! iterate!

	}
	
	return this;

}

// prints out all the relevant movie data
void Book::printItem() {
	
	cout << "********************** Book with barcode " << m_barcode << " **********************" << endl;
	cout << "Title:\t\t"		<< m_title	<< endl;
	cout << "Author:\t\t"		<< m_author << endl;
	cout << "Publish Date:\t"	<< m_date	<< endl;
	cout << "Price:\t\t"		<< m_price	<< endl;
	cout << "# of copy:\t"		<< m_copy	<< endl;
	cout << "# of demand:\t"	<< m_demand << endl;
	cout << endl;

}
