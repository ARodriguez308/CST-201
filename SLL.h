#include <iostream>
using namespace std;

#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

class SLL
{
protected:
	class SLLNode
	{
	public:
		//data variable holds the contents of the list
		int data;
		//Node object holds the adjacent node info
		SLLNode* next;

		SLLNode() //default constructor, next is a null
		{
			next = nullptr; //defaults an empty list to a null value
		}

		SLLNode(int element, SLLNode* ptr = nullptr) //Parameterized constructor that stores the element as data
			//Ptr Node is created to automatically set the adjacent next value to null
		{
			data = element;
			next = ptr;
		}
	}; //End of SLLNode

public:
	SLL(); //default constructor

	SLL(const SLL& myList); //copy constructor

	/*
	int isEmpty() //Default an empty list to 0
	{
		return head == 0;
	}
	*/

	void front(); //access to the first element
	void back(); //access to the last element
	void insert(int value); //insert element
	void pop_front(); //Remove value at front
	void pop_back(); //Remove value at tail
	bool empty(); //Determine if list is empty
	int size(); //Return # of elements
	void reverse(); //Reverse the order of a list
	void display(); //Show the list
	

private:
	SLLNode* head; //new node referenced to head
	SLLNode* tail; //new node referenced to tail
};

#endif //SINGLY_LINKED_LIST

