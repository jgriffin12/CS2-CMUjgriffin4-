#pragma once

#include <iostream> 
#include <string>
#include "movie.h"
#include "music.h"
#include "tvshows.h"

using namespace std; 

namespace database
{
    class Database
    {
        private: 
            string name;
            string db_id; 
            Database* movie_db[100];   
            Database* music_db[100];
            Database* tvshow_db[100];

        public:
            void addMedia(); 
            void deleteMedia();
            void displayInfo();
            void printMediaTable();
            void searchMedia(); 
    };
};

