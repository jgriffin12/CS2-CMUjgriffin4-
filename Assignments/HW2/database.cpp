#include "database.h"
#include <fstream>
#include <vector>
#include <cctype>
#include <string>

// Function to add an item to the media database 
void database::Database::addMedia()
{
    // variables 
    string media_info, med_id, med_name, med_year, type, med_genre, director, composer; 
    double rating, totalPlaytime;
    int numEpisodes, numTracks;  

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
    }
    else if (type == "TV" || type == "tv")
    {
        cout << "Rating: ";
        cin >> rating; 
        cout << "Number of Episodes: ";
        cin >> numEpisodes; 
    }
    else if (type == "Music" || type == "music")
    {
        cout << "Composer: "; 
        cin >> composer; 
        cout << "Number of Tracks: ";
        cin >> numTracks;
        cout << "Total Playtime: "; 
        cin >> totalPlaytime; 
    }
    else
    {
        cout << "Not a valid option."; 
    }  

    // Create Media, Movie, Music, and TV objects
    media::Media mediaObj(med_id, med_name, med_year);
    movies::Movie movieObj(med_genre, rating, director);
    music::Music musicObj(composer, med_genre, numTracks, totalPlaytime);
    tvshows::Tvshows tvshowObj(med_genre, rating, numEpisodes); 

    // if statement to add to Media DB depending on if the media type is tvshow, movie, or music
    if (type == "Movie" || type == "movie")
    {
        fstream fout;
        fout.open("movies.csv", ios::out|ios::app);

        //Adds movie to csv file. 
        fout << mediaObj.get_mediaId() << ", " << mediaObj.get_mediaTitle() << ", " << mediaObj.get_mediaYear() << ", " << movieObj.getGenre() << 
        ", " << movieObj.getRating() << ", " << movieObj.getDirector() << endl;

        //Closes file 
        fout.close(); 
    }
    else if (type == "TV" || type == "tv")
    {
        fstream fout;
        fout.open("tvshows.csv", ios::out|ios::app);

        //Adds movie to csv file. 
        fout << mediaObj.get_mediaId() << ", " << mediaObj.get_mediaTitle() << ", " << mediaObj.get_mediaYear() << ", " << tvshowObj.get_Tvgenre() 
        << ", " << tvshowObj.get_Tvrating() << ", " << tvshowObj.get_numEpisodes() << endl;

        //Closes file 
        fout.close(); 
    }
    else if (type == "Music" || type == "music")
    {
        fstream fout;
        fout.open("music.csv", ios::out|ios::app);

        //Adds movie to csv file. 
        fout << mediaObj.get_mediaId() << ", " << mediaObj.get_mediaTitle() << ", " << mediaObj.get_mediaYear() << ", " << musicObj.getComposer() 
        << ", " << musicObj.getGenre() << ", " << musicObj.getNumTrack() << musicObj.getTotalPlaytime();

        //Closes file 
        fout.close(); 
    }
    else
    {
        // Need to loop back to type options if here 
        cout << "Not a valid option. Try again."; 
    }

    //Print out the added item by calling the displayInfo() function from media.cpp
    cout << "\nThe following item was added to the database: " << endl; 
    
    cout << "displayInfo() not working - fixing" << endl; 

    cout << "Item was added. Please check the affiliated csv file for an updated record.";
}

// Function to delete an item from the media database 
void database::Database::deleteMedia()
{
    string mediaID; 

    // Ask user for media ID
    cout << "Please enter the Media ID of the item you would like to delete." << endl;
    cin >> mediaID; 

    fstream fin1, fin2, fin3, fout1, fout2, fout3; 
    string line1, line2, line3; 

    //Open CSV files
    fin1.open("movies.csv", ios::in);
    fin2.open("tvshows.csv", ios::in);
    fin3.open("music.csv", ios::in); 

    //Error message if movies.csv fails to open
    if (fin1.fail() || fin2.fail() || fin3.fail())
    {
        cout << "Error - Files did not open." << endl; 
    }

    // New file to store data that is not deleted
    fout1.open("movies_new.csv", ios::out);
    fout2.open("tvshows_new.csv", ios::out);
    fout3.open("music_new.csv", ios::out);

    //Search first file (movies.csv) and delete if found
    while (getline(fin1, line1))
    {
        if (line1.find(mediaID) == string::npos)
        {
            fout1 << line1 << endl;
        }
    }

    //Search second file and delete if found (tvshows.csv)
    while (getline(fin2, line2))
    {
        if (line2.find(mediaID) == string::npos)
        {
            fout2 << line2 << endl;
        }
    }

    //Search third file and delete if found (music.csv)
    while (getline(fin3, line3))
    {
        if (line3.find(mediaID) == string::npos)
        {
            fout3 << line3 << endl;
        }
    }

    //Close files
    fin1.close();
    fin2.close();
    fin3.close();
    fout1.close();
    fout2.close();
    fout3.close();

    //Rename updated files 
    remove("movies.csv");
    rename("movies_new.csv", "movies.csv"); 
    remove("tvshows.csv");
    rename("tvshows_new.csv", "tvshows.csv"); 
    remove("music.csv");
    rename("music_new.csv", "music.csv"); 

    cout << "The media item was successfully deleted."; 
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
    string answer, media_id, media_genre, media_title; 
    cout << "How would you like to search through the Multi-media database? (ID|Genre|Title)" << endl; 
    cin >> answer; 

    // Stream variables for the three csv files. 
    fstream fin, fout, fin2, fout2, fin3, fout3; 
    string line; 
    vector <string> rows; 

    //Open CSV files
    fin.open("movies.csv", ios::in);
    fin2.open("tvshows.csv", ios::in); 
    fin3.open("music.csv", ios::in);

    if (answer == "ID" || answer == "id")
    {
        cout << "Please enter the Media ID that you would like to search for: ";
        cin >> media_id; 

        //Search for ID in all of the files
        for (size_t i = 0; i < media_id.length(); i++)
        {
            if (i == 0 || media_title[i-1] == ' ')
            {
                media_title[i] = toupper(media_title[i]); // I dont need? 
            }
        }

        //Add line from file to vector <rows>
        while (getline(fin, line, '\n'))
        {
            rows.push_back(line); 
        }

        //Iterate through each element in vector <rows> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            if (rows[i].find((media_id)) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
    }
    if (answer == "title" || answer == "Title")
    {
        cout << "Please enter the name or title of the item you would like to search for: ";
        cin.ignore(); 
        getline(cin, media_title);

        for (size_t i = 0; i < media_title.length(); i++)
        {
            if (i == 0 || media_title[i-1] == ' ')
            {
                media_title[i] = toupper(media_title[i]); 
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
            if (rows[i].find((media_title)) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
    }
    else if (answer == "genre" || answer == "Genre")
    {
        cout << "Please enter the genre you would like to see: ";
        cin >> media_genre; 

        //Capitalizes first letter of word input so that search function works correctly
        media_genre[0] = toupper(media_genre[0]); 

        //Add line from file to vector <rows>
        while (getline(fin, line, '\n'))
        {
            rows.push_back(line); 
        }

        //Iterate through each element in vector <rows> and check if genre is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            if (rows[i].find(media_genre) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
    }
    else
    {
        cout << "Invalid input. Please try again."; 
    }

    // Close files
    fin.close();
    fin2.close();
    fin3.close(); 
}

//Function to write out entire Media Database to a separate combined csv file
void database::Database::writeCSVfile()
{
    fstream fin1, fin2, fin3, fout;  
    string line1, line2, line3; 

    //Open current CSV files
    fin1.open("movies.csv", ios::in);
    fin2.open("tvshows.csv", ios::in);
    fin3.open("music.csv", ios::in); 

    // New csv file to write all files to 
    fout.open("megaDatabase.csv", ios::out); 

    //Error message if any of files fail to open
    if (fin1.fail() || fin2.fail() || fin3.fail())
    {
        cout << "Error - Files did not open. " << endl; 
    }

    // Read first file
    fout << "Movie List: " << endl;
    while (getline(fin1, line1, '\n'))
    {
        fout << line1 << endl;
    }

    // Read second file 
    fout << "\nTv Show List: " << endl;
    while (getline(fin2, line2, '\n'))
    {
        fout << line2 << endl;
    }

    // Read Third File 
    fout << "\nMusic List: " << endl;
    while (getline(fin3, line3, '\n'))
    {
        fout << line3 << endl;
    }

    cout << "A Mega Database csv file was created. Please check megaDatabase.csv file." << endl; 

    //Close files
    fin1.close();
    fin2.close(); 
    fin3.close(); 
    fout.close(); 
}

