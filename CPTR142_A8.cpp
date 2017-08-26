/*****************************************************************************
Program file name: store.cpp			OS: Windows XP	   Assignment #: 8
 Programmer: Brian Pflugrad, Chris Wills & Daniel Peterson
 Class: CPTR 142				Date: 2 23 07
 Compiler: Dev-C++
 
 Assistance/references: Book
 Description: Tree Class uses STL stack and queue
 Inputs:  to user
 Outputs: to user
 
 Special Comments: 
    Have some graphical output for the levelorder for the extra credit

~~~~~~~~~~~~~~~~~~~~~~~~~~Grading Criteria~~~~~~~~~~~~~~~~~~~~~~~~~~
 Assignment Requirements ___/3.0
 Code Format/Cosmetics ___/3.0
 Header & Code Comments: ___/2.0
 Output Format/Cosmetics ___/2.0
 
 ***Does Not Compile***: ___ (-10.0)
 ***Late Work Deduction***: ___ (-0.5/day)
 Total Grade: ___/10.0

*****************************************************************************/
//Standard Includes.
#include <cstdlib>  // Include the stdlib for some functions
#include <stack>    //Include stack.h so STL stack can be used.
#include <queue>    //Include queue.h so STL queue can be used.
#include <iomanip>  // Include for indeting and other output modifing
#include <iostream> // include so we can use the cout and cin classes

using namespace std;    // so we dont have to use std::

//End Standard Includes

//BinTree_Node: Class that forms the nodes for our binary tree.
class BinTree_Node
{
	public:
		BinTree_Node(int); //Constructor, makes a node from input.
		BinTree_Node *LSon; //Left Son, pointer to left son of this node.
		int data; //Data contains node's data.
		BinTree_Node *RSon; //Right Son, pointer to the right son of this node.
};

//BinTree: Class that contains methods for manipulating the tree, and holds the pointer
//to the root node.
class BinTree
{
	private:
		BinTree_Node *root; //Pointer to the root node of the tree.
	public:
		BinTree(void); //First constructor creates an empty tree.
		BinTree(int); //Second constructor creates a tree with one node based on input.
		void insert(int); //Insert data into the tree.
		void rm(int);       // Calls del
		void del(int, BinTree_Node *&);    // Recursivly searchs for the node to delete
		void delNode(BinTree_Node *&);     // Deletes the given node
		void inorder(BinTree_Node *); //Inorder traversal of the tree (recursive).
		void postorder(void); //Postorder traversal (non-recursive).
		void postorder_recurse(BinTree_Node *); //Postorder traversal that is recursive.
		void levelorder(void);      // Level order traversal
		void levelorderGraphical(void);   // A levelorder traversal that lists the data by levels
		void clear(int);                      // Overloaded since root is out of scope if not in the class
		void clear(int, BinTree_Node *&);            // Clears the subtree below the given int
		void clearTree(BinTree_Node *&);
		void graph(void);                 // Graphs the tree sideways
		void graph_out(int, BinTree_Node *);    // Recursive function that does tha actual graphing
};

//BinTree_Node(int): Constructor for our BinTree_Node class.  Accepts input.
BinTree_Node::BinTree_Node(int input)
{
	LSon = NULL; //Set left son to NULL.
	RSon = NULL; //Set right son to Null.
	data = input; //Set data to input.
}

//BinTree(void): Constructor for our container tree class.  Makes an empty tree.
BinTree::BinTree(void)
{
	root = NULL; //Set root to NULL to indicate an empty tree.
}

//BinTree(int): Constructor for our tree class.  Makes a tree with a root node based on input.
BinTree::BinTree(int input)
{
	root = NULL; //Set root to NULL to indicate empty tree.
	insert(input); //Insert the data (will become root since root is currently NULL.
}

//Insert: Take user input and insert it into the tree.
void BinTree::insert(int input)
{
	BinTree_Node *ptr; //Temporary pointer to traverse tree.

	if(root != NULL) //Check if the tree is empty.
	{
		ptr = root; //Set temporary pointer to the top node.
		while(ptr != NULL) //Loop until temporary pointer is NULL.
		{
			if(input < ptr->data) //If input is less than data we want to go left.
			{
				if(ptr->LSon == NULL) //Check if we want to insert here.
				{
					ptr->LSon = new BinTree_Node(input); //Create a new node and assign it to the Left Son.
					return;
				}
				else //Else, there is a node below, increment temporary pointer.
					ptr = ptr->LSon;
			}
			else if(input > ptr->data) //If input is greater than data we want to go right.
			{
				if(ptr->RSon == NULL) //Check if we should insert here.
				{
					ptr->RSon = new BinTree_Node(input); //Create a new node and assign it to the Right Son.
					return;
				}
				else //Else, there is a node below, increment temporary pointer.
					ptr = ptr->RSon; 
			}
			else //Else, the input equals a node.
			{
				cout << input << " already found in tree." << endl;
				system("PAUSE"); //Tell user the node is already in the tree and wait for input.
				return;
			}
		}
	}
	else //Else, tree is empty.
	{
		root = new BinTree_Node(input); //Create a new node and assign it to root.
	}
}

//Inorder: Traverse the tree using inorder (LVR) traversal.
void BinTree::inorder(BinTree_Node *node)
{
	if(node == NULL) //If null was passed then we want to start from the top of the tree.
		node = root; //Set node to be root.
	
	if(node == NULL) //If node is null we have an empty tree.
	{
		cout << "Empty Tree"; //Say so.
		return;
	}

	if(node->LSon != NULL) //If there is a Left Son.
		inorder(node->LSon); //Call inorder on the Left Son.
	cout << node->data << " "; //Output this node's data.
	if(node->RSon != NULL) //If there is a Right Son.
		inorder(node->RSon); //Call inorder on the Right Son.
}

//postorder(void): Output the postorder traversal of the nodes (LRV) without using recursion or
//a tag field in the node itself or elsewhere.
void BinTree::postorder(void)
{
	if(root != NULL) //If root is NULL we have an empty list.
	{
		std::stack<BinTree_Node *> stack; //Initialize an STL stack with type BinTree_Node *.
		stack.push(root); //Put the root node pointer on the stack.

		//Create temporary pointers ptr and last, loop until the stack is empty.  Last = ptr each loop.
		BinTree_Node *ptr, *last = root;
		while (!stack.empty())
		{
			ptr = stack.top(); //Set ptr to be the top value on the stack.

			//If last is the same as the right son, or the right son is NULL and last is the same as the left son
			//or both sons are NULL we want to output the current node and remove it from the stack.
			if (last == ptr->RSon || 
				(ptr->RSon == NULL && last == ptr->LSon) ||
				(ptr->RSon == NULL && ptr->LSon == NULL))
			{
				cout << ptr->data << " "; //Output current node data.
				stack.pop(); //Remove it from the stack.
			}
			else
			{
				if (ptr->RSon) //If there is a right son.
					stack.push(ptr->RSon); //Put it on the stack.
				if (ptr->LSon) //If there is a left son.
					stack.push(ptr->LSon); //Put it on the stack.
			}
			
			last = ptr;
		}
	}
	else
	{
		cout << "Empty Tree"; //List is empty to output that.
		return; //Return
	}
}

// Recursive Function to show postorder  -- used to prove the other postorder function
void BinTree::postorder_recurse(BinTree_Node *node)
{
	if(node == NULL)              // If the node is null
		node = root;                // Set Node to the root
	
	if(node == NULL)              // If Node is still null
	{
		cout << "Empty Tree";       // Its an empty tree
		return;                     // Exit the function
	}

	if(node->LSon != NULL)        // if the LSon is not null
		postorder_recurse(node->LSon);   // Call the function with the Lson as argument
	if(node->RSon != NULL)             // If the Rson is not null
		postorder_recurse(node->RSon);   // Call the function with the Rson as argument
	cout << node->data << " ";         // Output the data
}

// Outputs the tree by levels 
void BinTree::levelorderGraphical()
{
  BinTree_Node *temp; // Temp node pointer
  
  queue<BinTree_Node*> q1;    // Queue for node traversal
  
  int level = 0;              // variable to hold the current level
  int levelNodes[20];         // Array to hold how many nodes are in the queue for each level

  if (root != NULL)           // Make sure the root is not null
    q1.push(root);            // Add the root to the queue
    
  for (int i = 0; i < 20; i++)    // Set the nodes to 0 for all levels
    levelNodes[i] = 0;            
    
  levelNodes[0] = 1;          // Set the level 0 to have one node which is the root
  
  cout << endl << "Level " << setw(2) << level << ":";    // ouput the Level 0:
  
  while (!q1.empty())         // Loop while the queue is not empty
  {
    temp = q1.front();        // Save the node on the front of the queue to temp
    q1.pop();                 // Pop off the top node

    levelNodes[level]--;      // Decrement the nodes for the level
    cout << " " << temp->data;    // output the data
    if (temp->LSon != NULL)       // If the node has a left son
    {       
      q1.push(temp->LSon);        // Push the left son on the queue
      levelNodes[level+1]++;      // Increment the next level's node counter
    }
    if (temp->RSon != NULL)       // If the node has a right son
    {
      q1.push(temp->RSon);        // Push the right son on the queue
      levelNodes[level+1]++;      // Increment the next level's node counter
    }
    if (levelNodes[level] < 1)    // If the current level has less than one node remaining
    {
      cout << endl << "Level " << setw(2) << ++level << ":";  // Output the next level indicator
    }
  }
}

// Outputs the levelorder of the tree
void BinTree::levelorder()
{
  BinTree_Node *temp; // Temp node pointer
  
  queue<BinTree_Node*> q1;    // Queue for node traversal
  
  if (root != NULL)           // Make sure the root is not null
    q1.push(root);            // Add the root to the queue
     
  while (!q1.empty())         // Loop while the queue is not empty
  {
    temp = q1.front();        // Save the node on the front of the queue to temp
    q1.pop();                 // Pop off the top node

    cout << " " << temp->data;    // output the data
    if (temp->LSon != NULL)       // If the node has a left son
      q1.push(temp->LSon);        // Push the left son on the queue
    if (temp->RSon != NULL)       // If the node has a right son
      q1.push(temp->RSon);        // Push the right son on the queue
  }
}

// Function to graph the tree sideways
void BinTree::graph(void)
{
	graph_out(0, root);             // Calls the recursive function with the start of root and 0 indent
}

// Recursive function that outputs each part of the tree
void BinTree::graph_out(int indent, BinTree_Node *node)
{
	if(node != NULL)                // As long as the node is not null continue
	{
		graph_out(indent + 8, node->RSon);      // Call the function with indent + 8 and the Rson
		cout << setw(indent) << " " << node->data << endl;    // Output the data after indenting
		graph_out(indent + 8, node->LSon);      // Call the function with indent + 8 and the Lson
	}
}

void BinTree::rm(int input)
{
    del(input, root);         //call del to start at root and look for input
}

void BinTree::delNode(BinTree_Node *&ptr)
{
  BinTree_Node *temp;               //make a temporary node for traversal
        
  //if no children
  if(ptr == NULL)                         //if entry not found
    cout << "No matching entry\n";        //output to user    
        
  //if one child
        else if(ptr->RSon == NULL)        //if no child on right
        {
            temp = ptr;                   //set temp as placeholder
            ptr = ptr->LSon;              //move ptr to its left child
            delete temp;                  //delete placeholder
        }
        else if(ptr->LSon == NULL)        //if no child on left
        {
            temp = ptr;                   //set temp as placeholder
            ptr = ptr->RSon;              //move ptr to its right child
            delete temp;                  //delete placeholder
        }
        
        //if more than one child
        else
        {
            temp = ptr->RSon;             //set temp to right son of deletee
            while(temp->LSon)             //while temp has a child on left
                temp = temp->LSon;        //move temp to left child
            temp->LSon = ptr->LSon;       //set temp's left child to deletee's left child
            temp = ptr;                   //set temp as placeholder
            ptr = ptr->RSon;              //replace ptr with it's right child
            delete temp;                  //delete placeholder
        }
  
}

//Delete:  delete a node from tree.
void BinTree::del(int input, BinTree_Node *&ptr)
{    
  if (ptr == NULL)
   return;
    //find node to delete
    if(input < ptr->data)                 //if input is less than the current ptr's data
        del(input, ptr->LSon);            //recursive call to delete with LSon as argument
    else if(input > ptr->data)            //if input is greater than the current ptr's data
        del(input, ptr->RSon);            //recursive call to delete with RSon as argument

    //deletion process
    else //if input is not smaller or larger than data in current node(implies ==)
      delNode(ptr);                       //call function to do deleting
}

// Overloaded so we dont need to give it root
void BinTree::clear(int value)
{
  clear(value,root);          // Call the other clear function
}

// Function the clears the tree
void BinTree::clear(int value, BinTree_Node*& node)
{
  if (node == NULL)           // If node is Null
  {
    cout << "Subtree to delete not found" << endl;  // Let the user know
    return;                   // Exit the function
  }
  
  if (value < node->data)         // If the value is less then the node's data
      clear(value, node->LSon);   // call clear with the LSon
  else if (value > node->data)    // If the value is less then the node's data
      clear(value, node->RSon);   // call clear with the RSon
  else   // Value equals the data
      clearTree(node);            // Lets clear the tree
}

// Function the recursivly goes through the tree deleting each node
void BinTree::clearTree(BinTree_Node*& node)
{
  if (node == NULL)         // If the node is NULL
   return;                  // We are done here
  
  clearTree(node->RSon);    // Call clearTree with the RSon
  clearTree(node->LSon);    // Call ClearTree with the LSon
  delNode(node);                // Delete the current node
}

int main(int argc, char *argv[])
{
    BinTree a;
	char input[64]; //Variable to hold user input.
	int mode = 0; //Variable to tell if the user is inserting, deleting, or clearing.

	while(strcmp(input, "$") != 0) //Loop while $ is not inputted.
	{
		system("CLS"); //Clear Screen.
		cout << "Inorder: ";          // Output stuff
		a.inorder(NULL);
		cout << endl << "Postorder: ";   // More output stuff
		a.postorder();
		cout << endl << "Postorder (Recursive): "; // Even more output stuff
		a.postorder_recurse(NULL);
		cout << endl << "Level Order: ";      // Not done yet with the output stuff
		a.levelorder();
		cout << endl;
		a.levelorderGraphical();          // Wait theres more output stuff
		cout << endl;
		cout << "----------------------------------------" << endl;
		a.graph(); //Output graphical levelorder.
		cout << "----------------------------------------" << endl;
		cout << endl;
		switch(mode) //Check mode.
		{
		case 0: //Mode zero: main menu.
			cout << "1: Insert" << endl;
			cout << "2: Delete" << endl;
			cout << "3: Clear" << endl;
			cout << "$: Exit Program" << endl;
		break;
		case 1: //Mode 1: inserting.
			cout << "Input integers." << endl;
			cout << "# Exits" << endl;
		break;
		case 2: //Mode 2: deleting.
			cout << "Input integers to delete." << endl;
			cout << "# Exits" << endl;
		break;
		case 3: //Mode 3: clearing.
			cout << "Input integers to clear." << endl;
		break;
		}
		cout << "Input: ";
		cin >> input; //Take user input.
		if(mode == 0 && (atoi(input) > 0 && atoi(input) < 4)) //If mode is zero we just set mode to be the input.
			mode = atoi(input); //Set mode to be the inputted number.
		else
		{
			switch(mode)  //Check mode.
			{
			case 1: //Mode 1: do insert.
				if(strcmp(input, "#") != 0) //If the user put in anything but a # sign.
					a.insert(atoi(input)); //Insert integer of the input.
				else //User inputted #.
					mode = 0; //Return to main menu.
			break;
			case 2: //Mode 2: do delete.
				if(strcmp(input, "#") != 0)
					a.rm(atoi(input)); //Delete integer of the input.
				else
					mode = 0; //User input #, return to main menu.
			break;
			case 3: //Mode 3: clearing.
				a.clear(atoi(input)); //Clear subtree of integer of input.
				mode = 0; //Return to main menu.
			break;
			}
		}
	}

	
	system("PAUSE");
    return EXIT_SUCCESS;
}
