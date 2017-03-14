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
	: m_title(""), m_author(""),
	StoreItem(barcode, price, copy, demand) 
{

}

Book::~Book() {
	cout << "Book Destructor called" << endl;
}

std::string Book::getTitle() const
{
	return std::string();
}

std::string Book::getAuthor() const
{
	return std::string();
}

Book* Book::createFromString( const string info ) {
	
	Book book;

	// parse the string
	stringstream ss(info);
	string data;
	int i = 0;

	while (getline(ss, data, DELIMITER)) {

		//cout << data << endl;
		switch (i) {
		case 0: break;	// discard first piece of data, type, movie or book
		case 1: book.m_barcode = data; break;
		case 2: book.m_title = data; break;
		case 3: book.m_author = data; break;
		case 4: book.m_price = stod(data); break;
		case 5: book.m_copy = stoi(data); break;
		case 6: book.m_demand = stoi(data); break;

		}

	}
	
	return &book;

}

// prints out all the relevant movie data
void Book::printItem() {
	
	cout << "********************** Movie with barcode " << m_barcode << " **********************" << endl;
	cout << "Title\t\t"		<< m_title << endl;
	cout << "Author\t\t"	<< m_author << endl;
	cout << "Price\t\t"		<< m_price << endl;
	cout << "# of copy\t\t" << m_copy << endl;
	cout << "# of demand\t\t" << m_demand << endl;
	cout << endl;

}
