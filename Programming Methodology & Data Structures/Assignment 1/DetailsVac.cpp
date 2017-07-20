#include <iostream>
#include "DetailsVac.h"

using namespace std;

DetailsVac::DetailsVac()
{
	totalprice = 0, roomneeded = 0, vacationtype = 0, packagetype = 0, season = 0;
}

DetailsVac::~DetailsVac()
{
	totalprice = 0, roomneeded = 0, vacationtype = 0, packagetype = 0, season = 0;
}

void DetailsVac::passname(string name) //Function to pass the name of user from friend function to ContactPerson
{
	contact.receivename(name);
}

void DetailsVac::passcontactno(string contactno) //Function to pass the contact number of user from friend function to ContactPerson
{
	contact.receivecontactno(contactno);
}

void DetailsVac::passemail(string email) //Function to pass the email address of the user from friend function to ContactPerson
{
	contact.receiveemail(email);
}

void DetailsVac::calculateDetails() //Calculation for the total price of the vacation package
{
	totalprice = GetBasicPrice();
	if(vacationtype == 2)
	totalprice = totalprice + (basicprice * 0.05); //Extra charge for Relaxing & Adventure

	if(packagetype == 1) //Extra charge for luxury and comfort package type
	totalprice = totalprice + (basicprice * 0.35);
	else if(packagetype == 2)
	totalprice = totalprice + (basicprice * 0.15);
	
	if(region == 1 || region == 2 || region == 4)
	{
		if(season == 1 || season == 3)
		totalprice = totalprice + (basicprice * 0.07); //Extra charge for spring and autumn
		else if(season == 2)
		totalprice = totalprice + (basicprice * 0.10); //Extra charge for summer
		else if(season == 4)
		totalprice = totalprice - (basicprice * 0.18); //For Winter, discount is given
	}

	if(duration == 2) //Extra charge for 7 days vacation packages
	{
		if(packagetype == 1)
		totalprice = totalprice + (1500 * (adult + children));
		else if(packagetype == 2)
		totalprice = totalprice + (1000 * (adult + children));
		else if(packagetype == 3)
		totalprice = totalprice + (750 * (adult + children));
	}
	else if(duration == 3) //Extra charge for 12 days vacation packages
	{
		if(packagetype == 1)
		totalprice = totalprice + (3500 * (adult + children));
		else if(packagetype == 2)
		totalprice = totalprice + (1800 * (adult + children));
		else if(packagetype == 3)
		totalprice = totalprice + (1200 * (adult + children));
	}
	
	roomneeded = (adult + children) / peopleperroom; //Formula to calculate number of room needed
	if((adult + children) % peopleperroom != 0) //If remaining number of people is not same as the maximum number of people per room
	roomneeded++;
	
	totalprice = totalprice * 1.06; //GST is included in totalprice
}

void DetailsVac::showDetails() //Print all of the information of the chosen package by user
{
	system("cls");
	cout << endl << endl << "\t\t----------Final Information----------" << endl << endl;
	cout << "\t\tRegion: ";
	if(region == 1)
	cout << "Europe" << endl;
	else if(region == 2)
	cout << "Central Asia" << endl;
	else if(region == 3)
	cout << "South East Asia" << endl;
	else if(region == 4)
	cout << "East Asia" << endl;
	
	cout << "\t\tSeason: ";
	if(season == 0)
	cout << "No season is available" << endl;
	else if(season == 1)
	cout << "Spring" << endl;
	else if(season == 2)
	cout << "Summer" << endl;
	else if(season == 3)
	cout << "Autumn" << endl;
	else if(season == 4)
	cout << "Winter" << endl;
	
	cout << "\t\tPackage code: ";
	if(region == 1)
	{
		if(packagecode == 1)
		cout << "EU.1 Paris, Brussel, Amsterdam" << endl;
		else if(packagecode == 2)
		cout << "EU.2 Paris, Strasbourg, Luxemburg" << endl;
	}
	else if(region == 2)
	cout << "CA.1 Samarkand, Bukhara, Tashkent" << endl;
	else if(region == 3)
	{
		if(packagecode == 1)
		cout << "SEA.1 Kuala Lumpur, Penang, Langkawi" << endl;
		else if(packagecode == 2)
		cout << "SEA.2 Kuala Lumpur, Kuching, Kota Kinabalu" << endl;
	}
	else if(region == 4)
	{
		if(packagecode == 1)
		cout << "EA.1 Beijing, Shanghai, Hangzhou" << endl;
		else if(packagecode == 2)
		cout << "EA.2 Seoul, Sokcho" << endl;
		else if(packagecode == 3)
		cout << "EA.3 Seoul, Busan, Jeju" << endl;
		else if(packagecode == 4)
		cout << "EA.4 Tokyo, Osaka" << endl;
	}
	
	cout << "\t\tPreferred package type: ";
	if(packagetype == 1)
	cout << "Luxury" << endl;
	else if(packagetype == 2)
	cout << "Comfort" << endl;
	else if(packagetype == 3)
	cout << "Normal" << endl;
	
	cout << "\t\tNumber of people per room: ";
	if(peopleperroom == 2)
	cout << "2 people" << endl;
	else if(peopleperroom == 3)
	cout << "3 people" << endl;
	else if(peopleperroom == 4)
	cout << "4 people" << endl;
	
	cout << "\t\tType of vacation: ";
	if(vacationtype == 1)
	cout << "Sightseeing & Shopping" << endl;
	else if(vacationtype == 2)
	cout << "Relaxing & Adventure" << endl;
	
	cout << "\t\tDuration of vacation: ";
	if(duration == 1)
	cout << "5 days" << endl;
	else if(duration == 2)
	cout << "7 days" << endl;
	else if(duration == 3)
	cout << "12 days" << endl;
	
	cout << "\t\tNumber of adult: " << adult << endl;
	cout << "\t\tNumber of children: " << children << endl;
	
	cout << "\t\tNumber of room: " << roomneeded << endl << endl;
	
	cout << "\t\tYour name: " << contact.getname() << endl;
	cout << "\t\tYour contact number: " << contact.getcontactno() << endl;
	cout << "\t\tYour email address: " << contact.getemail() << endl << endl;
	
	ShowBasicPrice();
	cout << "\t\tThe final price is: RM" << totalprice << endl << endl;
	cout << "\t\tHave a nice day :)" << endl << endl;
}
