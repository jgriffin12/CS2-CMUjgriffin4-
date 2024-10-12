#pragma once

#include <iostream> 
#include <string>
#include "movie.h"

using namespace std; 

namespace database
{
    class Database
    {
        private: 
            string name;
            string db_id; 
            Database* movie_db;   
        public:
            void addMovie(); 
            void deleteMovie();
            void printMovie();
            void writeMovieDB();
            void updateCSV(); 
    };
};

