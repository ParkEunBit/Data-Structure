//--------------------------------------------------------------------
//
//  Laboratory 8                                           ListDbl.cpp
//
//--------------------------------------------------------------------

#include <assert.h>
#include "ListDbl.h"

//--------------------------------------------------------------------
// Constructor
template < class LE >
ListNode<LE>::ListNode(const LE &elem, ListNode *priorPtr, ListNode *nextPtr)
	: element(elem),
	prior(priorPtr),
	next(nextPtr)
{}

//--------------------------------------------------------------------
// Constructor
template < class LE >
List<LE>::List(int ignored = 0)
	: head(0),
	cursor(0)
{}

//--------------------------------------------------------------------
// Destructor
template < class LE >
List<LE>::~List()
{
	clear();
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::insert(const LE &newElement)

// Inserts newElement after cursor

{
	ListNode<LE> *newNode;

	if (empty())
	{
		newNode = new ListNode<LE>(newElement, 0, 0);
		newNode->prior = newNode;
		newNode->next = newNode;
		newNode->element = newElement;
		head = newNode;
	}
	else
	{
		newNode = new ListNode<LE>(newElement, cursor, cursor->next);
						// (newElement, newNode->prior = cursor, newNode->next = curosr->next)
		cursor->next->prior = newNode;
		cursor->next = newNode;
	}
	cursor = newNode;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::remove()

// 현재 cursor가 가리키는 element를 지우고 next element로 이동

{
	ListNode<LE> *node;
	node = cursor;

	if (empty())
		cout << "empty list" << endl;

	// element 1개일 때
	else if (head->next == head)
	{
		head = 0;
		cursor = 0;
	}

	else
	{
		if (cursor == head)
		{
			cursor->prior->next = cursor->next;
			cursor->next->prior = cursor->prior;
			head = cursor->next;
			cursor = cursor->next;
		}
		else
		{
			cursor->prior->next = cursor->next;
			cursor->next->prior = cursor->prior;
			cursor = cursor->next;
		}
	}
	delete node;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::replace(const LE &newElement)

// Replace element

{
	if (!empty())
		cursor->element = newElement;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::clear()

{

	while (!empty())
	{
		remove();
	}
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::empty() const
{
	return (head == 0);
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::full() const
{
	return 0;
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::gotoBeginning()
{
	if (!empty())
	{
		cursor = head;
		return 1;
	}
	else
		return 0;
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::gotoEnd()
{
	if (!empty())
	{
		cursor = head->prior;
		return 1;
	}
	else
		return 0;
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::gotoNext()
{
	if (cursor->next != head)
	{
		cursor = cursor->next;
		return 1;
	}
	else
		return 0;
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::gotoPrior()
{
	if (cursor != head)
	{
		cursor = cursor->prior;
		return 1;
	}
	else
		return 0;
}

//--------------------------------------------------------------------

template <class LE>
LE List<LE>::getCursor() const

// Return element

{
	if (!empty())
		return (cursor->element);
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::showStructure() const
{
	ListNode<LE> *node;

	if (empty())
		cout << "empty list" << endl;
	else
	{
		node = head;
		do
		{
			if (node == cursor)
				cout << "[" << node->element << "] ";
			else
				cout << node->element << "  ";
			node = node->next;
		} while (node != head);
		cout << endl;
	}
}

//--------------------------------------------------------------------
// In-lab opertions

template <class LE>
void List<LE>::reverse()
{
	if (head == NULL)
		cout << "empty list" << endl;

	ListNode<LE> *temp, *p;
	temp = head;
	p = head->prior;
	while (temp != p)
	{
		swap(temp->element, p->element);
		temp = temp->next;
		if (temp == p)
			return;
		p = p->prior;
	}
}
