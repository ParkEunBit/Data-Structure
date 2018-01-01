#include "ptyQueue.h"

//--------------------------------------------------------------------
// Constructor

template < class DT >
PtyQueue<DT>::PtyQueue(int maxNumber = defMaxQueueSize)
{
//	maxSize = maxNumber;
//	size = 0;
//	element = new DT[maxSize];
}

//--------------------------------------------------------------------
// insert element

template < class DT >
void PtyQueue<DT>::enqueue(const DT &newDataItem)
{
	insert(newElement);
}

//--------------------------------------------------------------------
// removes the highest priority item

template < class DT >
DT PtyQueue<DT>::dequeue()
{
	removeMax();
}