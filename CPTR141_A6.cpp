/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: 6
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 11-9-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: Chris Wills
 Description: use of arrays
 Inputs: various
 Outputs: various
 
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
#include <iomanip>

using namespace std;

void printmenu()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+ Choose one of the following:                                     +\n";
	cout << "+ 1:  Determine the frequency for each letter in a string          +\n";
	cout << "+ 2:  Sort random ints into ascending order                        +\n";
	cout << "+ 3:  Use the Sieve of Eratosthenes to determine all primes < 1000 +\n";
	cout << "+ 4:  Add two matrices                                             +\n";
	cout << "+ 5:  Enter employees and output all females with payrate < $10/hr +\n";
	cout << "+ 0:  Exit                                                         +\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "Please enter your choice: ";
}

void LetterFreq(int freq[])
{
	char lett;
	
	cin >> lett;
	lett = toupper(lett);
	
	while(lett != '#')
	{
		freq[lett]++;
		
		cin >> lett;
		lett = toupper(lett);
	}
}

void freqIO()
{
	int freq[91];
	char letter;
	
	for(int i=65; i<=90; i++)
		freq[i]=0;
	
	cout << "You have chosen to determine the frequency of each letter in a string.\n";
	cout << "Input a string, end with #: ";
	
	LetterFreq(freq);
	
	for( letter='A'; letter <= 'Z'; letter++)
		cout << letter << " occurs " << freq[letter] << " times.\n";
}

void sort(int a[],int limit)
{
	
	for(int i=limit-1; i>=1; i--)
		for(int j=0; j<=i-1; j++)
			if(a[j]>a[i])
				swap(a[j],a[i]);
}

void sortIO()
{
	int a[20];
	int i;
	
	cout << "You have chosen to sort a random string of integers.\n";
	
	for(i=0;i<20;i++)
		{
			cout << "enter an integer: ";
			cin >> a[i];
		}
		
	sort(a,20);
	
	for(i=0;i<20;i++)
		cout << a[i] << " ";
}

void primes(int p[])
{
	for(int i=0; i<1000; i++)
		p[i] = 1;
	p[0]=p[1]=0;
	
	for(int m=2; m<=31; m++)
		for(int n=m; n<=1000/m; n++)
			p[m*n] = 0;
}

void primesIO()
{
	int p[1000];
	
	cout << "You have chosen to output all primes less than 1000.\n";
	
	primes(p);
	
	for(int i=0; i<=1000; i++)
		if(p[i]==1)
			cout << i << endl;
}

void matrixAdd(int a[][10], int b[][10], int c[][10], int row, int col)
{
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			c[i][j]=a[i][j]+b[i][j];
}

void matrixIO()
{
	int a[10][10],b[10][10],c[10][10],row,col;
	
	cout << "You have chosen to add 2 matrices.\n";
	cout << "Please select the size of your matrices (max is 10x10):\n";
	cout << "Rows: ";
	cin >> row;
	cout << "Columns: ";
	cin >> col;
	
	while((row>10)||(col>10))
	{
		cout << "Invalid entry, row and column must be 10 or smaller.\n";
		cout << "Rows: ";
		cin >> row;
		cout << "Columns: ";
		cin >> col;
	}
	
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
		{
			cout << "Enter the number at position " << i << "," << j << " in the first matrix: "; 
			cin >> a[i][j];
		}
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
		{
			cout << "Enter the number at position " << i << "," << j << " in the second matrix: "; 
			cin >> b[i][j];
		}
		
	cout << "Your first matrix is:\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << a[i][j]<< ' ';
		cout << endl;
	}
	
	cout << "Your second matrix is:\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << b[i][j]<< ' ';
		cout << endl;
	}

	matrixAdd(a,b,c,row,col);
	
	cout <<  "The sum of your matrices is:\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << c[i][j]<< ' ';
		cout << endl;
	}
}

void company()
{
	struct employee {string name; char gender; int age; long ssn; float pay;};
	employee emp[10];
	
	cout << "You have chosen the company database function.\n";
	
	for(int i=0;i<10;i++)
		{
			cout << "Input employee information:\n";
			cout << "name: ";
			cin >> emp[i].name;
			cout << "gender(M or F): ";
			cin >> emp[i].gender;
			emp[i].gender = toupper(emp[i].gender);
			while((emp[i].gender != 'M')&&(emp[i].gender !='F'))
			{
				cout << "Invalid gender. Try again: ";
				cin >> emp[i].gender;
				emp[i].gender = toupper(emp[i].gender);
			}
			cout << "age: ";
			cin >> emp[i].age;
			cout << "ssn: ";
			cin >> emp[i].ssn;
			cout << "pay($/hr): ";
			cin >> emp[i].pay;
		}
	
	cout << endl;//create a blank line to distinguish output more
	
	for(int i=0;i<10;i++)
		if((emp[i].gender=='F')&&(emp[i].pay<10))
		{
			cout << "This entry is a female with a pay rate < $10/hr.\n";
			cout << "Name:     " << emp[i].name << endl;
			cout << "Gender:   " << emp[i].gender << endl;
			cout << "Age:      " << emp[i].age << endl;
			cout << "SSN:      " << emp[i].ssn << endl;
			cout << "Pay rate: " << emp[i].pay << endl;
		}
	
	cout << "blah";
}

int main (int argc, char * const argv[]) 
{
	int choice;
	
	cout << "Welcome to my program.\n\n";
	printmenu();
	cin >> choice;
	
	while(choice != 0)
	{
		switch(choice)
		{
			case 1: freqIO(); break;
			case 2: sortIO(); break;
			case 3: primesIO(); break;
			case 4: matrixIO(); break;
			case 5: company(); break;
			default: cout << "\nInvalid input.  Please try again.\n";
		}
		
		printmenu();
		cin >> choice;
	}
	
	cout << "Thank you for using my program.\n";
	
	system("PAUSE");
    return EXIT_SUCCESS;
}