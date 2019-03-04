#include "pch.h"
#include "MyString.h"
#include <cstring>
#include <iostream>
using namespace std;

//Constructors
MyString::MyString()//Defualt Constructor
{
	Letters = new char[1]; //Sets New Char Array
	Letters[0] = '/0'; //Sets first array char to null
	Length = 0; //sets length to 0;
}

MyString::MyString(const char *CHAR)//Copies over the char pointer and puts it into mystring data
{
	Length = (strlen(CHAR) + 1); //Sets length to the char array
	Letters = new char[Length]; //Sets New Char Array
	strcpy_s(Letters, Length, CHAR);// copies over char data into mystring
}
MyString::MyString(const MyString & Other) //Copys over all the MyString data into the new MyString
{
	CopyString(Other);
}
//ENDConstructors

 //Copys Strings Over
void MyString::CopyString(const MyString & Other)
{
	Length = Other.Length; //Sets length Equal to the other MyString

	Letters = new char[Length + 1]; //Sets New Char Array

	strcpy_s(Letters, Length, Other.Letters); //Copys over all the letters
}

//Add Operator 
MyString MyString::operator+(const MyString &Other)
{
	MyString NewString; //MyString that will be returned

	NewString.Length = Length + Other.Length - 1;//Looks for new lenght minus one of the null bytes
	NewString.Letters = new char[NewString.Length]; //Makes the new Letter array

	strcpy_s(NewString.Letters, NewString.Length, Letters); //Copys first Mystring into NewString
	strcat_s(NewString.Letters, NewString.Length, Other.Letters); // Adds the other MyString to NewString

	return NewString;
}




//Checks if c-strings are equal to each other
bool MyString::operator==(MyString Other)
{
	bool Status;

	if(strcmp(Letters, Other.Letters) == 0 && Length == Other.Length) //Compare strings letters and length to see if they're the same
	{
		Status = true;
	}
	else
	{
		Status = false;
	}

	return Status;
}


const char * MyString::c_str() const //Helps Operartor Output overload find pointers to letters
{
	return Letters;
}

//Destructor
MyString::~MyString()
{
	cout << "Destructor Called." << endl;
}

ostream& operator<<(ostream& os, const MyString& obj) //Outputs the New String
{
	return os << obj.c_str();
}