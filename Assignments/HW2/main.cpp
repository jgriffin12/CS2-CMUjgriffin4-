/*
Name: Janet Griffin
Date: 11/6/2024
Program: Media Database
Description: Movie, Tv show, Music Database. The program will be able to do the following:
    -Add Media of choice
    -Delete Media of choice
    -Print out Media of choice
    -Write entire database to another csv file
*/

#include <iostream>
#include <iomanip>
#include "movie.h"
#include "tvshows.h"
#include "music.h"
#include "media.h"
#include "database.h"
#include <fstream>

using namespace std; 

// Function for the user to choose a menu option 
int readMenu()
{
    int option; 
    cout << "\nWelcome to the Multi-media Database. Please select an option below:  \n" << endl;
    cout << "[1] Add a new item to the Multi-media Database " << endl;
    cout << "[2] Delete an item in the Multi-media Database " << endl;
    cout << "[3] Display the Multi-media Database given a type of media" << endl;
    cout << "[4] Search the Multi-media Database" << endl; 
    cout << "[5] Write the Multi-media Database to a separate CSV file" << endl;
    cin >> option;

    if (option == 1)
    {
        return 1; 
    } 
    else if (option == 2)
    {
        return 2; 
    } 
    else if (option == 3)
    {
        return 3; 
    } 
    else if (option == 4)
    {
        return 4; 
    } 
    else if (option == 5)
    {
        return 5; 
    }
    else
    {
        cout << "Option not valid. Please try again." << endl;
        readMenu(); 
        return 0; 
    }
}

// Bool function for if user wants to select another option within Media Database 
bool repeatMenu()
{
    char answer; 
    cout << "\n\nWould you like to select another option within the database? Select [Y|N]" << endl;
    cin >> answer; 

    if (answer == 'Y' || answer == 'y')
    {
        return true; 
    }
    else if (answer == 'N'|| answer == 'n')
    {
        return false; 
    }
    else
    {
        cout << "Invalid input. Try again." << endl;
        return readMenu(); 
    }
}

int main()
{
    bool repeat; 

    do
    {
        //Prompt user to choose menu option
        int answer = readMenu();

        database::Database mdb;

        //if statement depending on what is returned from readMenu()
        if (answer == 1)
        {
            mdb.addMedia(); 
            repeat = repeatMenu(); 
        } 
        else if (answer == 2)
        {
            mdb.deleteMedia(); 
            repeat = repeatMenu(); 
        } 
        else if (answer == 3)
        {
            mdb.displayMedia(); 
            repeat = repeatMenu(); 
        }
        else if (answer == 4)
        {
            mdb.searchMediaDB();
            repeat = repeatMenu(); 
        }
        else if (answer == 5)
        {
            mdb.writeCSVfile(); 
            repeat = repeatMenu(); 
        }

    } while (repeat == true);

    cout << "\nThanks for using the Multi-media database! Goodbye!"; 
}

