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

#include "transactionfactory.h"

//----------------------------------------------------------Public member method
/**
 * createTransaction: Will parse through passed parameter information to 
   determine which type of Transaction object to create and return
 * @param[string&]: Input data to be parsed
 * @param[map<char, BinTree>&]: All movies contained in the store
 * @param[HashTable<Customer>&]: All customers of the store
*/
Transaction* createTransaction(string input,
                              map<char, BinTree>& inventory,
                              HashTable<Customer>& customers) {
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
    Transaction* t;
    switch (transType) {
        case 'B': {
            t = new Borrow(inputStream, inventory, customers);
            Borrow* b = static_cast<Borrow*>(t);
            if (b->getMovie() == NULL || b->getCustomer() == NULL) {
                return NULL;
            }
            return b;
        }
        case 'H': {
            t = new History(inputStream, customers);
            History* h = static_cast<History*>(t);
            if (h->getCustomer() == NULL) {
                return NULL;
            }
            return h;
        }
        case 'I': { 
            t = new Inventory(inventory);
            return t; 
        }
        case 'R': {
            t = new Return(inputStream, inventory, customers);
            Return* r = static_cast<Return*>(t);
            if (r->getMovie() == NULL || r->getCustomer() == NULL) {
                return NULL;
            }
            return r;
        }
        default:
            cout << "ERROR: Transaction type \"" << transType 
            << "\" is not valid";
            return NULL;
    }
}