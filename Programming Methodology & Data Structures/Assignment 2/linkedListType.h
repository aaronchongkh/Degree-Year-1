#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

template<class type> //Template is being used
struct nodeType //Declaration of nodeType as a struct
{
	type carInfo;
	nodeType<type> *link; //pointer part of the node
};

struct carInfo //Declaration of carInfo as a struct
{
	string engineno;
	string model;
	string color;
	int displacement;
	double sellingprice;
	double retailprice;
	double ontheroad;
};

template<class type>
class linkedListType
{
	public:
		linkedListType(); //Default constructor
		~linkedListType(); //Destructor
		void deleteparticular(string); //Function to delete one node in linked list
		void deleteall(); //Function to delete all nodes in linked list
	protected:
		int count;
		nodeType<type> *first; //Declaration of pointer first
		nodeType<type> *last; //Declaration of pointer last
};



template <class type>
linkedListType<type> :: linkedListType() //Default constructor to initialize variables
{
	first = NULL;
	last = NULL;
	count = 0;
}

template<class type>
linkedListType<type> :: ~linkedListType() //Destructor
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class type>
void linkedListType<type>::deleteparticular(string searchengineno)
{
	nodeType<type> *current; //Declaration of pointer current
	nodeType<type> *trail; //Declaration of pointer trail
	bool found;
	if(first == NULL) //If there is no linked list
	cout << "\t\t\tCannot perform the operation! There is an empty list." << endl;
	else
	{
		if(first->carInfo.engineno == searchengineno) //If first node is the same car engine number in the linked list with the input
		{
			current = first;
			first = first->link;
			
			if(first == NULL) // if the original list has only one node
			{
				last = NULL
;			}
			
			delete current;
			count--;
		}
		else
		{
			found = false;
			trail = first;
			current = first->link;
			while(current !=NULL && !found) //Condition to exit the loop: when current == NULL or when found == true
			{
				if(current->carInfo.engineno != searchengineno) //If car engine number pointed by the current pointer is not the same as the input
				{
					trail = current;
					current = current->link;
				}
				else
				found = true;
			}
			if(found) //If found == true
			{
				trail->link = current->link;
				
				if(last == current)
				last = trail;
				
				delete current;
				count--;
			}
			else //If car engine number is not exist
			cout << "\t\t\tCar engine number doesn't exist! Please try again." << endl;
		}
	}
}

template <class type>
void linkedListType<type>::deleteall() //Function to destroy the linked list
{
	nodeType<type> *temp; //Declaration of pointer temp
	while(first != NULL)
	{
		temp = first;
		first = first->link;
		delete temp;
	}
	
	first = NULL;
	last = NULL;
	count = 0;
}

#endif
