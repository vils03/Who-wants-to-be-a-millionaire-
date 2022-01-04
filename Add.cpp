#include <iostream>
#include <fstream>
#include <string>
#include "Add.h"

using namespace std;

void namePrint(){
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << "Who wants to be a millionaire";
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << endl << endl;
}
void question() {
	namePrint();
	cout << "Enter the level of difficulty of your question (1-10):";
	int level;
	cin >> level;
	fstream myFile;
	while (level < 1 || level > 10)
	{
		cout << "Please, enter valid number! ";
		cin >> level;
	}
	if (1 <= level && level <= 3) {
		myFile.open("easy.txt", ios::app);
		myFile << level << " ";
	}
	else if (4 <= level && level <= 7) {
		myFile.open("medium.txt", ios::app);
		myFile << level << " ";
	}
	else if (8 <= level && level <= 10) {
		myFile.open("hard.txt", ios::app);
		myFile << level << " ";
	}
	system("CLS");

	namePrint();
	string question;
	cout << "Enter your question: ";
	cin.ignore();
	getline (cin, question);
	myFile << question << endl;
	system("CLS");

	namePrint();
	string optionA, optionB, optionC, optionD;
	cout << "Enter answers: " << endl;
	getline(cin, optionA);
	getline(cin, optionB);
	getline(cin, optionC);
	getline(cin, optionD);
	myFile << optionA << endl;
	myFile << optionB << endl;
	myFile << optionC << endl;
	myFile << optionD << endl;
	system("CLS");

	namePrint();
	string rightAnswer;
	cout << "Enter the right answer (A-D): ";
	getline(cin, rightAnswer);
	myFile << rightAnswer << endl;
	int category;
	cout << "Choose category:" << endl;
	cout << "1. Geography" << endl;
	cout << "2. History" << endl;
	cout << "3. Literature" << endl;
	cout << "4. Art" << endl;
	cin >> category;
	myFile << category << endl;
	myFile.close();
	
	

	


}
