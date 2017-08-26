/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: 5
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 10-26-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: 
 Description: use of recursive functions
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
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+ Choose one of the following:                             +\n";
	cout << "+ 1:  Solve for a factorial                                +\n";
	cout << "+ 2:  Find a Fibonacci number                              +\n";
	cout << "+ 3:  Solve for the greatest common divisor of two integers+\n";
	cout << "+ 4:  Use the quadriatic formula                           +\n";
	cout << "+ 0:  Exit                                                 +\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "Please enter your choice: ";
}

unsigned long factorial(int n)
{
	if(n==0)
		return 1;
	else
		return n*factorial(n-1);
}

void factIO()
{
	int n;
	
	cout << "\nYou have chosen to solve for a factorial.\n";
	cout << "Please enter an integer between 0 and 12 inclusive: ";
	cin >> n;
	
	while((n<0)||(n>12))
	{
		cout << "Must enter an integer between 0 and 12 inclusive.\n";
		cout << "Please try again: ";
		cin >> n;
	}
	
	cout << "The factorial of your number is " << factorial(n) << endl << endl;
}

//I have deviated from the assignment because it cannot hold a high enough value as written
unsigned long long fibonacci(int n)
{
	if((n==1)||(n==2))
		return n;
	else
		return fibonacci(n-1)+fibonacci(n-2);
}

void fibIO()
{
	int n;
	
	cout << "\nYou have chosen to find a Fibonacci number\n";
	cout << "Please enter an integer between 1 and 47 inclusive: ";
	cin >> n;
	
	while((n<1)||(n>47))
	{
		cout << "Your entry must be between 1 and 47 inclusive.\n";
		cout << "Please try again: ";
		cin >> n;
	}
	
	cout << "The " << n << " Fibonacci number is " << fibonacci(n) << endl << endl;
}

unsigned long gcd(unsigned long m, unsigned long n)
{
	if(n==0)
		return m;
	else
		return gcd(n,m%n);
}

void gcdIO()
{
	unsigned long m,n;
	cout << "You have chosen to find the greatest common divisor of two numbers\n";
	cout << "Please enter your first positive number: ";
	cin >> m;
	cout << "Please enter your second positive number: ";
	cin >> n;

	cout << "The greatest common divisor of " << m << " and " << n <<
			" is " << gcd(m,n) << endl << endl;
}

void quadratic(int a, int b, int c, float &r1, float &r2)
{
	r1 = ((0-b) + ((sqrt(b*b-(4*a*c)))/(2*a)));
	r2 = ((0-b) - ((sqrt(b*b-(4*a*c)))/(2*a)));
}

void quadIO()
{
	int a,b,c;
	float r1,r2;
	
	cout << "You have chosen to use the quadriatic formula\n";
	cout << "The form for a quadriatic equation is: y=ax^2+bx+c\n";
	cout << "Please enter a value for a: ";
	cin >> a;
	cout << "Please enter a value for b: ";
	cin >> b;
	cout << "Please enter a value for c: ";
	cin >> c;
	
	if((a==0)||((b*b-(4*a*c))==0))
		cout << "This problem is not solvable via the quadriatic formula\n\n";
	else
	{
		quadratic(a,b,c,r1,r2);
		cout << "x = " << r1 << " or x = " << r2 << endl << endl;
	}
		
}

int main (int argc, char * const argv[]) 
{
	int choice;
	
	cout << "Welcome to my math library.\n\n";
	printmenu();
	cin >> choice;
	
	while(choice != 0)
	{
		switch(choice)
		{
			case 1: factIO(); break;
			case 2: fibIO(); break;
			case 3: gcdIO(); break;
			case 4: quadIO(); break;
			default: cout << "\nInvalid input.  Please try again.\n";
		}
		
		printmenu();
		cin >> choice;
	}
	
	cout << "Thank you for using my math library.\n";
	
	system("PAUSE");
    return EXIT_SUCCESS;
}