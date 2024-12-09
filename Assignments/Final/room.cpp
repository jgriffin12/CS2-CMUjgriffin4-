#include "room.h"
#include <iostream> 

//Constructor for Dungeon
Dungeon::Dungeon() 
{
    startingRoom = nullptr; 
}

//Add room
void Dungeon::addRoom(string description, string contents)
{
    Room* newRoom = new Room(description, contents); 

    if (startingRoom != nullptr)
    {
        //Traverse Rooms 
        Room* currRoom = startingRoom; 
        while(currRoom -> nextRoom != nullptr)
        {
            currRoom = currRoom -> nextRoom;
        }
        //Link the rooms together
        currRoom -> nextRoom = newRoom; 
    }
    else
    {
        //Set this as the starting point 
        startingRoom = newRoom; 
    }
}

//Get the first room
Room* Dungeon::getFirstRoom()
{
    return startingRoom; 
}

// Get the next room 
Room* Dungeon::getNextRoom(Room* currRoom)
{
    return currRoom -> nextRoom; 
}

//Print dungeon
void Dungeon::printDungeonDescription()
{
    Room* currRoom = getFirstRoom(); 
    while (currRoom != nullptr)
    {
        cout  << currRoom ->description << endl; 
        cout << "You notice that the room is not empty..." << endl;
        cout << "There is " << currRoom ->contents << endl; 
        currRoom = currRoom -> nextRoom; 
    }
}