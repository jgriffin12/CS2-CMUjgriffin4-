#include "movie.h"

// Constructor for Movie
movies::Movie::Movie(string titleid, string title, string year, string genre, double rating, string director)
{
    title_id = titleid;
    title_name = title;
    yea_r = year;
    gen_re = genre;
    rat_ing = rating;
    dir_ector = director; 
};

// Destructor for Movie - Will use when deleting a movie (does this work?)
movies::Movie::~Movie()
{
    cout << "Movie deleted." << endl; 
}

// Getters
string movies::Movie::get_titleID()
{
    return title_id;
}

string movies::Movie::getTitle()
{
    return title_name;
}

string movies::Movie::getYear()
{
    return yea_r;
}

string movies::Movie::getGenre()
{
    return gen_re;
}

double movies::Movie::getRating()
{
    return rat_ing;
}

string movies::Movie::getDirector()
{
    return dir_ector; 
}

// Setters
void movies::Movie::setTitleID(string new_title_id)
{
    title_id = new_title_id;
}

void movies::Movie::setTitle(string new_title)
{
    title_name = new_title;
}

void movies::Movie::setYear(string new_year)
{
    yea_r = new_year;
}

void movies::Movie::setGenre(string new_genre)
{
    gen_re = new_genre;
}

void movies::Movie::setRating(double new_rating)
{
    rat_ing = new_rating;
}

void movies::Movie::setDirector(string new_director)
{
    dir_ector = new_director; 
}