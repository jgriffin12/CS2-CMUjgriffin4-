/*
Name: Janet Griffin
Date: 09/18/2024
Program: Movie Database
Description: Movie database is able to add, delete, update, search or print depending on what the user wants. 
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
    cout << "Please select a menu option below: \n" << endl;
    cout << "[1] Add Movie" << endl;
    cout << "[2] Delete Movie" << endl;
    cout << "[3] Print Out Movies in Database" << endl;
    cout << "[4] Write Movie Database to Separate CSV file" << endl;
    cout << "[5] Search for Movie Given a Genre or Title" << endl;  
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

int main()
{
    //Prompt user to choose menu option
    int answer = readMenu();

    database::Database mdb;

    //if statement depending on what is returned from readMenu()
    if (answer == 1)
    {
        mdb.addMovie(); 

    } 
    else if (answer == 2)
    {
        mdb.deleteMovie(); 

    } 
    else if (answer == 3)
    {
        mdb.printMovie(); 
    }
    else if (answer == 4)
    {
        mdb.writeMovieDB(); 
    }
    else
    {
        mdb.searchMovies(); 
    }


    //Ask user if they would like to use database again
}

