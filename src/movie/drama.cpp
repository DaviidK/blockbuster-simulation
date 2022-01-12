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

//---------------------------------------------------Constructors and Destructor
/**
 * Constructor
 * Creates a Drama object and populates the genre, title,
 * director, and releaseYear fields
 * @param[in] string input : containing all fields
 */
Drama::Drama(string input) : Movie() {
    // Set genre to Drama (D)
    this->genre = 'D';
    
    // Place data from passed input into stringstream
    stringstream inputStream(input);
    
    // Temporary variable
    string dataString;

    // Get stock info from input
    getline(inputStream, dataString, ',');
    if (!this->checkValidInput(dataString, "Stock")) {
        return;
    }

    // Get director from input
    getline(inputStream, dataString, ',');
    if (!this->checkValidInput(dataString, "Director")) {
        return;
    }

    // Get title from input
    getline(inputStream, dataString, ',');
    if (!this->checkValidInput(dataString, "Title")) {
        return;
    }

    // Get title from input
    getline(inputStream, dataString, ',');
    if (!this->checkValidInput(dataString, "Year")) {
        return;
    }
}

/**
 * Constructor
 * Creates a Drama object and populates the genre, title,
 * director, and releaseYear fields
 * @param[in] char genre : movie genre
 * @param[in] string input : containing all fields after genre
 */
Drama::Drama(char, string input) : Movie() {
    // Set genre to Drama (D)
    this->genre = 'D';

    // Place data from passed input into stringstream
    stringstream inputStream(input);
    
    // Temporary variable
    string dataString;
    
    // Get director from input
    getline(inputStream, dataString, ',');
    if (!this->checkValidInput(dataString, "Director")) {
        return;
    }

    // Get title from input
    getline(inputStream, dataString, ',');
    if (!this->checkValidInput(dataString, "Title")) {
        return;
    }
}

/**
 * virtual Destructor
 * Destroys the Drama object
 */
Drama::~Drama() {}

//---------------------------------------------------------Public member methods
/**
 * public virtual compareTo
 * Will compare this Drama object to the passed parameter Movie object
 * Returns 1 if this is greater than the parameter, -1 if this is less
 * than the parameter, and 0 if the two Movies are equal.
 * @param[in] Movie : Movie object to be compared with this object
 * @return int : -1 (<), 0 (==), or 1 (>)
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

/**
 * Overloads the == comparison operator
 * Compares Director then Title of this to Movie given in rhs
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : == comparison result
 */
bool Drama::operator==(const Movie& movie) const {
    // Compare Director and Title 
    if (this->director.compare(movie.getDirector()) == 0 &&
        this->title.compare(movie.getTitle()) == 0) {
            return true;
    }
    // Movie is not same
    return false;
}

/**
 * Overloads the != comparison operator
 * Compares Director then Title of this to Movie given in rhs
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : != comparison result
 */
bool Drama::operator!=(const Movie& movie) const {
    return !(*this == movie);
}

/**
 * Overloads the > comparison operator
 * Compares Director then Title of this to Movie given in rhs
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : > comparison result
 */
bool Drama::operator>(const Movie& movie) const { 
    // First level of comparison
    int compare1 = this->director.compare(movie.getDirector());
    // Second level of comparison
    int compare2 = this->title.compare(movie.getTitle());
    
    // If first level is >, return true, else if first level is ==,
    // then compare at 2nd level
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
 * Compares Director then Title of this to Movie given in parameter
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : < comparison result
 */
bool Drama::operator<(const Movie& movie) const {
    return !(*this > movie) && *this != movie;
}