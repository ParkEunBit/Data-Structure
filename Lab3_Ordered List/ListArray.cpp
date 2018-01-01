//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------

#include <stdio.h>
#include "ListArray.h"

using namespace std;

//--------------------------------------------------------------------

typedef char DataType;

template < typename DataType >
List<DataType>::List(int maxNumber)

// Creates an empty list. Allocates enough memory for maxNumber
// data items (defaults to defMaxListSize).

	: maxSize(maxNumber),
	size(0),
	cursor(-1)
{
	// pre-lab
	dataItems = new DataType[maxNumber];
}

//--------------------------------------------------------------------

template < typename DataType >
List<DataType>:: ~List()

// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}


//--------------------------------------------------------------------
// 데이터추가
template < typename DataType >
void List<DataType>::insert(const DataType &newDataItem)
throw (logic_error)

// Inserts newDataItem after the cursor. If the list is empty, then
// newDataItem is inserted as the first (and only) data items in the
// list. In either case, moves the cursor to newDataItem.

{
	// pre-lab

	if (size == 0)
	{
		dataItems[++cursor] = newDataItem;
		size++;
		cursor = size - 1;
	}
	else if (size < maxSize)
	{
		size++;
		dataItems[cursor + 2] = dataItems[cursor + 1];
		dataItems[cursor + 1] = newDataItem;
		cursor++;

	}
	else if (size >= maxSize)
		cout << "List is full" << endl;
}

//--------------------------------------------------------------------
// 데이터 제거
template < typename DataType >
void List<DataType>::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.

{
	// pre-lab
	if (size == 0)
	{
		cout << "data is already empty" << endl;
	}
	else if (size == (cursor + 1))
	{
		size--;
		cursor--;
	}
	else
	{
		for (int i = cursor; i < (size - 1); i++)
		{
			dataItems[i] = dataItems[i + 1];
		}
		size--;
	}
}

//--------------------------------------------------------------------
template < typename DataType >
void List<DataType>::replace(const DataType &newDataItem)
throw (logic_error)

// Replaces the item marked by the cursor with newDataItem and
// leaves the cursor at newDataItem.

{
	// Requires that the list is not empty
	// pre-lab
	if (size != 0)
		dataItems[cursor] = newDataItem;
}

//--------------------------------------------------------------------
//초기화
template < typename DataType >
void List<DataType>::clear()

// Removes all the data items from a list.

{
	// pre-lab
	//	for (int i = 0; i < size; i++)
	//		dataItems[i] = NULL;
	size = 0;
	cursor = -1;
}

//--------------------------------------------------------------------
//리스트가 비었는지 확인
template < typename DataType >
bool List<DataType>::isEmpty() const

// Returns 1 if a list is empty. Otherwise, returns 0.

{
	// pre-lab
	if (size == 0)
		return 1;
	else
		return 0;
}

//--------------------------------------------------------------------
//리스트가 꽉 찼는지 확인
template < typename DataType >
bool List<DataType>::isFull() const

// Returns 1 if a list is full. Otherwise, returns 0.

{
	// pre-lab
	if (size <= maxSize)
		return 1;
	else
		return 0;
}

//--------------------------------------------------------------------
//시작지점으로
template < typename DataType >
void List<DataType>::gotoBeginning() throw (logic_error)

// Moves the cursor to the beginning of the list.

{
	// pre-lab
	if (size > 0)
	{
		cursor = 0;
	}
}



//--------------------------------------------------------------------
//끝지점으로
template < typename DataType >
void List<DataType>::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (size > 0)
	{
		cursor = size - 1;
	}
}

//--------------------------------------------------------------------
//다음으로
template < typename DataType >
bool List<DataType>::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.

{
	// pre-lab
	if (cursor < size)
	{
		cursor++;
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------
//앞으로
template < typename DataType >
bool List<DataType>::gotoPrior() throw (logic_error)

// If the cursor is not at the beginning of a list, then moves the
// cursor to the preceeding item in the list and returns true.
// Otherwise, returns false.

{
	// pre-lab
	if (cursor != 0)
	{
		cursor--;
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------
//위치확인
template < typename DataType >
DataType List<DataType>::getCursor() const throw (logic_error)

// Returns the item marked by the cursor.

{
	// pre-lab
	if (size > 0)
		return dataItems[cursor];
}

//--------------------------------------------------------------------
template < typename DataType >
void List<DataType>::showStructure() const

// Outputs the data items in a list. If the list is empty, outputs
// "Empty list". This operation is intended for testing/debugging
// purposes only.

{
	// pre-lab
	if (size == 0)
		cout << "Empty list" << endl;
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << "-data : " << dataItems[i].getKey() << endl;
		}
	}
	cout << "Current cursor pointed" << cursor << endl;
}


// Copy cursor's data to Nth
template < typename DataType >
void List<DataType>::moveToNth(int n)
{
	if (dataItems[cursor] == NULL)
		cout << "The cursor is pointing at nothing" << endl;
	else if (n >= size)
		cout << "n is bigger than current size" << endl;
	else
		dataItems[n] = dataItems[cursor];

	/*
	if (size < n + 1)
		cout << "Out of bounds" << endl;

	else
	{
		DataType temp;
		temp = getCursor();
		remove();
		gotoBeginning();
		if (n == 0)
		{
			size++;
			for (int i = size - 1; i >= cursor; i--)
				dataItems[i + 1] = dataItems[i];
			dataItems[0] = temp;
		}

		else
		{
			for (int i = 0; i<n - 1; i++)
				gotoNext();
			insert(temp);
		}
	}
	*/
}


