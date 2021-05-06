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

#include "transaction.h"

using namespace std;

class Return : public Transaction {
    public:
        //-------------------------------------------------Public member methods
        // Constructor: Will create a Return object and populate the m and c 
        // fields based on passed data
        Return(string, HashTable<string, Movie>&, HashTable<int, Customer>&);
        // Destructor: Will delete the Return object
        virtual ~Return();
        // Will increment the stock of a movie and log the Return Transaction in
        // the Customer's history field
        virtual void doTransaction(Store&, Customer&, Movie&) const;

    private:
        //-------------------------------------------------Private member fields
        // Pointer to the Movie object associated with this transaction
        Movie* m;
        // Pointer to the Customer object associated with this transaction
        Customer* c;
        
        //------------------------------------------------Private member methods
        // Will check that the movie exists in the Store's inventory and that
        // a Customer exists with the matching ID number
        virtual isValid(string info, HashTable<char, Movie>&,
                        HashTable<int, Customer>&);
};

#endif