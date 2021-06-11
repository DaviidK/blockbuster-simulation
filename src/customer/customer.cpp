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

/**
 * string Constructor: Takes in data from passed parameter string and 
   instantiates Customer fields accordingly
*/
Customer::Customer(string input) {
    stringstream data(input);
    data >> this->customerID;
    data >> this->lastName;
    data >> this->firstName;
    this->transactionHistory.reserve(1);
}

/**
 * Destructor: Destroys a Customer object
*/
Customer::~Customer() {}

//---------------------------------------------------------Public member methods
/**
 * getHistory: Returns the transactionHistory field of this
*/
int Customer::getCustomerID() const {
     return this->customerID; 
}

/**
 * getHistory: Returns the transactionHistory field of this
*/
vector<Transaction> Customer::getTransactionHistory() const {
     return this->transactionHistory; 
}

/**
 * Adds a Transaction object to the end of the transactionHistory field
 * @param[in]: None
 * @return[out]: None
*/
void Customer::addToHistory(const Transaction& t) {
	this->transactionHistory.push_back(t);
}