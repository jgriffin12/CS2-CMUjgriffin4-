#include "media.h"

using namespace std;

namespace music
{
    class Music
    {
        private:
            string composer;
            string genre;
            int numTracks;
            double totalPlaytime;

        public:

        //Constructor
        Music(string = "", string = "", int = 0, double = 0.0);

        //Destructor
        ~Music();

        //Getter Methods
        string getComposer();
        string getGenre();
        int getNumTrack();
        double getTotalPlaytime();

        //Setter Methods
        void setComposer(string);
        void setGenre(string);
        void setNumTrack(int);
        void setTotalPlaytime(double);

    };
}