#include<iostream>
#include"itemInfoNode.h"
#include<string>
using namespace std;
#ifndef itemList_H
#define itemList_H
class ItemList
{
private:
	ItemInfoNode* head;
	ItemInfoNode* tail;
	int noOfItems;
public:
	ItemList() // Default Constructor
	{
		head = NULL;
		tail = NULL;
		noOfItems = NULL;
	}
	void insertInfo(string product, double price, string rfid, string originalLoc, string currentLoc)
	{
		ItemInfoNode* newItem = new ItemInfoNode;
		newItem->setItemInfo(product, price, rfid, originalLoc, currentLoc);
		if (noOfItems == 0)
		{
			newItem->setPrev(NULL);
			newItem->setNext(NULL);
			head = newItem;
			tail = newItem;
		}
		else
		{
			ItemInfoNode* temp = head;
			long int rfidDec = hexaToDecimal(rfid);
			while (temp != NULL)
			{
				long int tempRfid = hexaToDecimal(temp->getItem().getRfidTagNumber());
				if (tempRfid > rfidDec)
				{
					newItem->setPrev(temp->getPrev());
					newItem->setNext(temp);
					temp->setPrev(newItem);
					break;

				}
				else if (tempRfid < rfidDec)
				{
					newItem->setNext(temp->getNext());
					temp->setNext(newItem);
					newItem->setPrev(temp);
					break;
				}
				temp = temp->getNext();
			}
		}
		noOfItems++;
	}
	void removeAllPurchased()
	{
		ItemInfoNode* temp = head;
		bool check = false;
		while (temp != NULL)
		{
			if (temp->getItem().getCurrentLoc() == "out")
			{
				ItemInfoNode* deleteNode = temp;
				cout << "\nProduct : " << temp->getItem().getProduct() << endl;
				cout << "Price : $ " << temp->getItem().getPrice() << endl;
				cout << "RFID Tag Number : " << temp->getItem().getRfidTagNumber() << endl;
				cout << "Orginal Location : " << temp->getItem().getOriginalLoc() << endl;
				cout << "Current Location : " << temp->getItem().getCurrentLoc() << endl;
				temp = temp->getNext();
				delete deleteNode;
				check = true;
				noOfItems--;
			}
			else
				temp = temp->getNext();
		}
		if (!(check))
		{
			cout << "\nThere are none of checked out products in the list." << endl;
		}
	}
	bool moveItem(string rfid, string source, string dest)
	{
		if (!(originalLocFormat(dest)) && !(currentLocFormat(dest)) && source == "out")
		{
			cout << "\nPlease Enter the Source or Destination in valid format." << endl;
			return false;
		}
		else
		{
			ItemInfoNode* temp = head;
			ItemInfo tempItem;
			string tempLoc;
			string tempRfid;
			while (temp != NULL)
			{
				tempItem = temp->getItem();
				tempLoc = tempItem.getCurrentLoc();
				tempRfid = tempItem.getRfidTagNumber();
				if (tempRfid == rfid && tempLoc == source)
				{
					temp->getItem().setCurrentLoc(dest);
					return true;
				}
				else
					temp = temp->getNext();
			}
			return false;
		}
	}
	void printAll()
	{
		ItemInfoNode* temp = head;
		while (temp != NULL)
		{
			cout << "\nProduct : " << temp->getItem().getProduct() << endl;
			cout << "Price $ : " << temp->getItem().getPrice() << endl;
			cout << "RFID Tag Number : " << temp->getItem().getRfidTagNumber() << endl;
			cout << "Orginal Location : " << temp->getItem().getOriginalLoc() << endl;
			cout << "Current Location : " << temp->getItem().getCurrentLoc() << endl;
			temp = temp->getNext();
		}
	}
	void printByLocation(string location)
	{
		ItemInfoNode* temp = head;
		while (temp != NULL)
		{
			if (temp->getItem().getCurrentLoc() == location)
			{
				cout << "\nProduct : " << temp->getItem().getProduct() << endl;
				cout << "Price : $ " << temp->getItem().getPrice() << endl;
				cout << "RFID Tag Number : " << temp->getItem().getRfidTagNumber() << endl;
				cout << "Orginal Location : " << temp->getItem().getOriginalLoc() << endl;
				cout << "Current Location : " << temp->getItem().getCurrentLoc() << endl;
			}
			temp = temp->getNext();
		}
	}
	void printByRFID(string rfid)
	{
		ItemInfoNode* temp = head;
		while (temp != NULL)
		{
			if (temp->getItem().getRfidTagNumber() == rfid)
			{
				cout << "\nProduct : " << temp->getItem().getProduct() << endl;
				cout << "Price : $ " << temp->getItem().getPrice() << endl;
				cout << "RFID Tag Number : " << temp->getItem().getRfidTagNumber() << endl;
				cout << "Orginal Location : " << temp->getItem().getOriginalLoc() << endl;
				cout << "Current Location : " << temp->getItem().getCurrentLoc() << endl;
			}
			temp = temp->getNext();
		}
	}
	void cleanStore()
	{
		ItemInfoNode* temp = head;
		while (temp != NULL)
		{
			if (temp->getItem().getCurrentLoc() != "out" && temp->getItem().getCurrentLoc()[0] != 'c')
			{
				cout << "\nProduct : " << temp->getItem().getProduct() << endl;
				cout << "Price : $ " << temp->getItem().getPrice() << endl;
				cout << "RFID Tag Number : " << temp->getItem().getRfidTagNumber() << endl;
				cout << "Orginal Location : " << temp->getItem().getOriginalLoc() << endl;
				cout << "Current Location : " << temp->getItem().getCurrentLoc() << endl;
				temp->getItem().setCurrentLoc(temp->getItem().getOriginalLoc());
			}
			temp = temp->getNext();
		}
	}
	double checkout(string cartNumber)
	{
		ItemInfoNode* temp = head;
		double totalCost = 0.0;
		while (temp != NULL)
		{
			if (temp->getItem().getCurrentLoc() == cartNumber)
			{
				totalCost += temp->getItem().getPrice();
				cout << "\nProduct : " << temp->getItem().getProduct() << endl;
				temp->getItem().setCurrentLoc("out");
			}
			temp = temp->getNext();
		}
		return totalCost;
	}
};
#endif