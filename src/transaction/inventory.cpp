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
 * @param[stringstream&]: Data from input file
 * @param[map<char, BinTree>&]: All customers of the store
*/
Inventory::Inventory(map<char, BinTree>& allMovies) { 
    // Set this as a "Inventory" type of transaction
    this->transactionType = "Inventory";

    // Set the inventory field to the passed data
    this->inventory = allMovies; 
} 

/**
 * Destructor: Destroys an Inventory object
*/
Inventory::~Inventory() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Will override the superclass method to print all movies
   currently contained in the Store
*/
void Inventory::doTransaction() const {
    // Pull the BSTree for comedy movies from inventory
    BinTree comedyMovies = this->inventory.at('F');
    // Print out all comedy movies if a BSTree exists
    if (!comedyMovies.isEmpty()) {
        cout << "Comedy Movies:" << endl;
        cout << comedyMovies << endl;
    } else {
        cout << "No Comedy movies were found!" << endl;
    }

    // Pull the BSTree for drama movies from inventory
    BinTree dramaMovies = this->inventory.at('D');
    // Print out all drama movies if a BSTree exists
    if (!dramaMovies.isEmpty()) {
        cout << "Drama Movies:" << endl;
        cout << comedyMovies << endl;
    } else {
        cout << "No Drama movies were found!" << endl;
    }

    // Pull the BSTree for classics movies from inventory
    BinTree classicsMovies = this->inventory.at('C');
    // Print out all classics movies if a BSTree exists
    if (!classicsMovies.isEmpty()) {
        cout << "Classics Movies:" << endl;
        cout << classicsMovies << endl;
    } else {
        cout << "No Classics movies were found!" << endl;
    }
}