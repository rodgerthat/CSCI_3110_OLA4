/*
 * Author: Norris, Joel R.
 * Date: Mar 13, 2017
 * File: StoreItem.h
 * As a part of the 3110 assignment, this file
 * contains the implementation of the 
 * base abstract class for the store items
 */
#include "StoreItem.h"

StoreItem::StoreItem(string barcode, double price, int copy, int demand)
{
	m_barcode = barcode;
	m_price = price;
	m_copy = copy;
	m_demand = demand;
}

//Get barcode 
string StoreItem::getBarcode(void) const {
	return m_barcode;
}

//Get price
double StoreItem::getPrice(void) const {
	return m_price;
}

//Get number of copies in the store
int StoreItem::getCopy(void) const {
	return m_copy;
}

//Get number of copies to be ordered
int StoreItem::getDemand(void) const {
	return m_demand;
}

//Increase # of copies by 1
//precondition: m_copy >= 0
void StoreItem::increaseCopy(void) {
	if (m_copy >= 0) ++m_copy;
}

//Decrease # of copies by 1
//precondition: m_copy > 0
void StoreItem::decreaseCopy(void) {
	if (m_copy > 0) --m_copy;
}

//Increase # of copies to be ordered by 1
//precondition: m_copy == 0
void StoreItem::increaseDemand(void) {
	if (m_copy == 0) ++m_demand;
}

//Decrease # of copies to be ordered by 1
//precondition: m_demand > 0
void StoreItem::decreaseDemand(void) {
	if (m_demand > 0) --m_demand;
}

//Compare two store items. Return true if they have the same barcode,
//otherwise false.
bool StoreItem::operator == (const StoreItem & rhs) const
{
	if (m_barcode == rhs.getBarcode()) return true;
	return false;
}

//Compare two store items by barcode
// for sorting pointers in the list
bool StoreItem::operator < (const StoreItem & rhs) const
{
	if (m_barcode < rhs.getBarcode()) return true;
	return false;
}
