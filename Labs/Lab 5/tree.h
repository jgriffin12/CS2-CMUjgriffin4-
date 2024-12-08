#pragma once
#include "node.h"

template <class T1>
class BST
{
private:
    Node<T1> *_root;
    Node<T1> *insertNode(Node<T1> *, T1);
    void inOrderPrint(Node<T1> *);
    Node<T1> *searchData(Node<T1> *, T1);
    Node<T1> *removeData(Node<T1> *, T1);
    Node<T1> *minVal(Node<T1> *);
    void destroyTree(Node<T1>* root);

public:
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1); 
    BST(); 
    ~BST();
};

template <class T1> 
//Constructor
BST<T1>::BST()
{
    _root = nullptr; 
}

// Destructor, should call destroyTree, passing _root to that method
template <class T1>
BST<T1>::~BST()
{
    destroyTree(_root); 
}

// This should recursively walk the tree and delete a node if both leafs are null. You can return from a void function if you just have the return statement.
// This is useful if root == nullptr...
template <class T1>
void BST<T1>::destroyTree(Node<T1>* root)
{
    if (root == nullptr)
    {
        return; 
    }
    else
    {
        //Destroy Left
        destroyTree(root -> getLeft());
        //Destroy Right
        destroyTree(root -> getRight()); 

        // Destroy current node
        delete root; 
    }
}

// Public method that takes in some data and passes that into the removeData method. Don't forget to update _root as you may end up deleting the original root.
template <class T1>
void BST<T1>::remove(T1 data)
{
    _root = removeData(_root, data); 
}

// Private method to recursively walk the tree until the data is found.
// Then using the process built in class, check if there is only one leaf, if so then move that leaf into the root position.
// If there are two leafs, find the smallest value in the right subtree (or the largest value in the left subtree but you would have to rename minVal method) and then replace
// the current node with that.
// Don't forget to clean up your memory!
template <class T1>
Node<T1> *BST<T1>::removeData(Node<T1> *root, T1 data)
{
    if (root == nullptr)
    {
        return nullptr; 
    }

    //Move left or right 
    if (root -> getData() > data)
    {
        root ->setLeft(removeData(root->getLeft(), data));  
    }
    else if (root -> getData() < data)
    {
        root ->setRight(removeData(root->getRight(), data));  
    }
    else
    {
        if (root ->getLeft() == nullptr)
        {
            Node<T1>* tempNode = root -> getRight(); 
            delete root; 
            return tempNode; 
        }
        else if (root ->getRight() == nullptr)
        {
            Node<T1>* tempNode = root -> getLeft(); 
            delete root; 
            return tempNode; 
        }

        //If here, node has two branches - finding the min value
        Node<T1>* minNode = minVal(root->getRight());

        root -> setData(minNode -> getData());
        root -> setRight(removeData(root -> getRight(), minNode ->getData())); 
    }
    return root;
}

// Given a node, find the smallest value in that subtree. Return that node
template <class T1>
Node<T1> *BST<T1>::minVal(Node<T1> *root)
{
    // Loop through until left most node is found 
    do
    {
        root = root -> getLeft();
    }while(root -> getLeft() != nullptr && root != nullptr); 

    //Return Smallest node value
    return root; 
}

// Given data and a node, recursively walk the tree to find that node if it exists.
template <class T1>
Node<T1> *BST<T1>::searchData(Node<T1> *root, T1 data)
{
    if (root != nullptr)
    {
        if (root -> getData() == data)
        {
            return root; 
        }
        else
        {   
            if (data < root -> getData())
            {
                Node<T1>* root = searchData(root->getLeft(), data); 
            }
            else
            {
                Node<T1>* root = searchData(root->getRight(), data); 
            }
        }
    }
    return root; 
}

// Wrapper function for searchData. Pass data, root into searchData and return true if data found, return false if data not found.
template <class T1>
bool BST<T1>::search(T1 data)
{
    if (searchData(_root, data) != nullptr)
    {
        return true; 
    }
    else
    {
        return false; 
    }
}

// Given a node, recursively walk the tree to print out the inOrder format. That's left->root->right.
// Make sure you cout with a space separating each value as I based my tests on that!
// For example, you would end up cout (do not add the "): "1 2 3 4 5 "
// Notice that there is an extra space at the end.
template <class T1>
void BST<T1>::inOrderPrint(Node<T1> *root)
{
    if (root != nullptr)
    {
        //Prints left root val
        inOrderPrint(root -> getLeft());

        std::cout << root -> getData() << " "; 

        //Print right side nodes on tree
        inOrderPrint(root-> getRight());
    }
    else
    {
        return; 
    }
}

// Wrapper for inOrderPrint
template <class T1>
void BST<T1>::inOrder()
{
    inOrderPrint(_root); 
}

// Give some data and a node, recursively walk the tree until you get to a nullptr and store the value there.
// You should ensure that if data < the current node's data, you walk the left. If data > current node's data, walk right.
// You should check if the value already exists and say so (it's just adding an else with a cout).
template <class T1>
Node<T1> *BST<T1>::insertNode(Node<T1> *root, T1 data)
{
    if (root == nullptr)
    {
        Node<T1>* newNode = new Node<T1>(); 
        newNode ->setData(data); 
        return newNode; 
    }

    if (root->getData() > data)
    {
        root ->setLeft(insertNode(root->getLeft(), data)); 
    }
    else if (root -> getData() < data)
    {
        root ->setRight(insertNode(root->getRight(), data)); 
    }
    else
    {
        std::cout << "Value " << data << "already exists." << std::endl; 
    }
}

// Wrapper for insertNode. Take in data to pass that and _root to insertNode. Ensure you update _root since if the tree is empty, that would be the new _root.
template <class T1>
void BST<T1>::insert(T1 data)
{
    _root  = insertNode(_root, data); 
}