//--------------------------------------------------------------------
//
//  Laboratory 1                                           logbook.h
//
//  Class declaration for the Logbook ADT
//
//--------------------------------------------------------------------
#include <time.h>

class Logbook
{
public:
	// Constructor
	Logbook(int month, int year);         // Create a logbook
	Logbook();                            // Default constructor
	virtual ~Logbook();
	
	// Logbook marking operations
	void putEntry(int day, int value);   // Store entry for day
	int getEntry(int day) const;         // Return entry for day
	void initEntry();
	void putEntry(int value);            // Store entry for today

	// General operations
	int getMonth() const;                  // Return the month
	int getYear() const;                   // Return the year
	int getDaysInMonth() const;            // Number of days in month

	// In-lab operations
	void displayCalendar() const;			// Display as calendar 
	
private:
	// Facilitator (helper) function
	int isLeapYear(int year) const;			// is Leap year?
	void setCurrentTime();
	// In-lab facilitator function
	int getDayOfWeek(int day) const;		// Return day of the week

	// Data members
	int logMonth,      // Month covered by logbook
		logYear,       // Year for this logbook
		entries[31];   // Logbook entries

	tm *currentTime;
};

// Requirements 
const int MAX_YEAR = 2099;				// Maximum year
const int MIN_YEAR = 1901;				// Minimum year

static int DaysOfMonth[2][12] = {
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },	// Normal years
	{ 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }	// Leap year
};
static char NameOfDay[7][4] = {
	"Sun",
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat"
};