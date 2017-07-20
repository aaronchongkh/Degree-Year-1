#ifndef STACKTYPE_H
#define STACKTYPE_H
#include <iostream>
#include "linkedListType.h"

using namespace std;

template <class type>
struct nodeTypes
{
	type info;
	nodeTypes<type> *link;
};

template <class type>
class stackType
{
	public:
		void initializeStack(); //Function to initialize the stack
		bool isEmptyStack() const; //Function to check the existence of a stack pointed by stackTop
		void push(const type&); //Function to push a variable/struct into a stack
		type top() const; //Function to return the variable/struct pointed by stackTop pointer
		void pop(); //Function to pop a variable/struct pointed by the stackTop pointer
		stackType(); //Default constructor
		~stackType(); //Destructor
		void searchPath(string, string, linkedListType<type>, linkedListType<type>); //Function in stack in order to search the flight path and store in a stack
		void displaystack(); //Function to display a stack
		void reversestack(); //Function to reverse a stack
		void pushtemp(const type&); //Function to push a variable/struct into a temporary stack in order to reverse the stack
	private:
		nodeTypes<type> *stackTop; //Pointer to point to the top element of the stack
		nodeTypes<type> *tempstack; //Temporary pointer in order to reverse the stack
};

template <class type>
stackType<type>::stackType() //Default constructor
{
	stackTop = NULL;
	tempstack = NULL;
}

template <class type>
stackType<type>::~stackType()
{
	initializeStack();
}

template <class type>
bool stackType<type>::isEmptyStack() const //Function to check the existence of a stack pointed by stackTop
{
	return (stackTop == NULL);
}

template <class type>
void stackType<type>::initializeStack() //Function to initialize the stack
{
	nodeTypes<type> *temp;
	
	while(stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
	tempstack = NULL;
}

template <class type>
void stackType<type>::push(const type& newElement) //Function to push a variable/struct into a stack
{
	nodeTypes<type> *newNode;
	newNode = new nodeTypes<type>;
	newNode->info= newElement;
	newNode->link = stackTop;
	stackTop = newNode;
}

template <class type>
type stackType<type>::top() const
{
	assert(stackTop != NULL);
	
	return stackTop->info.variable1;
}

template <class type>
void stackType<type>::pop() //Function to pop a variable/struct pointed by the stackTop pointer
{
	nodeTypes<type> *temp;
	
	if(stackTop != NULL)
	{
		temp = stackTop;
		stackTop = stackTop->link;
		delete temp;
	}
	else
	cout << "Cannot remove from an empty stack." << endl;
}

template <class type>
void stackType<type>::searchPath(string ori, string desti, linkedListType<type> list, linkedListType<type> orindeslist) //Function in stack in order to search the flight path and store in a stack
{
	info x;
	if(!list.exist(ori))
	{
		cout << "Requested origin does not exist." << endl;
		cout << "The path is not exist." << endl;
		return;
	}
	if(!list.exist(desti))
	{
		cout << "Requested destination does not exist." << endl;
		cout << "The path is not exist." << endl;
		return;
	}
	x.variable1 = ori;
	initializeStack(); //For every new scenario, need to make sure the stack is empty
	list.unvisitall(); //For every new scenario, need to make sure all the cities are not visited
	push(x); //Push the requested origin into the stack
	list.markvisited(x.variable1); //Mark the requested origin as visited
	while(!isEmptyStack() && stackTop->info.variable1 != desti) //While loop
	{
		if(orindeslist.getnext(stackTop->info.variable1, list) == "NO_CITY") //Pop the variable/struct when it doesn't have any available cities
		pop();
		else
		{
			x.variable1 = orindeslist.getnext(stackTop->info.variable1, list); //Search for the next city 
			push(x); //Push the next city
			list.markvisited(x.variable1); //Mark the next city as visited
		}
	}
	if(isEmptyStack()) //If the stack is empty
	{
		cout << "The path is not exist." << endl;
	}
	else
	{
		reversestack(); //Function to reverse the stack
		displaystack(); //Function to display the reversed stack
	}
	
	
}

template <class type>
void stackType<type>::displaystack() //Function to display a stack
{
	nodeTypes<type> *current;
	current = stackTop;
	while(current != NULL)
	{
		cout << current->info.variable1 << "->";
		current = current->link;
	}
	cout << '\b' << '\b';
	cout <<  " " << " ";
	cout << endl;
}

template <class type>
void stackType<type>::reversestack() //Function to reverse a stack
{
	info item;
	while(!isEmptyStack())
	{
		item = stackTop->info;
		pop(); //Pop the element pointed by stackTop
		pushtemp(item); //Push the element into another stack pointed by tempstack
	}
	
	stackTop = tempstack; //Assign the address of tempstack to stackTop so that stackTop will point to the reversed stack
}

template <class type>
void stackType<type>::pushtemp(const type& newElement) //Function to push a variable/struct into a temporary stack in order to reverse the stack
{
	nodeTypes<type> *newNode;
	newNode = new nodeTypes<type>;
	newNode->info = newElement;
	newNode->link = tempstack;
	tempstack = newNode;
}

#endif
