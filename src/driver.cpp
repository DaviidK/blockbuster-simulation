// ------------------------------- driver.cpp ----------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This code tests the functionality of the movie store program by 
// providing movie, customer, and transaction information through input files.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input files are formatted as required by their respective object
//    classes

#include "movie/movie.h"
#include "customer/customer.h"
#include "store/store.h"
#include "support/hashtable.h"
#include "transaction/transaction.h"
#include <string>

int main() {
    // String used to improve output readability
    string banner = "\n=======================================================";
    banner += "=============================================================\n";

    // File locations where input will be read from
    string movieFile = "../input/data4movies.txt";
    string customerFile = "../input/data4customers.txt";
    string commandFile = "../input/data4commands.txt";

    // Checking to ensure all files could be found
    ifstream data4movies(movieFile);
    if (!data4movies) {
      cout << "File: data4movies could not be opened." << endl;
      return 1;
    }
    ifstream data4customers(customerFile);
    if (!data4customers) {
        cout << "File: data4customers could not be opened." << endl;
        return 1;
    }
    ifstream data4commands(commandFile);
    if (!data4commands) {
        cout << "File: data4commands could not be opened." << endl;
        return 1;
    }

    cout << "Beginning movie store simulator. Current filepaths are:\n" << endl;
    cout << "Movie file: \t" << movieFile << endl;
    cout << "Customer file:\t" << customerFile << endl;
    cout << "Command file:\t" << commandFile << endl;
    cout << banner;

    // Beginning the movie store simulation
    Store redBox = Store("RedBox");
    redBox.populateInventory(data4movies);
    cout << banner;
    redBox.populateCustomers(data4customers);
    cout << banner;
    redBox.populateCommands(data4commands);
    cout << banner;
    redBox.executeCommands();
    return 0;
}