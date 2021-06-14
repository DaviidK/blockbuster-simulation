// ---------------------------------- drama.cpp --------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a drama movie. It will contain all information 
// related to the Drama and allow for comparisons to other Drama objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseYear(int)

#include "drama.h"
#include <sstream>

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates a Drama object and populates the genre, title,
 * director, and releaseYear fields
 * @param[in] string input: containing all fields
 */
Drama::Drama(string input) {
    this->genre = 'D';
    
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

Drama::Drama(char, string input) {
    this->genre = 'D';

    // Place data from passed input into stringstream
    stringstream inputStream(input);
    
    // Get director from input
    if (!this->checkValidInput(inputStream, "Director")) {
        return;
    }

    // Get title from input
    if (!this->checkValidInput(inputStream, "Title")) {
        return;
    }
}

//---------------------------------------------------------Public Data Accessors

/**
 * public virtual compareTo
 * Will compare this Drama object to the passed parameter Drama object
 * Returns 1 if this is greater than the parameter, -1 if this is less
 * than the parameter, and 0 if the two Movies are equal.
 * @param[in] Drama: Movie object to be compared with this object
 */
int Drama::compareTo(const Movie& movie) const {
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
 * @param[in] Drama movie: details to displayed
 */
ostream& operator<<(ostream& output, const Drama& movie){
    output << "Stock: " << movie.getStockInStore()
           << "; Title: " << movie.getTitle()
           << "; Director: " << movie.getDirector()
           << "; Release Year: " << movie.getReleaseYear() << endl;
    // return ostream&
    return output;
}

/**
 * Overloads the == comparison operator
 * Compares each field for Drama given in parameter
 * @param[in] Drama movie: left hand side of operation
 * @return boolean: == comparison result
 */
bool Drama::operator==(const Movie& movie) const {
    if (this->director.compare(movie.getDirector()) == 0 &&
        this->title.compare(movie.getTitle()) == 0) {
            return true;
    }
    // Movie is not same
    return false;
}

/**
 * Overloads the != comparison operator
 * Compares each field for Drama given in parameter
 * @param[in] Drama movie: left hand side of operation
 * @return boolean: != comparison result
 */
bool Drama::operator!=(const Movie& movie) const {
    return !(*this == movie);
}

/**
 * Overloads the > comparison operator
 * Compares Director then Title of this to Drama given in rhs
 * @param[in] Drama movie: left hand side of operation
 * @return boolean: > comparison result
 */
bool Drama::operator>(const Movie& movie) const {
    // First level of comparison
    int compare1 = this->director.compare(movie.getDirector());
    // Second level of comparison
    int compare2 = this->title.compare(movie.getTitle());
    
    // If first level is >, return true.
    // If first level is ==, then look at 2nd level.
    if (compare1 > 0) {
        return true;
    } else if (compare1 == 0 && compare2 > 0) {
        return true;
    } else {
        return false;
    }
}

/**
 * Overloads the < comparison operator
 * Compares each field for Drama given in parameter
 * @param[in] Drama movie: left hand side of operation
 * @return boolean: < comparison result
 */
bool Drama::operator<(const Movie& movie) const {
    return !(*this > movie) && *this != movie;
}