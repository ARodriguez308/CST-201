// Project1_MyString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "myString.h"

using namespace std;

int main()
{
	//String to be used
	string s1 = "Alita";
	string s2 = "Rodriguez";
	string s0 = "YaHOO!";
	string s00 = "Ally";

	cout << "Test program with the following strings: " << endl;
	cout << "s1 = " << s1 << " s2 = " << s2 << " and s0 = " << s0 << endl;
	cout << endl;

	//Constructor that takes in string type parameter
	cout << "Testing parameterized constructor. . . " << endl;
	myString firstWord(s1);
	cout << firstWord; //Overloading of the "<<" operator
	cout << endl;

	myString secondWord(s2);
	cout << secondWord; //Overloading of the "<<" operator
	cout << endl;
	cout << endl;
	//Tested: effective.

	//utilize the copy constructor
	cout << "Testing copy constructor. . . " << endl;
	myString newcopy(firstWord);
	cout << newcopy << endl; //Overloading of the "<<" operator (don't use friend method)
	string s3;
	for (int i = 0; i < s1.length(); i++)
	{
		s3 += newcopy[i];
	}
	cout << "A new string variable, s3 is assigned to the copy: " << endl;
	cout << "s3 = " << s3 << endl;
	cout << endl;
	//Tested: effective. Copy constructor works on its own

	//make sure length function that returns the length of the parameter
	cout << "Testing length method. . . " << endl;
	firstWord.getLength(firstWord);
	secondWord.getLength(secondWord);
	cout << endl;
	//Tested: effective.


	//Utilize the concatenation method
	cout << "Testing concatenation. . . " << endl;
	cout << firstWord << " concatenated to " << secondWord << " is: " << endl;
	myString result;
	result = firstWord.concat(firstWord, secondWord);
	cout << endl;
	cout << endl;
	//Tested: effective. concatenation returns a combination of the objects inside an array
	//Effective: shows array to user.
	
	//Utilize the equals method
	cout << "Testing == overloading method. . . " << endl;
	//First with an expression we know is valid
	cout << "Is: " << firstWord << " == " << firstWord << " ?" << endl;
	cout << (firstWord == firstWord) << endl; //Overloading of the << and == operators
	//Next with an expression we know is not valid
	cout << "Is: " << firstWord << " == " << secondWord << " ?" << endl;
	cout << (firstWord == secondWord) << endl; //Overloading of the << and == operators
	cout << endl;

	//Utilize the compareTo method
	cout << "Testing < 'before' overloading method, in which operator is indicative of alphabetical order. . . " << endl;
	cout << "Consider another string s00: " << s00 << endl;
	myString ally(s00);
	//First, when the two objects are the same
	cout << "Is: " << firstWord << " < " << firstWord << " ? " << endl;
	cout << (firstWord < firstWord) << endl; 
	//Next, when the first object is alphabetically before the second object
	cout << "Is: " << firstWord << " < " << secondWord << " ? " << endl;
	cout << (firstWord < secondWord) << endl; 
	//Now, when words start with similar letters
	cout << "Is: " << ally << " < " << firstWord << " ? " << endl;
	cout << (ally < firstWord) << endl;
	cout << endl;

	cout << "Testing > 'after' overloading method. . . " << endl;
	//First, when the two objects are the same
	cout << "Is: " << firstWord << " > " << firstWord << " ? " << endl;
	cout << (firstWord > firstWord) << endl;
	//Next when rodriguez comes after alita
	cout << "Is: " << secondWord << " > " << firstWord << " ? " << endl;
	cout << (secondWord > firstWord) << endl; 
	//Lastly, when alita does not come after ally
	cout << "Is: " << firstWord << " > " << ally << " ? " << endl;
	cout << (firstWord > ally) << endl;
	cout << endl;

	//Utilize the .get method
	/*
	cout << "Testing get(int) method. . . " << endl;
	cout << "At index 0: ";
	firstWord.get(0);
	cout << "At index 1: ";
	firstWord.get(1);
	cout << "At index 4: ";
	firstWord.get(4);
	cout << "At index 30: ";
	firstWord.get(30);
	*/

	//Utilize overloading of the [] operator
	cout << "Testing get method by overloading [] operator. . . " << endl;
	cout << "At index 0 of s1: ";
	cout << firstWord[0] << endl; 
	cout << "At index 1 of s1: ";
	cout << firstWord[1] << endl; 
	cout << "At index 4 0f s1: ";
	cout << firstWord[4] << endl; 
	cout << "At index 30 of s1: ";
	cout << firstWord[30] << endl; 
	cout << endl;

	//Utilize the toUpper method
	cout << "Testing toUpper method. . . " << endl;
	cout << "s1 = ";
	firstWord.toUpper(firstWord); //Successful
	cout << endl;
	//Try a new string
	myString newTest(s0);
	cout << "s0 = ";
	newTest.toUpper(newTest);
	cout << endl;

	//Utilize the toLower method
	cout << "Testing toLower method. . . " << endl;
	cout << "s1 = ";
	firstWord.toLower(firstWord);
	cout << endl;
	cout << "s0 = ";
	newTest.toLower(newTest);
	cout << endl;
	cout << endl;

	//Utilize the substring(int) method
	cout << "Testing substring method. . . " << endl;
	cout << "Substring following index 1 of s1: ";
	firstWord.substring(1);
	cout << endl;
	cout << "Substring following index 3 of s2: ";
	secondWord.substring(3);
	cout << endl;
	cout << "Substring following index 30 of s2: ";
	secondWord.substring(30);
	cout << endl;

	//Utilize the substring(int n, int m) method
	cout << "Testing substring method with multiple indexes. . . " << endl;
	cout << "Substring between index 2 and up to 4 of s1: ";
	firstWord.substring(2, 4);
	cout << endl; 
	cout << "Substring between index 1 and up to 7 of s2: ";
	string sub;
	sub = secondWord.substring(1, 7);
	myString substringOBJ(sub);
	cout << endl;
	cout << endl;

	//Utilize the indexOf method
	cout << "Testing indexOf method with a substring, " << substringOBJ << " within " << secondWord << " . . . " << endl;
	cout << "The starting index of the first occurence of the substring in the word is: " << endl;
	cout << secondWord.indexOf(substringOBJ);
	cout << endl;
	cout << "Or, testing if " << substringOBJ << " is within " << firstWord << " : " << endl;
	cout << firstWord.indexOf(substringOBJ);
	cout << endl;
	cout << endl;

	//Utilize LastIndexOf method
	cout << "Testing lastIndexOf method with a substring, " << substringOBJ << " within " << secondWord << " . . . " << endl;
	cout << "The ending index of the first occurence of the substring in the word is: " << endl;
	cout << secondWord.lastIndexOf(substringOBJ);
	cout << endl;
	cout << "Or, testing if " << substringOBJ << " is within " << firstWord << " : " << endl;
	cout << firstWord.lastIndexOf(substringOBJ);
	cout << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
