#ifndef BASICVAC_H
#define BASICVAC_H

class BasicVac
{
	public:
		void CalBasicPrice();
		void ShowBasicPrice();
		double GetBasicPrice();
		BasicVac();
		~BasicVac();
	protected:
		int adult;
		int children;
		int region;
		int duration;
		double basicprice;
		double discount;
};

#endif
