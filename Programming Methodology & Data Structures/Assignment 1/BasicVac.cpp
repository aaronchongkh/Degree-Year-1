#include <iostream>
#include "BasicVac.h"

using namespace std;

BasicVac::BasicVac()
{
	adult = 0, children = 0, region = 0, duration = 0;
}

BasicVac::~BasicVac()
{
	adult = 0, children = 0, region = 0, duration = 0;
}

void BasicVac::CalBasicPrice() //Calculation for the total basic price of the vacation package
{
	if(region == 1)
	basicprice = (adult * 3500) + (children * 2500);
	else if(region == 2)
	basicprice = (adult * 4800) + (children * 3700);
	else if(region == 3)
	basicprice = (adult * 2500) + (children * 2000);
	else if (region == 4)
	basicprice = (adult * 4500) + (children * 3500);
	
	if(adult >= 20) //Discount is given if number of adults is more than or equals to 20
	{
		discount = basicprice * 0.08;
		basicprice = basicprice - discount;
	}
}

void BasicVac::ShowBasicPrice() //Total basic price will be displayed
{
	cout << "\t\tTotal basic price of the package is: RM" << basicprice << endl;
}

double BasicVac::GetBasicPrice()
{
	return basicprice;
}
