#include "database.h"
#include "movie.h"
#include <fstream>

// Function to add movie to the database - Need to fix string input for Name of Movie
void database::Database::addMovie()
{
    // Prompts user to enter movie information 
    string imbd;
    string movie_name;
    string movie_year; 
    string movie_genre; 
    double movie_rating; 
    string movie_director; 
    cout << "\nPlease enter the IMBD number: ";
    cin >> imbd; 
    cout << "Name: ";
    cin.ignore(); 
    getline(cin, movie_name); 
    cout << "Year: ";
    cin >> movie_year;
    cout << "Genre: ";
    cin >> movie_genre; 
    cout << "Rating: ";
    cin >> movie_rating; 
    cout << "Director: ";
    cin >> movie_director; 

    // Create a movie object by using the Movie constructor
    movies::Movie movieObj(imbd, movie_name, movie_year, movie_genre, movie_rating, movie_director);

    fstream fout; 

    fout.open("movies.csv", ios::out|ios::app);

    // Print out the added movie
    cout << "The following movie was added to the database: \n" << endl;
    cout << movieObj.get_titleID() << ", " << movieObj.getTitle() << ", " << movieObj.getYear() << ", " << movieObj.getGenre() << ", " << 
        movieObj.getRating() << ", " << movieObj.getDirector() << endl;

    //Adds movieto csv file. 
    fout << movieObj.get_titleID() << ", " << movieObj.getTitle() << ", " << movieObj.getYear() << ", " << movieObj.getGenre() << ", " << 
        movieObj.getRating() << ", " << movieObj.getDirector() << endl;

    //Closes file 
    fout.close(); 
}

// Function to delete movie from the database 
void database::Database::deleteMovie()
{
    fstream fin, fout; 
    string line; 

    //Open CSV file
    fin.open("movies.csv", ios::in);

    // User input for which movie record to delete
    string movie_id; 
    cout << "Please enter the IMBD of the movie you would like to remove: "; 
    cin >> movie_id; 

    while (!fin.eof())
    {
        getline(fin, line); 

        string str; 
        for (unsigned int i = 0; i < line.size(); i++)
        {
            if (line[i] == ',')
            {
                break;
            }
            else
            {
                str += line[i]; 
            }
        }  
        if (movie_id != str)
        {
            fout << line; 
        }
    }
}

// Function to print all the movies from the database - Read csv file and print 
void database::Database::printMovie()
{
    cout << "\nThis is the list of all the movies in the database. \n\n"; 

    ifstream myfilepath("movies.csv");

    while (!myfilepath.eof())
    {
        string line; 
        getline(myfilepath, line, ',');
        cout << line; 
    }
}

// Function to write the movies from the database to a separate csv file
// void database::Database::writeMovieDB()
// {
//     cout << "write to movie" << endl; 
// }

// Update movies.csv with added movie (if statement?)
// void updateCSV()
// {
//     fstream fin, fout; 

//     //Open the csv file
//     fin.open("movies.csv", ios::in);

//     //Store updated database
//     fout.open("movies.csv", ios::out); 

// }

