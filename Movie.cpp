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
	: m_title(title), m_director(director),
	StoreItem(barcode, price, copy, demand) 
{

	// do nothing. because we're doing this for polymorphism!

}

Movie::~Movie() {
	cout << "Movie Destructor called" << endl;
}

std::string Movie::getTitle() const
{
	return m_title;
}

std::string Movie::getDirector() const
{
	return m_director;
}


// populate the movie object w/ data based on incomming string.
// |Movie|2000|Spider-Man 3|Sam Raimi|19.99|5|0|
// |Type|barcode|title|director|price|copy|demand|
Movie* Movie::createFromString( const string info ) {
	
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
			case 4: m_director	= data; break;
			case 5: m_price		= stod(data); break;
			case 6: m_copy		= stoi(data); break;
			case 7: m_demand	= stoi(data); break;
		}

		++i;	// iterator! iterate!

	}
	
	return this;

}

// prints out all the relevant movie data
void Movie::printItem() {
	
	cout << "********************** Movie with barcode " << m_barcode << " **********************" << endl;
	cout << "Title:\t\t"		<< m_title		<< endl;
	cout << "Director:\t"		<< m_director	<< endl;
	cout << "Price:\t\t"		<< m_price		<< endl;
	cout << "# of copy:\t"		<< m_copy		<< endl;
	cout << "# of demand:\t"	<< m_demand		<< endl;
	cout << endl;

}

