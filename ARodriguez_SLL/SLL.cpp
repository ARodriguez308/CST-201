#include "SLL.h"
using namespace std;

SLL::SLL() //default constructor
{
	head = nullptr;

	for (SLLNode* p; head != 0;)
	{
		p = head->next;
		delete head;
		head = p;
	}
}

SLL::SLL(const SLL& myList)
{
	head = myList.head;
	tail = myList.tail;
}

void SLL::front()
{
	cout << head->data << endl;
}

void SLL::back()
{
	cout << tail->data << endl;
}

void SLL::insert(int value)
{
	if (tail != nullptr) //decide if the list is empty
	{
		tail->next = new SLLNode(value); //create a new node, and put it next to the last value in the list
		tail = tail->next; //Now the new node is considered the tail of the list
	}
	else
	{
		head = tail = new SLLNode(value); //If the list is empty, reference to the head and tail will go to the only node in the list
	}
}

void SLL::pop_front()
{
	if (head != nullptr) //if the list has a value to actually remove
	{
		SLLNode* temporary = head;
		if (head == tail) //Next check to see if there is only one node in the list
		{
			head = tail = nullptr; //set the only node in the list to null, because now the list is empty
		}
		else
		{
			head = head->next; //the head now points to the node after it
			delete temporary;
		}
	}
	else
	{
		cout << "List is empty. Nothing to delete." << endl;
	}
}

void SLL::pop_back()
{
	if (head != nullptr)
	{
		SLLNode* temporary = tail;
		if (head == tail)
		{
			head = tail = nullptr;
		}
		else
		{
			for (temporary = head; temporary->next != tail; temporary = temporary->next);
			delete tail;
			tail = temporary;
			tail->next = nullptr;
		}
	}
	else
	{
		cout << "List is empty. nothing to delete." << endl;
	}
}

bool SLL::empty()
{
	if (head == nullptr) //The first value is null only if an empty list is created.
	{
		cout << "The list is empty." << endl;
		return true; //returns true if the first value is null
	}
	cout << "The list is NOT empty." << endl;
	return false;
}

int SLL::size()
{
	int size = 0;
	SLLNode* Node_iterator;
	Node_iterator = head;
	while (Node_iterator != NULL)
	{
		size += 1;
		Node_iterator = Node_iterator->next;
	}
	return size;
}

void SLL::reverse()
{
	SLLNode* Node_iterator = head; //create an iterator that will continuously switch places throughout the list
	SLLNode* precedent = nullptr, * next = nullptr; //create new nodes that point to nothing, this is default
	while (Node_iterator != 0) //Iterate until a null Node is reached
	{
		next = Node_iterator->next; //The last next position in the list is assigned to be the first next
		Node_iterator->next = precedent; //The tail points backwards
		precedent = Node_iterator; //The backwards pointing tail gets to be next in line for iteration now
		Node_iterator = next; //The next pointer before the prcedent is ready to iterate beginning the loop again
	}
	head = precedent; //The very last preceding value is now considered the head
	//After this function, the list that called this method is permanently changed
}

void SLL::display()
{
	SLLNode* Node_iterator; //Used to transfer between next values
	Node_iterator = head;
	while (Node_iterator != NULL) //iterate until pointing to a null value
	{
		cout << Node_iterator->data << " "; //output the data stored at each node member
		Node_iterator = Node_iterator->next; //Reassign the iterator to the next node in the list, loop is repeated
	}
}

