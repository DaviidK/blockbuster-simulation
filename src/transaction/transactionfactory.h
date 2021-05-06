// --------------------------- transactionfactory.h ----------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a factory that is responsible for determining
// what type of Transaction object should be instantiated based on provided
// input. Allows for dynamic binding of Transaction objects.
// ------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the formats neccessary for each type of 
//    associated Transaction object

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"

using namespace std;

class TransactionFactory {
    public:
        //-------------------------------------------------Public member methods
        // Will parse through passed parameter information to determine which
        // type of Transaction object to create and return
        Transaction createTransaction(string info,
                                      HashTable<string, Movie>&,
                                      HashTable<int, Customer>&) const;
                                      
};

#endif