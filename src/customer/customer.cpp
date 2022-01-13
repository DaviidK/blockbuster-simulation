// -------------------------------- customer.h ---------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements the creation of a customer object. Contains 
// information about the customer as well as the movies they have checked out
// and their transaction history
// -----------------------------------------------------------------------------
// Assumptions:
//  - Input provided to the constructor will be given in the form of: 
//      customerID# (int) lastName (string) firstName (string)

#include "customer.h"

//---------------------------------------------------Constructors and Destructor
/**
 * Constructor
 * Creates a Customer Object using the given input parameter.
 * @param[in] string input : with format <customerID#> <lastName> <firstName>
 */
Customer::Customer(string input) {
    stringstream data(input);
    data >> this->customerID;
    if (data.fail()) {
        this->customerID = -1; 
        this->lastName = "";
        this->firstName = "";
        return;
    }
    data >> this->lastName;
    data >> this->firstName;
}

/**
 * Destructor
 * Destroys a Customer object.
 */
Customer::~Customer() {}

//---------------------------------------------------------Public member methods
/**
 * public getCustomerID
 * Returns the customerID field
 * @return int : Customer ID
 */
int Customer::getCustomerID() const {
    return this->customerID; 
}

/**
 * public getCustomerName
 * Returns the fistName and lastName fields combined
 * @return int : Customer ID
 */
string Customer::getCustomerName() const {
    return this->firstName + " " + this->lastName; 
}

/**
 * public getCustomerID
 * Returns the customerID field
 * @return vector<const Transaction*> : List of Customer Transactions
 */
vector<const Transaction*> Customer::getTransactionHistory() const {
    return this->transactionHistory; 
}

/**
 * public addToHistory
 * Adds a Transaction object to the end of the transactionHistory field
 * @param[in] Transaction* t : To be added to Customer Transaction 
*/
void Customer::addToHistory(const Transaction* t) {
    this->transactionHistory.push_back(t);
}