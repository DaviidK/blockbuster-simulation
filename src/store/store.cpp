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

/**
 * printElement
 * Helper method that allows for easy printing of elements at set intervals
 * @param[in] Typename T: Data to be printed
 * @param[in] int width: Width between next element on print line
 */
template<typename T> void printElement(T t, const int& width) {
    const char separator = ' ';
    cout << left << setw(width) << setfill(separator) << t;
}

//---------------------------------------------------Constructors and Destructor
/**
 * Constructor
 * Assigns the passed parameter to the storeName field and 
 * instantiates all other fields to null
 * @param[string]: String containing the name of the store
 */ 
Store::Store(string name) : storeName(name) {}

/**
 * Destructor
 * Deallocates dynamically allocated memory
 */
Store::~Store() {
    // Call the HashTable destructor to delete the customers field
    this->customers.~HashTable();

    // Delete each Transaction* in this->transactions;
    for(Transaction* t : this->transactions) {
        delete t;
        t = NULL;
    }
    // Clear the transactions list to ensure there is no memory leaks
    this->transactions.clear();

    // Delete each BinTree in this->movies
    for(BinTree* m : this->movies) {
        delete m;
        m = NULL;
    }
    this->movies.clear();
}

/**
 * public populateInventory
 * Populates the inventory field by parsing through the 
 * passed data and creating Movie objects for each line of data
 * @param[in] input : Input file containing data for all movies that the store
 *                    will have in inventory
 */
void Store::populateInventory(ifstream& input) {
    // Print status message and column headers
    cout << "Reading movies from data file...\n" << endl;
    printElement("Error Type", 35);
    printElement("Data found", 20);
    printElement("Line #", 0);
    cout << "\n" << endl;

    // Instantiating inventory map
    this->inventory = map<char, BinTree*>();
    // Creating movie factory for future use
    MovieFactory movieFac = MovieFactory(); 
    string line;
    int lineCount = 0;

    // Read input until file is empty
    while (!input.eof()) {
        lineCount++;
        // Pull a line, representing a single movie, from the input file
        getline(input, line);

        // Skip the rest of this while loop iteration if an empty line is found
        if (line == "") {
            continue;
        }

        // Construct a Movie object using the Movie Factory
        Movie* m = movieFac.createMovie(line);
        Movie* tempMovie = NULL;
        // If movie isn't NULL, check to ensure it is valid and then add to the
        // correct BinTree. 
        // If movie is NULL, report what line the error occurred on
        if (m != NULL) {
            if (m->getTitle() != "") {
                char genre = m->getGenre();
                // If the genre does not yet exist in the map,
                // create a new BSTree and link it to the genre
                if (this->inventory.find(genre) == this->inventory.end()) {
                    BinTree* movieTree = new BinTree();
                    // Add the created movie into the BSTree
                    movieTree->insert(m);
                    // Add the BSTree into the map
                    this->inventory.insert({genre, movieTree});
                    this->movies.push_back(movieTree);
                } else if (!this->inventory.at(genre)->retrieve(*m, tempMovie)){
                    // If the genre does exist in the map, and the movie doesn't
                    // yet exist in the BinTree, add the movie 
                    this->inventory.at(genre)->insert(m);
                } else {
                    // If a BinTree for the genre exists AND the movie already 
                    // exists in that BinTree, add to the existing stock
                    tempMovie->setStock(tempMovie->getStockInStore() +
                                        m->getStockInStore());
                    if (tempMovie->getGenre() == 'C') {
                        // Cast both movies to Classics to ensure access to 
                        // majorActor field
                        Classics* oldMovie = static_cast<Classics*>(tempMovie);
                        Classics* secondMovie = static_cast<Classics*>(m);
                        oldMovie->addActor(secondMovie->getMajorActor());
                    }
                    delete m;
                    m = NULL;
                }
            } else {
                // If movie title is empty, the Movie is invalid
                // and must be deleted
                delete m; 
                m = NULL;
            }
        } else {
            cout << lineCount << endl;
        }
    }
}


/**
 * public populateCustomers
 * Populates the customers field by parsing through the 
 * passed data and creating Customer objects for each line of data
 * @param[in] input : Input file containing data for all customers that 
 *                    will be interacting with the Store
 */
void Store::populateCustomers(ifstream& input) {
    // Print status message and column headers
    cout << "Reading customers from data file...\n" << endl;
    printElement("Error Type", 35);
    printElement("Data found", 20);
    printElement("Line #", 0);
    cout << "\n" << endl;
    string line;
    int lineCount = 0;

    // Read input until file is empty
    while (!input.eof()) {
        lineCount++;
        // Pull one line, representing a single customer, from the input file
        getline(input, line);

        // Skip the rest of this while loop iteration if an empty line is found
        if (line == "") {
            continue;
        }

        // Construct a Customer object by passing the input line
        Customer* c = new Customer(line);
        // Report invalid customer ID if number passed is below 0
        if (c->getCustomerID() < 0) {
            printElement("Invalid customer ID", 40);
            printElement(c->getCustomerID(), 20);
            cout << lineCount << endl;
            delete c;
            c = NULL;
        } else {
            // Add the customer into the HashTable if given valid ID
            this->customers.insert(c->getCustomerID(), c); 
        }
        
    }
}


/**
 * public populateCommands
 * Populates the transactions field by parsing through the passed data
 * and creating Transaction objects for each line of data
 * @param[in] input: Input file containing data for all transactions that 
 *                   the store will be executing
 */
void Store::populateCommands(ifstream& input) {
    // Print status message and column headers
    cout << "Reading commands from data file...\n" << endl;
    printElement("Error Type", 50);
    printElement("Data found", 30);
    printElement("Line #", 0);
    cout << "\n" << endl;

    // Creating transaction factory for later use
    TransactionFactory transFac = TransactionFactory();
    // Line count to report any errors that are found
    int lineCount = 0;
    string line;

    // Read input until file is empty
    while (!input.eof()) {
        lineCount++;
        // Pull one line, representing a single command, from the input file
        getline(input, line);

        // Skip the rest of this while loop iteration if an empty line is found
        if (line == "") {
            continue;
        }

        // Constmovieruct a Transaction object using the transaction factory
        Transaction* t = transFac.createTransaction(line, this->inventory,
                                                    this->customers); 
        // Only insert the Transaction object into the transactions field if
        // a valid input was provided 
        if (t != NULL) {
            // If transaction is an invalid Return, do not add it to the 
            // transaction list
            if (t->getTransactionType() == "Return" && !this->validReturn(t)) {
                cout << "ERROR: Invalid return on line: " << lineCount << endl;
                delete t;
                t == NULL;
            } else {
                this->transactions.push_back(t);
            } 
        } else {
            cout << lineCount << endl;
        }

    }
}

/**
 * public executeCommands
 * Reads through the transactions field and executes each transaction found
 */
void Store::executeCommands() {
    // Banner used for output formatting
    string banner = "---------------------------------------------------------";
    cout << "Executing transactions...\n" << endl;
    // Bool representing if headers for borrow/return transactions have been
    // printed to the screen
    bool headersPrinted = false;

    // Iterate through each transaction in this->transactions
    for (Transaction* t : this->transactions) {
        // If transaction is inventory or history, execute transaction
        // If transaction is borrow or return, ensure that table headers
        // have been printed before calling are printed
        // before executing transaction
        if (t->getTransactionType() == "Inventory" 
            || t->getTransactionType() == "History") {
            cout << "\n";
            t->doTransaction();
            // Set headers to false, as the list is no longer iterating through
            // borrow/return objects
            headersPrinted = false;
        } else if (!headersPrinted) {
            cout << banner << banner << endl;
            // Print header columns for borrow/return transaction data
            printElement("Borrow/Return", 20);
            printElement("Customer Info", 40);
            printElement("Movie Info", 30);
            printElement("Current movie stock", 0);
            cout << "\n" << endl;
            headersPrinted = true;
            t->doTransaction();
        } else {
            // If headers are currently printed, then list is iterating through
            // borrow/returning objects
            t->doTransaction();
        }
    }
}

/**
 * private validReturn
 * Checks if the passed Return object is valid by counting the number of 
 * borrow & return transactions relating to the specified movie
 * in a customer's history. 
 * @param[in] Transaction* : The return object to be checked
 * @return bool : Will return true if the customer has borrowed the movie more 
 *                times than they have returned it
 */
bool Store::validReturn(Transaction* currentTransaction) {
    // Cast the passed Transaction object as a return to gain access to 
    // movie field
    const Return* currentR = static_cast<const Return*>(currentTransaction);
    int movieCount = 0;

    // Iterate through each transaction in this->transactions
    for (const Transaction* t : this->transactions) {
        if (t->getTransactionType() == "Borrow") {
            const Borrow* b = static_cast<const Borrow*>(t);
            // Before adding to movieCount, ensure that the Borrow found was
            // made by the correct Customer for the correct Movie
            if ((b->getMovie() == currentR->getMovie()) 
                && (b->getCustomer()->getCustomerID() 
                == currentR->getCustomer()->getCustomerID())) {
                movieCount++;
            }
        } else if (t->getTransactionType() == "Return") {
            const Return* r = static_cast<const Return*>(t);
            // Before subtracting from movieCount, ensure that the Return found
            // was made by the correct Customer for the correct Movie
            if ((r->getMovie() == currentR->getMovie())
                && (r->getCustomer()->getCustomerID() 
                == currentR->getCustomer()->getCustomerID())) {
                movieCount--;
            }
        }
    }
    return (movieCount > 0);
}