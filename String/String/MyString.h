#pragma once
#include <iostream>
using namespace std;

class MyString
{

private:
	char *Letters; //Letters pointer
	int Length; //how many chars are in the class
public:
	//CONSTRUCTORS
	MyString();//Defualt constructor
	MyString(const char*); //Accepts char pointer
	MyString(const MyString &Other); //accepts other MyString Classes
	//END CONSTRUCTORS
	
	void CopyString(const MyString &);	//Copies c-string

	MyString operator+(const MyString &Other); //Add Mystrings together
	bool operator==(MyString Other); //Checks if MyStrings are Equal
	const char* c_str() const; //Refences the adress to the Letters Pointer

	~MyString(); //Deconstucter
};

ostream& operator<<(ostream&, const MyString&); //Output stream
