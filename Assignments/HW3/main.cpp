#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"
#include <cassert>

using namespace std;

void test(); 

//RPN 
double evaluateRPN(string expression)
{
    //Create Stack object
    Stack rpn_el; 

    //Use stringstream to parse user input
    stringstream ss(expression);
    string temp; 
    double lVal, rVal, answer, number;  

    //Extract each character in expression and place in temp variable 
    while (ss >> temp)
    {
        if (temp == "-" || temp == "+"|| temp == "/" || temp == "*")
        {
            rVal = rpn_el.pop(); 
            lVal = rpn_el.pop(); 
        
            if (temp == "-")
            {
                answer = (lVal - rVal); 
            }
            else if (temp == "+")
            {
                answer = (lVal + rVal); 
            }
            else if (temp == "/")
            {
                answer = (lVal / rVal);  
            }
            else if (temp == "*")
            {
                answer = (lVal * rVal); 
            }
            //push answer to stack
            rpn_el.push(answer); 
        }
        else
        {
            // temp is a number not operator. 
            double number = stod(temp); 
            //Push number on to stack 
            rpn_el.push(number); 
        }
    }
    return rpn_el.top(); 
}

int main(int argc, char *argv[])
{
    string input; 
    double result; 

    if (argc == 3 && argv[1] == "-p")
    {
        input = argv[2]; 
        cout << evaluateRPN(input); 
    }

    //User input
    cout << "Plase enter an RPN expression: ";
    getline (cin, input); 

    // Call evaluateRPN function
    result = evaluateRPN(input); 

    cout << "Result: " << result; 

    //Test function 
    test();

   return 0; 
}

//Test function
void test()
{
    string test1 = " 3 4 + 5 6 - * ";
    string test2 = " 9 1 / 3 4 - / "; 
    assert(evaluateRPN(test1) == -7); 
    assert(evaluateRPN(test2) == -9); 

    cout << "All test cases passed." << endl; 
}