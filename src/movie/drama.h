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

using namespace std;

class Drama: public Movie {
    
        friend ostream& operator<<(ostream&, const Drama&);

    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates a Drama object and populates the genre, title,
        // director, and releaseYear fields
        Drama(string);
        Drama(char, string);
        // Virtual destructor: Destroys the Drama object
        virtual ~Drama();
        // Compares this object to other Drama objects
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

#endiff