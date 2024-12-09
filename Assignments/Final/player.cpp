#include <iostream>
#include "enemy.h"
#include "player.h"

//Constructor for Player
player::Player::Player(string pName, int pHealth, int pDamage)
{
    name = pName; 
    health = pHealth;
    damage = pDamage; 
};

//Destructor for Player
player::Player::~Player()
{

}

//Getter
string player::Player::get_name()
{
    return name; 
}
int player::Player::get_health()
{
    return health; 
}
vector <string> player::Player::get_inventory()
{
    return items; 
} 
int player::Player::get_damage()
{
    return damage; 
}

//Setter
void player::Player::setName(string new_name)
{
    name = new_name; 
}
void player::Player::setHealth(int new_health)
{
    health = new_health; 
}
void player::Player::setDamage(int new_damage)
{
    damage = new_damage; 
}

// Attack function
void player::Player::p_attack(enemy::Enemy& currEnemy, int amount) 
{
    cout << "You attack the Ogre with your knife. " << endl; 
    currEnemy.e_take_damage(amount); 
}

// Take damage function
void player::Player::p_take_damage(int amount)
{
    health -= amount;
    cout << "You have taken " << amount << " damage." << endl;
    cout << "Your health is " << health <<endl; 

    //CHeck if player has been defeated
    if (health <= 0)
    {
        cout << "Oh no! You did not make it out of the cave." << endl; 
    }
}

// Add items to inventory
void player::Player::add_to_inventory(string item)
{
    items.push_back(item); 
}
