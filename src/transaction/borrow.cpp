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

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor: Populates the fields of the Borrow object by using the 
   passed data
 * @param[string]: Data from input file
 * @param[map<string, BinTree<Movie>>&]: All movies contained in the store
 * @param[HashTable<int, Customer>&]: All customers of the store
 * @return[out]: None
*/
Borrow::Borrow(string data, map<string, BinTree<Movie>>& inventory,
                    HashTable<int, Customer>& customers) { 
    // Set this as a "Borrow" type of transaction
    this.transactionType = "Borrow";

    // Pull customer ID# and link the correct Customer object to this action by
    // searching through the HashTable
    int customerNumber << data;
    this->customer = customers.retrieve(customerNumber);

    // Pull the movie data and search through the correct BinTree in inventory 
    string movieFormat << data;
    char movieGenre << data;
    BinTree* movieList = inventory.at(movieGenre);
    this->movie = movieList.retrieve(data);
} 

/**
 * Destructor: Destroys a Transaction object
 * @param[in]: None
 * @return[out]: None
*/
Borrow::~Borrow() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Will override the superclass method to decrement the stock of 
   the movie associated with this object and will add a Borrow action to the 
   associated Customer's history
 * @param[in]: None
 * @return[out]: None
*/
void Borrow::doTransaction() const {
    this->movie->decreaseStock();
    this->customer->addToHistory(this);
} 