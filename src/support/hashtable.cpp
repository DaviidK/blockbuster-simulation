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

//---------------------------------------------------Constructors and Destructor

/**
 * Default Constructor
 * Creates an empty Hashtable and sets the size to 0, if size is not given.
 * Preconditions: NONE
 * Postconditions: Hashtable (empty) is created, data is NULL
 */
template<typename Value> 
HashTable<Value>::HashTable(int size) : size(size) {
    // Setting the array of Nodes containing data to NULL
    Node* data[size];
}						

/**
 * Destructor
 * Deallocates dynamically allocated memories
 * Preconditions: NONE
 * Postconditions: Hashtable becomes empty and value becomes NULL
 */
template<typename Value> 
HashTable<Value>::~HashTable() {
    
}

//---------------------------------------------------------Public member methods
/**
 * public insert
 * Inserts a new object of given value at the passed Key location
 * Preconditions: NONE
 * Postconditions: Value is inserted
 * @param[in] int key: Key of the object stored
 * @param[in] Value value: the object to be stored
 */
template<typename Value> 
void HashTable<Value>::insert(const int& key, const Value*& value) {
    // Finds the index for storing data
    int index = this->hash(key);
    // Inserts the key and value to table
    this->data[index]->value = new Node(key, value, this->data[index]);
}


/**
 * public remove
 * Remove an object at the passed Key location
 * If the Object does not exist, Print out a message
 * Preconditions: NONE
 * Postconditions: Value is removed
 * @param[in] int key: Key of the object to be removed
 */
template<typename Value> 
bool HashTable<Value>::remove(const int& key) {
    //TODO Implement Remove
}

/**
 * public retrieve
 * Retrieves the object present at the passed Key location
 * If the Object does not exist, return NULL
 * Preconditions: NONE
 * Postconditions: NONE
 * @param[in] int key: Key of the object to be retrieved
 */
template<typename Value> 
bool HashTable<Value>::retrieve(const int& searchKey, Value*& foundData) const {
    // Find the index to put the insterted data in
    int index = this->hash(searchKey);
    
    Node* current = data[index];
    
    while (current != NULL) {
        if(current->key == searchKey) {
            // Save data to foundData param
            foundData = current->value;
            return true;
        }
        // Point to next node
        current = current->next;
    }
    
    return false;  
}

//--------------------------------------------------------Private member methods
/**
 * private hash
 * Hashing function: Takes in a Key and returns the hashed index
 * Preconditions: HashTable size should not be 0.
 * Postconditions: NONE
 * @param[in] int key: Key of the object to be hashed
 */
template<typename Value> 
int HashTable<Value>::hash(const int& key) const {
    return key % size;
}

// -----------------------------------------------------------------Node methods
/**
* Constructor for private Struct Node
* @param[in] Value* data: sets coeff value
*/
template<typename Value> 
HashTable<Value>::Node::Node(int k, Value* d, Node* n) : key(k), 
                                                         data(d), 
                                                         next(n) {}