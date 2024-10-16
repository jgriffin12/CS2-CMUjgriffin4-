#include "database.h"
#include "movie.h"
#include <fstream>
#include <vector>
#include <cctype>

// Function to add movie to the database 
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
    cin.ignore();
    getline(cin, movie_director); 

    // Create a movie object by using the Movie constructor
    movies::Movie movieObj(imbd, movie_name, movie_year, movie_genre, movie_rating, movie_director);

    fstream fout; 

    fout.open("movies.csv", ios::out|ios::app);

    // Print out the added movie
    cout << "The following movie was added to the database: \n" << endl;
    cout << movieObj.get_titleID() << ", " << movieObj.getTitle() << ", " << movieObj.getYear() << ", " << movieObj.getGenre() << ", " << 
        movieObj.getRating() << ", " << movieObj.getDirector() << endl;

    //Adds movie to csv file. 
    fout << movieObj.get_titleID() << ", " << movieObj.getTitle() << ", " << movieObj.getYear() << ", " << movieObj.getGenre() << ", " << 
        movieObj.getRating() << ", " << movieObj.getDirector() << endl;

    //Closes file 
    fout.close(); 

    cout << "Movie was added. Please check movies.csv for an updated list.";
}

// Function to delete movie from the database 
void database::Database::deleteMovie()
{
    fstream fin, fout; 
    string line; 

    //Open CSV file
    fin.open("movies.csv", ios::in);

    //Error message if movies.csv fails to open
    if (fin.fail())
    {
        cout << "Error - File did not open." << endl; 
    }

    // New file to store data that is not deleted
    fout.open("movies_new.csv", ios::out);

    // User input for which movie record to delete
    string movie_id; 
    cout << "Please enter the IMBD of the movie you would like to remove: "; 
    cin >> movie_id; 

    while (getline(fin, line))
    {
        if (line.find(movie_id) == string::npos)
        {
            fout << line << endl;
        }
    }

    //Close files
    fout.close();
    fin.close();

    //Rename updated file to movies.csv
    remove("movies.csv");
    rename("movies_new.csv", "movies.csv"); 

    cout << "The movie was successfully deleted."; 

}

// Function to print all the movies from the database - Read csv file and print 
void database::Database::printMovie()
{
    cout << "\nThis is a list of all the movies in the database. \n\n"; 

    ifstream myfilepath("movies.csv");

    while (!myfilepath.eof())
    {
        string line; 
        getline(myfilepath, line, ',');
        cout << line; 
    }
}

// Function to write the movies from the database to a separate csv file
void database::Database::writeMovieDB()
{
    fstream fin, fout; 
    string line; 

    //Open current CSV file
    fin.open("movies.csv", ios::in);

    // New csv file to write database to
    fout.open("movielist_new.csv", ios::out);

    //Error message if movies.csv fails to open
    if (fin.fail())
    {
        cout << "Error - File did not open." << endl; 
    }

    //Read file. 
    while (getline(fin, line, '\n'))
    {
        fout << line << endl;
    }

    cout << "New movie database created. Please check the movielist_new.csv file. " << endl; 
    
}

void database::Database::searchMovies()
{
    string answer, movie_title, genre, words; 
    cout << "Would you like to search the movie database by title or genre? "; 
    cin >> answer; 

    fstream fin, fout; 
    string line; 
    vector <string> rows; 

    //Open CSV file
    fin.open("movies.csv", ios::in);

    if (answer == "title" || answer == "Title")
    {
        cout << "Please enter the title of the movie you would like to see: ";
        cin.ignore(); 
        getline(cin, movie_title);

        for (size_t i = 0; i < movie_title.length(); i++)
        {
            if (i == 0 || movie_title[i-1] == ' ')
            {
                movie_title[i] = toupper(movie_title[i]); 
            }
        }

        //Add line from file to vector <rows>
        while (getline(fin, line, '\n'))
        {
            rows.push_back(line); 
        }

        //Iterate through each element in vector <rows> and see if title or word is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            if (rows[i].find((movie_title)) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
    }
    else if (answer == "genre" || answer == "Genre")
    {
        cout << "Please enter the genre you would like to see: ";
        cin >> genre; 

        //Capitalizes first letter of word input so that search function works correctly
        genre[0] = toupper(genre[0]); 

        //Add line from file to vector <rows>
        while (getline(fin, line, '\n'))
        {
            rows.push_back(line); 
        }

        //Iterate through each element in vector <rows> and check if genre is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            if (rows[i].find(genre) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
    }
    else
    {
        cout << "Invalid input. Please try again."; 
    }

    // Close file
    fin.close();
}

