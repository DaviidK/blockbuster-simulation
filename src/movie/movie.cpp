// ---------------------------------- movie.cpp --------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a singular Movie object. The movie will contain
// information on the genre, director, title, release year, and current stock in
// the store. Depending on the type of movie object created, more information
// may also be stored. All Movie objects will be comparable to other Movies of
// the same genre.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//     genre(string) stock(int) director(string) title(string) 
//       In addition, the following movie genre's input will also contain:
//         Comedy: releaseYear(int) 
//         Drama: releaseYear(int)
//         Classics: majorActor(string) releaseMonth(int) releaseYear(int)

#include "movie.h"
#include <sstream>
#include <algorithm>

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates a Movie object
 */
Movie::Movie() {}

//---------------------------------------------------------Public Data Accessors
/**
 * public getGenre
 * Returns the movie genre
 */
char Movie::getGenre() const {
    return this->genre;
}

/**
 * public getDirector
 * Returns the movie director
 */
string Movie::getDirector() const {
    return this->director;
}

/**
 * public getDirector
 * Returns the movie director
 */
string Movie::getTitle() const {
    return this->title;
}


/**
 * public getReleaseYear
 * Returns the movie release year
 */
int Movie::getReleaseYear() const {
    return this->releaseYear;
}

/**
 * public getStockInStore
 * Returns how many copies of the movie are available in the store
 */
int Movie::getStockInStore() const {
    return this->stockInStore;
}

//---------------------------------------------------------Public Data Modifiers
/**
 * public increaseStock
 * Increases the stock by 1
 * @return bool true if stock is increased, else false
 */
bool Movie::increaseStock() {
    this->stockInStore++;
    return true;
}

/**
 * public decreaseStock
 * Decreases the stock by 1
 * @return bool true if stock is decreased, else false
 */
bool Movie::decreaseStock() {
    // check if there is stock left
    if (this->stockInStore > 0) {
        this->stockInStore--;
        return true;
    } else {
        // if stock is not available
        return false;                                       // TODO should we print a massage here?
    }
}

//------------------------------------------------------Protected Helper Methods
/**
 * protected checkValidInput
 * Check for invalid input. If input is invalid, prints an error and sets the 
 * Movie title to "".
 * @param[in] stringstream&: Data from input file
 * @return bool if valid
 */
bool Movie::checkValidInput(stringstream& input, const string& field) {
    string dataString;
    int dataInt;

    if (field == "Stock" || field == "Year") {
        input >> dataInt;
        
        // Check for valid integer input
        if (input.fail()) {
            cout << "ERROR: Movie " << field <<" is not an number" << endl;
            this->title = "";
            return false;
        }
        
        // Check for valid input
        if (input.peek() == ',') {
            input.ignore();
        }
        
        // Save valid data input
        if (field == "Stock") this->stockInStore = dataInt;
        else this->releaseYear = dataInt;
        return true;

    } else if (field == "Director" || field == "Title") {
        getline(input, dataString, ',');
        
        // Trim leading spaces and commas
        remove(dataString.begin(), dataString.end(), ' ');
        
        // Check for valid input
        if (dataString == "") {
            cout << "ERROR: Empty " << field << " is not valid" << endl;
            this->title = "";
            return false;
        }
        
        // Save valid data input
        if (field == "Director") this->director = dataString;
        else this->title = dataString;
        return true;

    }
    
    // invalid field
    return false;
}