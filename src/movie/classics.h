// -------------------------------- classics.h ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a classic movie. It will contain all information 
// related to the Movie and allow for comparisons to other Classics objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseMonth(int)
//     releaseYear(int) 

#ifndef CLASSICS_H
#define CLASSICS_H

#include "movie.h"

using namespace std;

class Classics : public Movie {

        friend ostream& operator<<(ostream&, const Classics&);
        
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates a Classics object and populates the genre,
        // title, director, and releaseYear fields
        Classics(string);
        Classics(char, string);
        // Virtual destructor: Destroys the Classics object
        virtual ~Classics();
        // Compares this object to other Classics objects
        virtual int compareTo(const Movie &) const;
        // Overloads the == comparison operator
		virtual bool operator==(const Movie &) const;
        // Overloads the != comparison operator
		virtual bool operator!=(const Movie &) const;
        // Overloads the > comparison operator
        virtual bool operator>(const Movie &) const;
        // Overloads the < comparison operator
		virtual bool operator<(const Movie &) const;
        // Returns the major actor
        string getMajorActor() const;
        // Returns the movie release month
        int getReleaseMonth() const;

    private:
        //-------------------------------------------------Private member fields
        // Main actor in the movie
        string majorActor;
        // Month that the movie was released in
        int releaseMonth;
};

#endif