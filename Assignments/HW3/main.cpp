#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

//RPN 
double evaluateRPN(string expression)
{
    return 0.0;
}

int main(int argc, char *argv[])
{
    string input; 

    if (argc == 3 && argv[1] == "-p")
    {
        string expression = argv[2]; 
        double answer = evaluateRPN(expression); 
    }

    //User input
    cout << "Plase enter an RPN expression: ";
    getline (cin, input); 
}