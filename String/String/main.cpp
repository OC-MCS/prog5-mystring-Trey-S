// Trey Scheurer
// 3-1-19
// PROGRAMMING 2


#include "pch.h"
#include "MyString.h"
#include <iostream>

using namespace std;

int main()
{
	char Name[5] = {'T', 'r', 'e', 'y'};	//Char Array
	char TName[5] = { 'Y', 'E', 'R', 'T' };	//Char Array

	char *NamePtr = Name; // Assigning Char Array to pointer
	char *NamePtr2 = TName; // Assigning Char Array to pointer

	//Mystring Declarations
	MyString NewString;
	MyString NewString1(NamePtr);
	MyString NewString2(NewString1);
	MyString NewString3(NamePtr2);

	NewString.CopyString(NewString1); //Copys MyString from NewString

	//Outputs Built Strings
	cout << NewString << endl;
	cout << NewString1 << endl;
	cout << NewString2 << endl;

	if(NewString1 == NewString3) //Checks if New Strings are Equal
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "False" << endl;
	}

	NewString3 = NewString3 + NewString1; //Adds Strings Together

	cout << NewString3 << endl; //Outputs New String

	return 0;
}