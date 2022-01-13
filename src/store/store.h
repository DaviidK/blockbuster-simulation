// ---------------------------------- store.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines a singular store, which contains information on 
// all available movies and all customers that are borrowing from the store. 
// Will parse through input files to populate Movie, Customer, and Transaction
// objects, and then execute all transactions that are created.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input files will be provided in the following formats:
//      -Movie: genre(string) stock(int) director(string) title(string) 
//        In addition, the following movie genre's input will also contain:
//         Comedy: releaseYear(int) 
//         Drama: releaseYear(int)
//         Classics: majorActor(string) releaseMonth(int) releaseYear(int)
//      -Customer: customerID#(int) lastName(string) firstName(string)
//      -Transaction: actionType(char)
//        In addition, the following transaction types will also contain:
//         Borrow: customerID#(int) mediaFormat(char) movieData(Formatted above)
//         Return: customerID#(int) mediaFormat(char) movieData(Formatted above)
//         History: customerID#(int)

#ifndef STORE_H
#define STORE_H

#include <fstream>
#include <string>
#include <list>
#include <map>
#include <iomanip>
#include "../support/bintree.h"
#include "../support/hashtable.h"
#include "../customer/customer.h"
#include "../movie/movie.h"
#include "../movie/drama.h"
#include "../movie/comedy.h"
#include "../movie/classics.h"
#include "../movie/moviefactory.h"
#include "../transaction/transaction.h"
#include "../transaction/transactionfactory.h"
#include "../transaction/borrow.h"
#include "../transaction/return.h"
#include "../transaction/history.h"
#include "../transaction/inventory.h"

using namespace std;

class Store {

    public:
        //-----------------------------------------------------------Constructor
        // Constructor: Will populate the storeName field
        Store(string);
        // Destructor: Destroys a Store object by de-allocating the customers, 
        // transactions, and movies fields
        ~Store();
        // Will fill the inventory field based on data from input an file
        void populateInventory(ifstream&);
        // Will fill the customers field based on data from input an file
        void populateCustomers(ifstream&);
        // Will fill the transactions field based on data from an input file
        void populateCommands(ifstream&);
        // Will execute all transactions stored in the transactions field
        void executeCommands();

    private:
        //------------------------------------------------Private member methods
        // Name of the store
        string storeName;
        // All available movies
        map<char, BinTree*> inventory;
        // Movie container
        list<BinTree*> movies;
        // All the customers of the Store
        HashTable<Customer> customers;
        // All valid transactions that are read in from input file
        list<Transaction*> transactions;
        // Helper method that ensures Return transactions can only be created if
        // the customer had already borrowed the same movie
        bool validReturn(Transaction*);

};

#endif