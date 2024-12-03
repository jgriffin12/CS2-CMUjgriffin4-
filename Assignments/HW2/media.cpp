# include "media.h"

// Constructor for Media
media::Media::Media(string mediaid, string mediatitle, string mediayear)
{
    media_id = mediaid;
    media_title = mediatitle;
    media_year = mediayear;
};

// Destructor for Media
media::Media::~Media()
{
   
}

// Getter Methods - The following returns a string of the media id, media title, and the media year. 
string media::Media::get_mediaId()
{
    return media_id; 
}

string media::Media::get_mediaTitle()
{
    return media_title;
}

string media::Media::get_mediaYear()
{
    return media_year;
}

// Setters
void media::Media::setMediaId(string new_mediaid)
{
    media_id = new_mediaid;
}

void media::Media::setMediaTitle(string new_mediatitle)
{
    media_title = new_mediatitle;
}

void media::Media::setMediaYear(string new_mediayear)
{
    media_year = new_mediayear;
}

// Function returns string
string media::Media::displayInfo()
{
    // Print out the added item
    cout << medObj.get_titleID() << ", " << movieObj.getTitle() << ", " << movieObj.getYear() << ", " << movieObj.getGenre() << ", " <<         
        movieObj.getRating() << ", " << movieObj.getDirector() << endl;
}