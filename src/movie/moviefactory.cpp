// ----------------------------- moviefactory.cpp ------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a factory that is responsible for determining
// what type of Movie object should be instantiated based on provided
// input. Allows for dynamic binding of Movie objects.
// ------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the formats neccessary for each type of 
//    associated Movie genre

#include "moviefactory.h"
#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include <sstream>
#include <algorithm>

//---------------------------------------------------Constructors and Destructor
/**
 * public createMovie
 * Instantiates the appropriate type of movie based on the given
 * genre parameter
 * @param[in] string input: contains all fields
 */
Movie* MovieFactory::createMovie(string input) {
    // Place data from passed input into stringstream
    stringstream inputStream(input);

    // Pull the first character of the passed string to determine the type of
    // Movie object to be created
    string movieGenre;
    inputStream >> movieGenre;
    // trim leading spaces and commas
    remove(movieGenre.begin(), movieGenre.end(), ' ');
    remove(movieGenre.begin(),movieGenre.end(), ',');

    // check for none char input
    if (movieGenre.size() != 1) {
        cout << "ERROR: Movie genre \"" << movieGenre << "\" is not valid" 
             << endl;
        return NULL;
    }

    // Create a Movie object and instantiate it according to the character
    // found in input.
    Movie* m;
    switch (movieGenre.at(0)) {
        case 'C':
            m = new Classics(inputStream.str());
            if (m->getTitle() == "") {
                return NULL;
            }
            break;
        case 'F':
            m = new Comedy(inputStream.str());
            if (m->getTitle() == "") {
                return NULL;
            }
            break;
        case 'D':
            m = new Drama(inputStream.str());
            if (m->getTitle() == "") {
                return NULL;
            }
            break;
        default:
            cout << "ERROR: Movie genre \"" << movieGenre << "\" is not valid"
                 << endl;
            return NULL;
    }

    return m;
}

Movie* MovieFactory::createMovie(char genre, string input) {

    // Create a Movie object and instantiate it according to the character
    // found in input.
    Movie* m;
    switch (genre) {
        case 'C':
            m = new Classics(genre, input);
            if (m->getTitle() == "") {
                return NULL;
            }
            break;
        case 'F':
            m = new Comedy(genre, input);
            if (m->getTitle() == "") {
                return NULL;
            }
            break;
        case 'D':
            m = new Drama(genre, input);
            if (m->getTitle() == "") {
                return NULL;
            }
            break;
        default:
            cout << "ERROR: Movie genre \"" << genre << "\" is not valid"
                 << endl;
            return NULL;
    }

    return m;
}