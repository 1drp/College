/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: 2
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 10-5-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: none
 Description: An Easter date calculator
 Inputs: year
 Outputs: date of easter in year
 
 Special Comments: 

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~
 Assignment Requirements ___/3.0
 Code Format/Cosmetics ___/3.0
 Header & Code Comments: ___/2.0
 Output Format/Cosmetics ___/2.0
 
 ***Does Not Compile***: ___ (-10.0)
 ***Late Work Deduction***: ___ (-0.5/day)
 Total Grade: ___/10.0

*****************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

int main (int argc, char * const argv[]) 
{
    // initialize the variables
	int A, B, C, D, E, F, year = 0;
	
	// state purpose and prompt for year
	cout << "Welcome to the Easter date calculator" << endl;
	cout << "Please enter a year between 1583 and 3999 AD: ";
	cin >> year;
	
	// check for erroneous input
	while((year < 1583) || (year > 3999))
	{
		cout << "The formula in this calculator is only good between 1583 and 3999 AD." << endl;
		cout << "Please enter a new year: ";
		cin >> year;
	}
	
	// perform the calculation
	A = year % 19;
	B = year % 4;
	C = year % 7;
	D = (19 * A + 24) % 30;
	E = (2 * B + 4 * C + 6 * D + 5) % 7;
	F = D + E + 22;
	
	// output the result
	if(F <= 31)
	    cout << "Easter falls on March " << F << " in the year " << year << " AD.";
    else
        cout << "Easter falls on April " << F % 31 << " in the year " << year << " AD.";
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
