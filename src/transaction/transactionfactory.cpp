// -------------------------- transactionfactory.cpp ---------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements a factory that will determine the correct
// what type of Transaction object should be instantiated based on provided
// input. After determining which Transaction object is called for, it will 
// create and return an instance of that object.
// ------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the formats neccessary for each type of 
//    associated Transaction object

#include "transactionFactory.h"

//----------------------------------------------------------Public member method
// Will parse through passed parameter information to determine which type of
// Transaction object to create and return
Transaction createTransaction(string input,
                              map<string, BinTree<Movie>>& inventory,
                              HashTable<int, Customer>& customers) const {
    // Place data from passed input into stringstream
    stringstream inputStream; 
    inputStream << input;

    // Pull the first character of the passed string to determine the type of
    // Transaction object to be created
    char transType;
    inputStream >> transType;

    // Create a Transaction object and instantiate it according to the character
    // found in input. For each type of Transaction, return NULL if object
    // instantiated was invalid
    Transaction t;
    swtich (transType):
        case("B"):
            t = Borrow(inputStream, inventory, customers);
            if (t.movie == NULL || t.customer == NULL) {
                return NULL;
            }
            break;
        case("H"):
            t = History(inputStream, customers);
            if (t.customer == NULL) {
                return NULL;
            }
            break;
        case("I"): 
            t = Inventory(inventory);
            break;
        case("R"):
            t = Return(inputStream, inventory, customers);
            if (t.movie == NULL || t.customer == NULL) {
                return NULL;
            }
            break;
        case(default):
            cout << "ERROR: Transaction type \"" << transType 
            << "\" is not valid";
            return NULL;
    
    return t;
}