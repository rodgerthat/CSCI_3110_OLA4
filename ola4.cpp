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
#include <algorithm>
#include <typeinfo>

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
using std::sort;

void clearScreen(void);
void printMainMenu(void);
void readInFile(const char * filename, list<StoreItem *>& storeInventory);
void listInventory(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory);
void listMovie(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory);
void listBook(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory);
void returnMovie(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory);
void checkoutItem(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory);
bool compareInventoryItems(StoreItem *first, StoreItem *second);
void pressEnterToContinue(void);

int main()
{

	const char * FILENAME = "inventory.txt";

	// create a list of pointers to hold references to the StoreItems
	list <StoreItem *> storeInventory;
	list <StoreItem *>::iterator it;

	char userInput;		// holder for user's menu choice

	readInFile(FILENAME, storeInventory);	// read in the file data and create new objects, then add their pointers to the list

	// sort the list based on barcode string
	storeInventory.sort(compareInventoryItems);

	// Main menu program loop
	// accept user input and handle accordingly
	do {

		clearScreen();	
		printMainMenu();

		// get initial user command, then clear the cin buffer for future input
		cout << "Please enter your command (M, B, L, R, C, Q):  ";
		cin >> userInput;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		switch (userInput) {
			case 'M':
				// Inquire a movie by title
				listMovie(it, storeInventory);
				break;
			case 'B':
				// Inquire a book by author
				listBook(it, storeInventory);
				break;
			case 'L':
				// List inventory
				listInventory(it, storeInventory);
				break;
			case 'R':
				returnMovie(it, storeInventory);
				// return one movie
				break;
			case 'C':
				checkoutItem(it, storeInventory);
				// Check out
				break;
			case 'Q':
				// quit the main menu
				break;
			default:
				cout << "You input a wrong command!" << endl;
				pressEnterToContinue();
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

// read in a file, create new objects, push returned pointers to objects in list
void readInFile( const char *filename, list<StoreItem *>& storeInventory) {

	cout << "LOADING..." << endl;

	// read in file data, add items to storeInventory list
	ifstream inFile;
	string line;

	inFile.open(filename);

	// get each line in the text file, 
	// as long as there are lines to get, do stuff. 
	// |Movie|2000|Spider-Man 3|Sam Raimi|19.99|5|0|
	while( getline(inFile, line ) ) {

		// check if it's a book or a movie
		// because a string is just a char array...
		if ( line[1] == 'M' ) {

			// create a new Movie object and add to list
			Movie* movie = new Movie();
			storeInventory.push_back(movie->createFromString(line));

		} 
		// technically, if it's not a Movie it's a book, 
		// but I feel like I should check...
		if (line[1] == 'B') {

			// create a new Book object and add it to the list
			Book* book = new Book();
			storeInventory.push_back(book->createFromString(line));
		}

    }

}

// list out store inventory ( in barcode order )
// loop through list of pointers and have each object display it's data
void listInventory(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory) {
	
	/*
	for (it = storeInventory.begin(); it != storeInventory.end(); ++it) {
		(*it).printItem();
	}
	*/

	// verify list contents, displays addresses ( pointers ) in list
	/*
	for (auto item : storeInventory) {
		cout << item << endl;
	}
	*/

	// c++11 version, i'd still like to know how to do it the c++98 way tho...
	for (auto item : storeInventory) {
		item->printItem();
	}
	
	pressEnterToContinue();

}

// 'M' --information for the specified movie.
// The user should be asked to input a movie title and your program should print out all information related to that movie.
// search through the list and output the movie type with the matching title
void listMovie(list<StoreItem*>::iterator it, list<StoreItem*>& storeInventory)
{
	// these are called up to do a typeid comparison at runtime
	// not the most elegant solution. I could globalize these and pass a reference to them
	Movie defaultMovie;
	Book defaultBook;

	string movieTitle;
	
	cout << endl;
	cout << "Please enter the movie title: ";
	getline(cin, movieTitle);

	for (auto item : storeInventory) {
		// if the typeid matches that of movie 
		// AND the title matches the one we're looking for
		// output the movie data
		// the item has to be cast as a Movie pointer, 
		// because StoreItem has no method getTitle()
		if ((typeid(*item) == typeid(defaultMovie)) && (movieTitle == ((Movie *)item)->getTitle())) item->printItem();
	}

	pressEnterToContinue();

}

// 'B'-- Inquire about a specific book by author and display inventory information for the specified book.
// The user should be asked to input(partial) name of an author 
// and your program should print out all information of the book written by that author.
void listBook(list<StoreItem*>::iterator it, list<StoreItem*>& storeInventory)
{
	Movie defaultMovie;
	Book defaultBook;

	string searchAuthor;
	string bookAuthor;

	bool bookFound = false;
	
	cout << endl;
	cout << "Please enter the author name: ";
	getline(cin, searchAuthor);

	for (auto item : storeInventory) {
		// if the typeid matches that of book 
		// AND the title contains part of what we're looking for
		// output the book data
		// the item has to be cast as a Book pointer, 
		// because StoreItem has no method getTitle()
		if ( typeid(*item) == typeid(defaultBook) ) {

			// Example code from Project Description
			/*
			string str1( "Alpha Beta Gamma Delta" );

			string::size_type loc = str1.find( "Omega", 0 );

			if( loc != string::npos ) cout << "Found Omega at " << loc << endl;

			else cout << "Didn't find Omega" << endl; 
			*/

			bookAuthor = ((Book *)item)->getAuthor();

			string::size_type loc = bookAuthor.find(searchAuthor, 0);

			if (loc != string::npos) {
				item->printItem();
				bookFound = true;
			}

		} 
			
	}
	if (!bookFound) cout << "Cannot find book with the author \""<< searchAuthor << "\"" << endl;

	pressEnterToContinue();

}

// 'R'--Return a movie / book to the inventory.
// The user should be asked to input the bar code.
// If the movie / book is in the inventory, 
// the number of copies of the item should be increased by 1 if the number of copies to be ordered is 0, 
// or decrease the number of copies to be ordered by 1 if it is greater than 0.
// ++m_copies if m_demand is 0
// --m_copies if m_demand > 0
void returnMovie(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory) {

	string returnItemBarcode;
	bool itemFound = false;
	
	cout << endl;
	cout << "Please enter the item barcode: ";
	getline(cin, returnItemBarcode);

	for (auto item : storeInventory) {
		// if the typeid matches that of movie 
		// AND the barcode matches as well
		// update the movie data
		//if ( typeid(*item) == typeid(defaultMovie) ) {
		// according to the demo, we don't have to worry about if it's a book or a movie
		// thanks the gods.

		if (returnItemBarcode == item->getBarcode()) {
			
			// ++m_copies if m_demand is 0
			// --m_copies if m_demand > 0
			if (item->getDemand() == 0) item->increaseCopy();
			if (item->getDemand() > 0) item->decreaseCopy();
			cout << "one more copy is added to the item " << returnItemBarcode << endl;
			itemFound = true;

		}
			
	}

	if (!itemFound) cout << "Cannot find book with the barcode "<< returnItemBarcode << endl;

	pressEnterToContinue();
}

// 'C'--Check out a movie / book.
// The user should be asked to input a barcode.
// If the item is in the inventory and the number of copies of the item is > 0, 
// your program should decrease the number of copies on hand by one.
// If the item is in the inventory but there are no copies available, 
// the number of copies to be ordered should be increased by 1. 
// If the item is not in the inventory, an error message should be printed.
void checkoutItem(list<StoreItem *>::iterator it, list<StoreItem *>& storeInventory) {

	string checkoutItemBarcode;
	bool itemFound = false;
	
	cout << endl;
	cout << "Please enter the item barcode: ";
	getline(cin, checkoutItemBarcode);

	for (auto item : storeInventory) {

		if (checkoutItemBarcode == item->getBarcode()) {

			// if m_copies > 0, --m_copies
			// if m_copies == 0
			// ++m_demand
			if (item->getCopy() > 0) {
				item->decreaseCopy();
				cout << "the item " << checkoutItemBarcode << " has been checked out successfully!" << endl;
			}
			if (item->getCopy() == 0) {
				item->increaseDemand();
				cout << "we're out of the item " << checkoutItemBarcode << " and we'll order another copy" << endl;
			}
			itemFound = true;

		}
			
	}

	if (!itemFound) cout << "Cannot find item with the barcode "<< checkoutItemBarcode << endl;

	pressEnterToContinue();
	

}

// compare function for list.sort()
bool compareInventoryItems(StoreItem *first, StoreItem *second) {
	return (*first) < (*second);
}

// I don't like typing things more than I have to.
// wait for the user to press ENTER before continuing.
// subtle program logic pause...
void pressEnterToContinue() {
	cout << "Press ENTER to continue... ";
	//cin.clear();
	//cin.ignore();
	cin.get();
}
