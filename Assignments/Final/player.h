#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "enemy.h"

using namespace std; 

//Declaring enemy 
class Enemy; 

namespace player
{
    class Player
    {
        private:
           string name;
           int health; 
           int damage; 
           vector <string> items; 
           // Adding a pointer to the current enemy
           Enemy* currEnemy; 

        public:
        //Initialize constructor and destructor
        Player (string = "", int = 0, int = 0); 
        ~Player();

        //Getter
        string get_name();
        int get_health(); 
        int get_damage(); 
        vector <string> get_inventory(); 

        //Setter
        void setName(string);
        void setHealth(int); 
        void setDamage(int); 

        //Other Methods
        void p_attack(enemy::Enemy& currEnemy, int amount);
        void p_take_damage(int amount);
        void add_to_inventory(string item);
    }; 
}