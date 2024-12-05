#pragma once
#include "node.h"
#include <iostream>
#include <cmath>

using namespace std;

class Stack
{
    private:
        Node<double> *_top;
        size_t stackSize;

    public:
        Stack();
        ~Stack();

        bool empty();
        size_t size();

        void push(double);
        double pop();
        double top();
};

// set to nullptr and initialize stackSize
Stack::Stack()
{
    _top = nullptr;
    stackSize = 0; 
}

// iteratively delete the stack starting at top
Stack::~Stack()
{
    for (size_t i = 0; i <= stackSize; i++)
    {
        pop(); 
    }
}

// return true if the Stack is empty, false otherwise.
// Do not just check stackSize, should actually check top
bool Stack::empty()
{
    if (_top == nullptr)
    {
        return 1; 
    }
    else 
    {
        return 0; 
    }
}

// return number of elements in Stack
size_t Stack::size()
{
    return stackSize; 
}

// add an element to the beginning of the Stack, updating top
void Stack::push(double data)
{
    //Create temporary stack
    Node<double> temp; 

    //Push element into temp stack

    //

    //Move data from original stack to temp stack
}

// return the first element in the Stack. (get the bottom element from stack)
// if the Stack is empty, print an error and return NaN (from cmath) nan = not a number value 
double Stack::top()
{
    if (empty())
    {
        cerr << "Stack is empty. " << endl;
        return NAN; 
    }
    else
    {
        //do studd
    }
}

// remove the first element from the Stack and return its data 
// if the Stack is empty, print an error and return NaN (from cmath)
double Stack::pop()
{
    if (empty())
    {
        cerr << "Stack is empty. " << endl;
        return NAN; 
    }
    else
    {
        // do stuff
    }
}