/*****************************************************************************
 Program file name: lists.cpp	OS: Mac OSX 10.4.8	Assignment #: 6
 Programmer: Daniel Peterson	Class: CPTR 142		Date: 2-9-07
 Compiler: Xcode 2.2.1
 
 Assistance/references: 
 Description: Working with queues
 Inputs: data for queue operations
 Outputs: data in queue, explanation of what's happening with queue
 
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
#include <iostream>

using namespace std;				//for cout

class Queue							//the Queue class
{
    private:						//Queue's private elements
        int *Q;						//pointer in Queue
        int size;					//size of Queue
        int front;					//front element of Queue
        int rear;					//rear element of Queue
    public:							//Queue's public elements
        Queue(int=20);				//initialize constructor with default length of 20
        bool emptyQ();				//if Queue is empty
        bool fullQ();				//if Queue is full
        void addQ(int);				//add element to rear of Queue
        int delQ();					//delete element from front of Queue
        int lengthQ();				//find length of Queue
        void writeQ();				//write complete Queue
        void clearQ();				//clear Queue
};

Queue::Queue(int setsize)			//A revived breathing queue
{
    size = setsize;					//option to set custom size
    Q = new int[size];				//initialize new Queue
    front = rear = 0;				//set front and rear to be the same(queue is empty)
}

bool Queue::emptyQ(void)			//see if Queue is empty
{
    return(front==rear);			//return true if front and rear are same; else return false
}

bool Queue::fullQ(void)				//see if Queue is full
{
    return(front == (rear+1)%size);	//return true if front is rear+1; else return false
}

void Queue::addQ(int data)			//to add element to Queue
{
    if (fullQ())					//check if Queue is full
        cout<<"Queue overflow\n";	//return overflow error if full
    else							//if not full
    {
       rear=(rear+1)%size;			//add element to rear
       Q[rear]=data;				//assign data to new element in rear
    }
}

int Queue::delQ()					//to delete element from Queue
{
    if (emptyQ())					//check if Queue is empty
        cout<<"Queue underflow\n";	//return underflow if empty
    else							//if not empty
    {
        front=(front+1)%size;		//move front of Queue back one place
        return Q[front];			//return new front
    }
}

void Queue::clearQ()				//function to clear queue
{
	while(front!=rear)				//while the front element isn't the back element
	{
		front=(front+1)%size;		//move the second item to the front
	}
	
}

int Queue::lengthQ()				//to check length of Queue
{
    return(size+rear-front)%size;	//return the length of the Queue
}

void Queue::writeQ()				//to output contents of Queue
{
	int b=size;						//integer for use with outputting "null chars"
    if(emptyQ())					//if the Queue is empty
        cout<<"Queue is empty\n";	//Output that queue is empty
    else							//if not empty
    {
        cout<<"Queue: ";			//output text
        for(int i=1; i<=lengthQ(); i++)//for loop to cycle through Queue
        {
            cout << Q[(front+i)%size] << " ";//cout data in each element
			b--;					//decrement the b count
        }
		for(b; b>0; b--)			//for loop to output 'phi' for each empty element in Q's array
		{
			cout << char(237) << " ";//output the 'phi' character
		}
        cout<<endl;					//put output on new line
    }
}

int main(int argc, char *argv[])	//main function
{
    Queue a(10);					//Queue of length 10 (functional length 9)
	cout << "First, we will output the initial queue.\n";//text to describe what is happening
	system("PAUSE");				//wait for user to continue
    a.writeQ();						//output Queue
	cout << "Next, we will add 5 elements to the queue and output it.\n";
	system("PAUSE");
    a.addQ(1);						//add 1 to back of queue (front in this case, it's first)
    a.addQ(2);						//add 2 to back of queue
    a.addQ(3);						//add 3 to back of queue
	a.addQ(4);						//add 4 to back of queue
	a.addQ(5);						//add 5 to back of queue
	a.writeQ();						//output whole queue
	cout << "Everything is good so far, let's see what happens when we add 5 more.\n";
	system("PAUSE");
	a.addQ(6);						//add 6 to back of queue
	a.addQ(7);						//add 7 to back of queue
	a.addQ(8);						//add 8 to back of queue
	a.addQ(9);						//add 9 to back of queue
	a.addQ(10);						//attempt to add 10 to back of queue, can't because one element must remain blank
	a.writeQ();						//output whole queue
	cout << "Oops, we added one too many, lets delete one and then try adding that last one again.\n";
	system("PAUSE");
    cout<<"deleted element: "<<a.delQ()<<endl;//delete first item in queue
	a.addQ(10);						//add 10 to back of queue
	a.writeQ();						//write whole queue
	cout << "Well, that was fun, time to clear the queue.\n";
	system("PAUSE");
	a.clearQ();						//clear queue
	a.writeQ();						//write queue to show it is empty
	cout << "As you probably saw, the queue is now empty.\nLet's see what happens when we try to delete something.\n";
	system("PAUSE");
	a.delQ();						//attempt to delete item from queue, can't because queue is empty
	a.writeQ();						//write queue to show nothing funky happened
	cout << "Thank you for exploring queues with me.\n";
	
    system("PAUSE");
    return EXIT_SUCCESS;
}
