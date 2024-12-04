# pragma once

#include <iostream>
#include <string>

using namespace std; 

namespace media 
{
    class Media
    {
        private:
            string media_id;
            string media_title;
            string media_year;

        public:
            // Constructor - initialize
            Media(string = "", string = "", string = ""); 

            // Destructor - initialize 
            ~Media(); 

            // Getter Methods
            string get_mediaId();
            string get_mediaTitle();
            string get_mediaYear(); 

            //displayInfo() needs to return a string
            //string displayInfo(media_obj, type_obj);

            //Setter Methods
            void setMediaId(string);
            void setMediaTitle(string);
            void setMediaYear(string);   
    };
}