/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: 3
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 10-12-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: Chris Wills
 Description: Converts text to phone-key
 Inputs: letter
 Outputs: key on phone that corresponds to letter
 
 Special Comments: Formatting is a little odd when the user enters more than one char at a time

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
    char lett; // declare variable
	
	// begin output
	cout << "Welcome to the text to phone-key converter." << endl;
	
	cout << "Please enter a letter (CTRL-z to quit): ";
	cin >> lett;

	while(!cin.eof())
	{
		lett = toupper(lett); // ensure that the letter is in uppercase
		
		// actual conversion process and output
		switch(lett)
		{
			case 'A' : case 'B' : case 'C' : cout << "2\n"; break;
			case 'D' : case 'E' : case 'F' : cout << "3\n"; break;
			case 'G' : case 'H' : case 'I' : cout << "4\n"; break;
			case 'J' : case 'K' : case 'L' : cout << "5\n"; break;
			case 'M' : case 'N' : case 'O' : cout << "6\n"; break;
			case 'P' : case 'Q' : case 'R' : case 'S' : cout << "7\n"; break;
			case 'T' : case 'U' : case 'V' : cout << "8\n"; break;
			case 'W' : case 'X' : case 'Y' : case 'Z' : cout << "9\n"; break;
			default : cout << "Non-Textual input.  Please try again." << endl;
		}
		
		cout << "Please enter a letter (CTRL-z to quit): ";
		cin >> lett;
	}
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
