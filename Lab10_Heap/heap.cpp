#include <stdexcept>
#include <iostream>
#include "heap.h"

using namespace std;

//--------------------------------------------------------------------
// Constructor

template < class HE >
Heap<HE>::Heap(int maxNumber = defMaxHeapSize)
{
	maxSize = maxNumber;
	size = 0;
	element = new HE[maxSize];
}

//--------------------------------------------------------------------
// Destructor

template < class HE >
Heap<HE>::~Heap()
{
	clear();
	delete element;
}

//--------------------------------------------------------------------
// Insert element

template < class HE >
void Heap<HE>::insert(const HE &newElement)
{
	int cursor, index;					// cursor=parent

	if (size >= maxSize)
		cout << "heap is full" << endl;

	index = size;
	cursor = ((size - 1) / 2);			// 현재 index값 구하기

	element[index] = newElement;
	size++;
	if (element[cursor].pty() < element[index].pty())
	{
		HE temp = element[cursor];
		element[cursor] = element[index];
		element[index] = temp;
	}
	

	for (int x = (size - 1); x >= 0; x--)
	{
		int parentx = ((x - 1) / 2);
		if (element[x].pty() > element[parentx].pty())
		{
			HE temp = element[parentx];
			element[parentx] = element[x];
			element[x] = temp;
		}
	}
}

//--------------------------------------------------------------------
// Remove max pty element

template < class HE >
HE Heap<HE> ::removeMax()
{	
	HE removedItem;
	HE temp;
	bool keepFinding = true;
	bool doSwap = false;
	int findCursor = 0;
	int childCursor = 0;

	// heap이 비어있지 않을 때
	if (size != 0)
	{
		removedItem = element[0];					// top item 저장
		element[0] = element[size - 1];				// copy the bottom-right most item to the top
		size--;										// item이 제거될 때 까지 size줄이기

		while (keepFinding)
		{
			// 초기화
			keepFinding = false;
			doSwap = false;

			childCursor = ((2 * findCursor) + 1);	// 첫번째 element 계산

			if (childCursor < size) {
				if (element[childCursor].pty() > element[findCursor].pty())
					doSwap = true;
			}
			if ((childCursor + 1) < size) {
				if (element[childCursor + 1].pty() > element[findCursor].pty())
				{
					doSwap = true;
					if (element[childCursor + 1].pty() > element[childCursor].pty())
						childCursor++;
				}
			}
			if (doSwap)
			{
				temp = element[childCursor];
				element[childCursor] = element[findCursor];
				element[findCursor] = temp;

				findCursor = childCursor;

				keepFinding = true;
			}
		}
	}
	else
		cout << "empty heap" << endl;

	return removedItem;
}

//--------------------------------------------------------------------

template < class HE >
void Heap<HE>::clear()
{
	size = 0;
}

//--------------------------------------------------------------------

template < class HE >
int Heap<HE>::empty() const
{
	return (size == 0);
}

//--------------------------------------------------------------------

template < class HE >
int Heap<HE>::full() const
{
	return (size == maxSize);
}

//--------------------------------------------------------------------

template < class HE >
void Heap<HE>::showStructure() const
{
	cout << endl;

	int j;

	if (size == 0)
		cout << "Empty heap" << endl;
	else
	{
		cout << "size = " << size << endl;       // array로 출력
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;
		for (j = 0; j < size; j++)
			cout << element[j].pty() << "\t";
		cout << endl << endl;

		showSubtree(0, 0);                        // tree로 출력
	}
}

//--------------------------------------------------------------------

template < class HE >
void Heap<HE>::showSubtree(int index, int level) const
{
	if (index < size)
	{
		showSubtree(2 * index + 2, level + 1);			// right subtree 출력

		for (int j = 0; j < level; j++)
			cout << "\t";
		cout << " " << element[index].pty();

		if (2 * index + 2 < size)
			cout << "<";
		else if (2 * index + 1 < size)
			cout << "\\";
		cout << endl;

		showSubtree(2 * index + 1, level + 1);			// left subtree 출력
	}
}
