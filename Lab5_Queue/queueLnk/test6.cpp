//--------------------------------------------------------------------
//
//  Laboratory 6                                           test6.cpp
//
//  Test program for the operations in the Queue ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "queueLnk.cpp"

using namespace std;


void main()
{
	Queue<char> testQueue(0);   // Test queue
	char testElement;           // Queue element
	char cmd;                   // Input command

	cout << endl << "Commands:" << endl;
	cout << "  +x : Enqueue x" << endl;
	cout << "  -  : Dequeue" << endl;
	cout << "  C  : Clear the queue" << endl;
	cout << "  E  : Empty queue?" << endl;
	cout << "  Q  : Quit the test program" << endl;
	cout << endl;

	do
	{
		testQueue.showStructure();                    // Output queue

		cout << endl << "Command: ";                  // Read command
		cin >> cmd;
		if (cmd == '+' || cmd == '>')
			cin >> testElement;

		switch (cmd)
		{
		case '+':                                  // enqueue
			cout << "Enqueue " << testElement << endl;
			testQueue.enqueue(testElement);
			break;

		case '-':                                  // dequeue
			cout << "Dequeued " << testQueue.dequeue() << endl;
			break;

		case 'C': case 'c':                       // clear
			cout << "Clear the queue" << endl;
			testQueue.clear();
			break;

		case 'E': case 'e':                       // empty
			if (testQueue.empty())
				cout << "Queue is empty" << endl;
			else
				cout << "Queue is NOT empty" << endl;
			break;

		case 'Q': case 'q':                   // Quit test program
			break;

		default:                               // Invalid command
			cout << "Inactive or invalid command" << endl;
		}
	} while (cmd != 'Q'  &&  cmd != 'q');

}