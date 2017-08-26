/*****************************************************************************
 Program file name: lists.cpp	OS: Windows XP x64	Assignment #: 5
 Programmer: Daniel Peterson	Class: CPTR 142		Date: 2-2-07
 Compiler: Dev-C++ 4.9.9.2
 
 Assistance/references: 
 Description: Working with stacks
 Inputs: data for stack operations
 Outputs: data in stacks, results of operations
 
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



class Stack
{
    private:
        int *stk;
        int top;
        int size;        
    public:
        Stack(void);
        Stack(int);
        bool Stack_empty(void);
        bool Stack_full(void);
        void push(int);
        int pop(void);
		int Stack_eval(int);
        void Stack_write(void);
        void Stack_clear(void);
};

    Stack::Stack(void)
    {
        size = 20;
        top = -1;
        stk = new int[size];
    }
    
    Stack::Stack(int set_size)
    {
        size = set_size;
        top = -1;
        stk = new int[size];
    }

    bool Stack::Stack_empty(void)
    {
        return(top < 0); //Return truth matrix for top < 0.
        //True if top < 0; False if top > 0.  Please don't forget in the
        //distant future.
    }
    
    bool Stack::Stack_full(void)
    {
        return(top > size); //See above comment.
    }
    
    void Stack::push(int data)
    {
        if(!Stack_full())
        {
            stk[++top] = data;
        } 
        else 
        {
            cout << "Stack OVERFLOW" << endl;
        }
    }
    
	int Stack::pop(void)
    {
        if(!Stack_empty())
        {
            return (stk[top--]);
        } 
        else 
        {
            cout << "Stack UNDERFLOW" << endl;
        }
    }
    
    void Stack::Stack_write(void)
    {
        int index = top;
        
        if(Stack_empty())
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            while (index != -1)
            {
                cout << "Stack " << index << ": " << stk[index] << endl;
				index--;
            }
        }
    }
	
int Stack::Stack_eval(int result)//evaluate stack and return answer
{
	//declare needed variables
	char choice;
	Stack a(20);
	//working variables
	int tempa;
	int tempb;
	int tempc;
	
	cout << "\nEnter a single digit integer or a arithmatical operation(+, -, *, /, =)\n"; //directions
	cin >> choice;
	while(choice != '=')
	{
		switch(choice)//switch statement to handle input
		{
			case '1': a.push(1); break;
			case '2': a.push(2); break;
			case '3': a.push(3); break;
			case '4': a.push(4); break;
			case '5': a.push(5); break;
			case '6': a.push(6); break;
			case '7': a.push(7); break;
			case '8': a.push(8); break;
			case '9': a.push(9); break;
			case '0': a.push(0); break;
			case '/'://integer division
				tempa=a.pop();//put top operand into a working variable
				tempb=a.pop();//put second top operand into a working varioble
				tempc=tempb/tempa;//perform operations
				a.push(tempc);//put result back into stack
				break;
			case '*'://multiplication
				tempa=a.pop();//put top operand into a working variable
				tempb=a.pop();//put second top operand into a working varioble
				tempc=tempb*tempa;//perform operations
				a.push(tempc);//put result back into stack
				break;
			case '+'://addition
				tempa=a.pop();//put top operand into a working variable
				tempb=a.pop();//put second top operand into a working varioble
				tempc=tempb+tempa;//perform operations
				a.push(tempc);//put result back into stack
				break;
			case '-'://subtraction
				tempa=a.pop();//put top operand into a working variable
				tempb=a.pop();//put second top operand into a working varioble
				tempc=tempb-tempa;//perform operations
				a.push(tempc);//put result back into stack
				break;
			default://test for invalid entry
				cout << "Invalid entry, please try again.\n";
				break;
		}
		a.Stack_write();//output contents of stack
		cout << "\nEnter a single digit integer or a arithmatical operation(+, -, *, /, =)\n"; //directions
		cin >> choice;
	}
	return(a.pop());
}

int main(int argc, char *argv[])
{
	//declare variables
	int r=0;
	Stack a(20);
	
    cout << "Welcome to the RPN calculator.\n";//welcome
	r=a.Stack_eval(r);//get return from eval
	cout << "The answer is " << r << endl;//output result
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
