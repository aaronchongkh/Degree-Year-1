#ifndef DETAILSVAC_H
#define DETAILSVAC_H

#include "BasicVac.h"
#include "ContactPerson.h"

using namespace std;

class DetailsVac : public BasicVac
{
	friend void input(DetailsVac&);
	public:
		void calculateDetails();
		void showDetails();
		void passname(string);
		void passcontactno(string);
		void passemail(string);
		DetailsVac();
		~DetailsVac();
	private:
		double totalprice;
		int roomneeded;
		int vacationtype;
		int packagetype;
		int season;
		int packagecode;
		int peopleperroom;
		ContactPerson contact;
		int maxpeople;
		int minpeople;
};

#endif
