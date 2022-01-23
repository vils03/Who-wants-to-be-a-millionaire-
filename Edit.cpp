#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Add.h"
#include "Edit.h"

using namespace std;
bool validCateg(int n) {
	return 1 <= n && n <= 4;
}

bool validAns(char ch) {
	return 'A' <= ch && ch <= 'D';
}

string element(int& index, string line)
{
	string options;
	for (int i = index + 1; line[i] != '|'; ++i) {
		options += line[i];
		++index;
	}
	return options;
}

vector <string> questionArr(string line) {
	vector <string> questionArr;
	string id, question, optionA, optionB, optionC, optionD, answer, category;
	int pipeIndex = 0;
	while (line[pipeIndex] != '|') {
		id += line[pipeIndex];
		++pipeIndex;
	}
	questionArr.push_back(id);
	question = element(pipeIndex, line);
	questionArr.push_back(question);
	pipeIndex += 1;
	optionA = element(pipeIndex, line);
	questionArr.push_back(optionA);
	pipeIndex += 1;
	optionB = element(pipeIndex, line);
	questionArr.push_back(optionB);
	pipeIndex += 1;
	optionC = element(pipeIndex, line);
	questionArr.push_back(optionC);
	pipeIndex += 1;
	optionD = element(pipeIndex, line);
	questionArr.push_back(optionD);
	pipeIndex += 1;
	answer = element(pipeIndex, line);
	questionArr.push_back(answer);
	pipeIndex += 1;
	category = element(pipeIndex, line);
	questionArr.push_back(category);
	pipeIndex += 1;

	return questionArr;
}
void nname() {
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << "Who wants to be a millionaire";
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << endl << endl;
}

void EditQuestion() {
	nname();
	cout << "Enter the ID number of the question you want to edit: ";
	int id;
	cin >> id;
	fstream myFile;
	myFile.open("easy.txt");
	if (myFile.fail())
	{
		cout << "File not found." << endl;
		exit(1);
	}
	string line;
	vector <string> questArray;
	while (getline(myFile, line)) {
		questArray = questionArr(line);
		while (id != stoi(questArray[0])) {
			cout << "Question with ID " << id << " not found" << endl;
			cout << "Please enter new ID: ";
			cin >> id;
		}
		if (id == stoi(questArray[0])) {
			system("CLS");
			nname();
			cout << "Enter the level of difficulty of your question (1-10):";
			int level;
			cin >> level;
			fstream myFile;
			line.replace(line.find(line), line.length(), "");
			while (level < 1 || level > 10)
			{
				cout << "Please, enter valid number! ";
				cin >> level;
			}
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

			system("CLS");

			nname();
			string question;
			cout << "Enter your question: ";
			cin.ignore();
			getline(cin, question);
			myFile << question << "|";
			system("CLS");

			nname();
			string optionA, optionB, optionC, optionD;
			cout << "Enter answers: " << endl;
			cout << "A) ";
			getline(cin, optionA);
			char chA = optionA[0];
			cout << "B) ";
			getline(cin, optionB);
			cout << "C) ";
			getline(cin, optionC);
			cout << "D) ";
			getline(cin, optionD);
			myFile << "A)" << optionA << "|";
			myFile << "B)" << optionB << "|";
			myFile << "C)" << optionC << "|";
			myFile << "D)" << optionD << "|";
			system("CLS");

			nname();
			char rightAnswer;
			cout << "Enter the right answer (A-D): ";
			cin >> rightAnswer;
			if (!validAns(rightAnswer)) {
				cout << "Please, enter letter between A and D!";
				cin >> rightAnswer;
			}
			myFile << rightAnswer << "|";
			int category;
			cout << "Choose category:" << endl;
			cout << "1. Geography" << endl;
			cout << "2. History" << endl;
			cout << "3. Literature" << endl;
			cout << "4. Art" << endl;
			cin >> category;
			while (!validCateg(category)) {
				cout << "Please, enter number betwee 1 and 4!" << " ";
				cin >> category;
			}
			myFile << category << "|" << endl;
			myFile.close();
			system("CLS");
			main();
		}
		
	}
	myFile.close();
}
