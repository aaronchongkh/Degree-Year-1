#ifndef CONTACTPERSON_H
#define CONTACTPERSON_H
#include <string>

using namespace std;

class ContactPerson
{
	public:
		void receivename(string);
		void receivecontactno(string);
		void receiveemail(string);
		string getname();
		string getcontactno();
		string getemail();
		ContactPerson();
		~ContactPerson();
	private:
		string name;
		string contactno;
		string email;
};

#endif
