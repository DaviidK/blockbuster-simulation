// --------------------------------- borrow.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of a Customer borrowing a Movie from a
// Store. Will contain information related to the specific Movie being borrowed 
// as well as the Customer that is borrowing the movie 
// -----------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the following format:
//      customerID#(int) mediaFormat(char) movieData(formatted based on genre)

#ifndef BORROW_H
#define BORROW_H

#include <map>
#include <sstream>
#include <iomanip>
#include "transaction.h"
#include "../movie/movie.h"
#include "../customer/customer.h"
#include "../support/hashtable.h"
#include "../support/bintree.h"
#include "../movie/moviefactory.h"

using namespace std;

class Borrow : public Transaction {

    public:
        //-------------------------------------------------Public member methods
        // Constructor: Will create a Borrow object and populate the m and c
        // fields based on passed data
        Borrow(string&, map<char, BinTree*>&, HashTable<Customer>&);
        // Destructor: Will destroy the Borrow object
        virtual ~Borrow();
        // Will decrement the stock of a movie and log the Borrow Transaction in
        // the Customer's history field
        virtual void doTransaction() const;
        // Returns the movie
        Movie* getMovie() const;
        // Returns the customer
        Customer* getCustomer() const;

    private:
        //-------------------------------------------------Private member fields
        // Pointer to the Movie object associated with this transaction
        Movie* movie;
        // Pointer to the Customer object associated with this transaction
        Customer* customer;

};

#endif