// -------------------------------- history.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of displaying a Customer's transaction 
// history
// -----------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

using namespace std;

class History : public Transaction {
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Will create a History object and assign a Customer
        // object to the c field
        History(string, HashTable<int, Customer>&);
        // Destructor: Will destroy the History object
        virtual ~History();
        // Prints the Customer's transaction history in chronological order
        virtual void doTransaction(Customer&) const;

    private:
        //-------------------------------------------------Private member fields
        // Pointer to the Customer object associated with this transaction
        Customer* c;
        //------------------------------------------------Private member methods
        // Will check if a Customer exists with the given ID number
        virtual bool isValid(string info, HashTable<int, Customer>&) const;
};

#endif