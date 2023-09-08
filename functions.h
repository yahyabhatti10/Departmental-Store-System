#include<iostream>
#include<string>
using namespace std;
#ifndef functions_H
#define functions_H
int hexaToDecimal(string hexa)
{
	int length = hexa.size();
	int base = 1;
	int decimal = 0;
	for (int i = length - 1; i >= 0; i--)
	{
		if (hexa[i] >= '0' && hexa[i] <= '9')
		{
			decimal += (int(hexa[i]) - 48) * base;
			base = base * 16;
		}
		else if (hexa[i] >= 'A' && hexa[i] <= 'F')
		{
			decimal += (int(hexa[i]) - 55) * base;
			base = base * 16;
		}
	}
	return decimal;
}
bool originalLocFormat(string originalLoc)
{
	int length = originalLoc.length();
	bool check = NULL;
	for (int i = 1; i < length; i++)
	{
		if (originalLoc[i] >= 48 && originalLoc[i] <= 57)
			check = true;
		else
		{
			check = false;
			break;
		}
	}
	if (length == 6 && originalLoc[0] == 's' && check)
		return true;
	else
		return false;
}
bool currentLocFormat(string currentLoc)
{
	int length = currentLoc.length();
	bool check = NULL;
	for (int i = 1; i < length; i++)
	{
		if (currentLoc[i] >= 48 && currentLoc[i] <= 57)
			check = true;
		else
		{
			check = false;
			break;
		}
	}
	if (length == 4 && currentLoc[0] == 'c' && check)
		return true;
	else if (currentLoc == "out")
		return true;
	else
		return false;
}
bool rfidTagNumberFormat(string rfidTagNumber)
{
	int length = rfidTagNumber.length();
	bool check = NULL;
	for (int i = 0; i < length; i++)
	{
		if ((rfidTagNumber[i] >= 65 && rfidTagNumber[i] <= 70) || (rfidTagNumber[i] >= 48 && rfidTagNumber[i] <= 57))
			check = true;
		else
		{
			check = false;
			break;
		}
	}
	if (length == 9 && check)
		return true;
	else
		return false;
}
#endif