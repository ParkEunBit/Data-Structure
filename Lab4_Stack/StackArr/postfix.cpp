/*
----------------------------
* Name: Song min pyo
* Last modified: 2015-10-16
* content: Calculator
----------------------------
*/
#include "stackarr.cpp"
#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

#define _Maxname 20

void runCalcul();
int Calcul(char* postfix);  //this is function which calculate postfix

int main(void)
{
	cout << "This is calculator" << endl;
	runCalcul();
	return 0;
}

void runCalcul()
{
	char post[_Maxname];                //this is array that allocated the character of postfix

//	char* post = new char[_Maxname];
	double opResult = 0;

	cout << "Please input the postfix: ";
	cin >> post;                         //save the postfix on post array

	opResult = Calcul(post);
}

int Calcul(char *postfix)
{
	Stack<char> stack(8);

	int i = 0;
	char curch = char(4);
	char* post = new char[_Maxname];
	double op1 = -8.88, op2 = -8.88, result = -8.88;


	for (i = 0; i < _Maxname; i++)
	{
		curch = postfix[i];

		switch (curch) {
		case '\0':
			i = _Maxname;
			break;

		case ' ':
			break;

		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			stack.push(double(curch - '0'));
			break;


		case '+':
			op2 = stack.pop();
			op1 = stack.pop();

			result = op1 + op2;

			stack.push(result);
			break;

		case '-':
			op2 = stack.pop();
			op1 = stack.pop();

			result = op1 - op2;

			stack.push(result);
			break;

		case '*':
			op2 = stack.pop();
			op1 = stack.pop();

			result = op1 * op2;

			stack.push(result);
			break;

		case '/':
			op2 = stack.pop();
			op1 = stack.pop();

			result = op1 / op2;

			stack.push(result);
			break;

		default:
			break;
		}
	}

	cout << "=" << result << endl;
	result = stack.pop();
	stack.clear();
	runCalcul();

	return 0;
}