#include <iostream>
#include "ContactPerson.h"

ContactPerson::ContactPerson()
{
	name = " "; contactno = " "; email = " ";
}

ContactPerson::~ContactPerson()
{
	name = " "; contactno = " "; email = " ";
}

void ContactPerson::receivename(string n) //Function which is used to receive name of the user
{
	name = n;
}

void ContactPerson::receivecontactno(string c) //Function which is used to receive contact number of the user
{
	contactno = c;
}

void ContactPerson::receiveemail(string e) //Function which is used to receive email address of the user
{
	email = e;
}

string ContactPerson::getname() //Function used to return name of the user
{
	return name;
}

string ContactPerson::getcontactno() //Function used to return contact number of the user
{
	return contactno;
}

string ContactPerson::getemail() //Function used to return email address of the user
{
	return email;
}
