/*****************************************************************************
 Program file name: main.cpp	OS: Windows XP x64	Assignment #: 3
 Programmer: Daniel Peterson	Class: CPTR 143		Date: 4/13/07
 Compiler: Dev-C++ 4.9.9.2
 
 Assistance/references: 
 Description: 
 Inputs: 
 Outputs: 
 
 Special Comments: 
    if statement in search causes program to crash if no entry is found.
    Reason for this is unknown.
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
#include <cmath>
#include <time.h>

using namespace std;

void adj(int n, int matrx[][32])
{    
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
      matrx[i][j] = (rand() % 2);
}

void Cost(int n, int cost_matrx[][32], int adj[][32])
{    
  if(n <= 8)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
      {
        if (i == j)
        {
          cost_matrx[i][j] = 0;
        }
        else if (adj[i][j] == 1)
        {
          cost_matrx[i][j] = (1 + rand() % 20);
        }
        else
        {
          cost_matrx[i][j] = 2000;
        }
      }
  else if(n <= 16)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
      {
        if (i == j)
        {
          cost_matrx[i][j] = 0;
        }
        else if (adj[i][j] == 1)
        {
          cost_matrx[i][j] = (30 + rand() % 370);
        }
        else
        {
          cost_matrx[i][j] = 2000;
        }
      }
  else
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++) 
      {
        if (i == j)
        {
          cost_matrx[i][j] = 0;
        }
        else if (adj[i][j] == 1)
        {
          cost_matrx[i][j] = (90 + rand() % 810);
        }
        else
        {
          cost_matrx[i][j] = 2000;
        }
      }
}

bool Warshall(int A[][32], int T[][32], int n)
{
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      T[i][j] = A[i][j];
    
  for(int k = 0; k < n; k++)
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        T[i][j] = min(T[i][j], T[i][k]+T[k][j]);
}

void Dijkstra(int v, int cost[][32], int D[], int n)
{
  int found[n];
  memset(found, 0, sizeof(found));
    
  for (int i = 0; i < n; i++)
    D[i] = cost[v][i];
    
  found[v] = true;
  D[v] = 0;
    
  for (int i = 2; i < n; i++)
  {
    int run_min = 999999;
    int u = -1;
    for (int w = 0; w < n; w++)
      if (!found[w])
        if (run_min > D[w])
        {
          run_min = D[w];
          u = w;
        }
      
    found[u] = true;
      
    for (int w = 0; w < n; w++)
      if (!found[w])
        D[w] = min(D[w], D[u]+cost[u][w]);
  }
}

void printDijk(int D[], int n)
{
  for(int i = 0; i < n; i++)
    cout << setw(4) << D[i];
  cout << endl;
}

void printMatrix(int matrix[][32], int n)
{
  // Top numbers
  cout << setw(3) << ' ';
  for (int i = 0; i < n; i++)
  {
    cout << setw(4) << i+1;
  }
  cout << endl;
  //Top of brackets
  cout << setw(3) << ' ' << char(218);
  cout << setw(4*n) << char(191) << endl;
  // Loop through rows
  for (int i = 0; i < n; i++)
  {
    cout << setw(2) << i+1 << " " << char(179);
    cout << setw(3);
    if (matrix[i][0] == 2000)
      cout << char(236);
    else
      cout << matrix[i][0];
    for (int j = 1; j < n; j++)
    {
      cout << setw(4);
      if (matrix[i][j] == 2000)
        cout << char(236);
      else
        cout << matrix[i][j];
    }
    cout << char(179) << endl;
  }
  // bottom of bracket
  cout << setw(4) << char(192) << setw(4*n) << char(217) << endl;
}

void chosen(int x)
{
    int matrix[32][32];
    int cost[32][32];
    int transitive[32][32];
    int D[32];
    
    adj(x, matrix);
    Cost(x, cost, matrix);
    Warshall(cost, transitive, x);
    Dijkstra(0, cost, D, x);
    
    cout << "Adjacency Matrix:\n";
    printMatrix(matrix, x);
    cout << "Cost Matrix:\n";
    printMatrix(cost, x);
    cout << "Transitive Closure from Warshall's:\n";
    printMatrix(transitive, x);
    cout << "Transitive Closure from Dijkstra:\n";
    printDijk(D, x);
}

void printMenu()                                //the menu function
{
    cout << endl;                                 //insert blank line here
    cout << "+----------------------------------+" << endl;//top of menu box
    cout << "| Choose an option:                |" << endl;//tell user what to do
    cout << "|   1 - Create an 8 element graph  |" << endl;//1st option
    cout << "|   2 - Create a 16 element graph  |" << endl;//2nd option
    cout << "|   3 - Create a 32 element graph  |" << endl;//3rd option
    cout << "|   0 - Exit                       |" << endl;//quit? why would you want to do that?
    cout << "+----------------------------------+" << endl;//bottom of menu box
    cout << endl;                                 //another blank line
}

int main(int argc, char *argv[])
{
    char choice;
    
    srand(time(NULL));
    
    printMenu();                                  //print the menu
  
    cout << endl << "Option: ";                   //blank line followed by "Option: "
    cin >> choice;                                //input for user's choice
    cin.ignore(1);                                //ignores one input
  
    // loop in the menu till the user selects 0 to exit
    while (choice != '0')
    {
        cout << endl;
        // Switch over the users choice
        switch (choice)
        {
            case '1': chosen(8);                        break;
            case '2': chosen(16);                       break;
            case '3': chosen(32);                       break;
            case '0':                                   break;
            default: cout << "Invalid Option" << endl;  break;
        }
        // Print the menu again
        printMenu();
        // Get the user's choice
        cout << "Option: ";
        cin >> choice;
        cin.ignore(1);
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
