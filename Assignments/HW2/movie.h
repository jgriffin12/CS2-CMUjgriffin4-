#pragma once
#include <iostream>
#include <string>
#include "media.h"

using namespace std;

namespace movies
{
    class Movie
    {
        private:
            string gen_re;
            double rat_ing;
            string dir_ector; 

        public: 
            // Constructor - initialize
            Movie(string = "", double = 0.00, string = ""); 

            // Destructor - initialize 
            ~Movie(); 

            // Getter Methods
            string getGenre();
            double getRating();
            string getDirector();

            // Setter Methods
            void setGenre(string);
            void setRating(double);
            void setDirector(string);
    };
}
