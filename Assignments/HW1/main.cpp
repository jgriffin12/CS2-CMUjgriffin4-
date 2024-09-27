/*
Name: Janet Griffin
Date: 09/18/2024
Program: Movie Database
Description:

*/

#include <iostream>
#include <iomanip>
#include <movie.h>
#include <database.h>

using namespace std; 

// Function to add movie to the database
void addMovie()
{
    cout << "Add movie" << endl; 
}

// Function to delete movie from the database 
void deleteMovie()
{
    cout << "Delete movie" << endl; 
}

// Function to print all the movies from the database 
void printMovie()
{
    cout << "Print movie" << endl; 
}

// Function to write the movies from the database to a separate csv file
void writeMovieDB()
{
    cout << "write to movie" << endl; 
}

// Function for the user to choose a menu option 
int readMenu()
{
    int option; 
    cout << "Please select a menu option below: \n" << endl;
    cout << "[1] Add Movie" << endl;
    cout << "[2] Delete Movie" << endl;
    cout << "[3] Print Out Movies" << endl;
    cout << "[4] Write Movie Database to Separate CSV file" << endl;
    cin >> option;

    if (option == 1)
    {
        return 1; 

    } else if (option == 2)
    {
        return 2; 

    } else if (option == 3)
    {
        return 3; 

    } else if (option == 4)
    {
        return 4; 
        
    } else
    {
        cout << "Option not valid. Please try again." << endl;
        readMenu(); 
    }
}

int main()
{
    //Prompt user to choose menu option
    readMenu();

    //if statement depending on what is returned from readMenu()
    if (readMenu() == 1)
    {
        addMovie(); 

    } else if (readMenu() == 2)
    {
        deleteMovie(); 

    } else if (readMenu() == 3)
    {
        printMovie(); 

    } else
    {
        writeMovieDB(); 
    }
}

