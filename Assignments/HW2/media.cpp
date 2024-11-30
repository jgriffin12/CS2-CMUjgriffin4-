# include "media.h"

// Constructor for Media
media::Media::Media(string mediaid, string mediatitle, string mediayear)
{
    media_id = mediaid;
    media_title = mediatitle;
    media_year = mediayear;
};

// Destructor for Movie - Will use when deleting a movie (does this work?)
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

// Function returns string
// void media::Media::displayInfo()
// {
    
// }