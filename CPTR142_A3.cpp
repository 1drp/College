/*****************************************************************************
 Program file name: lists.cpp	OS: Windows XP x64	Assignment #: 3
 Programmer: Daniel Peterson	Class: CPTR 142		Date: 1-18-07
 Compiler: Dev-C++ 4.9.9.2
 
 Assistance/references: 
 Description: Working with linked lists
 Inputs: data for lists
 Outputs: data in lists
 
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
#include <cstdlib>

using namespace std;

//create structure for node
struct node
{
    string name;
    node* link; 
      
};

//implement the class ListSL
class ListSL
{
    private:
        node* headptr;
        node* ptr;
    public:
        ListSL(void);      
        void insert_Node(void);
        void fill_Node(void);
        void search_Node(void);
        void write_List (void);
        void delete_Node (void);
        void clear_List (void);
      
};

//Constructor
ListSL::ListSL(void)
{
     headptr = NULL;
}

//object for putting info in a node
void ListSL::fill_Node(void)
{
     ptr = new node;
     cout << "Please enter a name: ";
     cin >> ptr->name;
     ptr->link = NULL;
}

//create new entry
void ListSL::insert_Node(void)
{
	node* p;
	node* q;
	
	if (headptr==NULL)
		headptr=ptr;
	else
	{
		p=q=headptr;
		while ((p != NULL) && (p->name < ptr->name))
		{
			q=p;
			p = p->link;
		}     
        if (ptr->name <= q->name)
		{
            ptr->link = q;
            headptr = ptr;
		}
        else
		{
			q->link = ptr;
			ptr->link = p;
		}
	}
}

//Output name fields to show results
void ListSL::write_List(void)
{
	if (headptr == NULL)
		cout<<"List is empty.\n\n";
	else
	{
		ptr = headptr;
		while (ptr != NULL)
		{
			cout << ptr->name << endl;
            ptr = ptr->link;    
		}
	}
	cout << endl;
}

//delete entry
void ListSL::delete_Node(void)
{
    string removal;
    node* r;//variable to test for entry to be removed
    node* p;//variable to fix broken link when r is deleted
    
    cout << "Enter the name of the entry to be deleted: ";
    cin >> removal;
    
    p=r=headptr;
	if(r != NULL)//ensure there is data in list
	{
		while((r->link != NULL)&&(r->name != removal))
		{
			p = r;
			r = r->link;
		}
		if(r->name == removal)
		{
			r->name = "";//clear data
			p->link = r->link;//replace link
			cout << removal << " was deleted.\n";//confirmation text
		}
		else
			cout << "Entry was not found.\n";
	}
	else
		cout << "No Entries.\n";
}

//clear all entries
void ListSL::clear_List (void)
{
    while(headptr != NULL)
    {
        ptr=headptr;
        headptr=ptr->link;
        ptr->name="";
        ptr->link=NULL;
    }
} 

//search database for item
void ListSL::search_Node(void)
{
    string query;
    node* q;
    
    cout << "Please enter the name of the entry you are searching for: ";
    cin >> query;
    
    q=headptr;//start at beginning
    //step through database
    while((q != NULL)&&(q->name != query))
        q = q->link;
    //if entry was found
    if((q != NULL)&&(q->name == query))
		cout << q->name << " was found.\n";
    //if entry was not found
    else
        cout << query << " was not found.\n";
}

//output the menu
void menu()
{
	cout << "+++++++++++++++++++++++++++++++++\n";
	cout << "+ Please select an option:      +\n";
	cout << "+ 1:  Create an entry.          +\n";
	cout << "+ 2:  Delete an entry.          +\n";
	cout << "+ 3:  Search for an entry.      +\n";
	cout << "+ 4:  Print complete list.      +\n";
	cout << "+ 5:  Clear complete list.      +\n";
	cout << "+ 0:  Exit                      +\n";
	cout << "+++++++++++++++++++++++++++++++++\n";
	cout << "Please enter your choice: ";
}

//main function
int main()
{
    char choice;
    ListSL a;
	
	cout << "Welcome to my program.\n\n";
	menu();
	cin >> choice;
	cout << endl;
	
	while(choice != '0')
	{
		switch(choice)
		{
			case '1': a.fill_Node(); a.insert_Node(); break;
            case '2': a.delete_Node(); break;
			case '3': a.search_Node(); break;
			case '4': a.write_List(); break;
			case '5': a.clear_List(); break;
			default: cout << "\nInvalid input.  Please try again.\n";
		}
		
		menu();
		cin >> choice;
		cout << endl;
	}
	
	cout << "Thank you for using my program.\n";
	
	system("PAUSE");
    return EXIT_SUCCESS;
}
