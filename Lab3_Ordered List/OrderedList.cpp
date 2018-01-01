
#include "OrderedList.h"

template < typename DataType, typename KeyType >
OrderedList<DataType, KeyType>::OrderedList(int maxNumber) : List<DataType>(maxNumber)
{
	
}

//데이터추가
template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::insert(const DataType &newDataItem) throw (logic_error)
{
	if (size == 0)
	{
		dataItems[++cursor] = newDataItem;
		size++;
		//cursor = size - 1;
	}
	
	else if (size >= maxSize)
		cout << "List is full" << endl;
	
	else if (size < maxSize)
	{
		int i = 0;
		for (i = 0; i < size; i++)
		{
			if (newDataItem.getKey() < dataItems[i].getKey())
			{
				for (int j = (size+1); j > i; j--)
				{
					dataItems[j].setKey(dataItems[j-1].getKey());
				}
				dataItems[i].setKey(newDataItem.getKey());
				break;
			}
		}
		if (i == size){
			dataItems[i].setKey(newDataItem.getKey());
		}
		size++;
		cursor = size - 1;
	}
}

//데이터교체
template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::replace(const DataType &newDataItem) throw (logic_error)
{
	if (size == 0)
		cout << "List is empty" << endl;

	else if (newDataItem.getKey() == dataItems[cursor].getKey())
		dataItems[cursor] = newDataItem;

	else
	{
		remove();
		insert(newDataItem);
	}
}

//데이터검색
template < typename DataType, typename KeyType >
bool OrderedList<DataType, KeyType>::retrieve(const KeyType& searchKey, DataType &searchDataItem)
{
	int curCursor = cursor;

	bool result = false;

	if (binarySearch(searchKey, curCursor))
	{
		searchDataItem = dataItems[cursor];
		result = true;
	}
	else
	{
		cursor = curCursor;
		result = false;
	}
	return result;
}

template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::showStructure() const
{
	if (size == 0)
		cout << "Empty list" << endl;
	else {
		for (int i = 0; i < size; i++) {
			cout << dataItems[i].getKey() << ", ";
		}
		cout << endl;
		cout << "Current cursor pointed:" << cursor << endl;
	}
}

template < typename DataType, typename KeyType >
bool OrderedList<DataType, KeyType>::binarySearch(KeyType searchKey, int &index)
{
	int low = 0, high = size - 1;	// Low and High index of current search range
	bool result;					// return result

	while (low <= high)
	{
		index = (low + high) / 2;						//중간지점계산

		if (searchKey < dataItems[index].getKey())
			high = index - 1;
		else if (searchKey > dataItems[index].getKey())
			low = index + 1;
		else
			break;
	}

	if (low <= high)
		result = true;
	else
	{
		index = high;
		result = false;
	}
	return result;
}


//In-lab
template < typename DataType, typename KeyType >
void OrderedList<DataType, KeyType>::merge(const OrderedList<DataType, KeyType> &other)
{

	for (int i = 0; i < other.size; i++)
	{
		insert(other.dataItems[i]);
	}
	
	/*
	if (size + other.size > maxSize)
		cout << "oversize" << endl;

	else if (size != 0)
		cursor = 0;
	*/
}