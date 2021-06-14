// --------------------------------- classics.cpp ------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a classic movie. It will contain all information 
// related to the Movie and allow for comparisons to other Classics objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) releaseMonth(int)
//     releaseYear(int) 

#include "classics.h"
#include <sstream>
#include <algorithm>

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates a Movie object and populates the genre, director
 *  title, and releaseYear fields
 * If there's error on the input, Title is set to "". 
 * @param[in] string input: containing all fields
 */
Classics::Classics(string input) {
    this->genre = 'C';
    
    // Place data from passed input into stringstream
    stringstream inputStream(input);
    string dataString;
    string dataInt;

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

    // Gets first name of Major Actor from Input
    inputStream >> this->majorActor;
    // Check for valid integer input
    if (this->majorActor == "") {
        cout << "ERROR: No Major Actor Given" << endl;
        this->title = "";
        return;
    }
    // Gets second name of Major Actor from Input
    inputStream >> dataString;
    // Check for valid integer input
    if (this->majorActor == "") {
        cout << "ERROR: No second name for Major Actor Given" << endl;
        this->title = "";
        return;
    }
    this->majorActor = this->majorActor + " " + dataString;


    // Get Release month from input
    inputStream >> this->releaseMonth;
    // Check for valid integer input
    if (inputStream.fail()) {
        cout << "ERROR: Movie Release date is not an number" << endl;
        this->title = "";
        return;
    }
    inputStream >> this->releaseYear;
    // Check for valid integer input
    if (inputStream.fail()) {
        cout << "ERROR: Movie Release date is not an number" << endl;
        this->title = "";
        return;
    }
}

Classics::Classics(char genre, string input) {
    this->genre = 'C';
    // Place data from passed input into stringstream
    stringstream inputStream(input);
    string dataString;

    // Get Release month from input
    inputStream >> this->releaseMonth;
    // Check for valid integer input
    if (inputStream.fail()) {
        cout << "ERROR: Movie Release date is not an number" << endl;
        this->title = "";
        return;
    }
    inputStream >> this->releaseYear;
    // Check for valid integer input
    if (inputStream.fail()) {
        cout << "ERROR: Movie Release date is not an number" << endl;
        this->title = "";
        return;
    }

    // Gets first name of Major Actor from Input
    inputStream >> this->majorActor;
    // Check for valid integer input
    if (this->majorActor == "") {
        cout << "ERROR: No Major Actor Given" << endl;
        this->title = "";
        return;
    }
    // Gets second name of Major Actor from Input
    inputStream >> dataString;
    // Check for valid integer input
    if (this->majorActor == "") {
        cout << "ERROR: No second name for Major Actor Given" << endl;
        this->title = "";
        return;
    }
    this->majorActor = this->majorActor + " " + dataString;
    this->title = "x";

}

//---------------------------------------------------------Public Data Accessors
/**
 * Overloads the ostream << operator
 * Prints the Movie details and stock
 * Output example: 
 * "TODO"
 * @param[out] ostream output;
 * @param[in] Classics movie: details to displayed
 */
ostream& operator<<(ostream& output, const Classics& movie){
    output << "Stock: " << movie.stockInStore
           << "; Title: " << movie.title
           << "; Director: " << movie.director
           << "; Major Actor: " << movie.majorActor
           << "; Release Date: " << movie.releaseMonth 
           << " " << movie.releaseYear << endl;
    // return ostream&
    return output;
}

/**
 * public virtual compareTo
 * Will compare this Classics object to the passed parameter Classics object
 * Returns 1 if this is greater than the parameter, -1 if this is less
 * than the parameter, and 0 if the two Movies are equal.
 * @param[in] Classics: Movie object to be compared with this object
 */
int Classics::compareTo(const Movie& movie) const {
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
 * Overloads the == comparison operator
 * Compares each field for Classics given in parameter
 * @param[in] Classics movie: left hand side of operation
 * @return boolean: == comparison result
 */
bool Classics::operator==(const Movie& movie) const {
    const Classics & m = static_cast<const Classics &>(movie);
    if (this->releaseMonth == m.getReleaseMonth() &&
        this->releaseYear == m.getReleaseYear() &&
        this->majorActor.compare(m.getMajorActor())) {
            return true;
    }
    // Movie is not same
    return false;
}

/**
 * Overloads the != comparison operator
 * Compares each field for Classics given in parameter
 * @param[in] Classics movie: left hand side of operation
 * @return boolean: != comparison result
 */
bool Classics::operator!=(const Movie& movie) const {
    return !(*this == movie);
}

/**
 * Overloads the > comparison operator
 * Compares Director then Title of this to Classics given in rhs
 * @param[in] Classics movie: left hand side of operation
 * @return boolean: > comparison result
 */
bool Classics::operator>(const Movie& movie) const {
    const Classics & m = static_cast<const Classics &>(movie);
    // If lhs year > rhs year, return true.
    if (this->releaseYear > m.getReleaseYear()) {
        return true;
    } else if (this->releaseYear == m.getReleaseYear()) {
        // If lhs year == rhs year, check for month.
        if (this->releaseMonth > m.getReleaseMonth()) {
            return true;
        } else if (this->releaseMonth == m.getReleaseMonth()) {
            // If lhs year&month == rhs year&month, check for major actor.
            if (this->majorActor.compare(m.getMajorActor()) > 0) {
                return true;
            }
        }
    } 
    // for all other case
    return false;
}

/**
 * Overloads the < comparison operator
 * Compares each field for Classics given in parameter
 * @param[in] Classics movie: left hand side of operation
 * @return boolean: < comparison result
 */
bool Classics::operator<(const Movie& movie) const {
    const Classics & m = static_cast<const Classics &>(movie);
    return !(*this > m) && *this != m;
}

//---------------------------------------------------------Public Data Accessors
/**
 * public getDirector
 * Returns the movie director
 */
string Classics::getMajorActor() const {
    return this->getMajorActor();
}


/**
 * public getReleaseYear
 * Returns the movie release month
 */
int Classics::getReleaseMonth() const {
    return this->releaseMonth;
}