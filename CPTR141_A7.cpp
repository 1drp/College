/*****************************************************************************
 Program file name: petedan.cpp	OS: Mac OSX 10.4	Assignment #: 6
 Programmer: Daniel Peterson	Class: 	CPTR141		Date: 11-9-06
 Compiler: Xcode 2.2.1
 
 Assistance/references: Chris Wills
 Description: use of arrays
 Inputs: various
 Outputs: various
 
 Special Comments: 
         Crashes if you run histogram without first loading a file
         Possible Solution: Create a boolean flag that is tripped when
                  ReadDisk() is run and check for the flag before running
                  histogram.
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
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//here is part of my fix
bool beenRead = 0;

void printmenu()
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "+ Choose one of the following:                   +\n";
	cout << "+ 1:  Write a file to disk                       +\n";
	cout << "+ 2:  Read a file from disk                      +\n";
	cout << "+ 3:  View a histogram of word lengths in a file +\n";
	cout << "+ 0:  Exit                                       +\n";
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout << "Please enter your choice: ";
}

void WriteDisk()
{ const int size = 81;
  char line[size];
  char *filename = new char[80];
  ofstream diskfile;
  
  cout << "To write a file to disk, enter its path and filename.extension:\n";
  cin  >> filename;
  diskfile.open(filename);
  if(!diskfile)
  {  cerr << "Failure trying to create diskfile: " << filename;
     exit(0);
  }
  cout << "Enter lines of text.\n";
  cout << "To quit, enter ^Z by itself on the last line:\n";
  while(!cin.getline(line,size).eof())
    diskfile << line << endl;
  diskfile.close();
  cin.clear();
}

void ReadDisk(int freq[])
{ char *filename = new char[80];
  string word;
  ifstream diskfile;
  
  cout << "Enter path and filename of the file from which to read:\n";
  cin  >> filename;
  diskfile.open(filename);
  if(!diskfile)
  {  cerr << "Failure to open disk file: " << filename;
     exit(0);
  } 
  //here is part of my fix
  beenRead = 1;
  
  for (int i=0; i<30; i++) freq[i]=0;  
  while(!diskfile.eof())
  {  diskfile >> word;
     freq[word.length()]++;
  }
  diskfile.close();
}

void Histogram(int freq[])
{ int i,j;
  string line;
  cout << endl << "No. of words -> ";
  for (i=0; i<=40; i+=5)
    cout << i << setw(5);
  cout << endl << " of Length:     ";
  line.assign(41, '-');
  cout << line << endl;
  for (i=1; i<=21; i++)
  { cout << setw(17) << i;
    for (j=1; j<=freq[i]; j++)
      cout << char(219);
    cout << endl;
  }
}

int main(int argc, char *argv[])
{
    int choice;
	int freq[30];
	
	cout << "Welcome to my program.\n\n";
	printmenu();
	cin >> choice;
	
	while(choice != 0)
	{
		switch(choice)
		{
			case 1: WriteDisk(); break;
			case 2: ReadDisk(freq); break;
			case 3: //the rest of my fix is here
               if(beenRead == 1)    
                  Histogram(freq);
               else
                  cout << "Must read a file first\n"; 
               break;
			default: cout << "\nInvalid input.  Please try again.\n";
		}
		
		printmenu();
		cin >> choice;
	}
	
	cout << "Thank you for using my program.\n";
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
