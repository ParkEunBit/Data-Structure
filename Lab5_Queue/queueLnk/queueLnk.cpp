//--------------------------------------------------------------------
//
//  Laboratory 6                                        queueLnk.cpp
//
//  SOLUTION: Linked list implementation of the Queue ADT
//
//--------------------------------------------------------------------

#include <assert.h>
#include "queueLnk.h"

//--------------------------------------------------------------------

template < class QE >
QueueNode<QE>::QueueNode(const QE &elem, QueueNode<QE> *nextPtr)

// Creates a queue node containing element elem and next pointer
// nextPtr.

: element(elem),
next(nextPtr)
{}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>::Queue(int ignored)

// Creates an empty queue. Parameter is provided for compatability
// with the array implementation and is ignored.

: front(0),
rear(0)
{}

//--------------------------------------------------------------------

template < class QE >
Queue<QE>:: ~Queue()

// Frees the memory used by a queue.

{
	// pre-lab (Linked)
	clear();
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::enqueue(const QE &newElement)

// Inserts newElement at the rear of a queue.

{
	// pre-lab (Linked)
	QueueNode<QE>* newnode = NULL;
	
	if (full())
		cout << "Queue is full" << endl;
	/*
	else
	{
		QueueNode<QE>* temp = new QueueNode<QE>(newElement, 0);

		if (empty())
			front = temp;
		else
			rear->next = temp;
	}
	*/
	
	else
	{
		newnode = new QueueNode<QE>(newElement, NULL);

		if (empty())
		{
			front = newnode;
			rear = newnode;
		}
		else
		{
			rear->next = newnode;
			rear = newnode;
		}
		newnode = NULL;
	}
	
}

//--------------------------------------------------------------------

template < class QE >
QE Queue<QE>::dequeue()

// Removes the least recently (front) element from a queue and
// returns it.

{
	// pre-lab (Linked)
	QueueNode<QE>* delete_location = NULL;
	QE the_element;

	if (empty())
		cout << "Queue is empty" << endl;
	else
	{
		delete_location = front;
		the_element = front->element;

		//노드가 1개일 때
		if (front == rear)
		{
			front = NULL;
			rear = NULL;
		}
		//노드가 1개 이상일 때
		else
			front = front->next;

		delete delete_location;			//노드삭제
		delete_location = NULL;			//포인터삭제

		return the_element;
	}
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::clear()

// Removes all the elements from a queue.

{
	// pre-lab (Linked)
	while(!empty())
		dequeue();
}

//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::empty() const

// Returns 1 if a queue is empty. Otherwise, returns 0.

{
	// pre-lab (Linked)
	return front == NULL;
}

//--------------------------------------------------------------------

template < class QE >
int Queue<QE>::full() const
{
	return false;
}

//--------------------------------------------------------------------

template < class QE >
void Queue<QE>::showStructure() const

// Linked list implementation. Outputs the elements in a queue. If
// the queue is empty, outputs "Empty queue". This operation is
// intended for testing and debugging purposes only.

{
	// pre-lab (Linked)
	QueueNode<QE>* p;

	if (empty())
		cout << "Queue is empty" << endl;
	else
	{
		cout << "front" << endl;
		for (p = front; p != 0; p = p->next)
		{
			if (p == front)
				cout << "[" << p->element << "]";
			else
				cout << p->element << " ";
		}
		cout << endl;
	}
}