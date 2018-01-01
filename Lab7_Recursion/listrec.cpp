#include <assert.h>
#include "stacklnk.cpp"
#include "listrec.h"

//--------------------------------------------------------------------

template <class LE>
ListNode<LE>::ListNode(const LE &elem, ListNode<LE> *nextPtr)
	: element(elem),
	next(nextPtr)
{}

//--------------------------------------------------------------------

template <class LE>
List<LE>::List(int ignored)
	: head(0),
	cursor(0)
{}

//--------------------------------------------------------------------

template <class LE>
List<LE>::~List()

{
	clear();
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::insert(const LE &newElement)
{
	if (head == 0)
	{
		head = new ListNode<LE>(newElement, 0);
		cursor = head;
	}

	else
	{
		ListNode<LE> * tmp = new ListNode<LE>(newElement, 0);
		cursor->next = tmp;
		cursor = tmp;
	}
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::clear()
{
	ListNode<LE> *p, *nextP;
	p = head;
	
	while (p != 0)
	{
		nextP = p->next;
		delete p;
		p = nextP;
	}

	head = 0;
	cursor = 0;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::showStructure() const
{
	ListNode<LE> *p;

	if (head == 0)
		cout << "Empty list" << endl;

	else
	{
		for (p = head; p != 0; p = p->next)
			if (p == cursor)
				cout << "[" << p->element << "] ";
			else
				cout << p->element << " ";
		cout << endl;
	}
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::write() const
{
	cout << "List : ";
	writeSub(head);
	cout << endl;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::writeSub(ListNode<LE> *p) const
{
	if (p != 0)
	{
		cout << p->element;
		writeSub(p->next);
	}
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::insertEnd(const LE &newElement)
{
	insertEndSub(head, newElement);
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::insertEndSub(ListNode<LE> *&p, const LE &newElement)
{
	if (p != 0)
		insertEndSub(p->next, newElement);
	else
	{
		p = new ListNode<LE>(newElement, 0);
		cursor = p;
	}
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::writeMirror() const
{
	cout << "Mirror : ";
	writeMirrorSub(head);
	cout << endl;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::writeMirrorSub(ListNode<LE> *p) const
{
	if (p != 0)
	{
		cout << p->element;
		writeMirrorSub(p->next);
		cout << p->element;
	}
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::reverse()
{
	reverseSub(0, head);
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::reverseSub(ListNode<LE> *p, ListNode<LE> *nextP)
{
	if (nextP != 0)
	{
		reverseSub(nextP, nextP->next);
		nextP->next = p;
	}
	else
		head = p;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::deleteEnd()
{
	deleteEndSub(head);
	cursor = head;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::deleteEndSub(ListNode<LE> *&p)
{
	if (p->next != 0)
		deleteEndSub(p->next);
	else
	{
		delete p;
		p = 0;
	}
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::length() const
{
	return lengthSub(head);
}

//--------------------------------------------------------------------

template <class LE>
int List<LE>::lengthSub(ListNode<LE> *p) const
{
	int result;

	if (p == 0)
		result = 0;
	else
		result = (lengthSub(p->next) + 1);
	return result;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::unknown1() const
{
	unknown1Sub(head);
	cout << endl;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::unknown1Sub(ListNode<LE> *p) const
{
	if (p != 0)
	{
		cout << p->element;
		if (p->next != 0)
		{
			unknown1Sub(p->next->next);
			cout << p->next->element;
		}
	}
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::unknown2()
{
	unknown2Sub(head);
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::unknown2Sub(ListNode<LE> *&p)
{
	ListNode<LE> *q;

	if (p != 0 && p->next != 0)
	{
		q = p;
		p = p->next;
		q->next = p->next;
		p->next = q;
		unknown2Sub(q->next);
	}
}

//--------------------------------------------------------------------
// In-lab

template <class LE>
void List<LE>::iterReverse()
{
	ListNode<LE> *trailP;
	ListNode<LE> *nextP;
	ListNode<LE> *p;

	trailP = 0;
	p = head;

	while (p != 0)
	{
		nextP = p->next;
		p->next = trailP;
		trailP = p;
		p = nextP;
	}
	head = trailP;
}

//--------------------------------------------------------------------

template <class LE>
void List<LE>::stackWriteMirror() const
{
	Stack<ListNode<LE>*> tempStack;
	ListNode<LE> *p;

	p = head;
	cout << "stackMirror : ";

	while (p != 0)
	{
		tempStack.push(p);
		cout << p->element;
		p = p->next;
	}
	while (!tempStack.empty())
	{
		p = tempStack.pop();
		cout << p->element;
	}
	cout << endl;
}
