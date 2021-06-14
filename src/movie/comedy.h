// --------------------------------- comedy.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a comedy movie. It will contain all information 
// related to the Movie and allow for comparisons to other Comedy objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int) 

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

using namespace std;

class Comedy : public Movie {

        friend ostream& operator<<(ostream&, const Comedy&);
    
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates a Comedy object and populates the genre, title,
        // director, and releaseYear fields
        Comedy(string);
        Comedy(char, string);
        // Virtual destructor: Destroys the Comedy object
        virtual ~Comedy();
        // Compares this object to other Comedy objects
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