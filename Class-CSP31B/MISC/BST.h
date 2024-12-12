#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#ifndef BST_H
#define BST_H
template < typename T >
class TreeNode
{
public:
	T element; // Element contained in the node
	TreeNode < T >* left; // Pointer to the left child
	TreeNode < T >* right; // Pointer to the right child
	TreeNode() // No-arg constructor
	{
		left = NULL;
		next = NULL;
	}
	TreeNode(T element) // Constructor
	{
		this->element = element;
		left = NULL;
		right = NULL;
	}
};
template < typename T >
class BST
{
public:
	BST();
	BST(T elements[], int arraySize);
	bool insert(T element);
	void inorder();
	void preorder();
	void postorder();
	int getSize();
	bool search(T element);
	void breadthFirstTraversal();
	int height();
	int getNumberOfNonLeaves();
private:
	TreeNode < T >* root;
	int size;
	void inorder(TreeNode < T >* root);
	void postorder(TreeNode < T >* root);
	void preorder(TreeNode < T >* root);
	bool search(T element, TreeNode < T >* root);
	int height(TreeNode<T>* root);
	int getNumberOfNonLeaves(TreeNode<T>* root);
};
template < typename T >
BST < T >::BST()
{
	root = NULL;
	size = 0;
}
template < typename T >
BST < T >::BST(T elements[], int arraySize)
{
	root = NULL;
	size = 0;
	for (int i = 0; i < arraySize; i++)
	{
		insert(elements[i]);
	}
}
/* Insert element into the binary tree * Return true if the element is inserted
successfully
* Return false if the element is already in the list */
template < typename T >
bool BST < T >::insert(T element)
{

	if (root == nullptr)
	{
		root = new TreeNode(element);
		return true;
	}

	TreeNode<T>* curNode = root;

	while (curNode != nullptr) {
		
		if (curNode->element == element)
		{
			// Duplicates are not allowed in a binary search tree.
			return false;
		}
		
		if (curNode->element > element)
		{
			if (curNode->left == nullptr)
			{
				curNode->left = new TreeNode<T>(element);
				size++;
				return true;
			}

			curNode = curNode->left;
		}
		else
		{
			if (curNode->element < element)
			{
				if (curNode->right == nullptr)
				{
					curNode->right = new TreeNode<T>(element);
					size++;
					return true;
				}

				curNode = curNode->right;
			}
		}
	}

	return false; // Yes professor i know this isnt necessary but i wanted to make sure you know this is where the method ends
}


/* Inorder traversal */
template < typename T >
void BST < T >::inorder()
{
	inorder(root);
}
/* Inorder traversal from a subtree */
template < typename T >
void BST < T >::inorder(TreeNode < T >* root)
{
	if (root == NULL) return;
	inorder(root->left);
	cout << root->element << " ";
	inorder(root->right);
}
/* Postorder traversal */
template < typename T >
void BST < T >::postorder()
{
	postorder(root);
}
/** Inorder traversal from a subtree */
template < typename T >
void BST < T >::postorder(TreeNode < T >* root)
{
	if (root == NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->element << " ";
}
/* Preorder traversal */
template < typename T >
void BST < T >::preorder()
{
	preorder(root);
}
/* Preorder traversal from a subtree */
template < typename T >
void BST < T >::preorder(TreeNode < T >* root)
{
	if (root == NULL) return;
	cout << root->element << " ";
	preorder(root->left);
	preorder(root->right);
}
template<typename T>
inline bool BST<T>::search(T element, TreeNode<T>* root)
{
	TreeNode<T>* currentNode = root;

	while (currentNode != nullptr)
	{
		if (currentNode->element > element)
		{
			currentNode = currentNode->left;
		}
		else if (currentNode->element < element)
		{
			currentNode = currentNode->right;
		}
		else if (currentNode->element == element) {
			return true;
		}
	}

	return false;

}
/* Get the number of nodes in the tree */
template < typename T >
int BST < T >::getSize()
{
	return size;
}
template<typename T>
inline bool BST<T>::search(T element)
{
	return search(element, root);
}
template < typename T >
int BST < T >::height()
{
	return height(root);
}

template<typename T>
inline int BST<T>::getNumberOfNonLeaves()
{
	return getNumberOfNonLeaves(root);
}

template<typename T>
int BST<T>::height(TreeNode<T>* root)
{
	if (root == nullptr)
	{
		return -1;
	}

	int L = height(root->left) + 1;
	int H = height(root->right) + 1;

	if (L >= H)
	{
		return L;
	}
	else if (H >= L)
	{
		return H;
	}

}
template<typename T>
inline int BST<T>::getNumberOfNonLeaves(TreeNode<T>* root)
{
	if (root == nullptr)
	{
		return 0;

	}

	if (root->left == nullptr && root->right == nullptr)
	{
		return 0;
	}

	int cL = getNumberOfNonLeaves(root->left);
	int cR = getNumberOfNonLeaves(root->right);

	int cT = 1 + cL + cR;

	return cT;
}
//Implement the getNumberOfNonLeaves() method here
// Two methods (overloaded) to be implemented.
#endif