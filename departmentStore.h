#include<iostream>
#include"itemList.h"
#include"functions.h"
#include<string>
using namespace std;
#ifndef	departmentStore_H
#define departmentStore_H
class DepartmentStore
{
	ItemList list;
public:
	void I()
	{
		string product;
		double price;
		string rfidTagNumber;
		string originalLoc;
	inputInfo:
		cout << "\nEnter the Product Name : ";
		cin.ignore();
		getline(cin, product);
		cout << "Enter the Price : ";
		cin >> price;
		cout << "Enter the RFID Tag Number : ";
		cin >> rfidTagNumber;
		cout << "Enter the Original Location : ";
		cin >> originalLoc;
		if (rfidTagNumberFormat(rfidTagNumber) && originalLocFormat(originalLoc))
		{
			list.insertInfo(product, price, rfidTagNumber, originalLoc, originalLoc);
			cout << "\nItem added successfully.\n";

		}
		else
		{
			cout << "\n!!! Invalid Input !!! Please input in valid formats.\n";
			goto inputInfo;
		}
		cout << endl;
	}
	void M()
	{
		string rfidTagNumber, source, dest;
		cout << "\nEnter the RFID Tag Number : ";
		cin >> rfidTagNumber;
		cout << "Enter the Source Location : ";
		cin >> source;
		cout << "Enter the Destined Location : ";
		cin >> dest;
		if (list.moveItem(rfidTagNumber, source, dest))
		{
			cout << "\nItem moved successfully." << endl;
		}
	}
	void L()
	{
		string location;
	inputLoc:
		cout << "\nEnter the Location : ";
		cin >> location;
		if (currentLocFormat(location) || originalLocFormat(location))
			list.printByLocation(location);
		else
		{
			cout << "\n!!! Invalid Input !!! Please Enter the Location in valid format.\n";
			goto inputLoc;
		}
	}
	void P()
	{
		list.printAll();
	}
	void O()
	{
		string cartNumber;
		cout << "\nEnter the Cart Number : ";
		cin >> cartNumber;
		list.checkout(cartNumber);
	}
	void C()
	{
		list.cleanStore();
	}
	void U()
	{
		list.removeAllPurchased();
	}
	void R()
	{
		string rfid;
	inputRFID:
		cout << "\nEnter the RFID Tag Number : ";
		cin >> rfid;
		if (rfidTagNumberFormat(rfid))
			list.printByRFID(rfid);
		else
		{
			cout << "\n!!! Invalid Input !!! Please Enter the RFID Tag Number in valid format.\n";
			goto inputRFID;

		}
	}
	void Q()
	{
		cout << "\nExiting the Program" << endl;
	}
	void menu()
	{
		char userCommand;
		while (true)
		{
 
			cout << "\n\t - W E L C O M E    TO    D E P A R T M  E N T A L    S T O R E    S Y S T E M -";
			cout << "\n\n1. Insert an item into the list - I\n2. Move an item in the store - M";
			cout << "\n3. List by location - L\n4. Print all items in store - P\n5. Checkout - O";
			cout << "\n6. Clean store - C\n7. Update record system - U\n8. Print by RFID tag number - R\n9. Quit - Q" << endl;
		inputChoice:
			cout << "\nEnter the Desired Option : ";
			cin >> userCommand;
			if (userCommand == 'I')
				I();
			else if (userCommand == 'M')
				M();
			else if (userCommand == 'L')
				L();
			else if (userCommand == 'P')
				P();
			else if (userCommand == 'O')
				O();
			else if (userCommand == 'C')
				C();
			else if (userCommand == 'U')
				U();
			else if (userCommand == 'R')
				R();
			else if (userCommand == 'Q')
			{
				Q();
				break;
			}
			else
			{
				cout << "Please Enter the Valid Input\n";
				goto inputChoice;
			}
			system("pause");
			system("cls");
		}
	}
};
#endif