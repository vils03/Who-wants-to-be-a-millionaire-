/**
*
* Solution to course project # 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Velislava Krumova
* @idnumber 0MI0600007
* @compiler VC
*
* <file with functions to add question>
*
*/


#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include "Add.h"

using namespace std;

bool validCategory(int n) {
	return 1 <= n && n <= 4;
}

bool validAnswer(char ch) {
	return 'A' <= ch && ch <= 'D';
}

int generateRandom() {
	srand(time(nullptr)); // use current time as seed for random generator
	int random_variable = rand();
	return random_variable;
}

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
	int id = generateRandom();
	if (1 <= level && level <= 3) {
		myFile.open("easy.txt", ios::app);
		myFile << id << "|";
	}
	else if (4 <= level && level <= 7) {
		myFile.open("medium.txt", ios::app);
		myFile << id << " " << "|";
	}
	else if (8 <= level && level <= 10) {
		myFile.open("hard.txt", ios::app);
		myFile << id << " " << "|";
	}

	cout << "\x1B[2J\x1B[H";

	namePrint();
	string question;
	cout << "Enter your question: ";
	cin.ignore();
	getline (cin, question);
	myFile << question << "|";
	cout << "\x1B[2J\x1B[H";

	namePrint();
	string optionA, optionB, optionC, optionD;
	cout << "Enter answers: " << endl;
	cout << "A) ";
	getline(cin, optionA);
	char chA = optionA[0];
	cout << "B) ";
	getline(cin, optionB);
	char chB = optionB[0];
	cout << "C) ";
	getline(cin, optionC);
	cout << "D) ";
	getline(cin, optionD);
	myFile << "A)" << optionA << "|";
	myFile << "B)" << optionB << "|";
	myFile << "C)" << optionC << "|";
	myFile << "D)" << optionD << "|";
	cout << "\x1B[2J\x1B[H";

	namePrint();
	char rightAnswer;
	cout << "Enter the right answer (A-D): ";
	cin >> rightAnswer;
	if (!validAnswer(rightAnswer)) {
		cout << "Please, enter letter between A and D!";
		cin >> rightAnswer;
	}
	myFile << rightAnswer << "|";
	int category;
	cout << "Choose category:" << endl;
	cout << "1. Geography" << endl;
	cout << "2. History" << endl;
	cout << "3. Literature" << endl;
	cout << "4. Math" << endl;
	cin >> category;
	while (!validCategory(category)) {
		cout << "Please, enter number betwee 1 and 4!" << " ";
		cin >> category;
	}
	myFile << category << "|" << endl;
	myFile.close();
	cout << "\x1B[2J\x1B[H";
	main();
	
	

	


}
