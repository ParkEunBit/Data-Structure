//--------------------------------------------------------------------
//
//  Laboratory 1                                           test1.cpp
//
//  Test program for the operations in the Logbook ADT
//
//--------------------------------------------------------------------

#include <iostream>
#include "Logbook.h"

using namespace std;

int main()
{
	int month,   // Input month
		year,    // Input year
		day,     // Input day
		entry,   // Input logbook entry
		dofw,    // Day of the week
		stop,    // Signals end of test
		j;       // Loop counter

	// Create a logbook (not used in Test 4).

	cout << endl << endl << "Enter the month and year for the logbook month : ";
	cin >> month >> year;
	Logbook testLog(month, year);

	// Test 1 : Tests the month, year, and daysInMonth operations.

	cout << "Month : " << testLog.getMonth() << endl;
	cout << "Year  : " << testLog.getYear() << endl;
	cout << "# days in month : " << testLog.getDaysInMonth() << endl;

	// Test 2 : Tests the putEntry and getEntry operations.

	stop = 0;
	while (!stop)
	{
		cout << endl << "Enter day and entry (0 0 to exit Test 2) : ";
		cin >> day >> entry;
		if (day != 0 && entry != 0)
		{
			testLog.putEntry(day, entry);
			cout << "Logbook:" << endl;
			for (day = 1; day <= testLog.getDaysInMonth(); day++)
			{
				cout << day << " " << testLog.getEntry(day) << '\t';
				if (day % 5 == 0)
					cout << endl;
			}
			cout << endl;
		}
		else stop = 1;
	}


	// In-lab 1 ... Test 3 : Tests the calendar operation.

	//3 cout << endl;
	//3 testLog.displayCalendar();
	//3 cout << endl;
	 
	 
	return 0;
}