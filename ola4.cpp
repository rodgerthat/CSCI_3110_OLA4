// ola4.cpp : Defines the entry point for the console application.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void clearScreen();
void printMainMenu();

int main()
{

	char userInput;		// holder for user's menu choice

	do {

		clearScreen();
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
	system("cls");	// I read that this is bad, but I am unsure of what to do on windows

}
