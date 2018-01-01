#include <iostream>
#include <assert.h>
#include <ctype.h>
#include "exprtree.h"

using namespace std;
ExprTreeNode * temp;		// copysub 전역변수

//--------------------------------------------------------------------

ExprTreeNode::ExprTreeNode(char elem, ExprTreeNode *leftPtr, ExprTreeNode *rightPtr)
	: element(elem),
	left(leftPtr),
	right(rightPtr)
{}

//--------------------------------------------------------------------
// Constructor : 빈 Expression Tree 생성

ExprTree::ExprTree()
	: root(0)
{}

//--------------------------------------------------------------------
// Destructor : Expression Tree 소멸

ExprTree::~ExprTree()
{
	clear();
}

//--------------------------------------------------------------------
//In-Lab. 2

// Copy Constructor
ExprTree::ExprTree(const ExprTree &valueTree)
{
	temp = valueTree.root;		// 복사할 트리의 root저장
	copySub(root);
}

//--------------------------------------------------------------------

void ExprTree::copySub(ExprTreeNode *&p)
{
	ExprTreeNode *a;			// 임시변수 
	while (temp != 0)
	{
		a = new ExprTreeNode(temp->element, 0, 0);
		p = a;

		ExprTreeNode * keep = temp;			// temp 노드 저장

		temp = temp->right;
		copySub(p->right);					// p->right 재귀호출

		temp = keep->left;
		copySub(p->left);					// p->left 재귀호출
	}
}

//--------------------------------------------------------------------
// prefix를 이용해 산술식을 읽고 Expression Tree 생성
	// prefix : 연산자가 제일 앞에 오고 피연산자가 뒤에 위치하는 표기법 (+ab)
	//			root부터 시작해서 왼쪽, 오른쪽 차례로 검색

void ExprTree::build()
{
	buildSub(root);
}

//--------------------------------------------------------------------
// build 재귀 함수
// Builds a subtree and sets p to point to its root

void ExprTree::buildSub(ExprTreeNode *&p)
{
	char ch;							// 연산자, 숫자 입력을 위한 char변수 선언

	cin >> ch;							// ch 입력받음
	p = new ExprTreeNode(ch, 0, 0);		// new 노드 생성, p와 노드 연결

	if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))		// 입력받은 ch가 연산자일 때
	{																	// tree build 계속
		buildSub(p->left);				// build the left branch
		buildSub(p->right);				// build the right branch
	}
}

//--------------------------------------------------------------------
// infix 형태로 출력
	// infix : 연산자를 중심으로 양쪽에 피연산자가 위치하는 표기법 (a+b)
	//			왼쪽->root->오른쪽 차례로 검색

void ExprTree::expression() const
{
	exprSub(root);
}

//--------------------------------------------------------------------
// expression 재귀 함수
// Outputs the subtree pointed to by p

void ExprTree::exprSub(ExprTreeNode *p) const
{
	if ((p->element >= '0') && (p->element <= '9'))		// element가 숫자일 때
	{
		cout << p->element;								// element출력
		return;
	}

	// element가 연산자일 때
	if ((p->element == '+') || (p->element == '-') || (p->element == '*') || (p->element == '/'))
	{
		cout << '(';
		exprSub(p->left);									// p->left 재귀호출
		cout << p->element;									// element 출력
		exprSub(p->right);									// p->right 재귀호출
		cout << ')';
	}
}

//--------------------------------------------------------------------
// 해당하는 산술식의 값 반환

float ExprTree::evaluate() const
{
	if (root != 0)
		return evaluateSub(root);
}

//--------------------------------------------------------------------
// evaluate 재귀 함수
// Returns the value of subtree pointed to by p

float ExprTree::evaluateSub(ExprTreeNode *p) const
{
	float a, b, result;										// 계산을 위해 float형식 변수 선언

	if ((p->element >= '0') && (p->element <= '9'))			// element가 숫자일 때
	{
		result = p->element - '0';							// char값을 숫자로 변환
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
			if (b == 0)										// 0으로 나눴을 때 예외처리
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
// 초기화 : Expression Tree의 모든 노드 삭제

void ExprTree::clear()
{
	clearSub(root);
	root = 0;
}

//--------------------------------------------------------------------
// clear 재귀 함수

void ExprTree::clearSub(ExprTreeNode *p)
{
	if (p != 0)
	{
		clearSub(p->left);			// p->left 재귀호출
		clearSub(p->right);			// p->right 재귀호출
		delete p;					// 노드 p 제거
		p = 0;						// p초기화
	}
}

//--------------------------------------------------------------------
// Expression Tree 출력

void ExprTree::showStructure() const
{
	if (root == 0)
		cout << "Empty Tree" << endl;
	else
	{
		cout << endl;
		showSub(root, 1);			// showSub 재귀호출
		cout << endl;
	}
}

//--------------------------------------------------------------------
// showStructure 재귀 함수

void ExprTree::showSub(ExprTreeNode *p, int level) const
{
	int j;										// loop counter

	if (p != 0)
	{
		showSub(p->right, level + 1);			// right subtree 출력
		for (j = 0; j < level; j++)
			cout << "\t";
		cout << " " << p->element;				// element 출력
		if ((p->left != 0) && (p->right != 0))
			cout << "<";
		else if (p->right != 0)
			cout << "/";
		else if (p->left != 0)
			cout << "\\";
		cout << endl;
		showSub(p->left, level + 1);			// left subtree 출력
	}
}

