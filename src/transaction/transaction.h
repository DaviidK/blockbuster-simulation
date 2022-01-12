// ------------------------------ transaction.h --------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines an interface for a single transaction. The object
// may be related to Movie, Store, or Customer objects depending on which type
// of Transaction object is created.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the format required by the associated 
//    Transaction class

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction {
    
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates an empty Transaction object
        Transaction();
        // Virtual destructor: Destroys the Transaction object
        virtual ~Transaction();
        // Using the type of Transaction object that is instantiated, determine 
        // and conduct the necessary action
        virtual void doTransaction() const;
        // Returns transaction type
        string getTransactionType() const;

    protected:
        // String representing the type of transaction
        string transactionType;

};

#endif