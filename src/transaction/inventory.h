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

#include <map>
#include <sstream>
#include <iomanip>
#include "transaction.h"
#include "../store/store.h"
#include "../movie/movie.h"
#include "../support/hashtable.h"
#include "../support/bintree.h"

using namespace std;

class Inventory : public Transaction {
    
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Creates an empty Inventory object
        Inventory(map<char, BinTree*>&);
        // Destructor: Deletes the Inventory object
        virtual ~Inventory();
        // Prints the Store's inventory according to the specified requirements 
        // for each different category of Movie
        virtual void doTransaction() const;

    private:
        //-------------------------------------------------Private member fields
        // All available movies in the Store
        map<char, BinTree*> inventory;

};

#endif