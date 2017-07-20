#ifndef LINKEDLISTTYPE_H
#define LINKEDLISTTYPE_H
#include <iostream>
#include <cassert>

using namespace std;

struct info //Generalized struct
{
	string variable1; //For list: city, for orindeslist: origin, for scenario: requested origin, for stack: stored city
	string variable2; //For list: visit status, for orindeslist: destination, for scenario: requested destination
	int variable3; //For list, orindeslist, scenario = counter for each node
};

template <class type>
struct nodeType
{
	type info;
	nodeType<type> *link;
};

template <class type>
class linkedListType
{
	public:
		linkedListType(); //Default constructor
		~linkedListType(); //Destructor
		void insert(type); //Function to insert as the last node of the linked list
		void displayall(); //Function to display all available cities
		void displayall2(); //Function to display all available one way flights
		void markvisited(string); //Function to mark visit status of a city as visited
		int getcount(); //Function to return the number of nodes
		string getori(int); //Function to return the origin
		string getdesti(int); //Function to return the destination
		void unvisitall(); //Function to mark visit status of all cities as not visited
		bool checkvisited(string); //Function to check visit status of a city
		string getnext(string, linkedListType<type>); //Function to get next city
		bool exist(string);
	protected:
		nodeType<type> *first;
		nodeType<type> *last;
		int count;
};

template <class type>
linkedListType<type>::linkedListType()
{
	first = NULL;
	last = NULL;
	count = 0;
}

template <class type>
linkedListType<type>::~linkedListType()
{
	
}

template <class type>
void linkedListType<type>::insert(type city) //Function to insert as the last node of the linked list
{
	nodeType<type> *newNode;
	newNode = new nodeType<type>;
	assert(newNode != NULL);
	newNode->info = city;
	if(first == NULL) //If there is no linked list
	{
		first = newNode;
		last = newNode;
		newNode->link = NULL;
	}
	else
	{
		last->link = newNode;
		last = newNode;
		newNode->link = NULL;
	}
	count++;
}

template <class type>
void linkedListType<type>::displayall() //Function to display all available cities
{
	nodeType<type> *current;
	current = first;
	cout << "List of cities available: " << endl << endl;
	while(current != NULL)
	{
		cout << current->info.variable1 << endl;
		current = current->link;
	}
	cout << endl << endl;
}

template <class type>
void linkedListType<type>::displayall2() //Function to display all available one way flights
{
	nodeType<type> *current;
	current = first;
	cout << "One way flights available: " << endl << endl;
	while(current != NULL)
	{
		cout << current->info.variable1 << " -> " << current->info.variable2 << endl;
		current = current->link;
	}
	cout << endl << endl;
}

template <class type>
int linkedListType<type>::getcount() //Function to return the number of nodes
{
	return count;
}

template <class type>
string linkedListType<type>::getori(int zcount) //Function to return the origin
{
	nodeType<type> *current;
	current = first;
	bool found = false;
	while(current != NULL && !found)
	{
		if(current->info.variable3 == zcount)
		found = true;
		else
		current = current->link;
	}
	if(found)
	return current->info.variable1;
}

template <class type>
string linkedListType<type>::getdesti(int zcount) //Function to return the destination
{
	nodeType<type> *current;
	current = first;
	bool found = false;
	while(current != NULL && !found)
	{
		if(current->info.variable3 == zcount)
		found = true;
		else
		current = current->link;
	}
	if(found)
	return current->info.variable2;
}

template <class type>
void linkedListType<type>::unvisitall() //Function to mark visit status of all cities as not visited
{
	nodeType<type> *current;
	current = first;
	while(current != NULL)
	{
		current->info.variable2 = "NO";
		current = current->link;
	}
}

template <class type>
void linkedListType<type>::markvisited(string place) //Function to mark visit status of a city as visited
{
	nodeType<type> *current;
	current = first;
	bool found = false;
	while(current != NULL && !found)
	{
		if(current->info.variable1 == place)
		found = true;
		else
		current = current->link;
	}
	if(found)
	current->info.variable2 = "YES";
	
}

template <class type>
bool linkedListType<type>::checkvisited(string place) //Function to check visit status of a city
{
	nodeType<type> *current;
	current = first;
	bool found = false;
	while(current != NULL && !found)
	{
		if(current->info.variable1 == place)
		found = true;
		else
		current = current->link;
	}
	if(found)
	{
		if(current->info.variable2 == "NO")
		return true;
		else if(current->info.variable2 == "YES")
		return false;
	}
}

template <class type>
string linkedListType<type>::getnext(string place, linkedListType<type> list) //Function to get next city
{
	nodeType<type> *current;
	current = first;
	bool found = false;
	while(current != NULL && !found)
	{
		if(current->info.variable1 == place && list.checkvisited(current->info.variable2) == true)
		found = true;
		else
		current = current->link;
	}
	if(found)
	return current->info.variable2;
	else
	return "NO_CITY";
}

template <class type>
bool linkedListType<type>::exist(string place)
{
	nodeType<type> *current;
	current = first;
	bool found = false;
	while(current != NULL && !found)
	{
		if(current->info.variable1 == place)
		found = true;
		else
		current = current->link;
	}
	if(found)
	return true;
	else
	return false;
}

#endif
