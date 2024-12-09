#pragma once
#include <iostream>
#include <string>

using namespace std; 

// Struct for room
struct Room 
{
    string description; 
    string contents; 
    Room* nextRoom; 

    //Constructor
    Room (string descript = "", string contentsForRoom = "")
    {
        description = descript;
        contents = contentsForRoom;
        nextRoom = nullptr; 
    }
}; 

// Dungeon class to represent linked list rooms
class Dungeon
{
    private:
        Room* startingRoom;                 //Starting room

    public: 
        Dungeon(); 
        //Add new room
        void addRoom(string description, string contents); 
        //Get first room
        Room* getFirstRoom(); 
        //Get next 
        Room* nextRoom();
        //Get next room from current room
        Room* getNextRoom(Room* currRoom); 
        void printDungeonDescription(); 
}; 
