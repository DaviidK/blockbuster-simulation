// --------------------------------- bintree.h ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class will define a Binary Tree that stores Movie objects
// -----------------------------------------------------------------------------
// Assumptions:
//  - The Movie objects stored in this BinTree will all have a compareTo() 
//    method which returns an int value representing the comparison between two
//    different movies
//  - An empty bintree will not print anything
//  - Classics Movie will be handled in Operator<< to print Major Actor 
//    and Realese Month

#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include "../movie/movie.h"

using namespace std;

class BinTree {				

	public:
        //---------------------------------------------Constructors & Destructor
        // Default constructor: Creates and empty BinTree
        BinTree();						
        // Copy constructor: Creates a deep copy of the passed BinTree object
        BinTree(const BinTree&);		
        // Destructor: Destroys a BinTree by de-allocating the tree nodes
        ~BinTree();		
        //---------------------------------------------------Assignment operator
        // Assigns the value of the BinTree object on the right of the operator
        // to the one on the left of the operator
        BinTree& operator=(const BinTree&);
        //--------------------------------------------------Comparison operators
        // Returns true if two BinTree objects contain the exact same Nodes in
        // the same order
        bool operator==(const BinTree&) const;
        // Returns true if two BinTree objects differ in any way
        bool operator!=(const BinTree&) const;
        //-------------------------------------------------Public member methods
        // Returns true if the tree is empty, false if not
        bool isEmpty() const;			
        // Empties the BinTree object
        void makeEmpty();				
        // Adds a Node containing the passed parameter Movie into the tree	
        bool insert(Movie*);
        // Gets the Movie* of a given object in the tree 
        // (via pass-by-reference parameter)
        bool retrieve(const Movie&, Movie* &);
	
	private:
        struct Node {
            // Node constructor with NULL as children's default value
			Node(Movie*, Node* = NULL, Node* = NULL);
            // Pointer to the data, which is stored in a Movie object
            Movie* data;
            // Pointer to the left child
            Node* left;					
            // Pointer to the right child
            Node* right;
        };
        // Root of the tree
        Node* root;	
		//------------------------------------------------Private member methods
        // Helper method that locates a Node with target data and copies the
        // memory of the found Node in a parameter. Will return false if no Node
        // is found 
        bool findNode(Node*, const Movie&, Node*&) const;
        // Helper method to compare values and structure of two trees. Returns
        // true if both trees contain identical values stored in the same order
        bool equalityHelper(const Node*, const Node*) const;
        // Helper method for the assignment operator(=). Will create a deep copy
        // of the second passed Node by copying all its values into the first
        void assignmentHelper(Node*&, const Node*);
        // Deletes a Node and all of the Nodes nested underneath it by
        // deallocating the Movie they contain and then the Node itself
        void deleteSubtree(Node*&);
        // Helper method to take in a Movie and find the correct location to add
        // it in the tree. Will return false if the data already exists in tree
        bool insertHelper(Node*&, Movie*);

};

#endif