// ------------------------------- return.cpp ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements an object that will conduct the action of a
// Customer returning a Movie to a Store. Will contain information related to
// the specific Movie being returned as well as the Customer that is returning 
// the movie 
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the following format:
//       actionType(char) customerID#(int) mediaFormat(char) movieData

#include "return.h"

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
 * Constructor
 * Populates the fields of the return object by using the passed data
 * @param[in] stringstream : Data from input file
 * @param[in] map<char, BinTree> : All movies contained in the store
 * @param[in] HashTable<Customer> : All customers of the store
 */
Return::Return(string& input, map<char, BinTree*>& inventory,
            HashTable<Customer>& customers) { 
    // Set this as a "Return" type of transaction
    this->transactionType = "Return";

    // Populate empty member variables
    this->movie = NULL;
    this->customer = NULL;
    
    // Place data from passed input into stringstream
    stringstream data(input);
    string dataString;

    // Pull customer ID# from passed data
    int customerNumber;
    data >> customerNumber;
    // Check for input errors
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
    // Check for input errors and invalid format
    if (data.fail() || movieFormat != 'D') {
        printElement("Invalid movie format", 55);
        printElement(customerNumber, 30);
        return;
    }
    
    // Pull the movie genre & genre from the passed data 
    char movieGenre;
    data >> movieGenre;
    // Check for input errors
    if (data.fail()) {
        printElement("Invalid movie", 40);
        printElement(dataString, 45);
        return;
    }
    
    // Get the movie details from input
    getline(data, dataString);

    // Create a temporary movie variable
    MovieFactory movieFac = MovieFactory();
    Movie* tempMovie = movieFac.createMovie(movieGenre, dataString);
    // Check for input errors (NULL return for invalid movie input) 
    if (tempMovie == NULL) {
        return;
    }

    // Find the BinTree that corresponds to the genre of movie
    BinTree* movieList = inventory.at(movieGenre);
    // Search through the BinTree to find a movie with the matching identifying
    // data and set the "movie" field to that object
    if (!movieList->retrieve(*tempMovie, this->movie)) {
        // If movie doesn't exist, report error to user
        printElement("Invalid movie", 55);
        printElement(dataString, 30);
    }

    // Delete temporary variable 
    delete tempMovie;
    tempMovie = NULL;
} 

/**
 * Destructor
 * Destroys a Return object
 */
Return::~Return() {} 

//---------------------------------------------------------Public member methods
/**
 * public virtual doTransaction
 * Will override the superclass method to increment the stock of 
 * the movie associated with this object and will add a Return action to the 
 * associated Customer's history
 */
void Return::doTransaction() const {
    // Combine all customer info to print later
    string customerInfo = this->customer->getCustomerName() + " (ID#" +
                        to_string(this->customer->getCustomerID()) + ")";
    // Increase stock of movie and add transaction to customer's history
    this->movie->increaseStock();

    // Print type of transaction, customer info, and movie info
    printElement("Return", 20);
    printElement(customerInfo, 40);
    printElement(this->movie->getTitle(), 40);
    printElement(this->movie->getStockInStore(), 0);
    cout << endl;
    
    this->customer->addToHistory(this);
}

/**
 * public getMovie
 * Returns the movie 
 * @return Movie : Movie object
 */
Movie* Return::getMovie() const {
    return this->movie;
}

/**
 * public getCustomer
 * Returns the Customer 
 * @return Movie : Customer object
 */
Customer* Return::getCustomer() const {
    return this->customer;
}