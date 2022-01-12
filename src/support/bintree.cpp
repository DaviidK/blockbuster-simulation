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

/**
 * Overloads the ostream << operator
 * Prints the In-Order traversal of data inside BinTree Object
 * Output example: 
 * "<data:1> <data:2> <data:3> ... <data:N>"
 * @param[out] ostream output
 * @param[in] BinTree btree : Object to displayed
 */
ostream& operator<<(ostream& output, const BinTree& btree){
    // Call inorderHelper
    btree.inorderHelper(output, btree.root);
    output << endl;
    return output;
}

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates an empty tree and sets size to 0
 */
BinTree::BinTree() : root(NULL) {}						

/**
 * Destructor
 * Deallocates dynamically allocated memory
 */
BinTree::~BinTree(){
    // call makeEmpty
    this->makeEmpty();
}

//---------------------------------------------------------Public member methods
/**
 * public isEmpty
 * Checks if the tree is empty
 * @return bool : true if tree is empty, false otherwise
 */
bool BinTree::isEmpty() const {
    // Return true if root is NULL, else false
    if (this->root == NULL)
        return true;
    else
        return false;
}

/**
 * public makeEmpty
 * Makes the tree empty so isEmpty returns true
 */
void BinTree::makeEmpty(){
    // Call deleteSubtree
    this->deleteSubTree(this->root);
}

/**
 * public insert
 * Inserts a given Node to Binary Search Tree
 * Movie is inserted on BinTree object, if not duplicate
 * BinTree remains unchanged if data is duplicate 
 * @param[in] Movie* data : Data to be inserted to a Node in BST
 * @return bool : != comparison result
 */
bool BinTree::insert(Movie* data){
    // If root is NULL
    if (this->isEmpty()) {
        // Insert Movie at root, then return true
        this->root = new Node(data, NULL, NULL);
        return true;
    } else {
        // Traverse through BST to insert at leaf
        // Return true if inserted successfully
        return this->insertHelper(this->root, data);
    }
}

/**
 * public retrieve
 * Gets the Movie* of a given object in the tree 
 * (via pass-by-reference parameter)
 * to report whether the object is found (true or false)
 * Preconditions: NONE
 * Postconditions: BinTree remains unchanged
 * @param[in] Movie data : to find on BST
 * @param[out] Movie* foundData : If the object is found, points to the actual 
 * object in the tree. Ignore if not found.
 * @return bool : True if the object is found, otherwise false
 */
bool BinTree::retrieve(const Movie &data, Movie* &foundData) {
    // Instantiate const node
    Node* foundNode = NULL;

    // If node is found
    if (findNode(this->root, data, foundNode)){ 
        // Save data to foundData param, then return true
        foundData = foundNode->data;
        return true;
    }

    // data not found
    return false;
}

// -------------------------------------------------------- Private Node methods
/**
* Constructor for private Struct Node
* @param[in] Movie* data: sets coeff value
* @param[in] Node* left: sets coeff value
* @param[in] Node* right: sets coeff value
*/
BinTree::Node::Node(Movie* data, Node* left, Node* right) : data(data), 
                                                            left(left), 
                                                            right(right) {}

//--------------------------------------------------------Private member methods
/**
 * private findNode
 * Searches Movie to existing BST
 * @param[in] Node* root : Root or parent with Movie (not NULL)
 * @param[in] Movie* target : Data to be inserted
 * @param[out] Node* foundNode : Where Node pointer saved, if found
 * @return bool : true if Movie of target is found, false otherwise
 */
bool BinTree::findNode(Node* subRoot,
                       const Movie &target, 
                       Node* &foundNode) const {
    // If node is not NULL
    if (subRoot != NULL) {
        // Comparing Movie. If equal, save Node then return true
        if (*subRoot->data == target) {
            foundNode = subRoot;
            return true;
        }

        // If Movie is found at left child leaves, return true
        if (findNode(subRoot->left, target, foundNode)) {
            return true;                            
        }

        // If Movie is found at right child leaves, return true
        if (findNode(subRoot->right, target, foundNode)) {
            return true;
        }

    } else {
        // if node is NULL, return false
        return false;                               
    }
}

/**
 * private deleteSubtree
 * Helper function for makeEmpty
 * Deletes left child, right child, then root
 * @param[in] Node* root : BinTree root to be deleted
 */
void BinTree::deleteSubTree(Node* &subRoot) {
    if (subRoot != NULL){
        // Traverse through left child
        deleteSubTree(subRoot->left);
        // Traverse through right child
        deleteSubTree(subRoot->right);
        // Delete Movie
        delete subRoot->data;
        subRoot->data = NULL;
        // Delete Node
        delete subRoot;
        subRoot = NULL;
    }
}

/**
 * private insertHelper
 * Helper function to insert a new Movie to existing BST
 * Movie is inserted on BinTree, if not duplicate
 * @param[in] Node* node : root or parent with Movie (not NULL)
 * @param[in] Movie* data : data to be inserted
 * @return bool : true if Movie is inserted, false if it's a duplicate
 */
bool BinTree::insertHelper(Node*& node, Movie* insertData) {
    // Compare data, to define if it should be at left or right of node 
    // If the Left/right pointer is empty, insert, else move to next level 
    if (*insertData < *node->data){
        // If left child is NULL
        if (node->left == NULL) {
            // Insert data then return true     
            node->left = new Node(insertData, NULL, NULL);
            return true;
        } else {
            // Insert at next level
            this->insertHelper(node->left, insertData);
        }    
    } else if (*insertData > *node->data) {
        // If right child is NULL
        if (node->right == NULL){
            // Insert data then return true
            node->right = new Node(insertData, NULL, NULL);
            return true;
        } else {
            // insert at next level
            this->insertHelper(node->right, insertData);
        }
    } else {
        // duplicate data, return false
        return false;
    }
}

/**
 * private inorderHelper
 * Overload for printing Binary Search Tree inorder
 * Operation: Inorder Printing
 *  - Traverses through left child 
 *  - Prints Movie
 *  - Then traverses through right child
 * @param[out] ostream output
 * @param[in] Node* node : BinTree Node to be traversed
 */
void BinTree::inorderHelper(ostream& out, const Node* node) const {
    if (node != NULL) {
        // traverse throught left child
        inorderHelper(out, node->left);

        // Special Handling of output for Classic Movie
        if (node->data->getGenre() == 'C') {
            Classics* c = static_cast<Classics* >(node->data);
            out << *c;
        } else {
            // print the nodeData using inorder Operation
            out << *node->data;
        }

        // traverse throught right child
        inorderHelper(out, node->right);
    }
}