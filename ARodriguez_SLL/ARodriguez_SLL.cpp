// ARodriguez_SLL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SLL.h"
using namespace std;

int main()
{
	cout << "Testing default constructor. . . " << endl;
	SLL myList;
	myList.insert(1);
	myList.insert(2);
	myList.insert(3);
	cout << "myList:  ";
	myList.display();
	cout << endl << endl;

	cout << "Testing copy constructor. . . " << endl;
	SLL copyList(myList);
	cout << "copy of myList, copyList:  ";
	copyList.display();
	cout << endl << endl;

	cout << "Testing front() of myList. . . " << endl;
	cout << "First element of myList:  ";
	myList.front();
	cout << endl;

	cout << "Testing back() of myList. . . " << endl;
	cout << "Last element of myList:  ";
	myList.back();
	cout << endl;

	cout << "Testing insert(value) on myList. . . " << endl;
	myList.insert(4);
	myList.insert(5);
	myList.insert(6);
	cout << "myList:  ";
	myList.display();
	cout << endl << endl;

	cout << "Testing pop_front() on myList. . . " << endl;
	myList.pop_front();
	cout << "myList without the first element is:  ";
	myList.display();
	cout << endl << endl;

	cout << "Testing pop_back() on myList. . . " << endl;
	cout << "myList without the last element is: ";
	myList.pop_back();
	myList.display();
	cout << endl << endl;

	cout << "Testing empty() on myList2. . . " << endl;
	SLL myList2;
	myList2.empty();
	cout << "Testing empty() on myList. . . " << endl;
	myList.empty();
	cout << endl;
	
	cout << "Testing size() on myList. . . " << endl;
	cout << myList.size() << endl << endl;
	
	cout << "Testing reverse() on myList. . . " << endl;
	myList.reverse();
	cout << "myList is now:  ";
	myList.display();
	cout << endl << endl;

	cout << "Testing merge() on myList and copyList. . . " << endl;


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
