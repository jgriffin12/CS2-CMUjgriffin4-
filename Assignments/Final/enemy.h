#pragma once
#include <iostream>
#include <string>

using namespace std; 

namespace enemy
{
    class Enemy
    {
        private:
           string name;
           int health; 
           int damage; 

        public:
        //Initialize constructor and destructor
        Enemy (string = "", int = 0, int = 0); 
        ~Enemy();

        //Getter
        string get_name();
        int get_health(); 
        int get_damage(); 

        //Setter
        void setName(string);
        void setHealth(int); 
        void setDamage(int); 

        // Methods
        void e_attack();
        void e_take_damage(int amount); 

    }; 
}