#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

using namespace std;


// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    if (root == nullptr) { // If the tree is empty, return a
        // new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}


bool search(Node* root, int data)
{
    bool retval;

    if (root == nullptr)
    {
        retval = false;
        return retval;
    }

    else if (root->data == data)
    {
        retval = true;
        return retval;
    }

    else if (data <= root->data)
    {
        return search(root->left, data);
    }

    else return search(root->right, data);
}

int main()
{

    Node* root = nullptr;
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    cout<<search(root, 1)<<endl;


    return 0;
}