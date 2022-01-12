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

#include "moviefactory.h"

/**
 * printElement
 * Helper method that allows for easy printing of elements at set intervals
 * @param[in] Typename T: Data to be printed
 * @param[in] int width: Width between next element on print line
 */
template<typename T> void printElement(T t, const int& width) {
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

//---------------------------------------------------------Public member methods
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
    string token;
    inputStream >> token;
    char movieGenre = token.at(0);

    string restOfLine;
    getline(inputStream, restOfLine);

    // Create a Movie object and instantiate it according to the character
    // found in input.
    Movie* m = NULL;
    switch (movieGenre) {
        case 'C':
            m = new Classics(restOfLine);
            break;
        case 'F':
            m = new Comedy(restOfLine);
            break;
        case 'D':
            m = new Drama(restOfLine);
            break;
        default:
            printElement("Invalid genre", 40);
            printElement(movieGenre, 20);
    }

    return m;
}

/**
 * public createMovie
 * Instantiates the appropriate type of movie based on the given
 * genre parameter
 * @param[in] char genre : contains all fields
 * @param[in] string input : contains all fields
 */
Movie* MovieFactory::createMovie(char genre, string input) {

    // Create a Movie object and instantiate it according to the character
    // found in input.
    Movie* m = NULL;
    switch (genre) {
        case 'C':
            m = new Classics(genre, input);
            break;
        case 'F':
            m = new Comedy(genre, input);
            break;
        case 'D':
            m = new Drama(genre, input);
            break;
        default:
            printElement("Invalid genre", 55);
            printElement(genre, 30);
    }

    return m;
}