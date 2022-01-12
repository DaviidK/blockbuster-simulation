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

/**
 * printElement
 * Helper method that allows for easy printing of elements at set intervals
 * @param[in] Typename T: Data to be printed
 * @param[in] int width: Width between next element on print line
 * @return string: Resulting string after element adjustment
 */
template<typename T> string printElement(T t, const int& width) {
    const char separator = ' ';
    stringstream result; 
    result << left << setw(width) << setfill(separator) << t;
    return result.str();
}

/**
 * Overloads the ostream << operator
 * Prints the Movie details and stock
 * @param[in] ostream output;
 * @param[in] Movie movie: details to displayed
 * @return ostream : output representing a Movie object
 */
ostream& operator<<(ostream& output, const Movie& movie){
    output << printElement(movie.getTitle(), 35);
    output << printElement(movie.getDirector(), 28);
    output << printElement(movie.getReleaseYear(), 15);
    output << printElement(movie.getFormat(), 10);
    output << printElement(movie.getStockInStore(), 0);
    output << endl;
    // return ostream&
    return output;
}

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates a Movie object
 */
Movie::Movie() {
    this->title = "";
    this->director = "";
    this->releaseYear = -1;
    this->stockInStore = -1;
    this->genre = ' ';
}

/**
 * Virtual Destructor
 * Destroys the Movie object
 */
Movie::~Movie() {}

//---------------------------------------------------------Public member methods
/**
 * public getFormat
 * Returns the movie format
 * @return char : movie format
 */
char Movie::getFormat() const {
    return this->format;
}

/**
 * public getGenre
 * Returns the movie genre
 * @return char : movie genre
 */
char Movie::getGenre() const {
    return this->genre;
}

/**
 * public getDirector
 * Returns the movie director
 * @return string : movie director
 */
string Movie::getDirector() const {
    return this->director;
}

/**
 * public getTitle
 * Returns the movie title
 * @return string : movie title
 */
string Movie::getTitle() const {
    return this->title;
}

/**
 * public getReleaseYear
 * Returns the movie release year
 * @return int : movie release year
 */
int Movie::getReleaseYear() const {
    return this->releaseYear;
}

/**
 * public getStockInStore
 * Returns how many copies of the movie are available in the store
 * @return int : movie stock in store
 */
int Movie::getStockInStore() const {
    return this->stockInStore;
}

/**
 * public setStock
 * Returns how many copies of the movie are available in the store
 * @param[in] int newStock : movie stock in store
 */
void Movie::setStock(int newStock) {
    this-> stockInStore = newStock;
}

/**
 * public increaseStock
 * Increases the stock by 1
 * @return bool : true if stock is increased, else false
 */
bool Movie::increaseStock() {
    this->stockInStore++;
    return true;
}

/**
 * public decreaseStock
 * Decreases the stock by 1
 * @return bool : true if stock is decreased, else false
 */
bool Movie::decreaseStock() {
    // If there is stock left, decrese stock by 1 then return true,
    // else return false
    if (this->stockInStore > 0) {
        this->stockInStore--;
        return true;
    } else {
        // Stock is not available
        return false;
    }
}

//------------------------------------------------------Protected member methods
/**
 * protected checkValidInput
 * Check for invalid input. If input is invalid, prints an error and sets the 
 * Movie title to "".
 * @param[in] stringstream& : Data from input file
 * @return bool : if valid
 */
bool Movie::checkValidInput(string& input, const string& field) {
    // Initialize temporary data
    int dataInt;

    // Erase leading whitespace from the passed string
    input.erase(0, 1);

    // Error/Invalid input checking for Movie integer fields OR string fields
    if (field == "Stock" || field == "Year") {
        // Create stream from input parameter
        stringstream inputStream(input);
        // Get data from stream created from input parameter
        inputStream >> dataInt;

        // Check for valid integer input
        if (inputStream.fail()) {
            cout << "ERROR: Movie " << field << ": " << input 
                 <<" is not an number" << endl;
            this->title = "";
            return false;
        }
        
        // Save valid data integer input if field
        if (field == "Stock") {
            // Set as stock
            this->stockInStore = dataInt;
        } else {
            // Set as realese year
            this->releaseYear = dataInt;
        }
        return true;

    } else if (field == "Director" || field == "Title") {  
        // Check for valid input
        if (input == "") {
            cout << "ERROR: Empty " << field << " is not valid" << endl;
            this->title = "";
            return false;
        }
        
        // Save valid data string input if field
        if (field == "Director") {
            // Set as director
            this->director = input;
        } else {
            // Set as title
            this->title = input;
        }
        return true;

    }
    
    // invalid field
    return false;
}