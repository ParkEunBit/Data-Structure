//--------------------------------------------------------------------
//
//  Laboratory 4                                         OrderedList.h
//
//  Class declaration for the array implementation of the Ordered
//  List ADT -- inherits the array implementation of the List ADT
//  (Laboratory 3)
//
//--------------------------------------------------------------------

#ifndef ORDEREDLIST_H
#define ORDEREDLIST_H

#include <stdexcept>
#include <iostream>

using namespace std;

#include "ListArray.cpp"

template < typename DataType, typename KeyType >
class OrderedList : public List<DataType>
{
  public:
     static const int DEFAULT_MAX_LIST_SIZE = 10;

    // Constructor
    OrderedList ( int maxNumber = DEFAULT_MAX_LIST_SIZE );

    // Modified (or new) list manipulation operations
    virtual void insert ( const DataType &newDataItem ) throw ( logic_error );
    virtual void replace ( const DataType &newDataItem ) throw ( logic_error );
    bool retrieve ( const KeyType& searchKey, DataType &searchDataItem );

    // Output the list structure -- used in testing/debugging
    void showStructure () const;

    // In-lab operations
    void merge ( const OrderedList<DataType,KeyType> &other ) throw ( logic_error );

  private:

    // Locates an element (or where it should be) based on its key
    bool binarySearch ( KeyType searchKey, int &index );

};

#endif // #ifndef ORDEREDLIST_H

