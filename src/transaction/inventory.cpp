// ------------------------------ inventory.cpp --------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements the action of displaying a Store's inventory
// -----------------------------------------------------------------------------
// Assumptions:
//  - doTransaction() will specifically print all Comedy movies, then all Drama
//    movies, then all Classics movies

#include "inventory.h"

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
 * Default Constructor: Populates the fields of the Inventory object by using
 * the passed data
 * @param[in] stringstream : Data from input file
 * @param[in] map<char, BinTree> : All customers of the store
 */
Inventory::Inventory(map<char, BinTree*>& allMovies) { 
    // Set this as a "Inventory" type of transaction
    this->transactionType = "Inventory";

    // Set the inventory field to the passed data
    this->inventory = allMovies; 
} 

/**
 * Destructor
 * Destroys an Inventory object
 */
Inventory::~Inventory() {} 

//---------------------------------------------------------Public member methods
/**
 * public virtual doTransaction 
 * Will override the superclass method to print all movies
 * currently contained in the Store
 */
void Inventory::doTransaction() const {
    // Divider used to indicate start and end of Inventory action
    string banner = "---------------------------------------------------------";
    cout << banner << banner << endl;
    cout << "Current Store Inventory:\n" << endl;

    // Pull the BSTree for comedy movies from inventory
    BinTree* comedyMovies = this->inventory.at('F');
    // Print out all comedy movies if a BSTree exists
    if (!comedyMovies->isEmpty()) {
        cout << "Comedy Movies:" << endl;
        // Print column headers for each movie
        printElement("Title", 35);
        printElement("Director", 25);
        printElement("Release Year", 15);
        printElement("Format", 10);
        printElement("Current Stock", 0);
        cout << endl;
        // Call BinTree output operator
        cout << *comedyMovies;
    } else {
        // Notify user if no Comedies are currently stocked in the Store
        cout << "No Comedy movies were found!" << endl;
    }

    // Pull the BSTree for drama movies from inventory
    BinTree* dramaMovies = this->inventory.at('D');
    // Print out all drama movies if a BSTree exists
    if (!dramaMovies->isEmpty()) {
        cout << "Drama Movies:" << endl;
        // Print column headers for each movie
        printElement("Title", 35);
        printElement("Director", 25);
        printElement("Release Year", 15);
        printElement("Format", 10);
        printElement("Current Stock", 0);
        cout << endl;
        // Call BinTree output operator
        cout << *dramaMovies;
    } else {
        // Notify user if no Dramas are currently stocked in the Store
        cout << "No Drama movies were found!" << endl;
    }

    // Pull the BSTree for classics movies from inventory
    BinTree* classicsMovies = this->inventory.at('C');
    // Print out all classics movies if a BSTree exists
    if (!classicsMovies->isEmpty()) {
        cout << "Classics Movies:" << endl;
        // Print column headers for each movie
        printElement("Title", 25);
        printElement("Director", 18);
        printElement("Release Month", 15);
        printElement("Release Year", 14);
        printElement("Major Actor(s)", 35);
        printElement("Format", 8);
        printElement("Current Stock", 0);
        cout << endl;
        // Call BinTree output operator
        cout << *classicsMovies;
    } else {
        // Notify user if no Classics are currently stocked in the Store
        cout << "No Classics movies were found!" << endl;
    }

    // Print closing divider
    cout << banner << banner << endl;
}