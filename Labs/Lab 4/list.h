#pragma once
#include "node.h"
#include <iostream>

using namespace std;

template <class T1>
class List
{
    private:
        Node<T1> *_head;
        Node<T1> *_tail;
        size_t listSize;

    public:
        List();
        ~List();

        bool empty();
        size_t size();

        void push_front(T1);
        T1 pop_front();
        T1 front();
        void push_back(T1);
        T1 pop_back();
        T1 back();

        bool operator==(const List<T1>&);
        // Have to declare a template for friend functions using a different template variable
        template <class T2>
        friend ostream &operator<<(ostream &, const List<T2> &);
};

// set to nullptr and initialize listSize
template <class T1>
List<T1>::List()
{
    _head = nullptr;
    _tail = nullptr; 
    listSize = 0; 
}

// iteratively delete the list starting at _head
template <class T1>
List<T1>::~List()
{
    Node<T1>* currNode = _head; 
    while (currNode != nullptr)
    {
        Node <T1>* temp = currNode;         //Set temp node to current node = _head
        currNode = currNode->getNext();     //Move current node to the next
        delete temp;                        //Delete the _head that was stored in temp.
    }
}

// return true if the list is empty, false otherwise.
// Do not just check listSize, should actually check _head and _tail
template <class T1>
bool List<T1>::empty()
{
    if (_head == nullptr && _tail == nullptr)
    {
        return 1; 
    }
    else 
    {
        return 0; 
    }
}

// return number of elements in list
template <class T1>
size_t List<T1>::size()
{
    return listSize; 
}

// add an element to the beginning of the list, updating _head
template <class T1>
void List<T1>::push_front(T1 data)
{
    //If not empty
    if (!empty())
    {
        Node<T1>* newNode = new Node<T1>;
        newNode -> setData(data);
        newNode -> setNext(_head);
        _head -> setPrev(newNode);
        _head = newNode;  
    }
    else
    {
        //List is empty
        _head = new Node<T1>;
        _head->setData(data); 
        _tail = _head; 
    }

    //Increase list size by 1
    listSize++;
    return; 
}

// return the first element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::front()
{
    //Checks if empty
    if (!empty())
    {
        return _head->getData(); 
    }
    else
    {
        cout << "List is empty" << endl;
        return 0; 
    }
}

// remove the first element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_front()
{
    if (!empty())
    {
        //Assign returnData to _head and link to getData()
        T1 returnData = _head -> getData();
        //Assign _head to temp Node
        Node<T1>* temp = _head;
        //Assign _head to next node
        _head = _head -> getNext();
        // Get rid of temp 
        delete temp; 
    
        // Decrement listSize by 1
        listSize--; 

        return returnData; 
    }
    else
    {
        cout << "List is empty" << endl;
        return 0; 
    }
}

// add an element to the end of hte list, updating _tail
template <class T1>
void List<T1>::push_back(T1 data)
{
    //If not empty
    if (!empty())
    {
        Node<T1>* newNode = new Node<T1>;
        newNode -> setData(data);
        _tail -> setNext(newNode);
        newNode -> setPrev(_tail);
        _tail = newNode;  
    }
    else
    {
        //List is empty
        _tail = new Node<T1>;
        _tail->setData(data); 
        _head = _tail; 
    }

    //Increase list size by 1
    listSize++;
    return; 
}

// return the last element in the list.
// if the list is empty, print that out and return 0
template <class T1>
T1 List<T1>::back()
{
    if (!empty())
    {
        return _tail -> getData(); 
    }
    else
    {
        cout << "List is empty" << endl;
        return 0; 
    }
}

// remove the last element from the list and return its data
// if the list is empty, print that out and return 0;
template <class T1>
T1 List<T1>::pop_back()
{
    if (!empty())
    {
        T1 returnData = _tail -> getData(); 

        //Temp node 
        Node<T1>* temp = _tail; 
        _tail = _tail->getPrev();     //_tail is assigned second to last
        _tail->setNext(nullptr); 

        //Delete the temp node
        delete temp; 

        //Decrement by 1
        listSize--; 

        return returnData;
    }
    else
    {
        cout << "List is empty" << endl;
        return 0; 
    }
}

// overloading <<, should return a space separated stream of all of the elements
template <class T1>
ostream &operator<<(ostream &os, const List<T1> &list)
{
    Node<T1>* currNode = list._head;

    if (currNode != nullptr)
    {
        do
        {
            os << currNode-> getData() << " ";  
            currNode = currNode->getNext();
        } while (currNode != nullptr); 
        
    }

    return os; 

}

// should iterate through each list to check that they are exactly the same
template <class T1>
bool List<T1>::operator==(const List<T1>& rhs)
{
    bool match = true; 

    Node<T1>* currNode = _head; 
    Node<T1>* tempNode = rhs->_head;

    //Check size of lists first
    if (listSize != rhs.listSize)
    {
        match = false; 
        return match; 
    } 

    while (currNode != nullptr && tempNode != nullptr)
    {
        if (currNode->getData() != tempNode->getData())
        {
            match = false; 
            return match; 
        }
        else    
        {
            currNode = currNode -> getNext(); 
            tempNode = tempNode -> getNext(); 
        }
    }
    return match; 
} 
