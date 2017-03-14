/*
 * Author: Norris, Joel
 * Date: Mar 13, 2017
 * File: Movie.cpp
 * As a part of the 3110 assignment, this file
 * implements a class Movie, which will be sold in 
 * a store
 */


#include "Movie.h"

Movie::Movie(string title, string director, string barcode, double price, int copy, int demand )
	: m_title(""), m_director(""),
	StoreItem(barcode, price, copy, demand) 
{



}

Movie* Movie::createFromString( const string info ) {
	
	// parse the string
	stringstream ss(info);
	string data;

	while (getline(ss, data, '|')) {

		cout << data << endl;

	}

}

// prints out all the relevant movie data
void Movie::printItem() {
	
	cout << "********************** Movie with barcode " << m_barcode << " **********************" << endl;
	cout << "Title\t\t"		<< m_title << endl;
	cout << "Director\t\t"	<< m_director << endl;
	cout << "Price\t\t"		<< m_price << endl;
	cout << "# of copy\t\t" << m_copy << endl;
	cout << "# of demand\t\t" << m_demand << endl;
	cout << endl;
	

}
