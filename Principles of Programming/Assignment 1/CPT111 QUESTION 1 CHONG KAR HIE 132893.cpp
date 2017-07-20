#include <iostream>

using namespace std;

int main()
{
	int testScore1, testScore2, testScore3, testScore4;
	double weightTestScore1, weightTestScore2, weightTestScore3, weightTestScore4, average;
	
	cout << "Please enter the first test score: "; //Prompt user to input the test scores and their respective weights
	cin >> testScore1;
	cout << "Please enter the weight of the first test score: ";
	cin >> weightTestScore1;
	
	cout << "Please enter the second test score: ";
	cin >> testScore2;
	cout << "Please enter the weight of the second test score: ";
	cin >> weightTestScore2;
	
	cout << "Please enter the third test score: ";
	cin >> testScore3;
	cout << "Please enter the weight of the third test score: ";
	cin >> weightTestScore3;
	
	cout << "Please enter the fourth test score: ";
	cin >> testScore4;
	cout << "Please enter the weight of the fourth test score: ";
	cin >> weightTestScore4;
	
	average = testScore1 * weightTestScore1 + testScore2 * weightTestScore2 + testScore3 * weightTestScore3 + testScore4 * weightTestScore4; //Formula to calculate the weighted average of the 4 test scores
	
	cout << "The weighted average of the 4 test scores is: " << average << endl; //Output the weighted average of the 4 test scores

	return 0;
}
