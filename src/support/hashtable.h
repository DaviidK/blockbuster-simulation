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

template<typename Value> 
class HashTable {

    public:
        // Constructor: Will create an empty HashTable object
        HashTable(int);
        // Destructor: Will delete the HashTable object
        ~HashTable();
        // Inserts a new object at the passed Key location
        void insert(const int&, const Value*&);
        // Removes the object contained in the passed Key location
        bool remove(const int&);
        // Retrieves the object present at the passed Key location
        // Returns the Object pointer to the 2nd parameter;
        bool retrieve(const int&, Value*&) const;

    private: 
        struct Node {
            // Node constructor with NULL as Next pointer default value
			Node(int, Value*, Node* = NULL);
            // Pointer to the Key
            int key;
            // Pointer to the Value
            Value* value;
            // Pointer to the next Node
            Node* next;
        };
        // Array that holds the Node
        Node* data;
        // Array size
        int size;
        // Hashing function: Takes in a Key and returns the hashed index
        int hash(const int&) const;
        

};

#endif