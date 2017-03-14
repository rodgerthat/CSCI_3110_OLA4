/*
 * Author: Zhijiang Dong
 * Date: Jan 15, 2007
 * File: Movie.h
 * As a part of the 3110 assignment, this file
 * defines a class Movie, which will be sold in 
 * a store
 */

#include <iostream>
#include <string>
#include <sstream>

/*
 * No methods are provided to modify movie information.
 * Movie information should be stable, whch means whenever
 * you get a movie object, you are not supposed to
 * change movie information such as title, and director.
 */

#include "StoreItem.h"

using std::string;
using std::stringstream;
using std::cout;
using std::endl;

class Movie : public StoreItem
{
public:
    //default constructor setting every thing to empty or 0
    Movie( std::string title="", std::string director="",
        std::string barcode="", double price=0, int copy=0, int demand=0);

    std::string getTitle() const;

    std::string getDirector() const;

    //This function returns a dynamically created Movie object
    //which is created from a string.
    //The string info must be of the line format specificed in
    //inventory.txt
    Movie* createFromString( const std::string info);

    //Print current item to the screen
    void printItem();

private:
    std::string m_title;        // movie title
    std::string m_director;     // movie directors
};
