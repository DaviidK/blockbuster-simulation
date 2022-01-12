// ---------------------------- moviefactory.h ----------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a factory that is responsible for determining
// what type of Movie object should be instantiated based on provided
// input. Allows for dynamic binding of Movie objects.
// ------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the formats neccessary for each type of 
//    associated Movie genre

#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H

#include <sstream>
#include <algorithm>
#include <iomanip>
#include "movie.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"

using namespace std;

class MovieFactory {

    public:
        //-------------------------------------------------Public member methods
        // Instantiates the appropriate type of movie based on the given
        // genre parameter
        Movie* createMovie(string);
        Movie* createMovie(char genre, string input);
    
};

#endif