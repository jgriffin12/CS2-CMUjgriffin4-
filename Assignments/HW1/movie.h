#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace movies
{
    class Movie
    {
        private:
            string title_id;
            string title_name;
            string yea_r;
            string gen_re;
            double rat_ing;
            string dir_ector; 

        public: 
            // Constructor - initialize
            Movie(string = "", string = "", string = "", string = "", double = 0.00, string = ""); 

            // Destructor - initialize 
            ~Movie(); 

            // Getter Methods
            string get_titleID();
            string getTitle();
            string getYear();
            string getGenre();
            double getRating();
            string getDirector();

            // Setter Methods
            void setTitleID(string);
            void setTitle(string);
            void setYear(string);
            void setGenre(string);
            void setRating(double);
            void setDirector(string);
    };
}
