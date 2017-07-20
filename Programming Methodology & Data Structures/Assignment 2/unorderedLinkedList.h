#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H
#include <iostream>
#include "linkedListType.h"
#include <cassert>
#include <fstream>

using namespace std;

template <class type>
class unorderedLinkedList : public linkedListType<type>
{
	public:
		unorderedLinkedList(); //Default constructor
		~unorderedLinkedList(); //Destructor
		void insertfirst(type); //Function to insert as the first node of the unordered linked list
		void insertlast(type); //Function to insert as the last node of the unordered linked list
		void readDataUnordered(); //Function to store car sales information from text file to temporary variables
		void addDataUnordered(string, string, string, int, double, double, double); //Function to assign temporary variables to variables in struct carInfo
};

template<class type>
unorderedLinkedList<type>::unorderedLinkedList()
{
	
}

template<class type>
unorderedLinkedList<type>::~unorderedLinkedList()
{
	
}

template<class type>
void unorderedLinkedList<type>::readDataUnordered()
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
		
		addDataUnordered(engine, mod, col, disp, sellingp, retailp, otrprice); //Function call
	}
	inData.close(); //Close the text file
}

template<class type>
void unorderedLinkedList<type>::addDataUnordered(string engine, string mod, string col, int disp, double sellingp, double retailp, double otrprice) //Function to assign temporary variables to variables in struct carInfo
{
	nodeType<type> *newNode;
	newNode = new nodeType<type>;
	newNode->carInfo.engineno = engine;
	newNode->carInfo.model = mod;
	newNode->carInfo.color = col;
	newNode->carInfo.displacement = disp;
	newNode->carInfo.sellingprice = sellingp;
	newNode->carInfo.retailprice = retailp;
	newNode->carInfo.ontheroad = otrprice;
	
	if(this->first == NULL) //When there is no linked list
	{
		this->first = newNode;
		this->last = newNode;
	}
	else
	{
		this->last->link = newNode; //insert last
		this->last = newNode;
		newNode->link = NULL;
	}
}

template <class type>
void unorderedLinkedList<type>::insertfirst(type carinfo)
{
	nodeType<type> *newNode;
	newNode = new nodeType<type>;
	assert(newNode != NULL);
	newNode->carInfo.engineno = carinfo.engineno; //Assigning variables
	newNode->carInfo.model = carinfo.model;
	newNode->carInfo.color = carinfo.color;
	newNode->carInfo.displacement = carinfo.displacement;
	newNode->carInfo.sellingprice = carinfo.sellingprice;
	newNode->carInfo.retailprice = carinfo.retailprice;
	newNode->carInfo.ontheroad = carinfo.ontheroad;
	newNode->link = this->first;
	this->first = newNode;
	if(this->last == NULL) //If last points to nothing
	{
		this->last = newNode; //Last pointer points to newNode
		newNode->link = NULL;
	}
}

template <class type>
void unorderedLinkedList<type>::insertlast(type carinfo)
{
	nodeType<type> *newNode;
	newNode = new nodeType<type>;
	assert(newNode != NULL);
	newNode->carInfo.engineno = carinfo.engineno;
	newNode->carInfo.model = carinfo.model;
	newNode->carInfo.color = carinfo.color;
	newNode->carInfo.displacement = carinfo.displacement;
	newNode->carInfo.sellingprice = carinfo.sellingprice;
	newNode->carInfo.retailprice = carinfo.retailprice;
	newNode->carInfo.ontheroad = carinfo.ontheroad;
	
	if(this->first == NULL) //If there is no linked list
	{
		this->first = newNode;
		this->last = newNode;
		newNode->link = NULL;
	}
	else
	{
		this->last->link = newNode;
		this->last = newNode;
		newNode->link = NULL;
	}
}

#endif
