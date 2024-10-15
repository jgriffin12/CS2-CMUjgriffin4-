/*
Name: Janet Griffin
Date: 09/18/2024
Program: Movie Database
Description: Movie database is able to add movies, delete movies, search by title/genre, and write to a separate csv file. 

*/

#include <iostream>
#include <iomanip>
#include "movie.h"
#include "database.h"
#include <fstream>

using namespace std; 

// Function for the user to choose a menu option 
int readMenu()
{
    int option; 
    cout << "\nPlease select a menu option below: \n" << endl;
    cout << "[1] Add Movie" << endl;
    cout << "[2] Delete Movie" << endl;
    cout << "[3] Print Out Movies" << endl;
    cout << "[4] Write Movie Database to Separate CSV file" << endl;
    cout << "[5] Search for Movie using Title or Genre" << endl; 
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
        readMenu(); 
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

    cout << "Thanks for using the movie database! Goodbye!"; 
}

