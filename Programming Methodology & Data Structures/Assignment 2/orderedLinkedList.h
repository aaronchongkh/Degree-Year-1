#include <iostream>
#ifndef ORDEREDLINKEDLIST_H
#define ORDEREDLINKEDLIST_H
#include <iomanip>
#include "linkedListType.h"
#include <fstream>

using namespace std;

template <class type>
class orderedLinkedList : public linkedListType<type>
{
	public:
		orderedLinkedList(); //Default constructor
		~orderedLinkedList(); //Destructor
		void addordered(type); //Function to add nodes in ordered linked list
		void displayall(); //Function to display all nodes in ordered linked list
		void displayotrbased(); //Function display nodes in ordered linked list from highest to lowest on the road price
		void displayparticular(string); //Function to display particular node in ordered linked list
		string checkengineno(string); //Function to check duplication of car engine number in input
		void readDataOrdered(); //Function to store car sales information from text file to temporary variables
		void addDataOrdered(string, string, string, int, double, double, double); //Function to assign temporary variables to variables in struct carInfo
		void writeData(); //Function to write car sales information from ordered linked list to text file
};



template <class type>
orderedLinkedList<type>::orderedLinkedList()
{
	
}

template <class type>
orderedLinkedList<type>::~orderedLinkedList()
{
	
}

template <class type>
void orderedLinkedList<type>::readDataOrdered()
{
	string engine, mod, col;
	int disp;
	double sellingp, retailp, otrprice;
	ifstream inData; //File stream declaration
	inData.open("CarDetails.txt"); //Open the text file
	while(inData >> engine) //When there is data to input after a "enter"
	{
		inData.ignore();
		getline(inData, mod);
		getline(inData, col);
		inData >> disp;
		inData.ignore();
		inData >> sellingp;
		inData.ignore();
		inData >> retailp;
		inData.ignore();
		inData >> otrprice;
		inData.ignore();
		
		addDataOrdered(engine, mod, col, disp, sellingp, retailp, otrprice); //Function call
	}
	inData.close(); //Close the text file
}

template<class type>
void orderedLinkedList<type>::addDataOrdered(string engine, string mod, string col, int disp, double sellingp, double retailp, double otrprice) //Function to assign temporary variables to variables in struct carInfo
{
	nodeType<type> *current;
	nodeType<type> *trail;
	nodeType<type> *newNode;
	bool found;
	newNode = new nodeType<type>;
	newNode->carInfo.engineno = engine; //Assigning variables
	newNode->carInfo.model = mod;
	newNode->carInfo.color = col;
	newNode->carInfo.displacement = disp;
	newNode->carInfo.sellingprice = sellingp;
	newNode->carInfo.retailprice = retailp;
	newNode->carInfo.ontheroad = otrprice;
	newNode->link = NULL;
	
	if(this->first == NULL) //When there is no linked list
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;
	}
	else
	{
		current = this->first;
		found = false;
		while(current != NULL && !found)
		{
			if(current->carInfo.ontheroad <= otrprice) //When on the price price inputted is larger than the one pointed by current
			found = true;
			else
			{
				trail = current;
				current = current->link;
			}
		}
		if(current == this->first) //Assign the inputted node in front of the first node
		{
			newNode->link = this->first;
			this->first = newNode;
			this->count++;
		}
		else //Assign the inputted node in front of the current
		{
			trail->link = newNode;
			newNode->link = current;
			
			if(current == NULL)
			this->last = newNode;
			
			this->count++;
		}
	}
}

template <class type>
void orderedLinkedList<type>::writeData()
{
	nodeType<type> *current;
	current = this->first;
	ofstream outData;
	outData.open("CarDetails.txt");
	while(current != NULL) //Write each node of the ordered linked list to text file
	{
		outData << current->carInfo.engineno << endl << current->carInfo.model << endl << current->carInfo.color << endl << current->carInfo.displacement << endl << current->carInfo.sellingprice << endl << current->carInfo.retailprice << endl << current->carInfo.ontheroad << endl << endl;
		current = current->link;
	}
	outData.close();
}

template <class type>
string orderedLinkedList<type>::checkengineno(string engine)
{
	nodeType<type> *current;
	current = this->first;
	while(current != NULL)
	{
		if(current->carInfo.engineno == engine) //To check the duplucation of the car engine number
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Engine number already exist. Please try again with another engine number: ";
			getline(cin, engine);
			while(engine.length() != 6 || engine.find_first_not_of("1234567890") != string::npos)
			{
				cin.clear();
				cin.ignore(100, '\n');
				cout << "Invalid input. Please try again: ";
				getline(cin, engine);
			}
			current = this->first; //To reset the current pointer to the first node
		}
		else
		current = current->link;
	}
	return engine;
}

template <class type>
void orderedLinkedList<type>::addordered(type carinfo)
{
	nodeType<type> *current;
	nodeType<type> *trail;
	nodeType<type> *newNode;
	
	bool found;
	
	newNode = new nodeType<type>;
	newNode->carInfo.engineno = carinfo.engineno; //Assigning variables
	newNode->carInfo.model = carinfo.model;
	newNode->carInfo.color = carinfo.color;
	newNode->carInfo.displacement = carinfo.displacement;
	newNode->carInfo.sellingprice = carinfo.sellingprice;
	newNode->carInfo.retailprice = carinfo.retailprice;
	newNode->carInfo.ontheroad = carinfo.ontheroad;
	newNode->link = NULL;
	
	if(this->first == NULL) //When there is no linked list
	{
		this->first = newNode;
		this->last = newNode;
		this->count++;
	}
	else
	{
		current = this->first;
		found = false;
		while(current != NULL && !found)
		{
			if(current->carInfo.ontheroad <= carinfo.ontheroad) //When on the road price inputted is larger than the one pointed by current
			found = true;
			else
			{
				trail = current;
				current = current->link;
			}
		}
		if(current == this->first) //Assign the inputted node in front of the first node
		{
			newNode->link = this->first;
			this->first = newNode;
			this->count++;
		}
		else //Assign the inputted node in front of the current
		{
			trail->link = newNode;
			newNode->link = current;
			
			if(current == NULL)
			this->last = newNode;
			
			this->count++;
		}
	}
}

template <class type>
void orderedLinkedList<type>::displayparticular(string searchengineno)
{
	nodeType<type> *current;
	bool found = false;
	current = this->first;
	while(current !=NULL && !found)
	{
		if(current->carInfo.engineno == searchengineno) //If the inputted car engine no is the same as the one pointed by current
		found = true;
		else
		current = current->link; //Current will point to the next node
	}
	if(found) //If found == true
	{
		cout << "Here is the car sales information: " << endl << endl;
		cout << "Car engine number: " << current->carInfo.engineno << endl;
		cout << "Model: " << current->carInfo.model << endl;
		cout << "Color: " << current->carInfo.color << endl;
		cout << "Displacement (cc): " << current->carInfo.displacement << endl;
		cout << "Car price:- " << endl;
		cout << "Selling price (inclusive of 6% GST): RM" << current->carInfo.sellingprice << endl;
		cout << "Retail price without insurance (inclusive of 6% GST): RM" << current->carInfo.retailprice << endl;
		cout << "On the road price with insurance (inclusive of 6% GST): RM" << current->carInfo.ontheroad << endl;
	}
	else //If found == false
	{
		cout << "Engine number doesn't exist! Please try again." << endl;
	}
	system("pause");
}

template <class type>
void orderedLinkedList<type>::displayotrbased()
{
	nodeType<type> *current;
	system("cls");
	current = this->first;
	cout << "Here is the car sales information based on the on the road price of the cars:" << endl << endl;
	cout << "Engine no." << "\t\t\t" << "Model" << setw(25) << "Color" << "\t" << "Disp." << "\t" << "Selling price" << "\t" << "Retail price" << setw(15) << "OTR price" << endl;
	while(current != NULL) //When current is pointing to any node
	{
		cout << setw(9) << current->carInfo.engineno << setw(28) << current->carInfo.model << setw(25) << current->carInfo.color << setw(6) << current->carInfo.displacement << setw(17) << current->carInfo.sellingprice << setw(15) << current->carInfo.retailprice << setw(15) << current->carInfo.ontheroad << endl;
		current = current->link; //Current points to the next node
	}
	cout << endl;
	cout << "Total number of cars sold is: " << this->count << endl << endl;
	system("pause");
}

template <class type>
void orderedLinkedList<type>::displayall()
{
	nodeType<type> *current;
	system("cls");
	current = this->first;
	cout << "Below is all of the car sales information:" << endl << endl;
	cout << "Engine no." << "\t\t\t" << "Model" << setw(25) << "Color" << "\t" << "Disp." << "\t" << "Selling price" << "\t" << "Retail price" << setw(15) << "OTR price" << endl;
	while(current != NULL) //When current is pointing to any node
	{
		cout << setw(9) << current->carInfo.engineno << setw(28) << current->carInfo.model << setw(25) << current->carInfo.color << setw(6) << current->carInfo.displacement << setw(17) << current->carInfo.sellingprice << setw(15) << current->carInfo.retailprice << setw(15) << current->carInfo.ontheroad << endl;
		current = current->link; //Current points to the next node
	}
	cout << endl;
	cout << "Total number of cars sold is: " << this->count << endl << endl;
	system("pause");
}

#endif
