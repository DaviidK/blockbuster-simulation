// --------------------------------- return.h ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class defines the action of a Customer returning a Movie to a
// Store. Will contain information related to the specific Movie being returned 
// as well as the Customer that is returning the movie 
// -----------------------------------------------------------------------------
// Assumptions:
//  - File input will be provided in the following format:
//      customerID#(int) mediaFormat(char) movieData(formatted based on genre)

#ifndef RETURN_H
#define RETURN_H

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

class Return : public Transaction {
    
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Will create a Return object and populate the m and c 
        // fields based on passed data
        Return(string&, map<char, BinTree*>&, HashTable<Customer>&);
        // Destructor: Will destroy the Return object
        virtual ~Return();
        // Will increment the stock of a movie and log the Return Transaction in
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