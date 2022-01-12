// ------------------------------- borrow.cpp ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements an object that will conduct the action of a
// Customer borrowing a Movie from a Store. Will contain information related to
// the specific Movie being borrowed as well as the Customer that is borrowing 
// the movie 
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//       actionType(char) customerID#(int) mediaFormat(char) movieData

#include "borrow.h"

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

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor: Populates the fields of the Borrow object by using the
 * passed data
 * @param[stringstream&]: Data from input file
 * @param[map<char, BinTree*>&]: All movies contained in the store
 * @param[HashTable<Customer>&]: All customers of the store
 */
Borrow::Borrow(string& input, map<char, BinTree*>& inventory,
               HashTable<Customer>& customers) { 
    // Set this as a "Borrow" type of transaction
    this->transactionType = "Borrow";
    this->movie = NULL;
    this->customer = NULL;

    stringstream data(input);
    string dataString;

    // Pull customer ID# from passed data
    int customerNumber;
    data >> customerNumber;

    if (data.fail()) {
        printElement("Customer ID isn't a number", 55);
        printElement(input, 25);
        return;
    }

    // Search through the HashTable to find the customer with the passed ID #, 
    // and set the "customer" field to that object
    customers.retrieve(customerNumber, this->customer);
    // If customer doesn't exist, report error to user
    if (this->customer == NULL) {
        printElement("Invalid customer ID", 55);
        printElement(customerNumber, 30);
        return;
    }

    // Pull the movie format & genre from the passed data 
    char movieFormat;
    data >> movieFormat;
    if (data.fail() || movieFormat != 'D') {
        printElement("Invalid movie format", 55);
        printElement(customerNumber, 30);
        return;
    }

    char movieGenre;
    data >> movieGenre;
    if (data.fail()) {
        printElement("Movie genre is not a character", 55);
        printElement(movieGenre, 30);
        return;
    }

    getline(data, dataString);

    MovieFactory movieFac = MovieFactory();
    Movie* tempMovie = movieFac.createMovie(movieGenre, dataString);
    if (tempMovie == NULL) {
        return;
    }

    // Find the BinTree that corresponds to the genre of movie
    BinTree* movieList = inventory.at(movieGenre);
    // Search through the BinTree to find a movie with the matching identifying
    // data and set the "movie" field to that object
    if (!movieList->retrieve(*tempMovie, this->movie)) {
        // If movie doesn't exist, report error to user
        printElement("Invalid movie", 40);
        printElement(dataString, 45);
    }
    delete tempMovie;
    tempMovie = NULL;
} 

/**
 * Destructor
 * Destroys a Borrow object
 */
Borrow::~Borrow() {} 

//---------------------------------------------------------Public member methods
/**
 * public virtual doTransaction
 * Will override the superclass method to decrement the stock of the movie 
 * associated with this object and will add a Borrow action to the associated 
 * Customer's history
 */
void Borrow::doTransaction() const {
    // Combine all customer info to print later
    string customerInfo = this->customer->getCustomerName() + " (ID#" + 
                          to_string(this->customer->getCustomerID()) + ")";
    
    // Print type of transaction, customer info, and movie info
    printElement("Borrow", 20);
    printElement(customerInfo, 40);
    printElement(this->movie->getTitle(), 40);

    // Notify user if movie could not be borrowed due to being out of stock
    if(!this->movie->decreaseStock()) {
        printElement("OUT OF STOCK", 0);
    } else {
        printElement(this->movie->getStockInStore(), 0);
    }
    cout << endl;

    // Add transaction to customer's history
    this->customer->addToHistory(this);
}

/**
 * public getMovie
 * Returns the movie 
 * @return Movie : Movie object
 */
Movie* Borrow::getMovie() const {
    return this->movie;
}

/**
 * public getCustomer
 * Returns the Customer 
 * @return Movie : Customer object
 */
Customer* Borrow::getCustomer() const {
    return this->customer;
}