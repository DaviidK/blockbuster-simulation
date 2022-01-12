// ----------------------------- transaction.cpp -------------------------------
// David Kang
// -----------------------------------------------------------------------------
// Purpose: This class implements an interface for a single transaction. The
// object created from this class may be related to Movie, Store, or Customer 
// objects depending on which type of Transaction object is instantiated.
// -----------------------------------------------------------------------------
// Assumptions:
//  - All input data will be provided in the format required by the associated 
//    Transaction class


#include "transaction.h"

//---------------------------------------------------Constructors and Destructor
/**
 * Default Constructor
 * Creates an empty Transaction object
 */
Transaction::Transaction() { 
    this->transactionType = "";
} 

/**
 * virtual Destructor
 * Destroys a Transaction object
 */
Transaction::~Transaction() {} 

//---------------------------------------------------------Public member methods
/**
 * public virtual doTransaction
 * Virtual method which is overriden by Transaction subclasses
 * Will execute differently depending on what kind of Transaction object is 
 * instantiated
 */
void Transaction::doTransaction() const {}

/**
 * public getTransactionType
 * Returns transaction type
 * @return string : transaction type
 */
string Transaction::getTransactionType() const {
    return this->transactionType;
}