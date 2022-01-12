// ---------------------------------- drama.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a drama movie. It will contain all information 
// related to the Movie and allow for comparisons to other Drama objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int) 

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"
#include <sstream>

using namespace std;

class Drama: public Movie {
    
    public:
        //-------------------------------------------Constructors and Destructor
        // Constructor: Creates a Drama object and populates the genre, title,
        // director, and releaseYear fields
        Drama(string);
        Drama(char, string);
        // Virtual destructor: Destroys the Drama object
        virtual ~Drama();
        //-------------------------------------------------Public member methods
        // Compares this object to other Movie objects
        virtual int compareTo(const Movie &) const;
        // Overloads the == comparison operator
		virtual bool operator==(const Movie &) const;
        // Overloads the != comparison operator
		virtual bool operator!=(const Movie &) const;
        // Overloads the > comparison operator
        virtual bool operator>(const Movie &) const;
        // Overloads the < comparison operator
		virtual bool operator<(const Movie &) const;

};

#endif