#include "enemy.h"

//Constructor for enemy
enemy::Enemy::Enemy(string eName, int eHealth, int eDamage)
{
    name = eName; 
    health = eHealth; 
    damage = eDamage; 
};

//Destructor for Enemy
enemy::Enemy::~Enemy()
{

}

//Getter
string enemy::Enemy::get_name()
{
    return name; 
}
int enemy::Enemy::get_health()
{
    return health; 
}
int enemy::Enemy::get_damage()
{
    return damage; 
}

//Setter
void enemy::Enemy::setName(string new_name)
{
    name = new_name; 
}
void enemy::Enemy::setHealth(int  new_health)
{
    health = new_health; 
}
void enemy::Enemy::setDamage(int new_damage)
{
    damage = new_damage; 
}

//Attack function
void attack()
{

}

//Take damage function
void take_damage(int amount)
{
    
}