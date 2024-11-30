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
    cout << "\nWelcome to the Media Database. Please select a media option you would like to work with: \n" << endl;
    cout << "[1] Movie " << endl;
    cout << "[2] Music " << endl;
    cout << "[3] Tv Show" << endl;
    cout << "[4] Write Media Database to Separate CSV file" << endl;
    cout << "[5] Search through Media Database" << endl; 
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

// Bool function for if user wants to select another option within Movie Database 
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
            mdb.addMovie(); 
            repeat = repeatMenu(); 
        } 
        else if (answer == 2)
        {
            mdb.deleteMovie(); 
            repeat = repeatMenu(); 
        } 
        else if (answer == 3)
        {
            mdb.printMovie(); 
            repeat = repeatMenu(); 
        }
        else if (answer == 4)
        {
            mdb.writeMovieDB();
            repeat = repeatMenu();  
        }
        else
        {
            mdb.searchMovies();
            repeat = repeatMenu(); 
        }

    } while (repeat == true);

    cout << "\nThanks for using the media database! Goodbye!"; 
}

