#include <iostream>
#include <assert.h>
#include <ctype.h>
#include "exprtree.h"

using namespace std;
ExprTreeNode * temp;		// copysub ��������

//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr)
	: element(elem),
	left(leftPtr),
	right(rightPtr)
{}

//--------------------------------------------------------------------
// Constructor : �� Expression Tree ����

ExprTree::ExprTree()
	: root(0)
{}

//--------------------------------------------------------------------
// Destructor : Expression Tree �Ҹ�

ExprTree::~ExprTree()
{
	clear();
}

//--------------------------------------------------------------------
//In-Lab. 2

// Copy Constructor
ExprTree::ExprTree(const ExprTree &valueTree)
{
	temp = valueTree.root;		// ������ Ʈ���� root����
	copySub(root);
}

//--------------------------------------------------------------------

void ExprTree::copySub(ExprTreeNode *&p)
{
	ExprTreeNode *a;			// �ӽú��� 
	while (temp != 0)
	{
		a = new ExprTreeNode(temp->element, 0, 0);
		p = a;

		ExprTreeNode * keep = temp;			// temp ��� ����

		temp = temp->right;
		copySub(p->right);					// p->right ���ȣ��

		temp = keep->left;
		copySub(p->left);					// p->left ���ȣ��
	}
}

//--------------------------------------------------------------------
// prefix�� �̿��� ������� �а� Expression Tree ����
	// prefix : �����ڰ� ���� �տ� ���� �ǿ����ڰ� �ڿ� ��ġ�ϴ� ǥ��� (+ab)
	//			root���� �����ؼ� ����, ������ ���ʷ� �˻�

void ExprTree::build()
{
	buildSub(root);
}

//--------------------------------------------------------------------
// build ��� �Լ�
// Builds a subtree and sets p to point to its root

void ExprTree::buildSub(ExprTreeNode *&p)
{
	char ch;							// ������, ���� �Է��� ���� char���� ����

	cin >> ch;							// ch �Է¹���
	p = new ExprTreeNode(ch, 0, 0);		// new ��� ����, p�� ��� ����

	if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))		// �Է¹��� ch�� �������� ��
	{																	// tree build ���
		buildSub(p->left);				// build the left branch
		buildSub(p->right);				// build the right branch
	}
}

//--------------------------------------------------------------------
// infix ���·� ���
	// infix : �����ڸ� �߽����� ���ʿ� �ǿ����ڰ� ��ġ�ϴ� ǥ��� (a+b)
	//			����->root->������ ���ʷ� �˻�

void ExprTree::expression() const
{
	exprSub(root);
}

//--------------------------------------------------------------------
// expression ��� �Լ�
// Outputs the subtree pointed to by p

void ExprTree::exprSub(ExprTreeNode *p) const
{
	if ((p->element >= '0') && (p->element <= '9'))		// element�� ������ ��
	{
		cout << p->element;								// element���
		return;
	}

	// element�� �������� ��
	if ((p->element == '+') || (p->element == '-') || (p->element == '*') || (p->element == '/'))
	{
		cout << '(';
		exprSub(p->left);									// p->left ���ȣ��
		cout << p->element;									// element ���
		exprSub(p->right);									// p->right ���ȣ��
		cout << ')';
	}
}

//--------------------------------------------------------------------
// �ش��ϴ� ������� �� ��ȯ

float ExprTree::evaluate() const
{
	if (root != 0)
		return evaluateSub(root);
}

//--------------------------------------------------------------------
// evaluate ��� �Լ�
// Returns the value of subtree pointed to by p

float ExprTree::evaluateSub(ExprTreeNode *p) const
{
	float a, b, result;										// ����� ���� float���� ���� ����

	if ((p->element >= '0') && (p->element <= '9'))			// element�� ������ ��
	{
		result = p->element - '0';							// char���� ���ڷ� ��ȯ
		return result;
	}

	else
	{
		a = evaluateSub(p->left);
		b = evaluateSub(p->right);

		switch (p->element)
		{
		case'+':											// addition
			result = a + b;	return result; break;
		case'-':											// subtraction
			result = a - b;	return result; break;
		case'*':											// multiplication
			result = a * b;	return result; break;
		case'/':											// division
		{
			if (b == 0)										// 0���� ������ �� ����ó��
				cout << " false" << endl;
			else
			{
				result = a / b;
				return result;
			}
			break;
		}
		}
	}
}

//--------------------------------------------------------------------
// �ʱ�ȭ : Expression Tree�� ��� ��� ����

void ExprTree::clear()
{
	clearSub(root);
	root = 0;
}

//--------------------------------------------------------------------
// clear ��� �Լ�

void ExprTree::clearSub(ExprTreeNode *p)
{
	if (p != 0)
	{
		clearSub(p->left);			// p->left ���ȣ��
		clearSub(p->right);			// p->right ���ȣ��
		delete p;					// ��� p ����
		p = 0;						// p�ʱ�ȭ
	}
}

//--------------------------------------------------------------------
// Expression Tree ���

void ExprTree::showStructure() const
{
	if (root == 0)
		cout << "Empty Tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);			// showSub ���ȣ��
		cout << endl;
	}
}

//--------------------------------------------------------------------
// showStructure ��� �Լ�

void ExprTree::showSub(ExprTreeNode *p, int level) const
{
	int j;										// loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);			// right subtree ���
		for (j = 0; j < level; j++)
			cout << "\t";
		cout << " " << p->element;				// element ���
		if ((p->left != 0) && (p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);			// left subtree ���
	}
}

