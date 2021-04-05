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

#include "transaction.h"

using namespace std;

class Borrow : public Transaction {
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Will create a Borrow object and populate the m and c
        // fields based on passed data
        Borrow(string, HashTable<string, Movie>&, HashTable<int, Customer>&);
        // Destructor: Will destroy the Borrow object
        virtual ~Borrow();
        // Will decrement the stock of a movie and log the Borrow Transaction in
        // the Customer's history field
        virtual void doTransaction(Store&, Customer&, Movie&) const;

    private:
        //-------------------------------------------------Private member fields
        // Pointer to the Movie object associated with this transaction
        Movie* movie;
        // Pointer to the Customer object associated with this transaction
        Customer* customer;
        
        //------------------------------------------------Private member methods
        // Will check that the movie exists in the Store's inventory and that
        // a Customer exists with the matching ID number
        virtual bool isValid(string info, map<string, BinTree<Movie>>&,
                             HashTable<int, Customer>&) const;
};

#endif