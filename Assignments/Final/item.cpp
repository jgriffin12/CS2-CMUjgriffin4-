#include "item.h"
#include "player.h"

//Item Constructor
item::Item::Item(string iName, string iEffect)
{
    name = iName;
    effect = iEffect; 
};

//Item Destructor
item::Item::~Item()
{

}

//Getter
string item::Item::get_name()
{
    return name; 
}
string item::Item::get_effect()
{
    return effect; 
}

//Setter
void item::Item::setName(string new_name)
{
    name = new_name; 
}
void item::Item::setEffect(string new_effect)
{
    effect = new_effect; 
}

//Function to use an item
void item::Item::use()
{
    if (name == "Health Potion")
    {
        cout << "You used the Health Potion. Your health has now been restored and doubled!\n" << endl; 
    }
    else if (name == "Strength Potion")
    {
        cout << "You used the Strength Potion. You doubled the amount of damage!\n" << endl; 
    }
    else if (name == "Rusty Knife")
    {
        cout << "You used the Rusty Knife.\n" << endl; 
    }
}
