#include <iostream>

using namespace std;

int main()
{
	int min, max, a, b, c;
	
	cout << "Please enter the minimum number for the range: ";
	cin >> min;
	cout << "Please enter the maximum number for the range: ";
	cin >> max;
	
	a = min + (max - min) / 2 * 6 / 4; //Formula to generate first number
	b = min + (max - min) * 6 / 2 / 3; //Formula to generate second number
	c = min + (max - min) / 5 * 8 / 5; //Formula to generate third number
	
	cout << "The 3 lucky numbers are: " << a << " " << b << " " << c << endl;
	cout << "Congratulations!";
	
	return 0;
}
