#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>
#include "stackType.h"
#include "linkedListType.h"

using namespace std;

template <class type>
bool searchrecursion(string, string, linkedListType<type>, linkedListType<type>);
template <class type>
void readFile(linkedListType<type>&);
template <class type>
void readFile2(linkedListType<type>&);
template <class type>
void readFilesce(linkedListType<type>&);
void welcome();
void menu();
int main()
{
	int selection, count;
	string ori, desti;
	char proceed = 'Y';
	bool success;
	welcome();
	stackType<info> stack;
	linkedListType<info> list; //list is for linked list which is used to store available cities and visit status
	linkedListType<info> orindeslist; //orindeslist is for linked list which is used to store origin and destination
	linkedListType<info> scenarios; //scenarios is for linked list which is used to store requested origin and destination
	readFile(list); //Read textfile for list
	readFile2(orindeslist); //Read textfile for orindeslist
	readFilesce(scenarios); //Read textfile for scenarios
	while(proceed == 'Y' || proceed == 'y')
	{
		menu(); //Function to show the main menu
		cin >> selection;
		while(selection < 0 || selection > 4 || !cin || cin.get() != '\n') //Validation for menu
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input. Please try again: ";
			cin >> selection;
		}
		switch(selection)
		{
			case 0: system("cls");
					cout << "Exiting program. Have a nice day!" << endl;
					Sleep(600);
					return 0;
			case 1: system("cls");
					cout << "By using stack: " << endl;
					count = scenarios.getcount(); // Get total number of scenarios
					for(int i = 0; i < count; i++)
					{
						cout << "Scenario " << i+1 << ":" << endl;
						ori = scenarios.getori(i+1); //Get the origin of the requested scenario
						desti = scenarios.getdesti(i+1); //Get the destination of the requested scenario
						cout << "From " << ori << " to " << desti << endl;
						stack.searchPath(ori, desti, list, orindeslist); //Function to find the path by using stack
						cout << endl;
					}
					system("pause");
					continue;
					
			case 2: system("cls");
					cout << "By using recursion: " << endl;
					count = scenarios.getcount();
					for(int j = 0; j < count; j++)
					{
						cout << "Scenario " << j+1 << ":" << endl;
						ori = scenarios.getori(j+1); //get the origin of the requested scenario
						desti = scenarios.getdesti(j+1); //get the destination of the requested scenario
						cout << "From " << ori << " to " << desti << endl;
						list.unvisitall(); //Function to ensure that all cities are not visited at beginning of the search path
						success = searchrecursion(ori, desti, list, orindeslist); //Function to find the path by using recursion
						if(success == false)
						{
							cout << endl;
							cout << "The path is not exist." << endl;
						}
						cout << endl;
					}
					system("pause");
					continue;
					
			case 3: system("cls");
					list.displayall(); //Function to display all available cities
					system("pause");
					continue;
					
			case 4: system("cls");
					orindeslist.displayall2(); //Function to display all of the available one way flights
					system("pause");
					continue;
		}
		
	cout << "Do you want to start again? Y/y for yes, any key to exit: "; //For the loop of the whole program
	cin >> proceed;
	}
	return 0;
}

void welcome()
{
	cout << endl << endl << endl << "\t\t\t";
	char welcome1[] = {'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o', '.', '.', '.'};
	for(int i = 0; i < 13; i++)
	{
		cout << welcome1[i];
		Sleep(100);
	}
	for(int j = 0; j < 3; j++)
	{
		system("cls");
		cout << endl << endl << endl << "\t\t\t";
		cout << "Welcome to..." << endl << endl;
		cout << "\t\t\teFTAir - Plane Routes Checking Program" << endl << endl;
		Sleep(300);
		system("cls");
		Sleep(300);
		
	}
	cout << endl << endl << endl;
	cout << "\t\t\tWelcome to..." << endl << endl;
	cout << "\t\t\teFTAir - Plane Routes Checking Program" << endl << endl;
	cout << "\t\t\tBy - Flying Traveller Airline Company (FTAir)" << endl;
	Sleep(600);
}

void menu() //Function to show the main menu
{
	system("cls");
	cout << "Please choose one of the following methods: " << endl;
	cout << "1. Using stack" << endl;
	cout << "2. Using recursion" << endl << endl;
	cout << "Others..." << endl;
	cout << "3. Show all available cities" << endl;
	cout << "4. Show all available one way flights" << endl << endl;
	cout << "0. Exit" << endl;
	cout << "Please enter your choice: ";
}

template <class type>
void readFile(linkedListType<type>& list) //Read textfile for list
{
	int z = 0;
	ifstream inFile;
	info city;
	inFile.open("Cities.txt");
	while(!inFile.eof())
	{
		inFile >> city.variable1;
		city.variable2 = "NO";
		city.variable3 = ++z;
		list.insert(city);
	}
	inFile.close();
}

template <class type>
void readFile2(linkedListType<type>& orindeslist) //Read textfile for orindeslist
{
	int z = 0;
	ifstream inFile;
	info orindes;
	inFile.open("PairsOfCities.txt");
	while(!inFile.eof())
	{
		inFile >> orindes.variable1 >> orindes.variable2;
		orindes.variable3 = ++z;
		orindeslist.insert(orindes);
	}
	inFile.close();
}

template <class type>
void readFilesce(linkedListType<type>& scenarios) //Read textfile for scenarios
{
	int z = 0;
	ifstream inFile;
	info scenario;
	inFile.open("Scenario.txt");
	while(!inFile.eof())
	{
		inFile >> scenario.variable1 >> scenario.variable2;
		scenario.variable3 = ++z;
		scenarios.insert(scenario);
	}
	inFile.close();
}

template <class type>
bool searchrecursion(string ori, string desti, linkedListType<type> list, linkedListType<type> orindeslist) //Function to search path by recursion
{
	
	bool done, finalresult;
	string next; //Variable of storing next city
	if(!list.exist(ori))
	{
		cout << "Requested origin does not exist";
		return false;
	}
	if(!list.exist(desti))
	{
		cout << "Requested destination does not exist.";
		return false;
	}
	
	list.markvisited(ori); //Function to mark city as visited
	if(ori == desti) //If the origin is same as the destination
	{
		cout << desti;
		finalresult = true;
		cout << endl;
	}
	else
	{
		done = false;
		next = orindeslist.getnext(ori, list); //Function to get next city
		if(next != "NO_CITY") //Print origin if it has unvisited cities
		cout << ori << "->";
		while(!done && next != "NO_CITY") //While loop if the condition is true
		{
			done = searchrecursion(next, desti, list, orindeslist); //Recursion starts here
			if(!done) //This will be executed based on the boolean value returned by the recursion
			next = orindeslist.getnext(ori, list); //Function to get next available city if the original next city has no any available cities
		}
		finalresult = done;
	}
	return finalresult;
}
