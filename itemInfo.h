#include<iostream>
#include<string>
#include"functions.h"
using namespace std;
#ifndef itemInfo_H
#define itemInfo_H
class ItemInfo
{
private:
	string product;
	double price;
	string rfidTagNumber;
	string originalLoc;
	string currentLoc;
public:
	ItemInfo() // Default Constructor
	{
		product = "";
		price = NULL;
		rfidTagNumber = "";
		originalLoc = "";
		currentLoc = "";
	}
	void setProduct(string product)
	{
		this->product = product;
	}
	void setPrice(double price)
	{
		if (price > 0)
			this->price = price;
		else
			cout << "\n!!! Invalid Input !!! Please Enter the price in positive double.\n";
	}
	void setRfidTagNumber(string rfidTagNumber)
	{
		if (rfidTagNumberFormat(rfidTagNumber))
			this->rfidTagNumber = rfidTagNumber;
		else
			cout << "\n!!! Invalid Input !!! Please Enter the RFID Tag Number in Hexadecimal format.\n";
	}
	void setOriginalLoc(string originalLoc)
	{
		if (originalLocFormat(originalLoc))
			this->originalLoc = originalLoc;
		else
			cout << "\n!!! Invalid Input !!! Please Enter the Original Location in valid format.\n";
	}
	void setCurrentLoc(string currentLoc)
	{
		if (currentLocFormat(currentLoc) || originalLocFormat(currentLoc))
			this->currentLoc = currentLoc;
		else
			cout << "\n!!! Invalid Input !!! Please Enter the Current Location in valid format.\n";
	}
	string getProduct()
	{
		return product;
	}
	double getPrice()
	{
		return price;
	}
	string getRfidTagNumber()
	{
		return rfidTagNumber;
	}
	string getOriginalLoc()
	{
		return originalLoc;
	}
	string getCurrentLoc()
	{
		return currentLoc;
	}

};
#endif