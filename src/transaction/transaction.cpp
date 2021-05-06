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
 * Default Constructor: Creates an empty Transaction object
 * @param[in]: None
 * @return[out]: None
*/
Transaction::Transaction() { 
    this.transactionType = "";
} 

/**
 * Destructor: Destroys a Transaction object
 * @param[in]: None
 * @return[out]: None
*/
Transaction::~Transaction() {} 

//---------------------------------------------------------Public member methods
/**
 * doTransaction: Virtual method which is overriden by Transaction subclasses. 
   Will execute differently depending on what kind of Transaction object is 
   instantiated
 * @param[in]: None
 * @return[out]: None
*/
void Transaction::doTransaction() const {}