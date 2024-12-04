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
        cout << "Not a valid option. Try again."; 
    }

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

// Function to display Media Database information given 
void database::Database::displayMedia()
{
    string type; 

    cout << "What type of media would you like to see? Please choose one of the following (Movie|Tv|Music): " << endl; 
    cin >> type; 

    if (type == "movie" || type == "Movie")
    {
        cout << "Here is a list of movies within the database: \n" << endl; 


        ifstream myfilepath("movies.csv");

        while (!myfilepath.eof())
        {
            string line; 
            getline(myfilepath, line, ',');
            cout << line; 
        }
    }
    else if (type == "Tv" || type == "tv")
    {
        cout << "Here is a list of TV Shows within the database: \n" << endl; 

        ifstream myfilepath("tvshows.csv");

        while (!myfilepath.eof())
        {
            string line; 
            getline(myfilepath, line, ',');
            cout << line; 
        }
    }
    else if (type == "Music" || type == "music")
    {
        cout << "Here is a list of Music within the database: \n" << endl; 

        ifstream myfilepath("music.csv");

        while (!myfilepath.eof())
        {
            string line; 
            getline(myfilepath, line, ',');
            cout << line; 
        }
    }
    else
    {
        cout << "Not valid. " << endl; 
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
    string line, line2, line3; 
    vector <string> rows, rows2, rows3; 

    //Open CSV files
    fin.open("movies.csv", ios::in);
    fin2.open("tvshows.csv", ios::in); 
    fin3.open("music.csv", ios::in);

    if (answer == "ID" || answer == "id")
    {
        cout << "Please enter the Media ID that you would like to search for: ";
        cin >> media_id; 

        //Add line from file 1 to vector <rows>
        while (getline(fin, line, '\n'))
        {
            rows.push_back(line); 
        }

        //Iterate through each element in vector <rows> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows[i].find((media_id)) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
        while (getline(fin2, line2, '\n'))
        {
            rows2.push_back(line2); 
        }

        //Iterate through each element in vector <rows2> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows2[i].find((media_id)) != string::npos)
            {
                cout << "\n" << rows2[i] << "\n" << endl; 
            }
        }
        while (getline(fin3, line3, '\n'))
        {
            rows3.push_back(line3); 
        }
        //Iterate through each element in vector <rows3> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows3[i].find((media_id)) != string::npos)
            {
                cout << "\n" << rows3[i] << "\n" << endl; 
            }
        }
    }

    else if (answer == "Genre" || answer == "genre")
    {
        cout << "Please enter the Media genre that you would like to search for: ";
        cin >> media_genre; 

        //Capitalizes first letter of word input so that search function works correctly
        media_genre[0] = toupper(media_genre[0]); 

        //Add line from file 1 to vector <rows>
        while (getline(fin, line, '\n'))
        {
            rows.push_back(line); 
        }

        //Iterate through each element in vector <rows> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows[i].find((media_genre)) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
        while (getline(fin2, line2, '\n'))
        {
            rows2.push_back(line2); 
        }

        //Iterate through each element in vector <rows2> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows2[i].find((media_genre)) != string::npos)
            {
                cout << "\n" << rows2[i] << "\n" << endl; 
            }
        }
        while (getline(fin3, line3, '\n'))
        {
            rows3.push_back(line3); 
        }
        //Iterate through each element in vector <rows3> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows3[i].find((media_genre)) != string::npos)
            {
                cout << "\n" << rows3[i] << "\n" << endl; 
            }
        }
    }
    else if (answer == "Title" || answer == "title")
    {
        cout << "Please enter the Media title that you would like to search for: ";
        cin >> media_title; 

        //Takes care of capitalization
        for (size_t i = 0; i < media_title.length(); i++)
        {
            if (i == 0 || media_title[i-1] == ' ')
            {
                media_title[i] = toupper(media_title[i]); 
            }
        }

        //Add line from file 1 to vector <rows>
        while (getline(fin, line, '\n'))
        {
            rows.push_back(line); 
        }

        //Iterate through each element in vector <rows> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows[i].find((media_title)) != string::npos)
            {
                cout << "\n" << rows[i] << "\n" << endl; 
            }
        }
        while (getline(fin2, line2, '\n'))
        {
            rows2.push_back(line2); 
        }

        //Iterate through each element in vector <rows2> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows2[i].find((media_title)) != string::npos)
            {
                cout << "\n" << rows2[i] << "\n" << endl; 
            }
        }
        while (getline(fin3, line3, '\n'))
        {
            rows3.push_back(line3); 
        }
        //Iterate through each element in vector <rows3> and see if media_id is found. 
        for (size_t i = 0; i <= rows.size(); i++)
        {
            // Record is found and printed out
            if (rows3[i].find((media_title)) != string::npos)
            {
                cout << "\n" << rows3[i] << "\n" << endl; 
            }
        }
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

