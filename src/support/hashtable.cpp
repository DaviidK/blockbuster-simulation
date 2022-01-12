// ------------------------------- hashtable.cpp -------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class will define a HashTable that stores data in an array. The
// HashTable will use open hashing to compute the correct array index in which
// to store the data.
// -----------------------------------------------------------------------------
// Assumptions:
//  - This Hashtable stores a given key-value pairs, where key is always an int.

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates an empty Hashtable and sets the size to 0, if size is not given.
 */
template<class Value> 
HashTable<Value>::HashTable() {
    for (int i = 0; i < this->ARRAY_SIZE; i++) {
        this->nodeArray[i] = new Node();
    }
}	

/**
 * Destructor
 * Deallocates dynamically allocated memories
 */
template<class Value> 
HashTable<Value>::~HashTable() {
    for (int i = 0; i < this->ARRAY_SIZE; i++) {
        delete this->nodeArray[i];
        this->nodeArray[i] = NULL;
    }
}

//---------------------------------------------------------Public member methods
/**
 * public insert
 * Inserts a new object of given value at the passed key location
 * @param[in] int key : Key of the object stored
 * @param[in] Value value : Value the object to be stored
 */
template<class Value> 
void HashTable<Value>::insert(const int& key, Value*& value) {
    // Finds the index for storing data
    int index = this->hash(key);
    // Inserts the key and value to table
    this->nodeArray[index] = new Node(key, value, this->nodeArray[index]);
}

/**
 * public retrieve
 * Retrieves the object present at the passed Key location
 * If the Object does not exist, sets foundData parameter to NULL
 * @param[in] int searchKey : Key of the object to be retrieved
 * @param[out] Value* foundData : Saves the pointer to this object if found
 */
template<class Value> 
bool HashTable<Value>::retrieve(const int& searchKey, Value*& foundData) const {
    // Set foundData to NULL
    foundData = NULL;
    
    // Find the array index to put the inserted data in
    int index = this->hash(searchKey);
    
    // Saves the first Node at index
    Node* current = this->nodeArray[index];
    
    // checks for the all nodes at index to find value of searchKey
    while (current->key != INT_MIN) {
        // If key is found
        if(current->key == searchKey) {
            // Save value to foundData param
            foundData = current->value;
            return true;
        }
        // Move to next node at index
        current = current->next;
    }
    
    // Key not found
    return false;  
}

//--------------------------------------------------------Private member methods
/**
 * private hash
 * Takes in a key and returns the hashed index
 * @param[in] int key : Key of the object to be hashed
 * @return int : hashed index
 */
template<class Value> 
int HashTable<Value>::hash(const int& key) const {
    return key % this->ARRAY_SIZE;
}

// ---------------------------------------------------------Private Node methods
/**
* Constructor for private Struct Node
* @param[in] Value* v: sets coeff value
*/
template<class Value> 
HashTable<Value>::Node::Node(int k, Value* v, Node* n) : key(k), 
                                                         value(v), 
                                                         next(n) {}

/**
* Destructor for private Struct Node
*/
template<class Value>
HashTable<Value>::Node::~Node() {
    // Delete value if not the empty end node
    if(this->key != INT_MIN) {
        delete this->value;
        this->value = NULL;
    }

    // Check and delete next node 
    if (this->next != NULL) {
        delete this->next;
        this->next = NULL;
    }
}