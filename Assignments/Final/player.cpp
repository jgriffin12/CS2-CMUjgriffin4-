#include "player.h"

//Constructor for Player
player::Player::Player(string pName, int pHealth)
{
    name = pName; 
    health = pHealth;
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

//Setter
void player::Player::setName(string new_name)
{
    name = new_name; 
}
void player::Player::setHealth(int  new_health)
{
    health = new_health; 
}

// Attack function
void attack()
{

}

// Take damage function
void take_damage(int amount)
{

}

// Add items to inventory
void add_to_inventory(string item)
{

}
