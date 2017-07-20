#include <iostream> //To enable the input and output function

using namespace std;

const double PI = 3.142; //Set the constant pie = 3.142

int main()
{
	double circumference, price, radius, pricepersq, area; //Declare the variables as double data type
	
	cout << "Please enter the circumference of the pizza in centimeter: ";
	cin >> circumference;
	
	cout << "Please enter the price of the pizza: ";
	cin >> price;
	
	radius = circumference / (2 * PI); //Formula to find the radius of pizza
	area = PI * radius * radius; //Formula to find the area of the pizza
	pricepersq = price / area; // Formula to find the price per centimeter square of the pizza
	
	cout << "Circumference of the pizza in centimeter: " << circumference << endl;
	cout << "Price of the pizza: " << price << endl;
	cout << "Radius of the pizza in centimeter: " << radius << endl;
	cout << "Price of the pizza per square centimeter: " << pricepersq << endl;
	
	return 0;
}
