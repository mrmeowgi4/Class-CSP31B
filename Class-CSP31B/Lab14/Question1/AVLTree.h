
#ifndef AVLTREE_H
#define AVLTREE_H

#include "BST.h"
#include <vector>
#include <algorithm>
#include <stdexcept>

//#define debugmacro xyz <-- ignore this professor

using namespace std;

template<typename T>
class AVLTreeNode : public TreeNode<T>
{
public:
    int height; // height of the node

    AVLTreeNode(const T& e) : TreeNode<T>(e) // Constructor
    {
        height = 0; // Set height to 0
    }
};

template <typename T>
class AVLTree : public BST<T>
{
public:
    AVLTree();
    AVLTree(const T elements[], int arraySize);
    AVLTree(const BST<T>& tree); //left as exercise
    ~AVLTree(); //left as exercise
    //  The = operator is also left as an exercise
    bool insert(const T& e); // Redefine insert defined in BST
    bool remove(const T& e); // Redefine remove defined in BST

protected:
    // Redefine createNewNode defined in BST
    AVLTreeNode<T>* createNewNode(const T& e);

private:
    // Balance the nodes in the path from the specified
    // node to the root if necessary 
    void balancePath(const T& e);

    // Update the height of a specified node 
    void updateHeight(AVLTreeNode<T>* node);

    // Return the balance factor of the node 
    int balanceFactor(AVLTreeNode<T>* node);

    // Balance LL (see Figure 26.1) 
    void balanceLL(TreeNode<T>* A, TreeNode<T>* parentOfA);

    // Balance LR (see Figure 26.3) 
    void balanceLR(TreeNode<T>* A, TreeNode<T>* parentOfA);

    // Balance RR (see Figure 26.2) 
    void balanceRR(TreeNode<T>* A, TreeNode<T>* parentOfA);

    // Balance RL (see Figure 26.4) 
    void balanceRL(TreeNode<T>* A, TreeNode<T>* parentOfA);
};

template <typename T>
AVLTree<T>::AVLTree()
{

}

template <typename T>
AVLTree<T>::AVLTree(const T elements[], int arraySize)
{
    this->root = nullptr;
    this->size = 0;

    for (int i = 0; i < arraySize; i++)
    {
        insert(elements[i]);
    }
}

/* Copy constructor */
template<typename T>
AVLTree<T>::AVLTree(const BST<T>& tree)
{
    this->root = nullptr;
    this->size = 0;
    copy(tree.root); // Recursively copy nodes to this tree
}

/* Destructor */
template<typename T>
AVLTree<T>::~AVLTree()
{
    BST<T>::clear();
    cout << "\nDestoying AVLTree";
}

template <typename T>
AVLTreeNode<T>* AVLTree<T>::createNewNode(const T& e)
{
    return new AVLTreeNode<T>(e);
}

template <typename T>
bool AVLTree<T>::insert(const T& e)
{
    bool successful = BST<T>::insert(e);
    if (!successful)
        return false; // element is already in the tree
    else
        // Balance from element to the root if necessary
        balancePath(e);

    return true; // element is inserted
}

template <typename T>
void AVLTree<T>::balancePath(const T& e)
{
    vector<TreeNode<T>*>* p = this->path(e);
    for (int i = (*p).size() - 1; i >= 0; i--)
    {
        AVLTreeNode<T>* A = static_cast<AVLTreeNode<T>*>((*p)[i]);
        updateHeight(A);
        AVLTreeNode<T>* parentOfA = (A == this->root) ? nullptr :
            static_cast<AVLTreeNode<T>*>((*p)[i - 1]);

        switch (balanceFactor(A)) // Test balance factor
        {
        case -2:
            if (balanceFactor(
                static_cast<AVLTreeNode<T>*>(((*A).left))) <= 0)
                balanceLL(A, parentOfA); // Perform LL rotation
            else
                balanceLR(A, parentOfA); // Perform LR rotation
            break;
        case +2:
            if (balanceFactor(
                static_cast<AVLTreeNode<T>*>(((*A).right))) >= 0)
                balanceRR(A, parentOfA); // Perform RR rotation
            else
                balanceRL(A, parentOfA); // Perform RL rotation
        }
    }
}

template <typename T>
void AVLTree<T>::updateHeight(AVLTreeNode<T>* node)
{
    if (node->left == nullptr && node->right == nullptr) // node is a leaf
        node->height = 0;
    else if (node->left == nullptr) // node has no left subtree
        node->height =
        1 + (*static_cast<AVLTreeNode<T>*>((node->right))).height;
    else if (node->right == nullptr) // node has no right subtree
        node->height =
        1 + (*static_cast<AVLTreeNode<T>*>((node->left))).height;
    else
        node->height = 1 +
        max((*static_cast<AVLTreeNode<T>*>((node->right))).height,
            (*static_cast<AVLTreeNode<T>*>((node->left))).height);
}

template <typename T>
int AVLTree<T>::balanceFactor(AVLTreeNode<T>* node)
{
    if (node->right == nullptr) // node has no right subtree
        return -node->height;
    else if (node->left == nullptr) // node has no left subtree
        return +node->height;
    else
        return (*static_cast<AVLTreeNode<T>*>((node->right))).height -
        (*static_cast<AVLTreeNode<T>*>((node->left))).height;
}

template <typename T>
void AVLTree<T>::balanceLL(TreeNode<T>* A, TreeNode<T>* parentOfA)
{
    TreeNode<T>* B = (*A).left; // // A and B are left-heavy

    if (A == this->root) // Test if A is root
        this->root = B;
    else
        if (parentOfA->left == A)
            parentOfA->left = B;
        else
            parentOfA->right = B;

    A->left = B->right; // Make T2 the left subtree of A
    B->right = A; // Make A the left child of B
    updateHeight(static_cast<AVLTreeNode<T>*>(A));
    updateHeight(static_cast<AVLTreeNode<T>*>(B));
}

template <typename T>
void AVLTree<T>::balanceLR(TreeNode<T>* A, TreeNode<T>* parentOfA)
{
    TreeNode<T>* B = A->left; // A is left-heavy
    TreeNode<T>* C = B->right; // B is right-heavy

    if (A == this->root)
        this->root = C;
    else
        if (parentOfA->left == A)
            parentOfA->left = C;
        else
            parentOfA->right = C;

    A->left = C->right; // Make T3 the left subtree of A
    B->right = C->left; // Make T2 the right subtree of B
    C->left = B;
    C->right = A;

    // Adjust heights
    updateHeight(static_cast<AVLTreeNode<T>*>(A));
    updateHeight(static_cast<AVLTreeNode<T>*>(B));
    updateHeight(static_cast<AVLTreeNode<T>*>(C));
}

template <typename T>
void AVLTree<T>::balanceRR(TreeNode<T>* A, TreeNode<T>* parentOfA)
{
    // A is right-heavy and B is right-heavy
    TreeNode<T>* B = A->right;

    if (A == this->root)
        this->root = B;
    else
        if (parentOfA->left == A)
            parentOfA->left = B;
        else
            parentOfA->right = B;

    A->right = B->left; // Make T2 the right subtree of A
    B->left = A;
    updateHeight(static_cast<AVLTreeNode<T>*>(A));
    updateHeight(static_cast<AVLTreeNode<T>*>(B));
}

template <typename T>
void AVLTree<T>::balanceRL(TreeNode<T>* A, TreeNode<T>* parentOfA)
{
    TreeNode<T>* B = A->right; // A is right-heavy
    TreeNode<T>* C = B->left; // B is left-heavy

    if (A == this->root)
        this->root = C;
    else
        if (parentOfA->left == A)
            parentOfA->left = C;
        else
            parentOfA->right = C;

    A->right = C->left; // Make T2 the right subtree of A
    B->left = C->right; // Make T3 the left subtree of B
    C->left = A;
    C->right = B;

    // Adjust heights
    updateHeight(static_cast<AVLTreeNode<T>*>(A));
    updateHeight(static_cast<AVLTreeNode<T>*>(B));
    updateHeight(static_cast<AVLTreeNode<T>*>(C));
}

template <typename T>
bool AVLTree<T>::remove(const T& e)
{
    if (this->root == nullptr)
        return false; // Element e is not in the tree

    // Locate the node to be deleted and also locate its parent node
    TreeNode<T>* parent = nullptr;
    TreeNode<T>* current = this->root;
    while (current != nullptr)
    {
        if (e < current->element) // Test if e < current->element
        {
            parent = current;
            current = current->left;
        }
        else if (e > current->element)
        {
            parent = current;
            current = current->right;
        }
        else
            break; // Element e is in the tree pointed by current
    }

    if (current == nullptr)
        return false; // Element e is not in the tree

    // Case 1: current has no left children (See Figure 23.6)
    if (current->left == nullptr)
    {
        // Connect the parent with the right child of the current node
        if (parent == nullptr)
            this->root = current->right;
        else
        {
            if (e < parent->element)
                parent->left = current->right; // Connect to parent's left
            else
                parent->right = current->right; // Connect to parent's right

            // Balance the tree if necessary
            balancePath(parent->element);
        }
    }
    else
    {
        // Case 2: The current node has a left child
        // Locate the rightmost node in the left subtree of
        // the current node and also its parent
        TreeNode<T>* parentOfRightMost = current;
        TreeNode<T>* rightMost = current->left;

        while (rightMost->right != nullptr)
        {
            parentOfRightMost = rightMost;
            rightMost = rightMost->right; // Keep going to the right
        }

        // Replace the element in current by the element in rightMost
        current->element = rightMost->element;

        // Eliminate rightmost node
        if (parentOfRightMost->right == rightMost)
            parentOfRightMost->right = rightMost->left;
        else
            // Special case: parentOfRightMost is current
            parentOfRightMost->left = rightMost->left;

        // Balance the tree if necessary
        balancePath(parentOfRightMost->element);
    }

    this->size--; // Decrease size
    return true; // Element inserted
}
#endif
