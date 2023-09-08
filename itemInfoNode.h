#include<iostream>
#include<string>
#include"itemInfo.h"
using namespace std;
#ifndef itemInfoNode_H
#define itemInfoNode_H
class ItemInfoNode
{
private:
	ItemInfo item;
	ItemInfoNode* prev;
	ItemInfoNode* next;
public:
	ItemInfoNode() // Default Constructor
	{
		prev = NULL;
		next = NULL;
	}
	void setItemInfo(string product, double price, string rfid, string originalLoc, string currentLoc)
	{
		item.setProduct(product);
		item.setPrice(price);
		item.setRfidTagNumber(rfid);
		item.setOriginalLoc(originalLoc);
		item.setCurrentLoc(currentLoc);
	}
	void setPrev(ItemInfoNode* prev)
	{
		this->prev = prev;
	}
	void setNext(ItemInfoNode* next)
	{
		this->next = next;
	}
	ItemInfo getItem()
	{
		return item;
	}
	ItemInfoNode* getPrev()
	{
		return prev;
	}
	ItemInfoNode* getNext()
	{
		return next;
	}
};
#endif