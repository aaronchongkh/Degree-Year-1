#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <windows.h>
#include "DetailsVac.h"
#include <string>

using namespace std;

int validation(int, int);
string validation2(int);
void welcome();
void loading();
void title();
int main()
{
	char proceed = 'Y';
	DetailsVac details1; //Definining object of DetailsVac
	cout << fixed << showpoint << setprecision(2);
	system("color 8F");
	while(proceed == 'Y' || proceed == 'y')
	{
		system("cls");
		welcome();
		title();
		Sleep(1500);
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl <<  "\t\t\t\t\t\tLet's get started." << endl;
		Sleep(800);
		input(details1); //friend function is being used to receive inputs from user
		details1.CalBasicPrice();
		details1.ShowBasicPrice();
		loading();
		details1.calculateDetails();
		details1.showDetails();
		cout << "Do you want to try again? Y or y for yes, any key for exit." << endl << "Please enter your choice: ";
		cin >> proceed;
	}
	system("pause");
	return 0;
}

int validation(int min, int max) //Validation function for all the inputs for integer value, minimum and maximum value are passed in as the range of selection
{
	int input;
	cin >> input;
	while(input < min || input > max || !cin || cin.get() != '\n')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << endl << "\t\t\tInvalid input. Please try again: ";
		cin >> input;
	}
	return input;
}

string validation2(int mode) //Validation function for name, contact number and email address
{
	string input;
	bool isemail = false;
	switch(mode) //3 modes for 3 types of validation, depending on the parameter received
	{
		case 1: getline(cin, input);
				while(input.find_first_of("`1234567890-=/*+~!@#$%^&*()[]{}|;'"":/.,<>?") != string::npos)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl << endl << "\t\t\tInvalid input! Please enter your name again: ";
					getline(cin, input);
				}
				break;
		case 2: getline(cin, input);
				while(input.length() < 10 || input.length() > 11 || input[0] != '0' || (input.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz`-=/*+~!@#$%^&*() []{}|;'" ":/.,<>?") != string::npos))
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl << endl << "\t\t\tInvalid input. Please enter your phone number again: ";
					getline(cin, input);
				}
				break;
		case 3: getline(cin, input);
				while(!isemail)
				{
					if(input.find(".com") != string::npos && input.find("@") != string::npos) //Validation for .com
					isemail = true;
					else
					{
						cin.clear();
						cin.ignore(100, '\n');
						cout << endl << endl << "\t\t\tInvalid input. Please enter your email address again: ";
						getline(cin, input);
					}
				}
				while(input.find_first_of("`~!#$%^&*()_+-=,< >?/;:'" "'[]{}\|") != string::npos)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << endl << endl << "\t\t\tInvalid input. Please enter your email address again: ";
					getline(cin, input);
				}
				break;
	}
	return input;
}

void loading() //function for the loading screen
{
	char c = '_';
	for(int i = 0; i <=100; i++)
	{
		system("cls");
		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\tLoading... " << i << "%" << endl << endl << endl;
		for(int j = 0; j < i; j++)
		{
			cout << c;
		}
		Sleep(1);
	}
}

void welcome() //function for the welcome screen
{
	cout << endl << endl << endl << endl << endl << "\t\t\t\t\t\t";
	char c[13] = {'W', 'e', 'l', 'c', 'o', 'm', 'e', ' ', 't', 'o', '.', '.', '.'};
	for(int i = 0; i < 13; i++)
	{
		cout << c[i];
		Sleep(100);
	}
}

void title() //Introduction for the program
{
	for(int i = 0; i < 3; i++)
	{	
		system("cls");
		Sleep(400);
		cout << endl << endl << endl << endl << endl << "\t\t\t\t\t\tWelcome to...";
		cout << endl << endl << endl;
		cout << " \t\t\t\tMyDreamV - Your Personal Vacation Cost Estimator" << endl << endl;
		cout << "\t\t\t\tWe can help you to estimate the cost for your vacation " << endl;
		cout << "\t\t\t\t\t\tbased on your choice." << endl << endl << endl;
		cout << "\t\t\t\t\tBy Dream Vacation Company";
		Sleep(400);
	}
}
void input(DetailsVac& d) //friend function for receiving all the inputs from user
{
	string name, contactno, email;
	system("cls");
	cout << endl << endl << endl << "\t\t\tPlease select the region as the number mentioned below: " << endl << endl;
	cout << "\t\t\t1. Europe" << endl << "\t\t\t2. Central Asia" << endl << "\t\t\t3. South East Asia" << endl << "\t\t\t4. East Asia" << endl << endl;
	cout << "\t\t\tPlease enter your choice: ";
	d.region = validation(1, 4); //Parameters for validation are minimum and maximum values allowed for the selection
	system("cls");
	if(d.region == 1 || d.region == 2 || d.region == 4) //Only Europe, Central Asia and East Asia have selection for season
	{
		cout << endl << endl << endl << "\t\t\tPlease select the season that you want to have during your vacation: " << endl << endl;
		cout << "\t\t\t1. Spring" << endl << "\t\t\t2. Summer" << endl << "\t\t\t3. Autumn" << endl << "\t\t\t4. Winter" << endl << endl;
		cout << "\t\t\tPlease enter your choice: ";
		d.season = validation(1, 4);
	}
	else if(d.region == 3)
	d.season = 0; //South East Asia countries do not have season
	system("cls");
	if(d.region == 1) //Package code will be shown to user by referring to chosen region respectively
	{
		cout << endl << endl << endl << "\t\t\tPlease type the package code as listed below: " << endl << endl;
		cout << "\t\t\t1 - EU.1 Paris, Brussel, Amsterdam" << endl << "\t\t\t2 - EU.2 Paris, Strasbourg, Luxemburg" << endl << endl;
		cout << "\t\t\tPlease enter your choice: ";
		d.packagecode = validation(1, 2);
	}
	if(d.region == 2)
	{
		cout << endl << endl << endl << "\t\t\tPlease type the package code as listed below: " << endl << endl;
		cout << "\t\t\t1 - CA.1 Samarkand, Bukhara, Tashkent" << endl << endl;
		cout << "\t\t\tPlease enter your choice: ";
		d.packagecode = validation(1,1);
	}
	if(d.region == 3)
	{
		cout << endl << endl << endl << "\t\t\tPlease type the package code as listed below: " << endl << endl;
		cout << "\t\t\t1 - SEA.1 Kuala Lumpur, Penang, Langkawi" << endl << "\t\t\t2 - SEA.2 Kuala Lumpur, Kuching, Kota Kinabalu" << endl << endl;
		cout << "\t\t\tPlease enter your choice: ";
		d.packagecode = validation(1, 2);
	}
	if(d.region == 4)
	{
		cout << endl << endl << endl << "\t\t\tPlease type the package code as listed below: " << endl << endl;
		cout << "\t\t\t1 - EA,1 Beijing, Shanghai, Hangzhou" << endl << "\t\t\t2 - EA.2 Seoul, Sokcho" << endl << "\t\t\t3 - EA.3 Seoul, Busan, Jeju" << endl << "\t\t\t4 - EA.4 Tokyo, Osaka" << endl << endl;
		cout << "\t\t\tPlease enter your choice: ";
		d.packagecode = (validation(1, 4));
	}
	system("cls");
	cout << endl << endl << endl << "\t\t\tPlease select the perferred package type that you want: " << endl << endl;
	cout << "\t\t\t1. Luxury" << endl << "\t\t\t\t-35% extra charge on total basic price of the package" << endl << "\t\t\t\t-Stay in 5 star hotel, maximum 2 people in a room"<< endl << "\t\t\t\t-Extra 2 meals are provided" << endl << "\t\t\t\t-Minumum 5 people, Maximum 15 people" << endl << endl << 
	"\t\t\t2. Comfort" << endl << "\t\t\t\t-15% extra charge on total basic price of the package" << endl << "\t\t\t\t-Stay in 3/4 star hotel, maximum 3 people in a room" << endl << "\t\t\t\t-Minimum 10 people, Maximum 20 people" << endl << 
	"\t\t\t3. Normal" << "\t\t\t\t-No extra charge" << endl << "\t\t\t\t-Stay in 3 star hotel, 3-4 people in a room" << endl << "\t\t\t\t-Minimum 20 people, maximum 30 people" << endl << endl;
	cout << "\t\t\tPlease enter your choice: ";
	d.packagetype = validation(1, 3);
	
	if(d.packagetype == 1) //For luxury package type
	{
		d.peopleperroom = 2;
		d.minpeople = 5;
		d.maxpeople = 15;
	}
	else if(d.packagetype == 2) //For comfort pacakge type
	{
		d.peopleperroom = 3;
		d.minpeople = 10;
		d.maxpeople = 20;
	}
	else if(d.packagetype == 3) //For normal package type
	{
		d.peopleperroom = 4;
		d.minpeople = 20;
		d.maxpeople = 30;
	}
	system("cls");
	cout << endl << endl << endl << "\t\t\tPlease select the type of vacation as the number mentioned below: " << endl << endl;
	cout << "\t\t\t1. Sightseeing & Shopping" << endl << "\t\t\t2. Relaxing & Adventure" << endl << endl;
	cout << "\t\t\tPlease enter your choice: ";
	d.vacationtype = validation(1, 2);
	system("cls");
	cout << endl << endl << endl << "\t\t\tPlease select the duration of vacation that you want: " << endl << endl;
	cout << "\t\t\t1. 5 days - No extra charge" << endl;
	cout << "\t\t\t2. 7 days - Extra charge for each person: Luxury - RM1500, Comfort - RM1000, Normal - RM750" << endl;
	cout << "\t\t\t3. 12 days - Extra charge for each person: Luxury - RM3500, Comfort - RM1800, Normal - RM1200" << endl << endl;
	cout << "\t\t\tPlease enter your choice: ";
	d.duration = validation(1, 3);
	system("cls");
	cout << endl << endl << endl << "\t\t\tPlease enter the number of adult: ";
	d.adult = validation(0, 30);
	cout << endl << endl;
	cout << endl << endl << "\t\t\tPlease enter the number of children: ";
	d.children = validation(0, 30);
	while((d.adult + d.children) < d.minpeople || (d.adult + d.children) > d.maxpeople) //While loop for detecing the total number of people involved in the vacation package
	{
		system("cls");
		cout << endl << endl << endl << "\t\t\tInvalid total number of people. Total number of people must be at least " << d.minpeople << " and at most " << d.maxpeople << "." << endl << "\t\t\tTry again. " << endl << endl;
		cout << "\t\t\tPlease enter the number of adult: ";
		d.adult = validation(0, 30);
		cout << endl << endl;
		cout << "\t\t\tPlease enter the number of children: ";
		d.children = validation(0, 30);
	}
	
	system("cls");
	cout << endl << endl << endl << "\t\t\tPlease enter your name: ";
	name = validation2(1);
	d.passname(name);
	
	cout << endl << endl << "\t\t\tPlease enter your contact number: ";
	contactno = validation2(2);
	d.passcontactno(contactno);
	
	cout << endl << endl << "\t\t\tPlease enter your email address: ";
	email = validation2(3);
	d.passemail(email);
}

