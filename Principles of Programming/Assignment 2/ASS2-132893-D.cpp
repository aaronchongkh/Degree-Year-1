#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{
	int unit, totalunit, accutotalunit, semester, course, i, j;
	string grade;
	double gp, gpa, cgpa, totalgp, accutotalgp;
	char proceed ='Y';
	
	while (proceed == 'Y' || proceed == 'y') //Loop for continuation of usage of the program
	{
	system("cls"); //Command to clear the screen
	
	totalunit = 0;
	gpa = 0, cgpa = 0, totalgp = 0, accutotalgp = 0, totalunit = 0, accutotalunit = 0;
	cout << fixed << showpoint << setprecision(2);
	
	cout << "--------------------------------------------------" << endl;
	cout << "|                                                 |" << endl;
	cout << "|		CGPA Calculator			  |" << endl;
	cout << "|                                                 |" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "Welcome to CGPA Calculator!" << endl;
	cout << "This program can help you to calculate your GPA and also CGPA!" << endl;
	
	cout << "Please enter the number of semester you have gone through: ";
	cin >> semester;
	while (semester <= 0 || semester > 10 || !cin)
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "Invalid input. The number of semester cannot be less than 0 or more than 10." << endl;
		cout << "Please try again: ";
		cin >> semester;
	}
	cout << endl;

	for (i = 0; i < semester; ++i) //Loop for semester
	{
		cout << "For Semester " << i+1 << endl;
		cout << "Please enter the number of courses you have taken: ";
		cin >> course;
		while (course < 0 || course > 6 || !cin) //Loop to prevent invalid input
		{
			cin.clear(); //Line to clear recent input
			cin.ignore(100,'\n'); //Line to ignore input
			cout << "The number of courses cannot be less than 0 or more than 6." << endl;
			cout << "Please try again: ";
			cin >> course;
		}
		cout << endl;
		
		for(j = 0; j < course; ++j) // Loop for number of course
		{
			cout << "For course " << j+1 << endl;
			cout << "Please enter the grade of the course: ";
			cin >> grade;
			while (grade!="A" && grade!="a" && grade!="A-" && grade!="a-" && grade!="B+" && grade!="b+" && grade!="B" && grade!="b" && grade!="B-" && grade!="b-" && grade!="C+" && grade!="c+" && grade!="C" && grade!="c" && grade!="C-" && grade!="c-" && grade!="D+" && grade!="d+" && grade!="D" && grade!="d" && grade!="D-" && grade!="d-" && grade!="F" && grade!="f") //Loop to prevent invalid input
			{
				cin.clear();
				cin.ignore(100,'\n');
				cout << "Invalid input. Please enter again: ";
				cin >> grade;
			}
			cout << "Please enter the unit of the course: ";
			cin >> unit;
			while (unit < 0 || !cin) //Loop to prevent invalid input for unit of course
			{
				cin.clear();
				cin.ignore(100,'\n');
				cout << "The unit of the course cannot be less than zero. Please enter again: ";
				cin >> unit;
			}
			cout << endl;
					
			if (grade == "A" || grade == "a")
			gp = 4.00;
			else if (grade == "A-" || grade == "a-")
			gp = 3.67;
			else if (grade == "B+" || grade == "b+")
			gp = 3.33;
			else if (grade == "B" || grade == "b")
			gp = 3.00;
			else if (grade == "B-" || grade == "b-")
			gp = 2.67;
			else if (grade == "C+" || grade == "c+")
			gp = 2.33;
			else if (grade == "C" || grade == "c")
			gp = 2.00;
			else if (grade == "C-" || grade == "c-")
			gp = 1.67;
			else if (grade == "D+" || grade == "d+")
			gp = 1.33;
			else if (grade == "D" || grade == "d")
			gp = 1.00;
			else if (grade== "D-" || grade == "d-")
			gp = 0.67;
			else if (grade == "F" || grade == "f")
			gp = 0.00;
		
			totalunit = totalunit + unit;
			totalgp = totalgp + (unit * gp);
			gpa = totalgp / totalunit;
		}
		cout << "Your GPA is: " << gpa << endl;
		cout << endl;
		accutotalgp = accutotalgp + totalgp;
		accutotalunit = accutotalunit + totalunit;
		totalgp = 0, totalunit = 0;
	}
	
	cgpa = accutotalgp / accutotalunit;
	cout << endl;
	cout << "Congratulations!" << endl;
	cout << "Your CGPA is: " << cgpa << endl;
	if(cgpa >= 3.75 && cgpa <= 4.00)
	cout << "Excellent!" << endl;
	else if (cgpa >= 3.25 && cgpa <=3.74)
	cout << "Very Good!" << endl;
	else if (cgpa >= 2.75 && cgpa <= 3.24)
	cout << "Good!" << endl;
	else if (cgpa >= 2.25 && cgpa <= 2.74)
	cout << "Work Smart!" << endl;
	else if (cgpa >= 0.00 && cgpa <= 2.24)
	cout << "Work Very Hard and Work Smart!" << endl;
	cout << endl;
	cout << "Do you want to continue? (Y for yes, any key to exit): "; //Ask user to continue
	cin >> proceed;
	}
	
	system("pause");
	return 0;
}
	
