#include <iostream>
#include "AVLTree.h"
using namespace std;

template <typename T>
void printTree(const AVLTree<T>& tree)
{
	// Traverse tree
	cout << "\nInorder (sorted): " << endl;
	tree.inorder();
	cout << "\nPostorder: " << endl;
	tree.postorder();
	cout << "\nPreorder: " << endl;
	tree.preorder();
	cout << "\nThe number of nodes is " << tree.getSize();
	cout << endl;
}

int main()
{
	// Create an AVL tree
	int numbers[] = { 25, 20, 5 };
	AVLTree<int> tree(numbers, 3);

	cout << "After inserting 25, 20, 5:" << endl;
	printTree<int>(tree);

	tree.insert(34);
	tree.insert(50);
	cout << "\nAfter inserting 34, 50:" << endl;
	printTree<int>(tree);

	tree.insert(30);
	cout << "\nAfter inserting 30" << endl;
	printTree<int>(tree);

	tree.insert(10);
	cout << "\nAfter inserting 10" << endl;
	printTree(tree);

	tree.remove(34);
	tree.remove(30);
	tree.remove(50);
	cout << "\nAfter removing 34, 30, 50:" << endl;
	printTree<int>(tree);

	tree.remove(5);
	cout << "\nAfter removing 5:" << endl;
	printTree<int>(tree);

	return 0;
}