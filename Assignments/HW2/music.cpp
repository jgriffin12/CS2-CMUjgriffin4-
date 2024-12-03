# include "music.h"

// Constructor for Music
music::Music::Music(string music_composer, string music_genre, int music_numTracks, double music_totalPlaytime)
{
    composer = music_composer;
    genre = music_genre;
    numTracks = music_numTracks;
    totalPlaytime = music_totalPlaytime;
};

// Destructor for Music
music::Music::~Music()
{

}

// Music Getters
string music::Music::getComposer()
{
    return composer;
}

string music::Music::getGenre()
{
    return genre;
}

int music::Music::getNumTrack()
{
    return numTracks;
}

double music::Music::getTotalPlaytime()
{
    return totalPlaytime;
}

// Music Setters
void music::Music::setComposer(string new_composer)
{
    composer = new_composer;
}

void music::Music::setGenre(string new_genre)
{
    genre = new_genre;
}

void music::Music::setNumTrack(int new_numTrack)
{
    numTracks = new_numTrack;
}

void music::Music::setTotalPlaytime(double new_totalPlaytime)
{
    totalPlaytime = new_totalPlaytime;
}

