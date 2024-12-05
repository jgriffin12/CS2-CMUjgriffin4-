#pragma once
#include <iostream>
#include <string>

using namespace std; 

namespace player
{
    class Player
    {
        private:
           string name;
           int health; 
           //<vector> inventory[][10];

        public:
        //Initialize constructor and destructor
        Player (string = "", int = 0); 
        ~Player();

        //Getter
        string get_name();
        int get_health(); 

        //Setter
        void setName(string);
        void setHealth(int); 

        //Other Methods
        void attack();
        void take_damage(int amount);
        void add_to_inventory(string item);
    }; 
}