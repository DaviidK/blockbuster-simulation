// ------------------------------- hashtable.h ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class will define a HashTable that stores data in an array. The
// HashTable will use open hashing to compute the correct array index in which
// to store the data.
// -----------------------------------------------------------------------------
// Assumptions:
//  - Only ints will be accepted as Key values for this table

#ifndef HASHTABLE_H
#define HASHTABLE_H

using namespace std;

template<class Value> 
class HashTable {

    public:
        // Constructor: Will create an empty HashTable object
        HashTable();
        // Destructor: Will delete the HashTable object
        ~HashTable();
        // Inserts a new object at the passed Key location
        void insert(const int&, const Value&);
        // Removes the object contained in the passed Key location
        void remove(const int&);
        // Retrieves the object present at the passed Key location
        Value* retrieve(const int&) const;

    private: 
        // Array that holds the data
        Value* data;
        // Array size
        int size;
        // Hashing function: Takes in a Key and returns the hashed index
        int hash(const int&) const;

};

#endif