//Alita Rodriguez
//single-linked list class to store integers

#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
/*
//class for integer singly linked list nodes
class IntSLLNode
{
public:

	//Constructor: Initializes the 'next' pointer to null and leaves 'info' unspecified
	IntSLLNode()
	{
		next = 0;
	}

	//Parameterized Constructor: Initializes info member and next member
	IntSLLNode(int el, IntSLLNode* ptr = 0) 
	//can also function when only one numerical argument is supplied
	{ //In the case only one argument is passed, info is the argument, 
		//and next becomes null
		info = el; next = ptr;
	}
	int info;
	IntSLLNode* next;

};*/

//Class for integer singly linked list, allows access to the list
class IntSLList
{
protected:
	//Nested class is protected within the list class
	class IntSLLNode
	{
	public:

		//Constructor: Initializes the 'next' pointer to null and leaves 'info' unspecified
		IntSLLNode()
		{
			next = 0;
		}

		//Parameterized Constructor: Initializes info member and next member
		IntSLLNode(int el, IntSLLNode* ptr = 0)
			//can also function when only one numerical argument is supplied
		{ //In the case only one argument is passed, info is the argument, 
			//and next becomes null
			info = el; next = ptr;
		}
		int info;
		IntSLLNode* next;

	}; //end of IntSLLNode

public:
	IntSLList();

	//IntSLList(const IntSLList& myList); //copy constructor

	//function defaulting an empty list to 0
	int isEmpty()
	{
		return head == 0;
	}

	//functions used to access the elements of the list
	void addToHead(int);
	void addToTail(int);
	int deleteFromHead(); //delete the head and return its info
	int deleteFromTail(); //delete the tail and return its info;
	void deleteNode(int);
	bool isInList(int) const;
	void displayList();

private:
	IntSLLNode* head, * tail;
};

#endif //INT_LINKED_LIST

