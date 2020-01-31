#include <string>
#include <cstring>
#include <iostream>
#include <string.h>

using namespace std;

class myString
{
public:

	//Constructor, default
	myString();

	//Constructor, parameterized to take in a string type
	myString(string me);

	//copy constructor that will create another object using the parameterized object that was already created
	myString(const myString &me);

	//destructor
	virtual ~myString();

	//method that concatenates strings by returning a resulting object and passing in two myString type objects as the parameters
	myString concat(myString, myString);

	//Method that returns a myString object that is in all uppercase
	myString toUpper(myString);
	//Method that returns a myString object that is in all lowercase
	myString toLower(myString);
	
	//overloading method that takes a myString parameter and returns true if the reference and the parameter at the same
	friend bool operator== (const myString& first, const myString& other); //Change to equals method

	//overloading method that compares two strings by overloading the < operator
	friend int operator< (const myString& first, const myString& second); //changed method to:

	friend int operator> (const myString& first, const myString& second); //change to greater than method

	//method that takes in a desired string and then returns the length of the string as an integer
	void getLength(myString arr1);
	//toString method that returns a string representation of the object by overloading the << operator

	friend ostream& operator << (ostream& out, const myString& firstWord); //change to get method
	

	//Method that takes in an integer and returns the substring starting at that index that was passed in as a parameter
	string substring(int index);

	//Method that takes in two integers and returns the substring between them
	string substring(int n, int m);

	//Method that takes a MyString parameter and returns the starting index of the first occurence of the myString in the calling object
	int indexOf(myString obj);

	int lastIndexOf(myString obj);

	//method that takes an integer and return the character at that index location
	//void get(int);

	//overloading method using [] that takes an integer and returns the character at that index location
	char& operator[] (int index);

private:
	char* arr;
	//Reference to an array that has a bunch of characters in it

//Integer reference to the number of characters or length the array may take on
	int curr_length;
	//Represents the size of the array

	//Capacity makes sure the current length of array and the length of the word are always equal
	int capacity;
	//recommend the array to be doubled when manipulating

	//Ensure capacity should be private because we want the array to only be manipulated within the class when it is needed, and not by anyone else
	void ensureCapacity();
	//is the array length == to current length?
	//if yes: ask for larger array, then copy the characters to the longer array, such as tempArray
	//delete the old array before reassigning it
	//Then update the original array reference to be the tempArray 

};

