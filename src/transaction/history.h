// -------------------------------- history.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of displaying a Customer's transaction 
// history
// -----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "../customer/customer.h"
#include "../support/hashtable.h"
#include <sstream>

using namespace std;

class History : public Transaction {
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Will create a History object and assign a Customer
        // object to the c field
        History(stringstream&, HashTable<Customer>&);
        // Destructor: Will destroy the History object
        virtual ~History();
        // Prints the Customer's transaction history in chronological order
        virtual void doTransaction() const;
        
        Customer* getCustomer() const;

    private:
        //-------------------------------------------------Private member fields
        // Pointer to the Customer object associated with this transaction
        Customer* customer;
};

#endif