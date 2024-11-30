# pragma once

#include <iostream>
#include "media.h"

namespace tvshows
{
    class Tvshows
    {
        private:
            string tvshow_genre;
            double tvshow_rating;
            int numEpisodes; 

        public:

        // Getter Methods
        string get_Tvgenre();
        double get_Tvrating();
        int get_numEpisodes();

        // Setter Methods
        void setTvGenre(string);
        void setTvRating(double);
        void setNumEpisodes(int);
    };
}