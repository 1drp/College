/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: 1
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 9-29-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: Chris Wills
 Description: A Fahrenheit to Celcius converter
 Inputs: Fahrenheit
 Outputs: Celcius
 
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
    float fahr = 0.0; // fahrenheit
	float cels = 0.0; // celsius
	
	// explain program and input fahrenheit temp
	cout << "Welcome to the fahrenheit to celsius converter." << endl;
	cout << "Please enter a temperature in fahrenheit: ";
	cin >> fahr;
	
	// calculate and output celsius temp
	cels = (fahr - 32) * 5 / 9;
	cout << fahr << " degrees fahrenheit converts to " << cels  << " degrees celsius.";
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
