//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueArr.cpp
//
//  SOLUTION: Array implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queuearr.h"

//--------------------------------------------------------------------

template < class QE >
Queue<QE>::Queue(int maxNumber)

// Creates an empty queue. Allocates enough memory for maxNumber
// elements (defaults to defMaxQueueSize).

: maxSize(maxNumber),
front(-1),
rear(-1)
{
	// pre-lab (Array)
	element = new QE[maxNumber];
}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	// pre-lab (Array)
	delete[] element;
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	// pre-lab (Array)
	if (full())
		cout << "Queue is full" << endl;
	else if (!full())
	{
		if (empty())
		{
			front = 0;
			rear = 0;
		}
		else
		{
			++rear;

			if (rear == maxSize)
				rear = 0;
		}
		element[rear] = newElement;
	}
}

//--------------------------------------------------------------------

template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently added (front) element from a queue and
// returns it.

{
	// pre-lab (Array)
	int return_location = front;

	if (empty())
		cout << "Queue is empty" << endl;
	else
	{
		++front;

		if (front == maxSize)
			front = 0;

		if ((front == 0) && (rear == (maxSize - 1)) || (front == rear + 1))
		{
			front = -1;
			rear = -1;
		}
		return element[return_location];
	}
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	// pre-lab (Array)
	front = -1;
	rear = -1;
}

//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	// pre-lab (Array)
	return (front == -1);
}

//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::full() const

// Returns 1 if a queue is full. Otherwise, returns 0.

{
	return ((rear + 1) % maxSize == front);
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::showStructure() const

// Array implementation. Outputs the elements in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
	int j;   // Loop counter

	if (front == -1)
		cout << "Empty queue" << endl;
	else
	{
		cout << "front = " << front << "  rear = " << rear << endl;
		for (j = 0; j < maxSize; j++)
			cout << j << "\t";
		cout << endl;

		// pre-lab (Array)
		if (front <= rear)
		{
			for (j = 0; j < maxSize; j++)
			{
				if ((j >= front) && (j <= rear))
					cout << element[j] << "\t";
				else
					cout << "\t";
			}
		}
		else
			for (j = 0; j < maxSize; j++)
			{
				if ((j >= front) || (j <= rear))
					cout << element[j] << "\t";
				else
					cout << "\t";
			}
		cout << endl;
	}
}

template < class QE >
void Queue<QE>::putFront(const QE &newDataItem){
	//In-Lab. 2
	
	if (full())
		cout << "Queue is full" << endl;
	else
	{
		if (empty())
		{
			enqueue(newDataItem);
			front = maxSize - 1;
		}
		else
		{
			element[front] = newDataItem;
			--front;
		}
	}
	
	
}

template < class QE >
QE Queue<QE>::getRear(){
	//In-Lab. 2
	int return_location = -1;

	if (empty())
		cout << "Queue is empty" << endl;
	else
	{
		return_location = rear;

		//Queue에 1개의 아이템만 들어있을 때
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		//1개 이상이 들어있을 때
		else
		{
			--rear;

			if (rear < 0)
				rear = maxSize - 1;
		}
		return element[return_location];
	}
}

template < class QE >
int Queue<QE>::getLength(){
	//In-Lab. 3
	int length = 0;

	if (empty())
		length = 0;
	else if (front <= rear)
		length = (rear - front) + 1;
	else if (front > rear)
		length = (maxSize - front) + (rear + 1);

	return length;
}
