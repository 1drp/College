/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: MidTerm
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 11-2-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: none
 Description: MidTerm test
 Inputs: numbers
 Outputs: mathematical relationships
 
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
#include <math.h>

using namespace std;

void printmenu()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+ Choose one of the following:                                             +\n";
	cout << "+ 1:  Investment Calculator                                                +\n";
	cout << "+ 2:  Sort integers                                                        +\n";
	cout << "+ 3:  Find all 3 digit numbers that = the sum of the cubes of their digits +\n";
	cout << "+ 4:  Rotate 3 integers                                                    +\n";
	cout << "+ 5:  Find the nth tribonacci number                                       +\n";
	cout << "+ 0:  Exit                                                                 +\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "Please enter your choice: ";
}

float invest(float p, float r, int n, float t)
{
	float A;
	
	A = (p*pow((1+(r/n)),(n*t)));
	return A;
}

void investIO()
{
	float p,r,t;
	int n;
	
	cout << "You have chosen the investment calculator.\n";
	cout << "What is your principal? ";
	cin >> p;
	cout << "What is your interest rate? (expressed as a decimal) ";
	cin >> r;
	cout << "How many times is your interest compounded per year? ";
	cin >> n;
	cout << "How many years do you want to calculate for? ";
	cin >> t;
	
	cout << "You would end up with $" << invest(p,r,n,t) << endl;
}

void sort3()
{
	int a,b,c;
	
	cout << "Enter 3 integers." << endl;
	cout << "First integer: ";
	cin >> a;
	cout << "Second integer: ";
	cin >> b;
	cout << "Third integer: ";
	cin >> c;
	
	if(a<b)
		if(b<c)
			cout << a << ", " << b << ", " << c << endl;
		else
			if(a<c)
				cout << a << ", " << c << ", " << b << endl;
			else
				cout << c << ", " << a << ", " << b << endl;
	else
		if(a<c)
			cout << b << ", " << a << ", " << c << endl;
		else
			if(b<c)
				cout << b << ", " << c << ", " << a << endl;
			else
				cout << c << ", " << b << ", " << a << endl;
}

void digitsCubed()
{
	int a,b,c;
	
	for(a=1;a<10;a++)
		for(b=0;b<10;b++)
			for(c=0;c<10;c++)
				if((a*a*a + b*b*b + c*c*c)==(100*a + 10*b + c))
					cout << a << b << c << endl;
}

void rotate(int &a, int &b, int &c)
{
	int temp;
	
	temp = a;
	a=c;
	c=b;
	b=temp;
}

void rotateIO()
{
	int a,b,c;
	
	cout << "You have chosen to rotate three integers.\n";
	cout << "Please enter your first integer: ";
	cin >> a;
	cout << "Please enter your second integer: ";
	cin >> b;
	cout << "Please enter your third integer: ";
	cin >> c;
	
	rotate(a, b, c);
	
	cout << "Your numbers have been rotated to: " << a << ", " << b << ", " << c << endl;
}

unsigned long tribonacci(int n)
{
	if((n==1)||(n==2)||(n==3))
		return 1;
	else
		return (tribonacci(n-1) + tribonacci(n-2) + tribonacci(n-3));
}

void tribIO()
{
	int n;
	
	cout << "You have chosen to find the nth Tribonacci number.\n";
	cout << "Enter an integer in the interval [1,38]: ";
	cin >> n;
	
	while((n<1)||(n>38))
	{
		cout << "Your number is not in the interval [1,38].\n";
		cout << "Please try again: ";
		cin >> n;
	}
	
	cout << "The nth Tribanacci number (n=" << n << ") is: " << tribonacci(n) << endl;
}

int main (int argc, char * const argv[]) 
{
	int choice;
	
	cout << "Welcome to my midterm exam.\n\n";
	printmenu();
	cin >> choice;
	
	while(choice != 0)
	{
		switch(choice)
		{
			case 1: investIO(); break;
			case 2: sort3(); break;
			case 3: digitsCubed(); break;
			case 4: rotateIO(); break;
			case 5: tribIO(); break;
			default: cout << "\nInvalid input.  Please try again.\n";
		}
		
		printmenu();
		cin >> choice;
	}
	
	cout << "Goodbye.\n";
	
	system("PAUSE");
    return EXIT_SUCCESS;
}