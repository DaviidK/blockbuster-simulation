// -------------------------------- customer.h ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements the creation of a customer object. Contains 
// information about the customer as well as the movies they have checked out
// and their transaction history
// -----------------------------------------------------------------------------
// Assumptions:
//  - Input provided to the constructor will be given in the form of: 
//      customerID# (int) lastName (string) firstName (string)

#include "customer.h"

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor: Creates an empty Customer object
 * @param[in]: None
 * @return[out]: None
*/
Customer::Customer() {
    this->customerID = -1;
    this->firstName = "";
    this->lastName = "";
    this->transactionHistory.reserve(1);
}

//----------------------------------------------------------------------------
/**
 * string Constructor: Takes in data from passed parameter string and 
   instantiates Customer fields accordingly
 * @param[in]: None
 * @return[out]: None
*/
Customer::Customer(string data) {
    this->customerID << data;
    this->lastName << data;
    this->firstName << data;
    this->transactionHistory.reserve(1);
}

//----------------------------------------------------------------------------
/**
 * Destructor: Destroys a Customer object
 * @param[in]: None
 * @return[out]: None
*/
Customer::~Customer(){
    // TODO: Do we need to add anything here?
}

//---------------------------------------------------------Public member methods
/**
 * getHistory: Returns the transactionHistory field of this
 * @param[in]: None
 * @return[out]: None
*/

vector<Transaction> Customer::getHistory() const {
     return this->transactionHistory; 
}