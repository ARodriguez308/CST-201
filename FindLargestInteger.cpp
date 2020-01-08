// FindLargestInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//Alita Rodriguez
//CST-201 Professor Lydia Fritz
//8 January 2020
//Return the Largest Integer in an Array of Random Numbers

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	//First, initialize the array that will be considered the "data" we are interested in

	int array[100];
	//Seed is time program is run
	srand((unsigned)time(0));

	cout << "Here is the data we are interested in: " << endl;

	//Fill each index of the array with a random number betwee 1 and 101, randomized by the time generated
	for (int i = 0; i < 100; i++)
	{
		array[i] = (rand() % 1000) + 1;
		cout << array[i] << ", ";
	}
	cout << endl;

	//Next, use a temporary integer variable to deduce the largest integer by beginning at the first integer
	int temp = array[0];
	//By beginning at the first value in the array, there is one less computation as opposed to setting temp to 0

	//Use an iterator to compare all of the values
	for (int i = 1; i < 100; i++)
	{
		//The temp value, the first index in the array, is compared to the index directly after that and so on
		//Each time the following statement is true, the temporary value is replaced
		if (temp < array[i])
			temp = array[i];
		//The iterator keeps replacing the value until all values have been tested in the iteration
	}
	cout << endl;

	//Once the iteration completes, the value that was last assigned as being greater than all other values is shown
	cout << "The greatest integer in our data is: " << temp << endl;

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
