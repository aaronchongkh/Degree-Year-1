#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

void numOfStudents(int[], string[], char[], string[], string[], int[], int&);
void menu();
void add(int[], string[], char[], string[], string[], int[], int);
void display(int[], string[], char[], string[], string[], int[], int);
void checkPoints(int[], string[], char[], string[], string[], int[], int, double);
double setWeighted(int[], int);
void showGender(int[], string[], char[], string[], string[], int[], int);
void showScore(int[], string[], char[], string[], string[], int[], int);
void showQualified(int[], string[], char[], string[], string[], int[], int, double);
void showCourse(int[], string[], char[], string[], string[], int[], int, double);
void showSpecific(int[], string[], char[], string[], string[], int[], int, double);
void updateScore(int[], string[], char[], string[], string[], int[], int);
int main()
{
	int n = 1000;
	int matric[n], score[n], selection, listselect;
	string course[n], name[n], contact[n];
	char gender[n];
	char proceed = 'Y';
	double weightedScore = -1;
	string password;
	char welcome[8] = {'W','E','L','C','O','M','E','!'};
	char ch;
	
	cout << fixed << showpoint << setprecision(2);
	
	system("color 3F");
	cout << endl << endl << endl << endl << endl << endl;
	cout << setw(50);
	for(int t = 0; t < 8; t++)
	{
		cout << welcome[t];
		Sleep(300); // Delay the time of showing the next thing for 300 milliseconds
	}
	
	
	while(proceed == 'Y' || proceed == 'y')
	{
	system("cls");
	system("color 8E");
	numOfStudents(matric, name, gender, course, contact, score, n);
	
	cout << "\t\t\t----------Total number of students in database: " << n << "----------" << endl << endl; // Shows the total number of students available in text file
	menu();
	cin >> selection;
	cout << endl;
	while(!cin || selection < 1 || selection > 8)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\t\tInvalid input. Please try again: ";
		cin >> selection;
		cout << endl;
	}
	
	if(selection == 1 || selection == 2 || selection == 3 || selection == 4 || selection == 5 || selection == 6)
	{
		system("cls");
		system("color 0A");
		cout << endl << endl << endl;
		cout << "\t\t\tFor hostel management officer, please enter the password: "; // Password to access to officer's functions is admin
		ch = getch();
		
		while(ch != 13) // Show typed keys as asterisks if enter key is not entered
		{
			password.push_back(ch);
			cout << "*";
			ch = getch();
		}
		
		cout << endl << endl;
		cout << "\t\t\tValidating.";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << ".";
		Sleep(500);
		cout << endl << endl;
		
		while(password != "admin") // Password to access to officer's functions is admin
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\t\t\tPassword incorrect! Please try again.";
			Sleep(500);
			system("cls");
			cout << endl << endl << endl;
			cout << "\t\t\tFor hostel management officer, please enter the password: ";
			password = "";
			ch = getch();
			while(ch != 13)
			{
				password.push_back(ch);
				cout << "*";
				ch = getch();
			}
			cout << endl << endl;
			cout << "\t\t\tValidating.";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << ".";
			Sleep(500);
			cout << endl;
		}
		cout << endl;
		cout << "\t\t\tPassword match!" << endl;
		Sleep(500);
	}
	
	switch(selection)
	{
		case 1: add(matric, name, gender, course, contact, score, n); // Function to add students' information
					continue;
		case 2: display(matric, name, gender, course, contact, score, n); // Function to display all students' information
				system("pause");
				system("cls");
				continue;
		case 3: system("cls");
				system("color 8F");
				cout << endl << endl << endl << endl;
				cout << "\t\t\tSearch a list of students by using..." << endl;
				cout << "\t\t\t1. - Minimum score" << endl;
				cout << "\t\t\t2. - Gender" << endl;
				cout << "\t\t\t3. - Qualifications" << endl;
				cout << "\t\t\t4. - Qualifications by course code" << endl;
				cout << "\t\t\tPlease enter your selection: ";
				cin >> listselect;
				while(!cin || listselect < 1 || listselect > 4)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tInvalid input. Please try again: ";
					cin >> listselect;
				}
				switch(listselect)
				{
					case 1: showScore(matric, name, gender, course, contact, score, n); // Function to display information of students who have more than the minimum score typed
							system("pause");
							break;
					case 2: showGender(matric, name, gender, course, contact, score, n); // Function to display information of students by gender
							system("pause");
							break;
					case 3: showQualified(matric, name, gender, course, contact, score, n, weightedScore); // Function to display information of qualified students
							system("pause");
							break;
					case 4: showCourse(matric, name, gender, course, contact, score, n, weightedScore); // Function to display information of students by course code
							system("pause");
							break;
					default: cout << "\t\t\tInvalid input!";
				}
				continue;
		case 4: showSpecific(matric, name, gender, course, contact, score, n, weightedScore); // Function to display information of specific students by matric number
				continue;
		case 5: weightedScore = setWeighted(score, n); // Function to set weighted score
				continue;
		case 6: updateScore(matric, name, gender, course, contact, score, n); // Function to update student's MyCSD score
				continue;
		case 7: checkPoints(matric, name, gender, course, contact, score, n, weightedScore); // Function to let students to check their MyCSD score and qualifications
				break;
		case 8: return 0;
		default: cout << "\t\t\tInvalid input!" << endl << endl;
	}
	
	
	
	cout << "\t\tDo you want to start again? Y/y for yes, other keys to exit.";
	cin >> proceed;
	}

	system("pause");
	return 0;
}

void numOfStudents(int matric[], string name[], char gender[], string course[], string contact[], int score[], int& number) // Function to count the number of students available in text file
{
	int i = 0;
	ifstream inData;
	inData.open("StudentMyCSD.txt");
	while(!inData.eof()) //Read the text file
	{
		inData >> matric[i] >> name[i] >> gender[i] >> course[i] >> contact[i] >> score[i];
		i++; // Increment of i for one time for each line of text file that has read
	}
	inData.close();
	
	number = i; // Assign i to number of students and pass back to main function by reference
}

void menu()
{
	cout << "\t\t\t------------------------------------------------------------" << endl;
	cout << " \t\t\t\t\t     1-Hostel USM (1Hostel)"<< endl;
	cout << "\t\t\t------------------------------------------------------------" << endl << endl;
	
	cout << "\t\t\t------------------------------------------------------------" << endl;
	cout << "\t\t\tFor Hostel Managing Officer..." << endl << endl;
	cout << "\t\t\t1. - Add student info..." << endl;
	cout << "\t\t\t2. - Display all student info..." << endl;
	cout << "\t\t\t3. - Display a list of students..." << endl;
	cout << "\t\t\t4. - Search for specific student..." << endl;
	cout << "\t\t\t5. - Set weighted percentage..." << endl;
	cout << "\t\t\t6. - Update specific student's score points..." << endl << endl;
	cout << "\t\t\t------------------------------------------------------------" << endl;
	cout << "\t\t\tFor students..." << endl << endl;
	cout << "\t\t\t7. - Check collected points and qualification status..." << endl;
	cout << endl;
	cout << "\t\t\t------------------------------------------------------------" << endl;
	cout << "\t\t\t8. - Exit program..." << endl;
	cout << "\t\t\t------------------------------------------------------------" << endl;
	cout << "\t\t\tPlease enter your choice: ";
	
	
}

void add(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number) //Function for add student's information
{
	system("cls");
	system("color 1F");
	int num;
	int i = 0;
	int addmatric, addscore;
	string addname, addcourse, addcontact;
	char addgender;
	cout << endl << endl << endl;
	cout << "\t\t\tPlease enter the amount of students that you want to input: ";
	cin >> num;
	while(!cin || num < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\t\tInvalid input. The amount of students must be in positive number." << endl;
		cout << "\t\t\tPlease try again: ";
		cin >> num;
	}
	cout << endl << endl << endl;
	ofstream outData;
	outData.open("StudentMyCSD.txt", ios::app);
	for(int j = 0; j < num; j++)
	{
		cout << "\t\t\tFor student " << j+1 << " :" << endl;
		cout << "\t\t\tPlease enter the matric number of student: ";
		cin >> addmatric;
		while(!cin || addmatric < 100000 || addmatric > 999999)
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\t\t\tInvalid input! Matric number must be in 6 digits integer!" << endl;
			cout << "\t\t\tPlease try again: ";
			cin >> addmatric;
		}
		for(i = 0; i < number; i++)
		{
			while(addmatric == matric[i])
			{
				cout << "\t\t\tMatric number is already existed! Please try with another matric number: ";
				cin >> addmatric;
				i = 0;
				while(!cin || addmatric < 100000 || addmatric > 999999)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tInvalid input! Matric number must be in 6 digits integer!" << endl;
					cout << "\t\t\tPlease try again: ";
					cin >> addmatric;
				}
			}
		}
		cout << endl << endl;
		
		cout << "\t\t\tPlease enter the name of student: ";
		cin >> addname;
		while(addname.find_first_of("`1234567890-=/*+~!@#$%^&*()[]{}|;'" ":/.,<>?") != string::npos) // Validation loop for non-alphabets input for name
		{
			cout << "\t\t\tInvalid input! Please enter again: ";
			cin >> addname;
		}
		cout << endl << endl;
		
		cout << "\t\t\tPlease enter the gender of student: ";
		cin >> addgender;
		while(addgender != 'M' && addgender != 'F')
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\t\t\tGender must be in 'M'- Male and 'F'- Female only" << endl;
			cout << "\t\t\tPlease try again: ";
			cin >> addgender;
		}
		cout << endl << endl;
		
		cout << "\t\t\tPlease enter the abbreviation of the course for student in capital letter: ";
		cin >> addcourse;
		while(addcourse.find_first_of("`1234567890-=/*+~!abcdefghijklmnopqrstuvwxyz@#$%^&*()[]{}|;'" ":/.,<>?") != string::npos) // Validation loop for non-alphabets inpyt for course code
		{
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\t\t\tInvalid input! Please try again: ";
			cin >> addcourse;
			
		}
		cout << endl << endl;
		
		cout << "\t\t\tPlease enter the contact number of student: ";
		cin >> addcontact;
		while(addcontact.length() < 10 || addcontact.length() > 11 || addcontact[0] != '0' || (addcontact.find_first_of("abcdefghijklmnopqrstuvwxyz`-=/*+~!@#$%^&*()[]{}|;'" ":/.,<>?") != string::npos)) // Validation loop for non-digit input for contact number
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "\t\t\tInvalid input. Please try again: ";
			cin >> addcontact;
		}
		cout << endl << endl;
		
		cout << "\t\t\tPlease enter the score obtained by student: ";
		cin >> addscore;
		while(!cin || addscore < 0)
		{
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\t\t\tInvalid input. The score must be in positive number only." << endl;
			cout << "\t\t\tPlease try again: ";
			cin >> addscore;
		}
		cout << endl << endl;
		outData << endl << addmatric << " " << addname << " " << addgender << " " << addcourse << " " << addcontact << " " << addscore;
	}
	outData.close();
	
	cout << "\t\t\tProcessing.";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << endl;
	cout << "\t\t\tDone!";
	Sleep(500);
	
}

void display(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number) // Function to display all students' information
{
	for(int z = 0; z < 2; z++)
	{
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(50) << "LOADING.";
		Sleep(400);
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl;;
		cout << setw(51) << "LOADING..";
		Sleep(400);
		system("cls");
		cout << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << setw(52) << "LOADING...";
		Sleep(400);
	}
	system("cls");
	system("color 8F");
	int i = 0;
	cout << endl;
	cout << "\t\t" << "Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
	}
	cout << endl;
	cout << "\t\t\t\t\t\tStudents found: " << i << endl << endl;
	cout << "\t\t\t";
}

void showScore(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number) // Function to display students' information which is above the score inputted
{
	system("cls");
	system("color 8F");
	int findscore;
	int exist = 0;
	int i = 0;
	cout << endl << endl << endl;
	cout << "\t\tPlease enter the minimum score that you want to find: ";
	cin >> findscore;
	while(!cin || findscore < 0)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\t\tInvalid input! Please try again: ";
		cin >> findscore;
	}
	
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\tThe students who have the score higher than " << findscore << " is: " << endl;
	cout << "\t\t" <<"Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(findscore < score[i])
		{
			cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
			exist++;
		}
	}
	if (exist == 0)
	cout << "\t\t\tNo students found!" << endl;
	cout << endl << "\t\t\t";
}

void showGender(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number) // Function to show students' information by gender
{
	system("cls");
	system("color 8F");
	int i = 0;
	char findgender;
	cout << endl << endl << endl;
	cout << "\t\tPlease enter the gender of students that you want to search" << endl;
	cout << "\t\t'M' for Male, 'F' for Female: ";
	cin >> findgender;
	while(findgender != 'M' && findgender !='m' && findgender != 'F' && findgender != 'f')
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\t\tInvalid input! Please try again: ";
		cin >> findgender;
	}
	
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t" <<"Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(findgender == gender[i])
		{
			cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
		}
	}
	cout << endl << "\t\t\t";
}

void showQualified(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number, double weightedScore) // Function to show qualified students' information
{
	system("cls");
	system("color 8F");
	int i = 0;

	system("cls");
	
	if(weightedScore == -1)
	{
		cout << endl << endl << endl;
		cout << "\t\t\tYou have not set the weighted score yet!" << endl << endl;
		cout << "\t\t\tPlease set it before proceed." << endl << endl;
		cout << "\t\t\t";
		return;
	}
		
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\tThe students who are qualified to stay in USM hostel: " << endl << endl;
	cout << "\t\t" <<"Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(score[i] > weightedScore)
		{
			cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
		}
	}
	cout << endl << endl << endl;
	cout << "\t\tThe students who are not qualified to stay in USM hostel: " << endl << endl;
	cout << "\t\t" <<"Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(score[i] < weightedScore)
		{
			cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
		}
	}
	cout << endl << "\t\t\t";
}

void showCourse(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number, double weightedScore) // Function to show qualified students' information by course code
{
	system("cls");
	system("color 8F");
	int i = 0;
	string findcourse;
	if(weightedScore == -1)
	{
		cout << endl << endl << endl;
		cout << "\t\t\tThe weighted score has not set by hostel officer!" << endl << endl;
		cout << "\t\t\tPlease contact hostel officer for more information." << endl << endl;
		cout << "\t\t\t";
		return;
	}
	
	cout << endl << endl << endl;
	cout << "\t\tPlease enter the course code of the students that you want to find in capital letter: ";
	cin >> findcourse;
	while(findcourse.find_first_of("`1234567890-=/*+~!abcdefghijklmnopqrstuvwxyz@#$%^&*()[]{}|;'" ":/.,<>?") != string::npos)
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\t\tInvalid input! Please try again: ";
		cin >> findcourse;
	}
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\tThe students in specific school who are qualified to stay in USM hostel: " << endl << endl;
	cout << "\t\t" << "Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(findcourse == course[i])
			{
				if(score[i] > weightedScore)
					cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
			}
	}
	cout << endl << endl << endl;
	cout << "\t\tThe students in specific school who are not qualified to stay in USM hostel: " << endl << endl;
	cout << "\t\t" << "Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(findcourse == course[i])
			{
				if(score[i] < weightedScore)
					cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
			}
	}
	cout << endl << "\t\t\t";
}

void showSpecific(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number, double weightedScore) // Function to search specific student's information by matric number
{
	system("cls");
	system("color 8F");
	int i = 0;
	int findmatric;
	int exist = 0;
	if(weightedScore == -1)
	{
		cout << endl << endl << endl;
		cout << "\t\t\tThe weighted score has not set by hostel officer!" << endl << endl;
		cout << "\t\t\tPlease contact hostel officer for more information." << endl << endl;
		cout << "\t\t\t";
		system("pause");
		return;
	}
	
	cout << endl << endl << endl;
	cout << "\t\tPlease enter the matric number of the student that you want to find: ";
	cin >> findmatric;
	while(!cin || findmatric < 100000 || findmatric > 999999)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\tInvalid input! Please try again: ";
		cin >> findmatric;
	}
	
	system("cls");
	cout << endl << endl << endl;
	cout << "\t\t" <<"Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(findmatric == matric[i])
			{
				cout << "\t\t" <<setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl << endl;
				exist++;
				if(score[i] > weightedScore)
					cout << "\t\t\tThis student is qualified to get USM hostel." << endl;
				else if(score[i] < weightedScore)
					cout << "\t\t\tThis student is not qualified to get USM hostel." << endl;
			}
	}
	if(exist == 0)
	cout << endl << "\t\t\t Student not exist! Please try again." << endl;
	cout << endl << "\t\t\t";
	system("pause");
}

double setWeighted(int score[], int number) // Function to set weighted score
{
	system("cls");
	system("color 1F");
	double weighted;
	double total = 0;
	double average;
	double weightedScore;
	
	cout << endl << endl << endl;
	cout << "\t\t\tPlease enter the weightage percentage (%): ";
	cin >> weighted;
	while(!cin || weighted < 0 || weighted > 100)
	{
		cin.clear();
		cin.ignore(10, '\n');
		cout << "\t\t\tInvalid input. Weighted percentage should be in between (0-100)%" << endl;
		cout << "\t\t\tPlease try again: ";
		cin >> weighted;
	}
	
	for(int j = 0; j < number; j++)
	{
		total = total + score[j];
	}
	
	average = total / number;
	weightedScore = average + ((weighted/100) * average);
	
	cout << endl << endl;
	cout << "\t\t\tThe qualified status is " << weightedScore << ". " << endl;
	cout << "\t\t\tStudents must score at least " << weightedScore << " or above." << endl << endl;
	cout << "\t\t\t";
	
	system("pause");
	return weightedScore;
	
}

void updateScore(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number) // Function to update specific student's MyCSD score
{
	system("cls");
	system("color 1F");
	int i = 0;
	int exist=0;
	int findmatric;
	cout << endl << endl << endl;
	cout << "\t\tPlease enter the matric number of the student that you want to update: ";
	cin >> findmatric;
	while(!cin || findmatric < 100000 || findmatric > 999999)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\t\tInvalid input. Please try again: ";
		cin >> findmatric;
	}
	
	system("cls");
	
	cout << endl << endl << endl;
	for(i = 0; i < number; i++)
	{
		if(i == 0)
		{
			ofstream outData;
			outData.open("StudentMyCSD.txt");
			if(matric[i] == findmatric)
			{
				cout << "\t\tThe student's details are as follow: " << endl << endl;
				cout << "\t\t" << "Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
				cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl << endl;
			
				ofstream outData;
				outData.open("StudentMyCSD.txt", ios::app);
				outData << matric[i] << " " << name[i] << " " << gender[i] << " " << course[i] << " " << contact[i] << " ";
				cout << "\t\t\tPlease enter the new score that you want to update: ";
				cin >> score[i];
				while(!cin || score[i] < 0)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tInvalid input! Please try again: ";
					cin >> score[i];
				}
				outData << score[i] << endl;
				outData.close();
				exist++;
			}
			else
				outData << matric[i] << " " << name[i] << " " << gender[i] << " " << course[i] << " " << contact[i] << " " << score[i] << endl;
			outData.close();
		}
		
		else if(i == number-1)
		{
			ofstream outData;
			outData.open("StudentMyCSD.txt", ios::app);
			if(matric[i] == findmatric)
			{
				cout << "\t\tThe student's details are as follow: " << endl << endl;
				cout << "\t\t" << "Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
				cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl << endl;
			
				ofstream outData;
				outData.open("StudentMyCSD.txt", ios::app);
				outData << matric[i] << " " << name[i] << " " << gender[i] << " " << course[i] << " " << contact[i] << " ";
				cout << "\t\tPlease enter the new score that you want to update: ";
				cin >> score[i];
				while(!cin || score[i] < 0)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tInvalid input! Please try again: ";
					cin >> score[i];
				}
				outData << score[i];
				outData.close();
				exist++;
			}
			else
				outData << matric[i] << " " << name[i] << " " << gender[i] << " " << course[i] << " " << contact[i] << " " << score[i];
			outData.close();	
		}
		
		else
		{
			ofstream outData;
			outData.open("StudentMyCSD.txt", ios::app);
			if(matric[i] == findmatric)
			{
				cout << "\t\tThe student's details are as follow: " << endl << endl;
				cout << "\t\t" << "Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
				cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl << endl;
			
				ofstream outData;
				outData.open("StudentMyCSD.txt", ios::app);
				outData << matric[i] << " " << name[i] << " " << gender[i] << " " << course[i] << " " << contact[i] << " ";
				cout << "\t\tPlease enter the new score that you want to update: ";
				cin >> score[i];
				while(!cin || score[i] < 0)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "\t\t\tInvalid input! Please try again: ";
					cin >> score[i];
				}
				outData << score[i] << endl;
				outData.close();
				exist++;
			}
			else
				outData << matric[i] << " " << name[i] << " " << gender[i] << " " << course[i] << " " << contact[i] << " " << score[i] << endl;
			outData.close();
		}
	}
	
	if(exist == 0)
	cout << "\t\t\tMatric number not found! Please try again." << endl << endl;
	cout << "\t\t\t";
	
	system("pause");
}

void checkPoints(int matric[], string name[], char gender[], string course[], string contact[], int score[], int number, double weightedScore) // Function to let students to check their MyCSD score and qualifications
{
	system("cls");
	system("color F1");
	int i = 0;
	int exist = 0;
	int findmatric;
	char fetching[16] = {'F','e','t','c','h','i','n','g',' ','d','a','t','a','.','.','.'};
	
	if(weightedScore == -1)
	{
		cout << endl << endl << endl;
		cout << "\t\t\tThe weighted score has not set by hostel officer!" << endl << endl;
		cout << "\t\t\tPlease contact hostel officer for more information." << endl << endl;
		cout << "\t\t\t";
		system("pause");
		return;
	}
	
	
	cout << endl << endl << endl;
	cout << "\t\t\tYou can use your matric number to search for your accumulated points! " << endl;
	cout << "\t\t\tAnd also your qualification!" << endl;
	cout << "\t\t\tPlease enter your matric number to proceed: ";
	cin >> findmatric;
	while(!cin || findmatric < 100000 || findmatric > 999999)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << "\t\tInvalid input! Matric number should be in 6 digit numbers!" << endl;
		cout << "\t\tPlease try again: ";
		cin >> findmatric;
	}
	
	system("cls");
	
	cout << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << setw(50);
	for(int z = 0; z < 16; z++)
	{
		cout << fetching[z];
		Sleep(200);
	}
	
	system("cls");
	
	cout << "\t\t" << "Matric no." << setw (14) << "Name" << '\t' << "Gender" << setw(12) << "Course" << setw(17) << "Contact no." << setw(10) << "MyCSD" << endl;
	for(i = 0; i < number; i++)
	{
		if(matric[i] == findmatric)
			{
				cout << "\t\t" << setw(9) << matric[i] << setw(15) << name[i] << setw(14) << gender[i] << setw(12) << course[i] << setw(16) << contact[i] << setw(11) << score[i] << endl;
				exist++;
				if(score[i] > weightedScore)
					{
						cout << endl << "\t\t\tGood news for you!" << endl;
						cout << "\t\t\tYou're qualified to get USM hostel!" << endl << endl;
					}
				else
					{
						cout << endl << "\t\t\tBad news for you." << endl;
						cout << "\t\t\tYou're not qualified to get USM hostel." << endl;
						cout << "\t\t\tPlease do not give up!" << endl << endl;
					}
			}

	}
	
	if(exist == 0)
	{
		cout << endl << endl << endl;
		cout << "\t\tMatric number not found! " << endl << endl;
	}
	cout << "\t\t";
}
