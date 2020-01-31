#include "myString.h"

//default constructor, does not take any parameters
myString::myString()
{
	//Initializes array to a null pointer
	char* arr = nullptr;

	//length is zero, capacity is zero
	curr_length = 0;
	capacity = 0;
}

//Parameterized constructor that uses information from a string-type parameter
myString::myString(string me)
{
	//get the length of the word in the string, and initialize it to the curr_length variabke
	curr_length = me.length();

	//Initialize the capacity of the array
	capacity = curr_length;

	arr = new char[curr_length];
	
	//Check to make sure the 
	for (int i = 0; i < curr_length; i++)
	{
		arr[i] = { me[i] };
	}
}

//toString method that returns a string representation of the object by overloading the << operator
ostream& operator << (ostream& out, const myString& firstWord) //takes in the myString parameter firstWord
{
	for (int i = 0; i < firstWord.curr_length; i++)
	{
		out << firstWord.arr[i];
	}
	return out;
}

//Overloading the == operator to return boolean values

bool operator== (const myString& first, const myString& other)
{
	if (first.arr == other.arr)
	{
		cout << "Yes, returns: ";
		return true;
	}
	cout << "No, returns: ";
	return false;
}

//tried to redo < operators
/*
bool myString::operator<(const myString& first) const
{
	//find shorter string
	if (curr_length < first.curr_length)
	{
		int len = curr_length;
		for (int i = 0; i < len; i++)
		{
			if (int(arr[i] < int(first.arr[i])))
			{
				return true;
			}
			else if (int(arr[i] > int(first.arr[i])))
			{
				return false;
			}
		}
	}
	return curr_length < first.curr_length;
}
*/


//Overloading the less than operator to return integers based on alphabetical order
int operator<(const myString& first, const myString& second)
{
	if (first.curr_length < second.curr_length)
	{
		int len = first.curr_length;
		for (int i = 0; i < len; i++)
		{
			if (first.arr[i] < second.arr[i])
			{
				cout << "Yes, returns: ";
				return 1;
			}
			else if (first.arr[i] > second.arr[i])
			{
				cout << "No, returns: ";
				return -1;
			}
		}
	}
	else
	{
		cout << "They are equivalent, returns: ";
		return 0;
	}
}

//Overloading the greater than operator to return integers based on alphabetical order
int operator>(const myString& first, const myString& second)
{
	if (first.curr_length > second.curr_length)
	{
		int len = first.curr_length;
		for (int i = 0; i < len; i++)
		{
			if (first.arr[i] > second.arr[i])
			{
				cout << "Yes, returns: ";
				return -1;
			}
			else if (first.arr[i] < second.arr[i])
			{
				cout << "No, returns: ";
				return 1;
			}
		}
	}
	else
	{
		cout << "They are equivalent, returns: ";
		return 0;
	}
}

char& myString::operator[](int index)
{
	if (index < curr_length)
	{
		return arr[index];
	}
	cout << "Index out of bounds." << endl;
}

//copy constructor that takes the object "me" as its parameter
myString::myString(const myString &me)
{
	//Takes in the members of the old "me" object and copies them to this object's members
	curr_length = me.curr_length;
	//Copy constructor makes an array of the same size
	arr = new char[curr_length];

	for (int i = 0; i < curr_length; i++)
	{
		arr[i] = { me.arr[i] };
	}
	
	//Copy constructor preserves size of the array
	capacity = me.capacity;
}

//default destructor
myString::~myString()
{
}

//Function that checks the amount of elements in the array
void myString::ensureCapacity()
{
	//Create a temparary array that has a bigger size
	char* temp = new char[capacity * 3];

	//Copy previous elements over to the new, bigger array by iteration
	for (int i = 0; i < curr_length; i++)
	{
		temp[i] = arr[i];
	}

	//Delete the previous smaller array that is still stored in memory
	delete[] arr;

	//Assign the reference of the original array to the new bigger array
	arr = temp;
	//Update the capacity value for the new, bigger array
	capacity = capacity * 3;

}

myString myString::concat(myString arr1, myString arr2)
{
	//object created within the method using the copy constructor
	myString result(arr1);
	if (result.capacity >= result.curr_length)
	{
		result.ensureCapacity();
		for (int i = 0; i < (result.curr_length + arr2.curr_length); i++)
		{
			result.arr[curr_length + i] = arr2.arr[i];
		}
		result.curr_length = arr1.curr_length + arr2.curr_length;

		for (int i = 0; i < result.curr_length; i++)
		{
			cout << result.arr[i];
		}
	}
	else
	{
		for (int i = 0; i < (result.curr_length + arr2.curr_length); i++)
		{
			result.arr[curr_length + i] = arr2.arr[i];
		}
		result.curr_length = arr1.curr_length + arr2.curr_length;

		for (int i = 0; i < result.curr_length; i++)
		{
			cout << arr1.arr[i];
		}
		cout << endl;
	}
	//method returns the result object
	return result;
}

//Method that takes in a desired string and returns it all in uppercase letters
myString myString::toUpper(myString original)
{
	//Use of the copy constructor to create a new object
	myString uppercase(original);
	for (int i = 0; i < original.curr_length; i++)
	{
		uppercase.arr[i] = toupper(arr[i]);
	}

	for (int i = 0; i < uppercase.curr_length; i++)
	{
		cout << uppercase.arr[i];
	}
	return uppercase;
}

//Method that takes in a desired string object and returns it all in lowercase letters
myString myString::toLower(myString original)
{
	//Use of copy constructor to create a new object
	myString lowercase(original);
	for (int i = 0; i < original.curr_length; i++)
	{
		lowercase.arr[i] = tolower(arr[i]);
	}

	for (int i = 0; i < lowercase.curr_length; i++)
	{
		cout << lowercase.arr[i];
	}
	return lowercase;
}

//method that takes an integer and returns a substring starting at that index
string myString::substring(int index)
{
	string result;
	if (index < curr_length)
	{
		for (int i = index; i < curr_length; i++)
		{
			result += arr[i];
		}
		cout << result;
		return result;
	}
	cout << "Index out of bounds." << endl;
	return result;
}

//Method that takes in two integers and returns the substring between then
string myString::substring(int n, int m)
{
	string result;
	if (n < (curr_length - 1) && m < curr_length)
	{
		for (int i = n; i < (m); i++)
		{
			result += arr[i];
		}
		cout << result;
		return result;
	}
	cout << "At least one index is out of bounds." << endl;
	return result;
}

//length method
void myString::getLength(myString arr1)
{
	cout << "Length of the string, " << arr1 << ", is: " << arr1.curr_length << endl;
}

int myString::indexOf(myString sub)
{
	// A loop to scan one by one 
	for (int i = 0; i <= curr_length - sub.curr_length; i++) 
	{
		int j;
		// For current index i, check for matches between the array of the substring and array of the original word
		for (j = 0; j < sub.curr_length; j++)
			if (arr[i + j] != sub.arr[j])
				break; //skips to the end when no successive similarities are found

		if (j == sub.curr_length)
			return i; //returns the number of indicies the iteration went through until it found its match
	}

	cout << "Substring not found, returned: ";
	return -1;
}

int myString::lastIndexOf(myString sub)
{
	//a loop to scan one by one
	for (int i = 0; i < curr_length - sub.curr_length; i++)
	{
		int j;
		//For current index i, check for matches between the array of substring and original word
		for (j = 0; j < sub.curr_length; j++)
			if (arr[i + j] != sub.arr[j])
				break;
		if (j = sub.curr_length)
			return (i + sub.curr_length);
	}

	cout << "Substring not found, returned: ";
	return -1;
}

/*
//method that takes an integer and returns the character at that index location
void myString::get(int index)
{
	if (index < curr_length)
	{
		cout << arr[index] << endl;
	}
	else
	{
		cout << "Index does not exist." << endl;
	}
}
*/