/*
 * Author: Norris, Joel R.
 * Date: Mar 13, 2017
 * File: ola4.cpp
 * As a part of the 3110 assignment, this file
 * contains the main program logic for the store
 */

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

#include "StoreItem.h"
#include "Movie.h"
//#include "Book.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;

const char * FILENAME = "inventory.txt";

void clearScreen();
void printMainMenu();

void readInFile(const char * filename);

int main()
{

	// read in file data first
	readInFile(FILENAME);

	char userInput;		// holder for user's menu choice

	do {

		//clearScreen();	// TODO: put this back in
		printMainMenu();

		cout << "Please enter your command (M, B, L, R, C, Q):  ";
		cin >> userInput;

		switch (userInput) {
			case 'M':
				// Inquire a movie by title
				break;
			case 'B':
				// Inquire a book by author
				break;
			case 'L':
				// List inventory
				break;
			case 'R':
				// return one movie
				break;
			case 'C':
				// Check out
				break;
			case 'Q':
				// quit the main menu
				break;
			default:
				cout << "You input a wrong command!" << endl;
				cout << "Press ENTER to continue..." << endl;
				cin.ignore();
				cin.get();
		}

	} while ( userInput != 'Q' );

	return 0;
}

void printMainMenu() {

	cout  
		<< "                 MiniMovie Store" << endl
		<< "******************************************************" << endl
		<< "* Command   Description                              *" << endl
		<< "* M         Inquire a movie by title                 *" << endl
		<< "* B         Inquire a book by author				 *" << endl
		<< "* L         List inventory                           *" << endl
		<< "* R         return one movie                         *" << endl
		<< "* C         Check out                                *" << endl
		<< "* Q         Quit the main menu                       *" << endl
		<< "******************************************************" << endl;

}

void clearScreen() {

	//out << "\033[2J\033[1;1H";		// works on linux
	system("cls");	// I read that system calls are bad, but I am unsure of what to do on windows

}

void readInFile( const char *filename) {

	ifstream inFile;

	inFile.open(filename);

	string aStringVariable;
	string aVariable;
	string stringVariable2HoldValue;
	
	string line;

	while( getline(inFile, line ) ) {

		//stringstream ss(line);
		//ss >> aVariable;
		//getline(ss, data, '|');

		// |Movie|2000|Spider-Man 3|Sam Raimi|19.99|5|0|

		// check if it's a book or a movie
		if ( line[1] == 'M' ) {

			// create a new Movie object and add to list
			Movie movie(line);
		} 
		// technically, if it's not a Movie it's a book, 
		// but I feel like I should check...
		if (line[1] == 'B') {

			// create a new Book object and add it to the list
			//Book book(line);
			cout << "New book created! YAY!" << endl;
		}

		//stringstream ss(line);

		// save this madness for in the class...
		// you just have to pass each class a string in the constructor...
		/*
		ss >> mediaType
			>> barCode
			>> title
			>> author_director
			>> price
			>> copies
			>> demand;
		cout << "line : " << line << endl;

		cout << line[0] << endl;
		cout << line[1] << endl;
		cout << line[3] << endl;
		cout << endl;

		ss >> aVariable;

		getline(ss, stringVariable2HoldValue, '|'); 

		cout << "stringVariable2HoldValue : " << stringVariable2HoldValue << endl;

		cout << endl;
		*/

		//stringstream ss(aStringVariable);

		//ss >> aVariable;

		//getline(ss, stringVariable2HoldValue, '|');

    }


}
