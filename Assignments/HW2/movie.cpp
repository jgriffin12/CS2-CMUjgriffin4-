#include "movie.h"

// Constructor for Movie
movies::Movie::Movie(string genre, double rating, string director)
{
    gen_re = genre;
    rat_ing = rating;
    dir_ector = director; 
};

// Destructor for Movie - Will use when deleting a movie (does this work?)
movies::Movie::~Movie()
{
   
}

// Getters
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