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

std::string Book::getTitle() const
{
	return std::string();
}

std::string Book::getAuthor() const
{
	return std::string();
}

Book* Book::createFromString( const string info ) {
	
	// parse the string
	stringstream ss(info);
	string data;

	while (getline(ss, data, DELIMITER)) {

		cout << data << endl;

	}

	return this;

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
