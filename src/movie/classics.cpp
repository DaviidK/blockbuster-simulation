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
 * @param[in] Classics movie: details to displayed
 * @return ostream : output representing a Classics object
 */
ostream& operator<<(ostream& output, const Classics& movie){
    output << printElement(movie.getTitle(), 25);
    output << printElement(movie.getDirector(), 24);
    output << printElement(movie.getReleaseMonth(), 13);
    output << printElement(movie.getReleaseYear(), 10);
    
    // Loop through the major actors array, combining all actors into a stream
    int arraySize = movie.getAllMajorActors().size();
    stringstream allActors;
    for (int i = 0; i < arraySize - 1; i++) {
        allActors << movie.getAllMajorActors()[i] << ", ";
    }
    allActors << movie.getAllMajorActors()[arraySize - 1];
    // Output the resulting string after all major actors have been concatenated
    output << printElement(allActors.str(), 35);
    output << printElement(movie.getFormat(), 8);
    output << printElement(movie.getStockInStore(), 0);
    output << endl;
    // return ostream&
    return output;
}

//---------------------------------------------------Constructors and Destructor
/**
 * Constructor
 * Creates a Movie object and populates the genre, director
 * title, release date and major actor fields
 * If there's error on the input, Title is set to invalid (-1) 
 * @param[in] string input : containing all fields
 */
Classics::Classics(string input) : Movie() {
    // Populate empty member variables
    this->releaseMonth = -1;

    // Set genre to Classics (C)
    this->genre = 'C';
    
    // Place data from passed input into stringstream
    stringstream inputStream(input);
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

    // Gets first name of Major Actor from Input
    string firstName;
    inputStream >> firstName;
    // Check for valid integer input
    if (firstName == "") {
        cout << "ERROR: No Major Actor Given" << endl;
        this->title = "";
        return;
    }
    // Gets second name of Major Actor from Input
    string secondName;
    inputStream >> secondName;
    // Check for valid integer input
    if (secondName == "") {
        cout << "ERROR: No second name for Major Actor Given" << endl;
        this->title = "";
        return;
    }
    // Combine Firstname and Last name of Major Actor
    string actor = firstName + " " + secondName;
    this->majorActors.push_back(actor);


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

/**
 * Constructor
 * Creates a Movie object and populates the genre, director
 * title, release date and major actor fields
 * If there's error on the input, Title is set to invalid (-1)
 * @param[in] char genre : movie genre
 * @param[in] string input : containing all fields after genre
 */
Classics::Classics(char genre, string input) : Movie() {
    // Set genre to Classics (C)
    this->genre = 'C';
    
    // Populate empty member variables
    this->releaseMonth = -1;

    // Place data from passed input into stringstream
    stringstream inputStream(input);

    // Get Release month from input
    inputStream >> this->releaseMonth;
    // Check for valid integer input
    if (inputStream.fail()) {
        cout << "ERROR: Movie release date is not an number" << endl;
        this->title = "";
        return;
    }
    inputStream >> this->releaseYear;
    // Check for valid integer input
    if (inputStream.fail()) {
        cout << "ERROR: Movie release date is not an number" << endl;
        this->title = "";
        return;
    }

    // Gets first name of Major Actor from Input
    string firstName;
    inputStream >> firstName;
    // Check for valid integer input
    if (firstName == "") {
        cout << "ERROR: No Major Actor Given" << endl;
        this->title = "";
        return;
    }
    // Gets second name of Major Actor from Input
    string secondName;
    inputStream >> secondName;
    // Check for valid integer input
    if (secondName == "") {
        cout << "ERROR: No second name for Major Actor Given" << endl;
        this->title = "";
        return;
    }
    // Combine Firstname and Last name of Major Actor
    string actor = firstName + " " + secondName;
    this->majorActors.push_back(actor);

    this->title = "-1";
}

/**
 * virtual Destructor
 * Destroys the Classic object
 */
Classics::~Classics() {}

//---------------------------------------------------------Public member methods
/**
 * public virtual compareTo
 * Will compare this Classics object to the passed parameter Movie object
 * Returns 1 if this is greater than the parameter, -1 if this is less
 * than the parameter, and 0 if the two Movies are equal.
 * @param[in] Movie : Movie object to be compared with this object
 * @return int : -1 (<), 0 (==), or 1 (>)
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

/**
 * Overloads the == comparison operator
 * Compares Release Date then Major actor (first stored) of this 
 * to Movie given in rhs
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : == comparison result
 */
bool Classics::operator==(const Movie& movie) const {
    const Classics & m = static_cast<const Classics &>(movie);
    if (this->releaseMonth == m.getReleaseMonth() &&
        this->releaseYear == m.getReleaseYear()) {
            if (movie.getTitle() == "-1") {
                return (this->includesActor(m.getMajorActor()));
            } else {
                return (this->title.compare(m.getTitle()) == 0);
            }
    }
    // Movie is not same
    return false;
}

/**
 * Overloads the != comparison operator
 * Compares Release Date then Major actor (first stored) of this 
 * to Movie given in rhs 
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : != comparison result
 */
bool Classics::operator!=(const Movie& movie) const {
    return !(*this == movie);
}

/**
 * Overloads the > comparison operator
 * Compares Release Date then Major actor (first stored) of this 
 * to Movie given in rhs
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : > comparison result
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
            if (this->getMajorActor().compare(m.getMajorActor()) > 0) {
                return true;
            }
        }
    } 
    // for all other case
    return false;
}

/**
 * Overloads the < comparison operator
 * Compares Release Date then Major actor (first stored) of this 
 * to Movie given in rhs
 * @param[in] Movie movie : right hand side of operation
 * @return boolean : < comparison result
 */
bool Classics::operator<(const Movie& movie) const {
    const Classics & m = static_cast<const Classics &>(movie);
    return !(*this > m) && *this != m;
}

/**
 * public getMajorActor
 * Returns the first Major Actor
 * @return string : major actors
 */
string Classics::getMajorActor() const {
    return this->majorActors[0];
}

/**
 * public getAllMajorActors
 * Returns all the Major Actor(s)
 * @return vector<string> : major actors(s)
 */
vector<string> Classics::getAllMajorActors() const {
    return this->majorActors;
}

/**
 * public includesActor
 * Returns true if the passed parameter is included in the majorActors field
 * @param string actor : movie actor to be checked
 * @return bool : true if actor is found in the array, else false
 */
bool Classics::includesActor(string s) const {
    for (int i = 0; i < this->majorActors.size(); i++) {
        if (this->majorActors[i] == s) {
            return true;
        }
    }
    return false;
}

/**
 * public addActor
 * Adds a new actor to the majorActors field
 * @param string actor : movie actor to be added
 */
void Classics::addActor(string s) {
    this->majorActors.push_back(s);
}

/**
 * public getReleaseYear
 * Returns the movie release month
 * @return int : release month
 */
int Classics::getReleaseMonth() const {
    return this->releaseMonth;
}