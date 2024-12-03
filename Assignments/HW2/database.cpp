#include "database.h"
#include "movie.h"
#include <fstream>
#include <vector>
#include <cctype>
#include <string>

// Function to add an item to the media database 
void database::Database::addMedia()
{
    // variables 
    string media_info; 
    string med_id;
    string med_name; 
    string med_year; 
    string type; 
    string med_genre; 
    string rating; 
    string director;
    int numEpisodes;  
    int numTracks;
    double totalPlaytime; 
    string composer; 

    media::Media mediaDB; 

    // Prompts user to enter media information to add item
    cout << "\nPlease enter the following information to add an item to the Multi-media Database: \n" << endl; 
    cout << "Media Type (TV|Movie|Music): ";
    cin.ignore(); 
    getline(cin, type); 
    cout << "Media ID #: ";
    cin >> med_id;
    cout << "Name: ";
    cin.ignore(); 
    getline(cin, med_name); 
    cout << "Year: ";
    cin >> med_year; 
    cout << "Genre: ";
    cin >> med_genre;
    if (type == "Movie" || type == "movie")
    {
        cout << "Rating: ";
        cin >> rating; 
        cout << "Director: ";
        cin >> director; 

        //Create Movie Constructor
        movies::Movie movieObj(med_genre, rating, director); 
    }
    else if (type == "TV" || type == "tv")
    {
        cout << "Rating: ";
        cin >> rating; 
        cout << "Number of Episodes: ";
        cin >> numEpisodes; 

        // Create Tv Show constructor
        tvshows::Tvshows tvshowObj(genre, rating, numEpisodes); 
    }
    else if (type == "Music" || type == "music")
    {
        cout << "Composer: "; 
        cin >> composer; 
        cout << "Number of Tracks: ";
        cin >> numTracks;
        cout << "Total Playtime: "; 
        cin >> totalPlaytime; 

        // Create Music constructor
        music::Music musicObj(composer, genre, numTracks, totalPlaytime);
    }
    else
    {
        cout << "Not a valid option."; 
    }  

    // Create Media Constructor
    media::Media mediaObj(med_id, med_name, med_year);

    // if statement to add to Media DB depending on if the media type is tvshow, movie, or music
    if (type == "Movie" || type == "movie")
    {
        fstream fout;
        fout.open("movies.csv", ios::out|ios::app);

        //Closes file 
        fout.close(); 
    }
    else if (type == "TV" || type == "tv")
    {
        fstream fout;
        fout.open("tvshows.csv", ios::out|ios::app);

        //Closes file 
        fout.close(); 
    }
    else if (type == "Music" || type == "music")
    {
        fstream fout;
        fout.open("music.csv", ios::out|ios::app);

        //Closes file 
        fout.close(); 
    }
    else
    {
        cout << "Not a valid option. Try again."; 
    }

    //Print out the added item by calling the displayInfo() function from media.cpp
    cout << "\nThe following item was added to the database: " << endl; 
    mediaDB.displayInfo(); 

    cout << "Item was added. Please check the affiliated csv file for an updated record.";
}



    // //Adds movie to csv file. 
    // fout << movieObj.get_titleID() << ", " << movieObj.getTitle() << ", " << movieObj.getYear() << ", " << movieObj.getGenre() << ", " << 
    //     movieObj.getRating() << ", " << movieObj.getDirector() << endl;


// Function to delete an item from the media database 
void database::Database::deleteMedia()
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

// Function to display Media Database information
void database::Database::displayMedia()
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

//Function to search the Media Database given ID, name, type, etc
void database::Database::searchMediaDB()
{

}

//Function to write out entire Media Database to a separate csv file
void database::Database::writeCSVfile()
{

}

// {
//     fstream fin, fout; 
//     string line; 

//     //Open current CSV file
//     fin.open("movies.csv", ios::in);

//     // New csv file to write database to
//     fout.open("movielist_new.csv", ios::out);

//     //Error message if movies.csv fails to open
//     if (fin.fail())
//     {
//         cout << "Error - File did not open." << endl; 
//     }

//     //Read file. 
//     while (getline(fin, line, '\n'))
//     {
//         fout << line << endl;
//     }

//     cout << "New movie database created. Please check the movielist_new.csv file. " << endl; 
    
//     //Close files
//     fin.close(); 
//     fout.close(); 
// }

// void database::Database::searchMovies()
// {
//     string answer, movie_title, genre, words; 
//     cout << "Would you like to search the movie database by title or genre? "; 
//     cin >> answer; 

//     fstream fin, fout; 
//     string line; 
//     vector <string> rows; 

//     //Open CSV file
//     fin.open("movies.csv", ios::in);

//     if (answer == "title" || answer == "Title")
//     {
//         cout << "Please enter the title of the movie you would like to see: ";
//         cin.ignore(); 
//         getline(cin, movie_title);

//         for (size_t i = 0; i < movie_title.length(); i++)
//         {
//             if (i == 0 || movie_title[i-1] == ' ')
//             {
//                 movie_title[i] = toupper(movie_title[i]); 
//             }
//         }

//         //Add line from file to vector <rows>
//         while (getline(fin, line, '\n'))
//         {
//             rows.push_back(line); 
//         }

//         //Iterate through each element in vector <rows> and see if title or word is found. 
//         for (size_t i = 0; i <= rows.size(); i++)
//         {
//             if (rows[i].find((movie_title)) != string::npos)
//             {
//                 cout << "\n" << rows[i] << "\n" << endl; 
//             }
//         }
//     }
//     else if (answer == "genre" || answer == "Genre")
//     {
//         cout << "Please enter the genre you would like to see: ";
//         cin >> genre; 

//         //Capitalizes first letter of word input so that search function works correctly
//         genre[0] = toupper(genre[0]); 

//         //Add line from file to vector <rows>
//         while (getline(fin, line, '\n'))
//         {
//             rows.push_back(line); 
//         }

//         //Iterate through each element in vector <rows> and check if genre is found. 
//         for (size_t i = 0; i <= rows.size(); i++)
//         {
//             if (rows[i].find(genre) != string::npos)
//             {
//                 cout << "\n" << rows[i] << "\n" << endl; 
//             }
//         }
//     }
//     else
//     {
//         cout << "Invalid input. Please try again."; 
//     }

//     // Close file
//     fin.close();
// }

