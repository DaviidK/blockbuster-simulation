// --------------------------------- comedy.cpp --------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a comedy movie. It will contain all information 
// related to the Movie and allow for comparisons to other Comedy objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int)

#include "comedy.h"
#include <sstream>

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates a Comedy object and populates the genre, title, director, 
 * and releaseYear fields
 * @param[in] string input: containing all fields
 */
Comedy::Comedy(string input) {
    this->genre = 'F';
    
    // Place data from passed input into stringstream
    stringstream inputStream(input);

    // Get stock info from input
    if (!this->checkValidInput(inputStream, "Stock")) {
        return;
    }

    // Get director from input
    if (!this->checkValidInput(inputStream, "Director")) {
        return;
    }

    // Get title from input
    if (!this->checkValidInput(inputStream, "Title")) {
        return;
    }

    // Get title from input
    if (!this->checkValidInput(inputStream, "Year")) {
        return;
    }
}

Comedy::Comedy(char, string input) {
    this->genre = 'F';

    // Place data from passed input into stringstream
    stringstream inputStream(input);

    // Get title from input
    if (!this->checkValidInput(inputStream, "Title")) {
        return;
    }

    // Get title from input
    if (!this->checkValidInput(inputStream, "Year")) {
        return;
    }
}

//---------------------------------------------------------Public Data Accessors
/**
 * public virtual compareTo
 * Will compare this Comedy object to the passed parameter Comedy object
 * Returns 1 if this is greater than the parameter, -1 if this is less
 * than the parameter, and 0 if the two Movies are equal.
 * @param[in] Comedy: Movie object to be compared with this object
 */
int Comedy::compareTo(const Movie& movie) const {
    if (*this == movie) {
        return 0;
    } else if (*this > movie) {
        return 1;
    } else {
        return -1;
    }
}

//---------------------------------------------------------Overloaded Operations
/**
 * Overloads the ostream << operator
 * Prints the Movie details and stock
 * Output example: 
 * "TODO"
 * @param[out] ostream output;
 * @param[in] Comedy movie: details to displayed
 */
ostream& operator<<(ostream& output, const Comedy& movie){
    output << "Stock: " << movie.getStockInStore()
           << "; Title: " << movie.getTitle()
           << "; Director: " << movie.getDirector()
           << "; Release Year: " << movie.getReleaseYear() << endl;
    // return ostream&
    return output;
}

/**
 * Overloads the == comparison operator
 * Compares each field for Comedy given in parameter
 * @param[in] Comedy movie: left hand side of operation
 * @return boolean: == comparison result
 */
bool Comedy::operator==(const Movie& movie) const {
    if (this->title.compare(movie.getTitle()) == 0 &&
        this->releaseYear == movie.getReleaseYear()) {
            return true;
    }
    // Movie is not same
    return false;
}

/**
 * Overloads the != comparison operator
 * Compares each field for Comedy given in parameter
 * @param[in] Comedy movie: left hand side of operation
 * @return boolean: != comparison result
 */
bool Comedy::operator!=(const Movie& movie) const {
    return !(*this == movie);
}

/**
 * Overloads the > comparison operator
 * Compares Director then Title of this to Comedy given in rhs
 * @param[in] Comedy movie: left hand side of operation
 * @return boolean: > comparison result
 */
bool Comedy::operator>(const Movie& movie) const {
    // First level of comparison
    int compare1 = this->title.compare(movie.getTitle());
    // Second level of comparison
    bool compare2 = this->releaseYear > movie.getReleaseYear();
    
    // If first level is >, return true.
    // If first level is ==, then look at 2nd level.
    if (compare1 > 0) {
        return true;
    } else if (compare1 == 0 && compare2) {
        return true;
    } else {
        return false;
    }
}

/**
 * Overloads the < comparison operator
 * Compares each field for Comedy given in parameter
 * @param[in] Comedy movie: left hand side of operation
 * @return boolean: < comparison result
 */
bool Comedy::operator<(const Movie& movie) const {
    return !(*this > movie) && *this != movie;
}