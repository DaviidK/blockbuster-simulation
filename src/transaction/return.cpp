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

#include "transaction.h"
#include "../movie/movie.h"
#include "../customer/customer.h"
#include "../store/store.h"
#include "../support/hashtable.h"
#include "../support/bintree.h"
#include <map>

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor: Populates the fields of the return object by using the 
   passed data
 * @param[string]: Data from input file
 * @param[map<string, BinTree<Movie>>&]: All movies contained in the store
 * @param[HashTable<int, Customer>&]: All customers of the store
 * @return[out]: None
*/
Return::Return(string data, map<string, BinTree<Movie>>& inventory,
                    HashTable<int, Customer>& customers) { 
    // Set this as a "Return" type of transaction
    this.transactionType = "Return";

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
Return::~Return() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Will override the superclass method to increment the stock of 
   the movie associated with this object and will add a Return action to the 
   associated Customer's history
 * @param[in]: None
 * @return[out]: None
*/
void return::doTransaction() const {
    this->movie->increaseStock();
    this->customer->addToHistory(this);
}