/*
 * Author: Norris, Joel R.
 * Date: Mar 13, 2017
 * File: ola4.cpp
 * As a part of the 3110 assignment, this file
 * contains the main program logic for the store
 */
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

#include "StoreItem.h"
#include "Movie.h"
#include "Book.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::list;
using std::iterator;

const char * FILENAME = "inventory.txt";

list <StoreItem *> storeInventory;
list <StoreItem *>::iterator it;
Book defaultBook;
Movie defaultMovie;

void clearScreen(void);
void printMainMenu(void);
void readInFile(const char * filename);
void listInventory(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory);

int main()
{

	// create a list of pointers to hold references to the StoreItems
	char userInput;		// holder for user's menu choice

	// read in file data, add items to storeInventory list
	ifstream inFile;
	string line;

	inFile.open(FILENAME);

	// get each line in the text file, 
	// as long as there are lines to get, do stuff. 
	// |Movie|2000|Spider-Man 3|Sam Raimi|19.99|5|0|
	while( getline(inFile, line ) ) {

		// check if it's a book or a movie
		// because a string is just a char array...
		if ( line[1] == 'M' ) {

			// create a new Movie object and add to list
			cout << "New Movie created" << endl;
			cout << defaultMovie.createFromString(line) << endl << endl;
			storeInventory.push_back(defaultMovie.createFromString(line));
			

		} 
		// technically, if it's not a Movie it's a book, 
		// but I feel like I should check...
		if (line[1] == 'B') {

			// create a new Book object and add it to the list
			cout << "New Book created" << endl;
			cout << defaultBook.createFromString(line) << endl << endl;
			storeInventory.push_back(defaultBook.createFromString(line));
		}

    }

	// sort the list based on barcode
	//sortStoreInventory();


	// Main menu program loop
	// accept user input and handle accordingly
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
				listInventory(it, storeInventory);
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
		<< "* B         Inquire a book by author                 *" << endl
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



}

// list out store inventory ( in barcode order )
// loop through list of pointers and have each object display it's data
void listInventory(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory) {
	
	/*
	for (it = storeInventory.begin(); it != storeInventory.end(); ++it) {
		(*it).printItem();
	}
	*/

	// verify list contents
	for (auto item : storeInventory) {
		cout << item << endl;
	}

	// c++11 version, i'd still like to know how to do it the c++98 way tho...
	/*	for (auto item : storeInventory) {
		item->printItem();
	}
	*/

}
