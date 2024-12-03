# include "tvshows.h"

// Constructor for Tvshows
tvshows::Tvshows::Tvshows(string tvshowgenre, double tvshowrating, int numberEpisodes)
{
    tvshow_genre = tvshowgenre;
    tvshow_rating = tvshowrating;
    numEpisodes = numberEpisodes; 
}

// Destructor for Tvshows
tvshows::Tvshows::~Tvshows()
{

}

//Tvshow Getters
string tvshows::Tvshows::get_Tvgenre()
{
    return tvshow_genre;
}

double tvshows::Tvshows::get_Tvrating()
{
    return tvshow_rating;
}

int tvshows::Tvshows::get_numEpisodes()
{
    return numEpisodes;
}

//Tvshow Setters
void tvshows::Tvshows::setTvGenre(string new_tvgenre)
{
    tvshow_genre = new_tvgenre;
}

void tvshows::Tvshows::setTvRating(double new_tvrating)
{
    tvshow_rating = new_tvrating;
}

void tvshows::Tvshows::setNumEpisodes(int new_NumEpisodes)
{
    numEpisodes = new_NumEpisodes;
}