#include <iostream>
#include <string>
using namespace std;

template <class T>
class SinglyLinkedList
{
protected:
	//nested Node class within the SLL class
	class Node 
	{
	public: 
		T data;
		Node* next;

		Node(T val)
		{
			this->data = val;
			this->next = nullptr;
		}
		Node(T val, Node* nextNode)
		{
			this->data = val;
			this->next = nextNode;
		}
	};

public:
	//Constructor for an empty list
	SinglyLinkedList()
	{
		front = nullptr;
	}

	SinglyLinkedList(string str, Node* )

	friend ostream& operator<<(ostream& out, const SinglyLinkedList& lst)
	{
		Node curr = front;
		while (curr != nullptr)
		{
			out << curr.val << " ";
			curr = curr.next;
		}
		return out;
	}

	// base function to output the string by iterating over a list
	/*
	string toString()
	{
		string str = "";
		Node<T> curr = front;
		while (curr != NULL)
		{
			str += curr.val + " ";
			curr = curr.next;
		}
		return str;
	}*/

private:
	//front of list
	void insert(T v)
	{
		//insert v at the fron t of the list

	}
};

