#include <assert.h>
#include "bstree.h"
#include <iostream>
#include <algorithm>

//--------------------------------------------------------------------

template <class TE, class KF>
BSTreeNode<TE,KF>::BSTreeNode(const TE &elem,
	BSTreeNode<TE,KF> *leftPtr, BSTreeNode<TE,KF> *rightPtr)
	: element(elem),
	left(leftPtr),
	right(rightPtr)
{}

//--------------------------------------------------------------------
// Constructor

template <class TE, class KF>
BSTree<TE,KF>::BSTree()
	: root(0)
{}

//--------------------------------------------------------------------
// Destructor

template <class TE, class KF>
BSTree<TE, KF>::~BSTree()
{
	clear();
}

//--------------------------------------------------------------------
// Inserts newElement into a binary search tree.
// If an element with the same key as newElement already exists in the tree,
// then updates that data item's nonkey fields with newElement's nonkey fields.

template <class TE, class KF>
void BSTree<TE, KF>::insert(const TE &newElement)
{
	insertSub(root, newElement);
}

//--------------------------------------------------------------------
// Recursive partner of the insert() function
// Inserts newElement in the SubTree pointed to by p

template <class TE, class KF>
void BSTree<TE, KF>::insertSub(BSTreeNode<TE, KF> *&p, const TE &newElement)
{
	if (p == 0)
		p = new BSTreeNode<TE, KF>(newElement, 0, 0);
	else if (newElement.key() < p->element.key())
		insertSub(p->left, newElement);
	else if (newElement.key() > p->element.key())
		insertSub(p->right, newElement);
	else
		p->element = newElement;
}

//--------------------------------------------------------------------
// Searches a BSTree for the data item with key searchKey.
// If the element is found, then copies the element to searchElement and returns true.
// Otherwise, returns false with searchElement undefined.

template <class TE, class KF>
int BSTree<TE, KF>::retrieve(KF searchKey, TE &searchElement) const
{
	return retrieveSub(root, searchKey, searchElement);
}

//--------------------------------------------------------------------
// recursive partner of retrieve

template <class TE, class KF>
int BSTree<TE, KF>::retrieveSub(BSTreeNode<TE, KF> *p, KF searchKey, TE &searchElement) const
{
	if (p == 0)
		return 0;
	else if (searchKey < p->element.key())
		retrieveSub(p->left, searchKey, searchElement);
	else if (searchKey > p->element.key())
		retrieveSub(p->right, searchKey, searchElement);
	else
	{
		searchElement = p->element;
		return 1;
	}
}

//--------------------------------------------------------------------
// Removes the element with key deleteKey from a BSTree.
// If the element is found, then deletes it from the tree and returns true(1).
// Otherwise, returns false(0).

template <class TE, class KF>
int BSTree<TE, KF>::remove(KF deleteKey)
{
	return removeSub(root, deleteKey);
}

//--------------------------------------------------------------------
// recursive partner of remove

template <class TE, class KF>
int BSTree<TE, KF>::removeSub(BSTreeNode<TE, KF> *&p, KF deleteKey)
{
	int result;
	BSTreeNode<TE, KF> *delPtr;
	
	if (p == NULL)
		result = 0;
	else if (deleteKey < p->element.key())
		result = removeSub(p->left, deleteKey);
	else if (deleteKey > p->element.key())
		result = removeSub(p->right, deleteKey);
	else {
		delPtr = p;
		if (p->left == NULL)
			p = p->right;
		else if (p->right == NULL)
			p = p->left;
		else
			cutRightmost(p->left, delPtr);

		delete delPtr;
		result = 1;
	}
	return 1;
}

//--------------------------------------------------------------------
// 가장 큰 값 삭제

template<class TE, class KF>
void BSTree<TE, KF>::cutRightmost(BSTreeNode<TE, KF> *&r, BSTreeNode<TE, KF> *&delPtr)
{
	if (r->right != 0)
		cutRightmost(r->right, delPtr);
	else {
		delPtr->element = r->element;
		delPtr = r;
		r = r->left;
	}
}

//--------------------------------------------------------------------
// Outputs the keys of the BSTree in ascending order
// 오름차순 정렬

template <class TE, class KF>
void BSTree<TE, KF>::writeKeys() const
{
	if (root == NULL)
		cout << "Empty tree" << endl;
	else
		writeKeysSub(root);
}

//--------------------------------------------------------------------
// recursive partner of writeKeys

template <class TE, class KF>
void BSTree<TE, KF>::writeKeysSub(BSTreeNode<TE, KF> *p) const
{
	if (p != NULL)
	{
		writeKeysSub(p->left);
		cout << p->element.key() << "\t";
		writeKeysSub(p->right);
	}
}

//--------------------------------------------------------------------
// Removes all the nodes from a BSTree

template <class TE, class KF>
void BSTree<TE, KF>::clear()
{
	clearSub(root);
	root = 0;
}

//--------------------------------------------------------------------
// recursive partner of clear

template <class TE, class KF>
void BSTree<TE, KF>::clearSub(BSTreeNode<TE, KF> *p)
{
	if (p != NULL)
	{
		clearSub(p->left);
		clearSub(p->right);
		delete p;
	}
}

//--------------------------------------------------------------------
// Returns true if a tree is empty, otherwise returns false

template <class TE, class KF>
int BSTree<TE, KF>::empty() const
{
	return (root == 0);
}

//--------------------------------------------------------------------
// Returns true if a tree is full, otherwise returns false

template <class TE, class KF>
int BSTree<TE, KF>::full() const
{
	return 0;
}

//--------------------------------------------------------------------
// Outputs the keys in the BSTree

template <class TE, class KF>
void BSTree<TE, KF>::showStructure() const
{
	if (root == 0)
		cout << "Empty tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);
		cout << endl;
	}
}

//--------------------------------------------------------------------
// recursive partner of showStructure

template <class TE, class KF>
void BSTree<TE, KF>::showSub(BSTreeNode<TE, KF> *p, int level) const
{
	int j;

	if (p != 0)
	{
		showSub(p->right, level + 1);
		for (j = 0; j < level; j++)
			cout << "\t";
		cout << " " << p->element.key();

		if ((p->left != 0) && (p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";

		cout << endl;
		showSub(p->left, level + 1);
	}
}

//--------------------------------------------------------------------
// In-lab operations

// bstree height = longest path from the node to a leaf node

template <class TE, class KF>
int BSTree<TE, KF>::height() const
{
	return heightSub(root);
}

//--------------------------------------------------------------------
//recursive partner of height

template <class TE, class KF>
int BSTree<TE, KF>::heightSub(BSTreeNode<TE, KF> *p) const
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(heightSub(p->left), heightSub(p->right));
}

//--------------------------------------------------------------------
// print when the key is smaller than searchKey

template <class TE, class KF>
void BSTree<TE, KF>::writeLessThan(KF searchKey) const
{
	writeLTSub(root, searchKey);
	cout << endl;
	cout << endl;
}

//--------------------------------------------------------------------
// recursive partner of writeLessThan

template <class TE, class KF>
void BSTree<TE, KF>::writeLTSub(BSTreeNode<TE, KF> *p, KF searchKey) const
{
	if (p != NULL){
		if (p->left != NULL)
			writeLTSub(p->left, searchKey);
		if (p->element.key() <= searchKey)
			cout << p->element.key() << "\t";
		if (p->right != NULL)
			writeLTSub(p->right, searchKey);
	}
}
