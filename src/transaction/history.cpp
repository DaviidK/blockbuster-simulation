// ------------------------------- history.cpp ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements the action of displaying a Customer's
// transaction history
// -----------------------------------------------------------------------------

#include "history.h"

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor: Populates the fields of the History object by using the 
   passed data
 * @param[stringstream]: Data from input file
 * @param[HashTable<int, Customer>&]: All customers of the store
 * @return[out]: None
*/
History::History(stringstream data, HashTable<int, Customer>& customers) { 
    // Set this as a "History" type of transaction
    this->transactionType = "History";

    // Pull customer ID# from passed data
    int customerNumber << data;
    this->customer = customers.retrieve(customerNumber);
    // If customer doesn't exist, report error to user
    if (this->customer == NULL) {
        cout << "ERROR: customer " << customerNumber << " is not valid";
    }    
} 

/**
 * Destructor: Destroys a History object
 * @param[in]: None
 * @return[out]: None
*/
virtual History::~History() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Will override the superclass method to increment the stock of 
   the movie associated with this object and will add a History action to the 
   associated Customer's history
 * @param[in]: None
 * @return[out]: None
*/
virtual void history::doTransaction() const {
    this->customer->printHistory();
}