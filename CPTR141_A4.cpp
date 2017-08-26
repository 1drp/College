/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: 4
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 10-19-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: Chris Wills
 Description: menu system for 5 functions
 Inputs: menu selection and ints
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
#include <iomanip>

using namespace std;

void gcd()
{
		int m,n,r = 0;
		
		cout << "You have chosen to find the greatest common divisor of two positive integers." << endl;
		cout << "Please enter your first integer: ";
		cin >> m;
		cout << "Please enter your second integer: ";
		cin >> n;
		
		while(m<0||n<0)
		{
			cout << "Your integers were not positive.  Please try again." << endl;
			cout << "Please enter your first integer: ";
			cin >> m;
			cout << "Please enter your second integer: ";
			cin >> n;
		}
		
		r = m%n;
		while(r!=0)
		{
			r = m%n;
			m = n;
			n = r;
		}
		cout << "The greastest common divisor is: " << m << endl;
}

void fact()
{
	unsigned long long n = 1;
	
	cout << "You have chosen to output n! to the largest possible value that's significant figures can be output on a PC" << endl;
	for(int i=1;i*n >= n && i <= 20;i++)
	{
		n = i*n;
		cout << n << endl;
	}
}

void fibonacci()
{
	long a=1;
	long b=1;
	long c=0;
	
	cout << "You have chosen to output all Fibonacci numbers of type long." << endl;
	while(a+b>b)
	{
		c=a+b;
		a=b;
		b=c;
		cout << c << endl;
	}
}

void abcd()
{
	int a,b,c,d;
	
	cout << "You have chosen to find four positive digits that satisfy A^B*C^D = ABCD" << endl;
	for (a=1; a<=9; a++)
		for (b=0; b<=9; b++)
			for (c=1; c<=9; c++)
				for (d=0; d<=9; d++)
					if (pow(a,b)*pow(c,d) == 1000*a + 100*b + 10*c + d)
					{
						cout << "A = " << a << " B = " << b << " C = " << c << " D = " << d << endl;
						return;
					}
}

void diophantine()
{
	int w,x,y,z;
	
	cout << "You have chosen to find at least 8 solutions for the diophantine equation." << endl;
	for(w=1;w<25;w++)
		for(x=w;x<25;x++)
			for(y=x;y<25;y++)
				for(z=y;z*z*z <= w*w*w + x*x*x + y*y*y; z++)
					if(z*z*z == w*w*w + x*x*x + y*y*y)
						cout << "W = " << setw(2) << w << " X = " << setw(2) << x << " Y = " << setw(2) << y << " Z = " << setw(2) << z << endl;
}

int main (int argc, char * const argv[]) 
{
	char choice;

	cout << "Welcome to the mathematical formula program." << endl;
	cout << "A. Find the greatest common divisor of to positive integers." << endl;
	cout << "B. Output n! to the largest possible value to be held by a single variable on a pc." << endl;
	cout << "C. Generate and output all Fibonacci numbers of type long." << endl;
	cout << "D. Find 4 positive digits, A,B,C,D that satisfy: A^B*C^D = ABCD." << endl;
	cout << "E. Find at least 8 unique solutions for 4 positive integers which satiisfy the diophantine equation." << endl;
	cout << "Q. Quit." << endl;
	cout << "Please choose an option: ";
	cin >> choice;
	choice = toupper(choice);
	
	while (choice != 'Q')
	{
		switch (choice)
		{
			case 'A': gcd(); break;
			case 'B': fact(); break;
			case 'C': fibonacci(); break;
			case 'D': abcd(); break;
			case 'E': diophantine(); break;
			default : cout << "Unrecognized selection.  Please try again." << endl;
		}
		
		cout << "A. Find the greatest common divisor of to positive integers." << endl;
		cout << "B. Output n! to the largest possible value to be held by a single variable on a pc." << endl;
		cout << "C. Generate and output all Fibonacci numbers of type long." << endl;
		cout << "D. Find 4 positive digits, A,B,C,D that satisfy: A^B*C^D = ABCD." << endl;
		cout << "E. Find at least 8 unique solutions for 4 positive integers which satiisfy the diophantine equation." << endl;
		cout << "Q. Quit." << endl;
		cout << "Please choose an option: ";
		cin >> choice;
		choice = toupper(choice);
	}
	
	cout << "Thank you for using this program" << endl;
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
