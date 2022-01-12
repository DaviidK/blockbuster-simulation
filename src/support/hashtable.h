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

#include <cstddef>
#include <climits>

template<class Value> 
class HashTable {

    public:
        //-------------------------------------------Constructors and Destructor
        // Constructor: Creates an empty HashTable object
        HashTable();
        // Destructor: Deletes the HashTable object
        ~HashTable();
        //-------------------------------------------------Public member methods
        // Inserts a new object at the passed Key location
        void insert(const int&, Value*&);
        // Retrieves the object present at the passed Key location
        // returning Object pointer to Value parameter
        bool retrieve(const int&, Value*&) const;

    private:
        //------------------------------------------------Private member methods
        // Hashing function: Takes in a Key and returns the hashed index
        int hash(const int&) const;
        // Node Struct to store Key, Value and Next Node
        struct Node {
            // Node constructor with NULL as Next pointer default value
            Node(int=INT_MIN, Value* = NULL, Node* = NULL);
            // Node destructor
            ~Node();
            // Pointer to the Key
            int key;
            // Pointer to the Value
            Value* value;
            // Pointer to the next Node
            Node* next;
        };
        // Constant array size 
        static const int ARRAY_SIZE = 503;
        // Array that holds the Node
        Node* nodeArray[ARRAY_SIZE];
        
};

#include "hashtable.cpp"
#endif