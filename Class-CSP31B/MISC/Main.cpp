//This the test linked list file that has the main function.
#include <iostream>
#include <string>
#include "BST.h"
using namespace std;
int main()
{
	// Create a list for strings
	/*LinkedList list;
	list.add(23);
	list.add(56);
	list.add(0, 32);
	list.add(88);
	list.add(123);
	cout << "\n\nList Size should be 5, it is = " << list.getSize() << endl;
	list.print();
	cout << endl << endl;
	list.add(77);
	list.add(88);
	list.add(99);
	list.add(45);
	cout << "\nList Size should be (9) it is : " << list.getSize() << endl;
	list.print();*/
	LinkedList list;
	list.addOrder(23);
	list.addOrder(56);
	list.addOrder(32);
	list.addOrder(88);
	list.addOrder(123);
	cout << "\n\nList Size should be 5, it is = " << list.getSize() << endl;
	list.print();
	cout << endl << endl;
	list.addOrder(77);
	list.addOrder(88);
	list.addOrder(99);
	list.addOrder(45);
	cout << "\nList Size should be (9) it is : " << list.getSize() << endl;
	list.print();
	return 0;
}
