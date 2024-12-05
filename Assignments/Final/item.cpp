#include "item.h"

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
void item::Item::setEffect(string  new_effect)
{
    effect = new_effect; 
}

//Function to use an item
void use()
{

}
