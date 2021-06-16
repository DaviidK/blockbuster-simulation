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
 * @param[stringstream&]: Data from input file
 * @param[HashTable<Customer>&]: All customers of the store
*/
History::History(stringstream& data, HashTable<Customer>& customers) { 
    // Set this as a "History" type of transaction
    this->transactionType = "History";

    // Pull customer ID# from passed data
    int customerNumber;
    data >> customerNumber;
    customers.retrieve(customerNumber, this->customer);
    // If customer doesn't exist, report error to user
    if (this->customer == NULL) {
        cout << "ERROR: customer " << customerNumber << " is not valid";
    }    
} 

/**
 * Destructor: Destroys a History object
*/
History::~History() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Will override the superclass method to increment the stock of 
   the movie associated with this object and will add a History action to the 
   associated Customer's history
*/
void History::doTransaction() const {
    cout << "Transaction(s) for " << this->customer->getCustomerID()
         << ":" << endl;
    for (Transaction t: this->customer->getTransactionHistory()) {
        if (t.getTransactionType() == "Borrow") {
            const Borrow& b = static_cast<const Borrow&>(t);
            cout << "\tBorrowed " << b.getMovie()->getTitle() << endl;
        } else if (t.getTransactionType() == "Return") {
            const Return& b = static_cast<const Return&>(t);
            cout << "\tReturned " << b.getMovie()->getTitle() << endl;
        }
    }
}

Customer* History::getCustomer() const {
    return this->customer;
}