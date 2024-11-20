// This is LinkedList.h file
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdexcept>
#include <iostream>
using namespace std;
class Node {
public:
	int element;
	// Element contained in the node
	Node* next;
	// Pointer to the next node
	// No-arg constructor
	Node() {
		next = nullptr;
	}
	// Constructor
	Node(const int& e) {
		this->element = e;
		next = nullptr;
	}
};
class LinkedList {
private:
	Node* head;
	Node* tail;
	int size;
public:
	LinkedList(); // No-arg constructor
	LinkedList(const LinkedList& list); // Copy constructor
	virtual ~LinkedList(); // Destructor
	void add(const int& e);
	void add(int index, const int& e);
	void addLast(const int& e);
	void addFirst(const int& e);
	int& getFirst() const;
	int& getLast() const;
	int removeFirst();
	int removeLast();
	void clear();
	bool isEmpty() const;
	int getSize() const;
	int& get(int index) const;
	void addOrder(const int& e); // ADDED, to be implemented
	void remove(const int& e); // WAS there before
	// to be implemented
	// The print was done in a static method print() in the
	// main() method. Now print() is an instance method.
	void print() const; // ADDED, implemented.
};
//-- No argument constructor
LinkedList::LinkedList()
{
	head = tail = nullptr; // Initialize head and tail
	size = 0;
}
//-- Copy Constructor
LinkedList::LinkedList(const LinkedList& list)
{
	head = tail = nullptr;
	size = 0;
	Node* current = list.head;
	while (current != nullptr)
	{
		this->add(current->element);
		current = current->next;
	}
}
//-- Destructor
LinkedList::~LinkedList()
{
	clear();
}
//-- Add elements e to beginning of list
void LinkedList::addFirst(const int& e)
{
	Node* newNode = new Node(e);
	newNode->next = head;
	head = newNode;
	size++;
	if (tail == nullptr)
		tail = head;
}
//-- Add elements e to end of list
void LinkedList::addLast(const int& e)
{
	if (tail == nullptr) {
		head = tail = new Node(e);
	}
	else
	{
		tail->next = new Node(e);
		tail = tail->next;
	}
	size++;
}
//-- return element at the beginning of list
int& LinkedList::getFirst() const
{
	if (size == 0)
		throw runtime_error("Index out of range");
	else
		return head->element;
}
//-- return element at end of list
int& LinkedList::getLast() const
{
	if (size == 0)
		throw runtime_error("Index out of range");
	else
		return tail->element;
}
//-- remove element at the beginning of the list
int LinkedList::removeFirst()
{
	if (size == 0)
		throw runtime_error("No elements in the list");
	else
	{
		Node* temp = head;
		head = head->next;
		if (head == nullptr) tail = nullptr;
		size--;
		int element = temp->element;
		delete temp;
		return element;
	}
}
//-- remove element at the end of the list
int LinkedList::removeLast()
{
	if (size == 0 || size == 1)
		return removeFirst();
	else
	{
		Node* current = head;
		for (int i = 0; i < size - 2; i++)
			current = current->next;
		Node* temp = tail;
		tail = current;
		tail->next = nullptr;
		size--;
		int element = temp->element;
		delete temp;
		return element;
	}
}
//- check if the linked list is emtpy.
bool LinkedList::isEmpty() const
{
	return head == nullptr;
}
//- return how many elements in the linked list
int LinkedList::getSize() const
{
	return size;
}
//- return element at position specified by index.
int& LinkedList::get(int index) const
{
	if (index < 0 || index > size - 1)
		throw runtime_error("Index out of range");
	Node* current = head;
	for (int i = 0; i < index; i++)
		current = current->next;
	return current->element;
}
//- clear or destroy the linked list
void LinkedList::clear()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	tail = nullptr;
	size = 0;
}
//-- Adding element e to the list, and it is now set
//-- to be added to the end of the list
void LinkedList::add(const int& e)
{
	addLast(e);
}
//-- Adding element e so it will end up in position
//-- indicated by index after the insertion
void LinkedList::add(int index, const int& e)
{
	if (index == 0)
		addFirst(e);
	else if (index >= size)
		addLast(e);
	else
	{
		Node* current = head;
		for (int i = 1; i < index; i++)
			current = current->next;
		Node* temp = current->next;
		current->next = new Node(e);
		(current->next)->next = temp;
		size++;
	}
}
//-- instance method to print values in the linked list
//-- Iteration used. Recursion can be used but is an overkill
//-- and not efficient in terms of memory used.
void LinkedList::print() const
{
	Node* current = head;
	cout << "head";
	while (current != nullptr) {
		cout << "-->" << current->element;
		current = current->next;
	}
	cout << "-->NULL";
}
//Add list such that nodes are in order
// 3 different CASES possible:
// if TREE IS empty
// CASE 1
// else set current pointer to head
// Loop until find end AND find value > inserted value
// update pointer current
// End Loop
// if current point to head Then
// insert in first node (CASE 2)
// else
// insert any where else (CASE 3)
// endIf
// Increment size of list
// endElse
//-- add elements to list and list are in order after inserting
void LinkedList::addOrder(const int& e)
{
	Node* currPtr = head;

	if (head == nullptr)
	{
		Node* newNode = new Node(e);
		head = newNode;
		head->next = nullptr;
	}
	else if (head->element > e)
	{
		Node* newNode = new Node(e);
		newNode->next = head;
		head = newNode;
	}
	else {

		while (currPtr->next != nullptr && currPtr->next->element < e)
		{
			currPtr = currPtr->next;
		}

		Node* newNode = new Node(e);
		newNode->next = currPtr->next;
		currPtr->next = newNode;
	}
	size++;
}

//-- To delete a node, there are 4 different CASES to be considered
//
//-- If list is EMPTY then
//-- CASE 1 - No deletion done
//-- else the list NOT empty
//-- if node to delete is first node then it is CASE 2
//- adjust head pointer
//- else the node to delete is somewhere else, it is CASE 3
//- adjust pointers.
//- Your will need TWO pointers
//- also, consider case the node to delete is the last node
//- if so, adjust tail pointer.
//- else it is CASE 4
//- the value to be deleted has no just value in all nodes in the list
//- endif
//- endif
//-- remove a specified element e from the linked list.
void LinkedList::remove(const int& e)
{
	//TO BE IMPLEMENTED using the algorithm above
}//end delete node
#endif