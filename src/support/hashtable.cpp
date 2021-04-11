// ------------------------------- hashtable.cpp -------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class will define a HashTable that stores data in an array. The
// HashTable will use open hashing to compute the correct array index in which
// to store the data.
// -----------------------------------------------------------------------------
// Assumptions:
//  - This Hashtable stores a given key-value pairs, where key is always an int.

#include "hashtable.h"

// ------------------ Constructors and Destructors ----------------------------

/**
 * Default Constructor
 * Creates an empty Hashtable and sets the size to 0
 * Preconditions: NONE
 * Postconditions: Hashtable (empty) is created, data is NULL
 */
template<class Value> 
HashTable<Value>::HashTable() : data(NULL), size(0) {}						

/**
 * Destructor
 * Deallocates dynamically allocated memories
 * Preconditions: NONE
 * Postconditions: Hashtable becomes empty and value becomes NULL
 */
template<class Value> 
HashTable<Value>::~HashTable() {
    
}

/**
 * public insert
 * Inserts a new object of given value at the passed Key location
 * Preconditions: NONE
 * Postconditions: Value is inserted
 * @param[in] int key: Key of the object stored
 * @param[in] Value value: the object to be stored
 */
template<class Value> 
void HashTable<Value>::insert(const int& key, const Value& value) {
    
}


/**
 * public remove
 * Remove an object at the passed Key location
 * If the Object does not exist, Print out a message
 * Preconditions: NONE
 * Postconditions: Value is removed
 * @param[in] int key: Key of the object to be removed
 */
template<class Value> 
void HashTable<Value>::remove(const int&) {
    //TODO Implement Remove
    //TODO if Key does not exist, Print a message?
}

/**
 * public retrieve
 * Retrieves the object present at the passed Key location
 * If the Object does not exist, return NULL
 * Preconditions: NONE
 * Postconditions: NONE
 * @param[in] int key: Key of the object to be retrieved
 */
template<class Value> 
Value* HashTable<Value>::retrieve(const int&) const {

}
