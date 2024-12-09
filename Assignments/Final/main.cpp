/*
Name: Janet Griffin
Date 12/5/2024
Program: Final - Game 
Description: This program is a text based game that that will have the player navigate through a dungeon where they will meet enemies, 
collect items, and try to beat a final boss.
*/

#include <iostream>
#include "room.h"
#include "item.h"
#include "player.h"
#include "enemy.h"

using namespace std; 

// Setting intro
void intro()
{
    // Introduction
    cout << "\nYou wake up and find yourself in a dimly lit cave. As you look around, you notice there is a torch on the wall and some items in" <<
    " your pocket. There is a note from your friend, Tobias. \n" << endl; 
    cout << "If you are reading this, I am no longer alive. I'm not sure where we are, but you must get out of this cave. I've given you all I "<<
    "have. There are two potions and one knife - one healing potion and one strength potion. " << 
    "I haven't been able to explore much, but I do know that the monsters that guard our room typically leave the door unattended at midnight. " <<
    "That is your best chance to escape. Godspeed. \n" << endl;
    cout << "-Tobias \n" << endl; 
    cout << "Midnight comes around. You hear the guards leave and decide now is your chance. You gather your belongings and courage"<<
    " and open the door...\n" << endl; 
}

// Player decides to move to a different room, fight, or use an item.
int playerDecision()
{
    int answer; 

    // Player options (move rooms/fight/use item)
    cout << "\nWhat would you like to do? : " << endl;
    cout << "[1] Move to the Next Room" << endl; 
    cout << "[2] Fight an Enemy" << endl; 
    cout << "[3] Use an Item" << endl; 
    cin >> answer;

    return answer;
}

int main()
{
    string name; 
    int health = 20;  
    int amount = 5;

    //Get Player name
    cout << "Choose a player name: ";
    cin >> name; 

    //Create Player
    player::Player player1(name, health); 

    //Create dungeon
    Dungeon dungeon; 

    // Add the rooms and their descriptions to the dungeon
    //Hallway - first comes out of room (startingRoom)
    dungeon.addRoom("You see that you are in a long hallway with only one door on the other end. Torches line the hallway. The air feels thick.", 
                    "You look around and it appears to be empty. You move forward to the only door available."); 
    // Bad Room
    dungeon.addRoom("You open the door and a stench hits you.",
                    "To your right, an Ogre looks at you. As the Ogre approaches, you have to think quick.");     
    //Treasure Room
    dungeon.addRoom("Whew, you barely survived! You open the door to the next room. You start to notice that the air is feeling lighter. ",
                    "Thankfully, there is no one in this room."); 
    //Final boss room
    dungeon.addRoom("You hear a strange noise." ,
                    "Bravely, you open the door. Inside there is a giant Ogre waiting for you."); 
    //Outside Freedom - Last room 
    dungeon.addRoom("You reach a door that's the heaviest. You pull with all your might until the door finally gives.",
                    "You open your eyes and see blue sky for the first time in forever. Congrats, you make it out of the cave!");  

    //Intro
    intro(); 

    //Create items and add to player inventroy
    item::Item health_potion("Health Potion", "Restores you back to full health");
    item::Item strength_potion("Strength Potion", "Doubles the damage to enemy");  
    item::Item knife("Rusty Knife", "Deals -5 Damage to enemy"); 

    player1.add_to_inventory("1.Health Potion");
    player1.add_to_inventory("2.Strength Potion"); 
    player1.add_to_inventory("3.Rusty Knife"); 

    // Game has starting room at hallway - not where player wakes up
    Room* currRoom = dungeon.getFirstRoom();

    //Counter - Keep track of rooms
    int count = 1; 

    if (currRoom != nullptr)
    {
        while (player1.get_health() > 0)
        {
            //Display Player Stats
            cout << "Player Health: " << player1.get_health(); 
            vector <string> inventory = player1.get_inventory(); 
            cout << "\nPlayer Inventory: " << endl;
            for (size_t i = 0; i < inventory.size(); i++)
            {
                cout << inventory[i] << " "; 
            }
            cout << "\n" << endl; 

            //Display the current room 
            cout << currRoom -> description << endl; 
            cout << currRoom -> contents << endl; 

            //Player decision
            int decision = playerDecision(); 
            if (decision == 1)
            {
                cout << "\nYou have decided to move to the next room.\n" << endl;
                count += 1; 

                //Move to the next room
                if (currRoom ->nextRoom != nullptr)
                {
                    currRoom = dungeon.getNextRoom(currRoom); 
                }
                else
                {
                    cout << "There are no more rooms. " << endl; 
                }
            }
            else if (decision == 2)
            {
                cout << "You have decided to fight!" << endl;
                //Loop until someone dies
                if (count == 2)
                {
                    //Create first enemy - Name, Health (20/20), Damage 4
                    enemy::Enemy enemy("Ogre", 20, 4); 

                    while (enemy.get_health() > 0 && player1.get_health() > 0)
                    {
                        cout << "You used the Rusty knife to attack.\n" << endl; 
                        //Player attacks with damage 5
                        player1.p_attack(enemy, amount); 

                        if (enemy.get_health() <= 0)
                        {
                            cout << "The Ogre has fallen.\n" << endl; 
                            break; 
                        }

                        //Enemy attacks
                        cout << "\nThe Ogre attacks!!" << endl; 
                        player1.p_take_damage(enemy.get_damage());

                        //Check player health
                        if (player1.get_health() <=0)
                        {
                            cout << "Oh no! You did not make it out of the cave." << endl; 
                        }
                    }
                    //You defeat the Ogre
                    //Move to the next room
                    if (currRoom ->nextRoom != nullptr)
                    {
                        currRoom = dungeon.getNextRoom(currRoom); 
                        count++; 
                    }
                    else
                    {
                        cout << "There are no more rooms. " << endl; 
                    }
                }
                else if (count == 4)
                {
                    //Create big boss 
                    enemy::Enemy boss("King Ogre", 20, 9); 
                    while (boss.get_health() > 0 && player1.get_health() > 0)
                    {
                        cout << "You used the Rusty knife to attack.\n" << endl; 
                        //Player attacks with damage 5
                        player1.p_attack(boss, amount); 

                        if (boss.get_health() <= 0)
                        {
                            cout << "The King Ogre has fallen.\n" << endl; 
                            break; 
                        }
                        //Enemy attacks
                        cout << "\nThe King Ogre attacks!!" << endl; 
                        player1.p_take_damage(boss.get_damage());

                        //Check player health
                        if (player1.get_health() <=0)
                        {
                            cout << "Oh no! You lost the game. You did not make it out of the cave. :(" << endl; 
                        }
                    }
                    //You defeat the Ogre
                    //Move to the next room
                    if (currRoom ->nextRoom != nullptr)
                    {
                        currRoom = dungeon.getNextRoom(currRoom); 
                        count++; 
                    }
                    else
                    {
                        cout << "There are no more rooms. " << endl; 
                    }
                }
                else
                {
                    cout << "There are no enemies to fight.\n" << endl; 
                }
            }
            else if (decision == 3)
            {
                int use_item; 
                cout << "You decide to use an item.\n" << endl; 
                //Print out inventory
                cout << "Inventory: ";
                for (size_t i = 0; i < inventory.size(); i++)
                {
                    cout << inventory[i] << " "; 
                }
                cout << "\n\nEnter a number of the item you would like to use: "; 
                cin >> use_item; 

                // Adjust Player stats depending on what they chose
                if (use_item == 1)
                {
                    player1.setHealth(40); 
                    cout << "\nYou decide to use the Health Potion." << endl;
                    health_potion.use();  
                }
                else if (use_item == 2)
                {
                    player1.setDamage(10); 
                    cout << "\nYou decide to use the Strength Potion." << endl;
                    strength_potion.use(); 
                }
                else if (use_item == 3) 
                {
                    cout << "\nYou decide to use the Rusty Knife." << endl;
                    knife.use(); 
                }
                else
                {
                    cout << "That option is invalid." << endl; 
                }
            }
        }
    }
}