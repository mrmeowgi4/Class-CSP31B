#include <iostream>
#include <string>

#include "bst.h"
#include "Cylinder.h"
#include "Circle.h"
#include "LinkedList.h"

using namespace std;

int main()
{
	
	LinkedList<int> ll;
	/*
	[1->2->3->4->null]
		addlast(5);
	[1->2->3->4->5->null]
	*/
	ll.addFirst(4);
	ll.add(5);
	ll.add(6);
	ll.print();

	return 0;
}