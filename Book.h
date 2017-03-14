/*
 * Author: Zhijiang Dong
 * Date: Jan 15, 2007
 * File: Book.h
 * As a part of the 3110 assignment, this file
 * defines a class Book, which will be sold in 
 * a store
 */

#pragma once
#include <string>
#include <iostream>
#include <sstream>

/*
 * No methods are provided to modify movie information.
 * Book information should be stable, whch means whenever
 * you get a book object, you are not supposed to
 * change book information such as title, and author.
 */

#include "StoreItem.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;


class Book : public StoreItem
{
public:
    //default constructor setting every thing to empty or 0
    Book( std::string title="", std::string author="",
        std::string barcode="", double price=0, int copy=0, int demand=0);

	// destructor
	~Book();

    std::string getTitle() const;

    std::string getAuthor() const;

    //This function returns a dynamically created Book object
    //which is created from a string.
    //The string info must be of the line format specificed in
    //inventory.txt
    Book* createFromString( const std::string info);

    //Print current item to the screen
    void printItem();

private:
    std::string m_title;        // movie title
    std::string m_author;		// movie directors
};
