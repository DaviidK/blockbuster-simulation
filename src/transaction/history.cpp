// ------------------------------- history.cpp ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements the action of displaying a Customer's
// transaction history
// -----------------------------------------------------------------------------

#include "history.h"

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
 * Default Constructor: Populates the fields of the History object by using the 
   passed data
 * @param[stringstream&]: Data from input file
 * @param[HashTable<Customer>&]: All customers of the store
 */
History::History(string& input, HashTable<Customer>& customers) { 
    // Set this as a "History" type of transaction
    this->transactionType = "History";
    this->customer = NULL;

    stringstream data(input);

    // Pull customer ID# from passed data
    int customerNumber;
    data >> customerNumber;
    if (data.fail()) {
        printElement("Customer ID isn't a number", 55);
        printElement(input, 25);
        return;
    }

    customers.retrieve(customerNumber, this->customer);
    // If customer doesn't exist, report error to user
    if (this->customer == NULL) {
        printElement("Invalid customer ID", 55);
        printElement(customerNumber, 30);
    }
}

/**
 * Destructor 
 * Destroys a History object
 */
History::~History() {} 

//---------------------------------------------------------Public member methods
/**
 * public virtual doTransaction 
 * Will override the superclass method to increment the stock of the movie 
 * associated with this object and will add a History action to the associated 
 * Customer's history
 */
void History::doTransaction() const {
    // Notify user if customer has no borrow/return transactions at this moment
    if (this->customer->getTransactionHistory().size() == 0) {
        cout << this->customer->getCustomerName() 
             << " (ID#" 
             << to_string(this->customer->getCustomerID())
             << ") has no transactions." << endl;
    } else {
        cout << "Transaction(s) for " 
             << this->customer->getCustomerName() 
             << " (ID#" 
             << to_string(this->customer->getCustomerID()) << "):" << endl;

        // Iterate through all transactions of the customer, checking for any
        // borrow or return actions
        for (const Transaction* t: this->customer->getTransactionHistory()) {
            // If the customer borrowed or returned an item, report it
            if (t->getTransactionType() == "Borrow") {
                // Cast the transaction as a Borrow object to ensure access to
                // movie title
                const Borrow* b = static_cast<const Borrow*>(t);
                printElement("Borrowed", 10);
                printElement(b->getMovie()->getTitle(), 0);
                cout << endl;
            } else if (t->getTransactionType() == "Return") {
                // Cast the transaction as a Return object to ensure access to
                // movie title
                const Return* b = static_cast<const Return*>(t);
                printElement("Returned", 10);
                printElement(b->getMovie()->getTitle(), 0);
                cout << endl;
            }
        }
    }
}

/**
 * public getCustomer
 * Returns the Customer 
 * @return Movie : Customer object
 */
Customer* History::getCustomer() const {
    return this->customer;
}