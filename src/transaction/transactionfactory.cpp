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

//----------------------------------------------------------Public member method
/**
 * public createTransaction
 * Will parse through passed parameter information to
 * determine which type of Transaction object to create and return
 * @param[in] string : Input data to be parsed
 * @param[in] map<char, BinTree> : All movies contained in the store
 * @param[in] HashTable<Customer> : All customers of the store
*/
Transaction* TransactionFactory::createTransaction(string input,
                              map<char, BinTree*>& inventory,
                              HashTable<Customer>& customers) {
    // Place data from passed input into stringstream
    stringstream inputStream(input);

    // Pull the first character of the passed string to determine the type of
    // Transaction object to be created
    char transType = ' ';
    inputStream >> transType;

    string restOfLine;
    getline(inputStream, restOfLine);

    // Create a Transaction object and instantiate it according to the character
    // found in input. For each type of Transaction, return NULL if object
    // instantiated was invalid
    Transaction* t = NULL;
    switch (transType) {
        case 'B': {
            t = new Borrow(restOfLine, inventory, customers);
            Borrow* b = static_cast<Borrow*>(t);
            if (b->getMovie() == NULL || b->getCustomer() == NULL) {
                delete t;
                t = NULL;
            }
            break;
        }
        case 'H': {
            t = new History(restOfLine, customers);
            History* h = static_cast<History*>(t);
            if (h->getCustomer() == NULL) {
                delete t;
                t = NULL;
            }
            break;
        }
        case 'I': { 
            t = new Inventory(inventory);
            break; 
        }
        case 'R': {
            t = new Return(restOfLine, inventory, customers);
            Return* r = static_cast<Return*>(t);
            if (r->getMovie() == NULL || r->getCustomer() == NULL) {
                delete t;
                t = NULL;
            }
            break;
        }
        default:
            printElement("Invalid transaction label", 55);
            printElement(transType, 30);
    }
    return t;
}