#pragma once
#include <iostream>
#include <string>

using namespace std; 

namespace item
{
    class Item
    {
        private:
           string name; 
           string effect;

        public:
        //Initialize constructor and destructor
        Item (string = "", string = ""); 
        ~Item();

        //Getter
        string get_name();
        string get_effect(); 

        //Setter
        void setName(string);
        void setEffect(string); 

        //Other Methods
        void use(); 
    }; 
}