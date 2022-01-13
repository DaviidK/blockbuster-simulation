// -------------------------------- customer.h ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a singular customer. Contains information about
// the customer as well as the movies they have checked out and their
// transaction history
// -----------------------------------------------------------------------------
// Assumptions:
//  - Input provided to the constructor will be given in the form of: 
//      customerID# (int) lastName (string) firstName (string)

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <sstream>
#include "../support/hashtable.h"
#include "../movie/movie.h"
#include "../transaction/transaction.h"

using namespace std;

class Customer {

    public:
        //-------------------------------------------------Public member methods
        // Default constructor: Creates an empty Customer object
        // Customer();
        // Constructor: Will populate the customerID, firstName, and lastName 
        // fields after parsing through the passed input string
        Customer(string);
        // Destructor: Destroys a Customer object
        ~Customer();
        // Returns the customerID field
        int getCustomerID() const;
        // Returns the name of the customer (first and last combine)
        string getCustomerName() const;
        // Returns the transactionHistory field
        vector<const Transaction*> getTransactionHistory() const;
        // Adds a Transaction object to the transactionHistory field
        void addToHistory(const Transaction*);
        
    private:
        //-------------------------------------------------Private member fields
        // Number representing the customer
        int customerID;
        // First name of the customer
        string firstName;
        // Last name of the customer
        string lastName;
        //------------------------------------------------Private member methods
        // All transactions from this customer
        vector<const Transaction*> transactionHistory;
        
};

#endif