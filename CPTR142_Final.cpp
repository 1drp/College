#include <cstdlib>                                  //The C Standard Library
#include <iostream>                                 //input/output
#include <fstream>                                  //file input/output
#include <time.h>                                   //header for timing stuff

using namespace std;                                //so don't have to use std::
   
int main(int argc, char *argv[])                    //main function
{
    clock_t t1, t2;                                 //Clock Vars for timing
    char file[2000];                                //char array to store file
    char sorted[2000];                              //char array for sorted file
    int u = 0;                                      //index for array
	int r = 0;
	int b = 1999;
    int z;                                          //variable for maniplations
    const char* marble = "marbles.dat";             //Name of data file
    ifstream inFile(marble);                        //input stream object
	    
    if(!inFile)                                     //make sure file opened
    {
        cout << "Grr, I can't open " << marble;     //output error message
        system("PAUSE");                            //give user time to read it
        return 1;                                   //exit program
    }
    
    while(!inFile.eof())                            //step through file till reach eof
    {
        inFile >> file[u];                          //copy charecter to array
        u++;                                        //increment index
    }
    
    for(int i = 0; i <= 1999; i++)                  //output original file
        cout << file[i] << " ";                     //one char at a time
    
    t1 = clock();                                   //Store Start Time
//    for (long int i = 1; i <= 1000000; i++)         //test loop for timings
//    {
        for (int u = 0; u <= 1999; u++)
            sorted[u] = file[u];
        
        for (int u = 0; u <= 1999; u++)
        {
            if(sorted[u] == 'R')
            {
                z = u;
                while(z > r)
                {
                    sorted[z] = sorted[z-1];
                    z--;
                }
                sorted[r] = 'R';
                r++;
            }
            
            else if(sorted[u] == 'B')
            {
                z=u;
                while(z < b)
                {
                    sorted[z] = sorted[z+1];
                    z++;
                }
                sorted[1999] = 'B';
                b--;
            }
        }
//    }
    t2 = clock();                                   //Store stop time
    
    cout << endl << endl;                           //insert blank line
    for(int i = 0; i <= 1999; i++)                  //for loop for outputting results
        cout << sorted[i] << " ";                   //output sorted file
		
    cout << "Red: " << r + 1 << endl;
    cout << "White: " << 2000 - (1999 - b) - (r + 1)  << endl;
    cout << "Blue: " << 1999 - b << endl;
    
    cout << "Time difference is " <<                //output time taken...
        (t2 - t1) / CLK_TCK << " microseconds.\n";  //...continued
    system("PAUSE");                                //give user time to read results
    return EXIT_SUCCESS;                            //yay, the program quit properly
}
