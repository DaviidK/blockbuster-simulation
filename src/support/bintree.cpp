// ------------------------------- bintree.cpp ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class will define a Binary Search Tree that stores Movie 
// objects.
// -----------------------------------------------------------------------------
// Assumptions:
//  - The Movie objects stored in this BinTree will all have a compareTo() 
//    method which returns an int value representing the comparison between two
//    different movies
//  - An empty bintree will not print anything
//  - Classics Movie will be handled in Operator<< to print Major Actor 
//    and Realese Month

#include "bintree.h"

// ------------------ Constructors and Destructors ----------------------------

/**
 * Default Constructor
 * Creates an empty tree and sets size to 0
 * Preconditions: NONE
 * Postconditions: BinTree (empty) is created, root is NULL
 */
BinTree::BinTree() : root(NULL) {}						

/**
 * Copy Constructor
 * Takes care of a deep copy of the Polynomial
 * Preconditions: NONE
 * Postconditions: BinTree is created as deep copy of parameter bintree
 * @param[in] BinTree bintree: Binary Tree object to be copied
 */
BinTree::BinTree(const BinTree &btree) : root(NULL) {
    *this = btree;          // using assignment operator=
}

/**
 * Destructor
 * Deallocates dynamically allocated memories
 * Calls makeEmpty()
 * Preconditions: NONE
 * Postconditions: BinTree becomes empty and value becomes NULL
 */
BinTree::~BinTree(){
    this->makeEmpty();
}

// ------------------------ Overload Operators --------------------------------

/**
 * Assignment Operator= for BinTree objects
 * Creates a deep copy of given BinTree object
 * Preconditions: NONE
 * Postconditions: BinTree is created as deep copy right hand side of operation
 * @param[in] BinTree btree: BinTree object to be copied
 * @return BinTree with same reference, as deep copy of parameter bintree
 */
BinTree& BinTree::operator=(const BinTree &btree){
    // if the two objects have same reference, return this
    if (this == &btree) {
        return *this;
    }
    
    this->makeEmpty();              // clear, delete all existing Nodes

    if (!btree.isEmpty()){
        this->assignmentHelper(this->root, btree.root);
    }

    return *this;
}

/**
 * private assignmentHelper
 * Helper function for creating a deep copy of Binary Search Tree
 * Copies from left, root, to right
 * Preconditions: Node* copyTo should not be NULL;
 * Postconditions: creates a new Node 
 * @param[in] Node* copyFrom: BinTree Node to be copied
 * @param[out] Node* copyTo: new Node
 */
void BinTree::assignmentHelper(Node* &copyTo, const Node* copyFrom) {
    copyTo = new Node(new Movie(*copyFrom->data));   // new Node, copy data

    // if left child is not NULL, traverse through left child
    if (copyFrom->left != NULL) {
        assignmentHelper(copyTo->left, copyFrom->left); 
    }

    // if right child is not NULL, traverse through right child
    if (copyFrom->right != NULL) {
        assignmentHelper(copyTo->right, copyFrom->right); 
    }
}

/**
 * Overloads the == comparison operator
 * Compares items for each Movie in Binary Trees
 * Preconditions: NONE
 * Postconditions: BinTree remains unchanged
 * @param[in] BinTree btree: left hand side of operation
 * @return boolean: == comparison result
 */
bool BinTree::operator==(const BinTree & btree) const {
    return equalityHelper(this->root, btree.root);     // use equalityHelper()
}

/**
 * Overloads the != comparison operator
 * Compares items for each Movie in Binary Trees
 * Preconditions: NONE
 * Postconditions: BinTree remains unchanged
 * @param[in] BinTree btree: left hand side of operation
 * @return boolean: != comparison result
 */
bool BinTree::operator!=(const BinTree & btree) const {
    return !(*this == btree);   // return the opposite of == comparison value
}

/**
 * private equalityHelper
 * Recursively compares to 2 subtrees given their roots
 * Preconditions: None
 * Postconditions: BinTree remains unchanged
 * @param[in] Node* rootA: root of first subtree
 * @param[in] Node* rootB: root of second subtree
 * @return bool true if subtrees have equal Movies, false otherwise
 */
bool BinTree::equalityHelper(const Node* rootA, const Node* rootB) const {
    if (rootA == rootB) {                   // subtrees are equal
        return true;                        // for same ref and NULL values
    } else if(rootA == NULL || rootB == NULL) { // if either roots are NULL
        return false;                       // one is NULL, but not the other
    } else {                                // if rootA and rootB is not NULL
        // checks the data of root and traverses through left and right subtrees
        if(*rootA->data == *rootB->data &&
           equalityHelper(rootA->left, rootB->left) &&
           equalityHelper(rootA->right, rootB->right)) {
                return true;                // if root, left and right is equal
        } else {
            return false;                   // if not equal, retun false;
        }
    }
}

// ------------------------ Utility Functions ---------------------------------

/**
 * public isEmpty
 * Checks if the tree is empty
 * Preconditions: NONE
 * Postconditions: BinTree remains unchanged
 * @return bool true if tree is empty, false otherwise
 */
bool BinTree::isEmpty() const {
    if (this->root == NULL)
        return true;
    else
        return false;
}
/**
 * public makeEmpty
 * Makes the tree empty so isEmpty returns true
 * Preconditions: NONE
 * Postconditions: BinTree becomes empty
 */
void BinTree::makeEmpty(){
    this->deleteSubtree(this->root);            // helper method to clear tree
}

/**
 * private deleteSubtree
 * Helper function for makeEmpty
 * Deletes left child, right child, then root
 * Preconditions: Node* copyTo should not be NULL;
 * Postconditions: creates a new Node 
 * @param[in] Node* root: BinTree root to be deleted
 */
void BinTree::deleteSubtree(Node* &subRoot) {
    if (subRoot != NULL){
        deleteSubtree(subRoot->left);           // traverse through left child
        deleteSubtree(subRoot->right);          // traverse through right child
        delete subRoot->data;                   // delete Movie
        subRoot->data = NULL;                   // data set to NULL
        delete subRoot;                         // delete Node
        subRoot = NULL;                         // node (root/child) set to NULL
    }
}

/**
 * public insert
 * Inserts a given Node to Binary Search Tree
 * Preconditions: NONE
 * Postconditions: Movie is inserted on BinTree object, if not duplicate
 *                 BinTree remains unchanged if data is duplicate 
 * @param[in] Movie* data: Data to be inserted to a Node in BST
 * @return bool != comparison result
 */
bool BinTree::insert(Movie* data){
    if (this->isEmpty()) {              // if root is NULL
        this->root = new Node(data);    // insert Movie at root
        return true;                    // successful insert, return true
    } else {
        // traverse through BST, then insert
        // return true if inserted successfully
        return this->insertHelper(this->root, data);
    }
}

/**
 * private insertHelper
 * Helper function to insert a new Movie to existing BST
 * Preconditions: BinTree Object should not be empty
 * Postconditions: BinTree remains unchanged if data is duplicate
 *                 Movie is insterted on BinTree, if not duplicate
 * @param[in] Node* node: root or parent with Movie (not NULL)
 * @param[in] Movie* data: data to be inserted
 * @return bool true if Movie is inserted, false if it's a duplicate
 */
bool BinTree::insertHelper(Node* &node, Movie* insertData) {
    if (*insertData < *node->data){         // if data < current node's data
        if (node->left == NULL){            // if left child is NULL
            node->left = new Node(insertData);        // insert data
            return true;                    // successful insert, return true
        } else {
            this->insertHelper(node->left, insertData);   // insert at next level
        }    
    } else if (*insertData > *node->data) { // if data > current node's data
        if (node->right == NULL){           // if right child is NULL
            node->right = new Node(insertData);       // insert data
            return true;                    // successful insert, return true
        } else {
            this->insertHelper(node->right, insertData);  // insert at next level
        }
    } else {                                // if data == current node's data
        return false;                       // duplicate data, return false
    }
}

/**
 * public retrieve
 * Gets the Movie* of a given object in the tree 
 * (via pass-by-reference parameter)
 * to report whether the object is found (true or false)
 * Preconditions: NONE
 * Postconditions: BinTree remains unchanged
 * @param[in] Movie to find on BST
 * @param[out] Movie* 
 *   if the object is found, points to the actual object in the tree
 *   ignore if not found
 * @return bool True if the object is found, otherwise false
 */
bool BinTree::retrieve(const Movie &data, Movie* &foundData) {
    Node* foundNode = NULL;               // instantiating const node

    if (findNode(this->root, data, foundNode)){ // if node is found
        foundData = foundNode->data;            // save data to foundData param
        return true;                            // return true
    }

    return false;                               // node not found
}

/**
 * private findNode
 * Searches Movie to existing BST
 * Preconditions: None
 * Postconditions: BinTree remains unchanged
 * @param[in] Node* root: root or parent with Movie (not NULL)
 * @param[in] Movie* target: data to be inserted
 * @param[out] Node* foundNode: where Node pointer saved, if found
 * @return bool true if Movie of target is found, false otherwise
 */
bool BinTree::findNode(Node* subRoot,
                       const Movie &target, 
                       Node* &foundNode) const {
    if (subRoot != NULL) {                          // if node is not NULL
        if (*subRoot->data == target) {             // comparing Movie
            foundNode = subRoot;                    // if equal, save Node
            return true;                            // return true
        }

        // if Movie is found at left child leaves, return true
        if (findNode(subRoot->left, target, foundNode)) {
            return true;                            
        }

        // if Movie is found at right child leaves, return true
        if (findNode(subRoot->right, target, foundNode)) {
            return true;
        }

    } else {                                        // if node is NULL
        return false;                               // return false
    }
}

/**
 * Overloads the ostream << operator
 * Prints the In-Order traversal of data inside BinTree Object
 * Output example: 
 * "and eee ff iii jj m not ooo pp r sssss tttt y z"
 * Preconditions: NONE
 * Postconditions: BinTree remains unchanged
 * @param[out] ostream output;
 * @param[in] BinTree btree: BinTree object to displayed
 */
ostream& operator<<(ostream& output, const BinTree& btree){
    btree.inorderHelper(output, btree.root);        // call inorderHelper()
    output << endl;                                 // line break;
    return output;                                  // return ostream&
}

/**
 * private inorderHelper
 * Overload for printing Binary Search Tree inorder
 * Operation: Inorder Printing
 *  - Traverses through left child 
 *  - Prints NodeData
 *  - Then traverses through right child
 * Preconditions: BinTree is not empty
 * Postconditions: BinTree remains unchanged
 * @param[out] ostream output;
 * @param[in] Node* node: BinTree Node to be traversed
 */
void BinTree::inorderHelper(ostream& out, const Node* node) const {
    if (node != NULL) {
        inorderHelper(out, node->left);     // traverse throught left child
    
        // print the nodeData using inorder Operation
        out << *node->data << " ";
    
        inorderHelper(out, node->right);    // traverse throught right child
    }
}

// ------------------------ Node methods --------------------------------------

/**
* Constructor for private Struct Node
* @param[in] Movie* data: sets coeff value
*/
BinTree::Node::Node(Movie* d, Node* l, Node* r) : data(d), 
                                                     left(l), 
                                                     right(r) {}