// ------------------------------ inventory.cpp --------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements the action of displaying a Store's inventory
// -----------------------------------------------------------------------------
// Assumptions:
//  - doTransaction() will specifically print all Comedy movies, then all Drama
//    movies, then all Classics movies

#include "inventory.h"

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor: Populates the fields of the Inventory object by using
   the passed data
 * @param[stringstream]: Data from input file
 * @param[map<string, BinTree<Movie>>&]: All customers of the store
 * @return[out]: None
*/
Inventory::Inventory(stringstream data,
                     map<string, BinTree<Movie>>& allMovies) { 
    // Set this as a "Inventory" type of transaction
    this->transactionType = "Inventory";

    // Set the inventory field to the passed data
    this->inventory = allMovies; 
} 

/**
 * Destructor: Destroys an Inventory object
 * @param[in]: None
 * @return[out]: None
*/
virtual Inventory::~Inventory() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Will override the superclass method to print all movies
   currently contained in the Store
 * @param[in]: None
 * @return[out]: None
*/
virtual void inventory::doTransaction() const {
    for (BinTree movieGenre : this->inventory) {
        cout << movieGenre;
    }
}