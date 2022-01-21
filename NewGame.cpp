#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "NewGame.h"

using namespace std;

//vector <string> getQuestion(fstream &myFile) {
//	vector <string> question;
//	string line;
//	int questions = 1;
//
//	if (1 <= questions && questions <= 3) {
//		ifstream myFile("easy.txt");
//		while (myFile >> line)
//			question.push_back(line);
//	}
//	else if (4 <= questions && questions <= 7) {
//		ifstream myFile("medium.txt");
//		while (myFile >> line)
//			question.push_back(line);
//	}
//	else if (8 <= questions && questions <= 10) {
//		ifstream myFile("hard.txt");
//		while (myFile >> line)
//			question.push_back(line);
//	}
//	return question;
//}
string elements(int &index, string line)
{
	string options;
	for (int i = index + 1; line[i] != '|'; ++i) {
		options += line[i];
		++index;
	}
	return options;
}
vector <string> questionArray(string line) {
	vector <string> questionArr;
	string id, question, optionA, optionB, optionC, optionD, answer, category;
	int pipeIndex = 0;
	while (line[pipeIndex] != '|') {
		id += line[pipeIndex];
		++pipeIndex;
	}
	questionArr.push_back(id);
	question = elements(pipeIndex, line);
	questionArr.push_back(question);
	pipeIndex += 1;
	optionA = elements(pipeIndex, line);
	questionArr.push_back(optionA);
	pipeIndex += 1;
	optionB = elements(pipeIndex, line);
	questionArr.push_back(optionB);
	pipeIndex += 1;
	optionC = elements(pipeIndex, line);
	questionArr.push_back(optionC);
	pipeIndex += 1;
	optionD = elements(pipeIndex, line);
	questionArr.push_back(optionD);
	pipeIndex += 1;
	answer = elements(pipeIndex, line);
	questionArr.push_back(answer);
	pipeIndex += 1;
	category = elements(pipeIndex, line);
	questionArr.push_back(category);
	pipeIndex += 1;

	return questionArr;
}

bool validCat(int n) {
	return 1 <= n && n <= 4;
}

void name() {
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << "Who wants to be a millionaire";
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << endl << endl;
}

void newGame(){
	name();
	cout << setfill(' ') << setw(57) << "Choose category" << endl;
	cout << setfill(' ') << setw(55) << "1.Geography" << endl;
	cout << setfill(' ') << setw(53) << "2.History" << endl;
	cout << setfill(' ') << setw(56) << "3.Literature" << endl;
	cout << setfill(' ') << setw(49) << "4.Art" << endl << endl;
	cout << setfill(' ') << setw(60) << "Enter your choice: ";
	int category;
	cin >> category;
	while (!validCat(category)) {
		cout << "Please, enter number from 1 to 4." << " ";
		cin >> category;
	}
	fstream myFile;
	myFile.close();

	//брояч на въпросите
	// отваряме съответния файл
	// функция get question която слага въпрос в масив
	// прочитаме категория ??????????????????????
	// switch case за категория
}