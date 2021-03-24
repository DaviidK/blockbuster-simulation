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