// --------------------------------- store.cpp ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements the logic behind a singular store, which 
// contains information on all available movies at that store and all customers 
// that are borrowing from the store. The Store will parse through input files 
// to populate Movie, Customer, and Transaction objects, and then execute all
// transactions that are created.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input files will be provided in the following formats:
//      -Movie: genre(string) stock(int) director(string) title(string) 
//        In addition, the following movie genre's input will also contain:
//         Comedy: releaseYear(int) 
//         Drama: releaseYear(int)
//         Classics: majorActor(string) releaseMonth(int) releaseYear(int)
//      -Customer: customerID#(int) lastName(string) firstName(string)
//      -Transaction: actionType(char)
//        In addition, the following transaction types will also contain:
//         Borrow: customerID#(int) mediaFormat(char) movieData(Formatted above)
//         Return: customerID#(int) mediaFormat(char) movieData(Formatted above)
//         History: customerID#(int)
//  - For this Store, an estimated 200-500 customers will be created


#include "store.h"

//---------------------------------------------------Constructors and Destructor
/**
 * Constructor: Assigns the passed parameter to the storeName field and 
   instantiates all other fields to null
 * @param[string]: String containing the name of the store
*/ 
Store::Store(string name) { 
    this->storeName = name;
} 

Store::~Store() { 
  // delete this->customers;
  // delete this->inventory;
  // delete this->transactions;
} 

/**
 * populateInventory: Populates the inventory field by parsing through the 
   passed data and creating Movie objects for each line of data
 * @param[ifstream&]: Input file containing data for all movies that the store
   will have in inventory
*/
void Store::populateInventory(ifstream& input) {
    this->inventory = map<char, BinTree>();
    MovieFactory movieFac = MovieFactory(); 
    string line;
    // Read input until file is empty
    while (!input.eof()) {
        // Pull one line, representing a single movie, from the input file
        getline(input, line);
        // Construct a Movie object using the Movie Factory
        Movie* m = movieFac.createMovie(line);
        char genre = m->getGenre();
        // If the genre does not yet exist in the map, create a new BSTree
        // and link it to the genre
        if (m != NULL && this->inventory.find(genre) != this->inventory.end()) {
            BinTree movieTree = BinTree();
            // Add the created movie into the BSTree
            movieTree.insert(m);
            // Add the BSTree into the map
            this->inventory.insert({genre, movieTree});
        } else if (m != NULL) {
            // If the genre does exist in the map, add the movie into the 
            // corresponding tree
            this->inventory.at(genre).insert(m);
        }   
    }
}


/**
 * populateCustomers: Populates the customers field by parsing through the 
   passed data and creating Customer objects for each line of data
 * @param[ifstream&]: Input file containing data for all customers that 
   will be interacting with the Store
*/
void Store::populateCustomers(ifstream& input) {
    // Assuming a maximum of 500 customers, instantiate the HashTable with a
    // size of 503, the next prime number after 500.
    this->customers = HashTable<Customer>(503);
    string line;
    // Read input until file is empty
    while (!input.eof()) {
        // Pull one line, representing a single movie, from the input file
        getline(input, line);
        // Construct a Customer object by passing the input line
        const Customer* c = new Customer(line); 
        // Add the customer into the HashTable
        this->customers.insert(c->getCustomerID(), c); 
    }
}


/**
 * readTransactions: Populates the transactions field by parsing through the 
   passed data and creating Transaction objects for each line of data
 * @param[ifstream&]: Input file containing data for all transactions that 
   the store will be executing
*/
void Store::readTransactions(ifstream& input) {
    TransactionFactory transFac = TransactionFactory();
    string line;
    // Read input until file is empty
    while (!input.eof()) {
        // Pull one line, representing a single movie, from the input file
        getline(input, line);
        // Construct a Transaction object using the transaction factory
        Transaction* t = transFac.createTransaction(line, this->inventory,
                                                    this->customers); 
        // Only insert the Transaction object into the transactions field if
        // a valid input was provided 
        if (t != NULL) {
            this->transactions.push_back(t); 
        }
    }
}