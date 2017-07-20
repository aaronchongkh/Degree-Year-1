#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include "orderedLinkedList.h"
#include "unorderedLinkedList.h"
#include <cassert>
#include <fstream>

using namespace std;

void welcome();
void menu();
void menu2();
void menu3();
int validation(int, int);
string validation2(int);
double validation3();
int main()
{
	int choice, choice2, choice3, selection; //Variables declaration
	string searchengineno;
	string addengineno;
	char proceed = 'Y';
	unorderedLinkedList<carInfo> car1; //Declaration of objects
	orderedLinkedList<carInfo> car2;
	carInfo carinfo; //Declaration of struct carInfo
	cout << fixed << showpoint << setprecision(2); //Set into 2 decimal point
	
	car1.readDataUnordered(); //Function to read text file into unordered linked list
	car2.readDataOrdered(); //Function to read text file into ordered linked list
	welcome();
	while(proceed == 'Y' || proceed == 'y') //While loop for looping the whole program
	{
		system("cls");
		menu(); //Main menu
		choice = validation(0, 3);
		switch(choice)
		{
			case 0: car2.writeData(); //Function to store ordered linked list into text file
					return 0;
			case 1: system("cls");
					cout << endl << endl << endl;
					cout << "\t\t\tPlease enter the car engine number of the car: ";
					addengineno = validation2(1); //Validation function for car engine number
					carinfo.engineno = car2.checkengineno(addengineno); //Function to check the duplication of car engine number in linked list
					
					cout << "\t\t\tPlease enter the model of the car: ";
					getline(cin, carinfo.model);
					
					cout << "\t\t\tPlease enter the color of the car: ";
					carinfo.color = validation2(2); //Validation function for color of the cara
					
					cout << "\t\t\tPlease enter the displacement (cc) of the car: ";
					carinfo.displacement = validation(1000, 9999); //Validation function for displacement (cc) of the car
					
					cout << "\t\t\tPlease enter the selling price of the car (inclusive of 6% GST): RM";
					carinfo.sellingprice = validation3(); //Validation function for selling price of the car
					
					cout << "\t\t\tPlease enter the retail price without insurance (inclusive of 6% GST): RM";
					carinfo.retailprice = validation3(); //Validation function for retail price of the car
					
					cout << "\t\t\tPlease enter the on the road price with insurance (inclusive of 6% GST): RM";
					carinfo.ontheroad = validation3(); //Validation function for on the road price of the car
					
					cout << "\t\t\tFor unordered linked list, do you want to..." << endl; //Ask user to input first or input last in unordered linked list
					cout << "\t\t\t1. - Insert first" << endl;
					cout << "\t\t\t2. - Insert last" << endl << endl;
					cout << "\t\t\tYour selection: ";
					selection = validation(1, 2);
					car2.addordered(carinfo); //Insert information as a node in ordered linked list
					if(selection == 1)
					car1.insertfirst(carinfo); //Insert first in unordered linked list
					else if(selection == 2)
					car1.insertlast(carinfo); //Insert last in unordered linked list
					continue;
			case 2: menu2(); //Menu for deletion of information
					choice2 = validation(0, 2);
					switch(choice2)
					{
						case 0: menu(); //Main menu
								continue;
						case 1: system("cls");
								cout << endl << endl << endl;
								cout << "\t\t\tPlease enter the car engine number that you wished to delete: ";
								searchengineno = validation2(1);
								car1.deleteparticular(searchengineno); //Function to delete one node in unordered linked list
								car2.deleteparticular(searchengineno); //Function to delete one node in ordered linked list
								system("pause");
								continue;
						case 2: car1.deleteall(); //Function to delete all nodes in unordered linked list
								car2.deleteall(); //Function to delete all nodes in ordered linked list
								continue;
					}
			case 3: menu3();
					choice3 = validation(0, 3);
					switch(choice3)
					{
						case 0: menu();
								continue;
						case 1: system("cls");
								cout << "Please enter the car engine number that you want to find: ";
								searchengineno = validation2(1);
								car2.displayparticular(searchengineno); //Function to display one node in ordered linked list
								continue;
						case 2: car2.displayotrbased(); //Function to display from highest to lowest on the road price
								continue;
						case 3: car2.displayall(); //Function to display all nodes in ordered linked list
								continue;
					}
		}
		cout << "\t\t\tDo you want to continue? Y/y for yes, any key to exit: ";
		cin >> proceed;
	}
	car2.writeData(); //Function to store ordered linked list into text file
	return 0;
}

void welcome() //First welcome screen of the program
{
	cout << endl << endl << endl << "\t\t\t";
	char welcome1[] = {'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o', '.', '.', '.'};
	for(int i = 0; i < 13; i++)
	{
		cout << welcome1[i];
		Sleep(50);
	}
	for(int j = 0; j < 3; j++)
	{
		system("cls");
		Sleep(300);
		cout << endl << endl << endl << "\t\t\t";
		cout << "Welcome to..." << endl << endl;
		cout << "\t\t\tHonda Cars Sales Displayer";
		Sleep(300);
	}
}

void menu() //Main menu
{
	system("cls");
	cout << endl << endl;
	cout << "\t\t\tHonda Cars Sales Displayer" << endl;
	cout << "\t\t_________________________________________" << endl;
	cout << "\t\t\t\tMain Menu" << endl;
	cout << "\t\t_________________________________________" << endl;
	cout << "\t\t\t1. - Add car sales information" << endl;
	cout << "\t\t\t2. - Delete car sales information" << endl;
	cout << "\t\t\t3. - Display car sales information" << endl << endl;
	cout << "\t\t_________________________________________" << endl;
	cout << "\t\t\t0. - Exit program" << endl;
	cout << "\t\t_________________________________________" << endl;
	cout << "\t\t\tPlease enter your choice: ";
}

void menu2() //Menu of deletion of nodes
{
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\tPlease choose one of the following: " << endl;
	cout << "\t\t\tDo you want to..." << endl << endl;
	cout << "\t\t\t1. - Delete particular car sales information" << endl;
	cout << "\t\t\t2. - Delete all car sales information" << endl << endl;
	cout << "\t\t\tOr" << endl << endl;
	cout << "\t\t\t0. - Go back"<< endl << endl;
	cout << "\t\t\tPlease select: ";
}

void menu3() //Menu for displaying nodes of ordered linked list
{
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t\tPlease choose one of the following: " << endl;
	cout << "\t\t\tDisplay..." << endl << endl;
	cout << "\t\t\t1. - The particular car sales information" << endl;
	cout << "\t\t\t2. - The details car sales information based on the car on road price" << endl;
	cout << "\t\t\t3. - All car sales information" << endl << endl;
	cout << "\t\t\tOr" << endl << endl;
	cout << "\t\t\t0. - Go back" << endl << endl;
	cout << "\t\t\tPlease select: ";
}

int validation(int min, int max) //Validation function for int type data type
{
	int input;
	cin >> input;
	while(!cin || cin.get() != '\n' || input < min || input > max)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\t\tInvalid input. Please try again: ";
		cin >> input;
	}
	return input;
}


string validation2(int mode) //Validation function for string type data type
{
	string input;
	getline(cin, input);
	switch(mode)
	{
		case 1: while(input.length() != 6 || input.find_first_not_of("1234567890") != string::npos)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tInvalid input. Please try again: ";
					getline(cin, input);
				}
				break;
		case 2: while(input.find_first_not_of("abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ") != string::npos)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tInvalid input. Please try again: ";
					getline(cin, input);
				}
				break;
	}
	return input;
}

double validation3() //Validation function for double type data type
{
	double input;
	cin >> input;
	while(!cin || input <= 0 || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\t\tInvalid input. Please try again: RM";
		cin >> input;
	}
	return input;
}
