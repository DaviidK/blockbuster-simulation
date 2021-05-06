// ------------------------------- inventory.h ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of displaying a Store's inventory
// -----------------------------------------------------------------------------
// Assumptions:
//  - doTransaction() will specifically print all Comedy movies, then all Drama
//    movies, then all Classics movies

#ifndef INVENTORY_H
#define INVENTORY_H

#include "transaction.h"

using namespace std;

class Inventory : public Transaction {
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates an empty Inventory object
        Inventory(HashTable<string, Movie>&);
        // Destructor: Deletes the Inventory object
        virtual ~Inventory();
        // Prints the Store's inventory according to the specified requirements 
        // for each different category of Movie
        virtual void doTransaction(HashTable<string, Movie>&) const;

    private:
        //-------------------------------------------------Private member fields
        // All available movies in the Store
        HashTable<string, BinTree>* inventory;
        //------------------------------------------------Private member methods
        // Will check if the Store's inventory is empty
        virtual bool isValid(HashTable<char, Movie>&) const;
};

#endif