//--------------------------------------------------------------------
//
//                                                       listarr.cpp
//
//  SOLUTION: Array implementation of the List ADT
//
//--------------------------------------------------------------------


#include "listarr.h"

using namespace std;

//--------------------------------------------------------------------

List::List(int maxNumber)

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

List:: ~List()

// Frees the memory used by a list.

{
	// pre-lab
	delete[] dataItems;
}

//--------------------------------------------------------------------
//데이타추가
void List::insert(const DataType &newDataItem)
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
	else
	{
		cout << "List is Full" << endl;
	}
}

//--------------------------------------------------------------------
//데이타제거
void List::remove() throw (logic_error)

// Removes the data items  marked by the cursor from a list. Moves the
// cursor to the next data item item in the list. Assumes that the
// first list data items "follows" the last list data item.

{
	// pre-lab
	//	dataItems[cursor] = NULL;

	/*
	if (size != 0)
	{
	for (int i = cursor; i < size; i++)
	{
	dataItems[i] = dataItems[i + 1];
	}
	size--;
	cursor--;
	}
	else
	cursor++;*/

	if (size == 0)
	{
		cout << "지울거 없음" << endl;
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

void List::replace(const DataType &newDataItem)
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
void List::clear()

// Removes all the data items from a list.

{
	// pre-lab
	for (int i = 0; i < size; i++)
		dataItems[i] = NULL;
	size = 0;
	cursor = -1;
}

//--------------------------------------------------------------------
//리스트가 비었는지 확인
bool List::isEmpty() const

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
bool List::isFull() const

// Returns 1 if a list is full. Otherwise, returns 0.

{
	// pre-lab
	if (size == maxSize)
		return true;
	else if (size > maxSize)
		return false;
}

//--------------------------------------------------------------------
//시작지점으로
int List::gotoBeginning() throw (logic_error)

// Moves the cursor to the beginning of the list.

{
	// pre-lab
	if (maxSize > 0)
	{
		cursor = 0;
		return true;
	}
}



//--------------------------------------------------------------------
//끝지점으로
int List::gotoEnd() throw (logic_error)

// Moves the cursor to the end of the list.

{
	// pre-lab
	if (maxSize > 0)
	{
		cursor = size - 1;
		return true;
	}
}

//--------------------------------------------------------------------
//다음으로
bool List::gotoNext() throw (logic_error)

// If the cursor is not at the end of a list, then moves the
// cursor to the next item in the list and returns true. Otherwise,
// returns false.

{
	// pre-lab
	if (dataItems[cursor + 1] != NULL)
	{
		cursor++;
		return true;
	}
	else
		return false;
}

//--------------------------------------------------------------------
//앞으로
bool List::gotoPrior() throw (logic_error)

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
DataType List::getCursor() const throw (logic_error)

// Returns the item marked by the cursor.

{
	// pre-lab
	if (size > 0)
		return dataItems[cursor];
}

//--------------------------------------------------------------------

void List::showStructure() const

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
			cout << i << "-data : " << dataItems[i] << endl;
		}
	}
	cout << "Current cursor pointed" << cursor << endl;
}

//////////////////////////////////////////////////////////
// test4.cpp에 M을 명령했을 때 불러올 case를 지정해 준다
// Move data item to n
void List::moveToNth(int n) throw (logic_error)
{
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
}