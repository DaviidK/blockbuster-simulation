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

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor: Populates the fields of the return object by using the 
   passed data
 * @param[stringstream&]: Data from input file
 * @param[map<char, BinTree>&]: All movies contained in the store
 * @param[HashTable<Customer>&]: All customers of the store
*/
Return::Return(stringstream& data, map<char, BinTree>& inventory,
               HashTable<Customer>& customers) { 
    // Set this as a "Return" type of transaction
    this->transactionType = "Return";
    // Pull customer ID# from passed data
    int customerNumber;
    data >> customerNumber;
    
    // Search through the HashTable to find the customer with the passed ID #, 
    // and set the "customer" field to that object
    customers.retrieve(customerNumber, this->customer);
    // If customer doesn't exist, report error to user
    if (this->customer == NULL) {
        cout << "ERROR: customer " << customerNumber << " is not valid";
    }    

    // Pull the movie format & genre from the passed data 
    string movieFormat;
    data >> movieFormat;
    char movieGenre;
    data >> movieGenre;

    // Find the BinTree that corresponds to the genre of movie
    BinTree movieList = inventory.at(movieGenre);
    // Search through the BinTree to find a movie with the matching identifying
    // data and set the "movie" field to that object
    MovieFactory movieFac = MovieFactory();
    Movie* tempMovie = movieFac.createMovie(movieGenre, data.str());


    if (movieList.retrieve(*tempMovie, this->movie)) {
        // If movie doesn't exist, report error to user
        cout << "ERROR: movie " << data.str() << " is not valid";
    }
} 

/**
 * Destructor: Destroys a Return object
*/
Return::~Return() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Will override the superclass method to increment the stock of 
   the movie associated with this object and will add a Return action to the 
   associated Customer's history
*/
void Return::doTransaction() const {
    this->movie->increaseStock();
    this->customer->addToHistory(*this);
}

Movie* Return::getMovie() const {
    return this->movie;
}

Customer* Return::getCustomer() const {
    return this->customer;
}