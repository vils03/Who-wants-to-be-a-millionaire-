#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include "NewGame.h"

using namespace std;

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

int randomNumber(vector <int> v) {
	srand(time(NULL));
	int random = rand() % v.size();
	int sel_elem = v[random];
	return sel_elem;
}

void wrongPrize(int money, string right) {
	system("CLS");
	name();
	cout << "Wrong answer :(" << endl;
	cout << "The right answer was " << right << "." << endl;
	cout << "You won " << money << "$.";
	cout << endl << endl;
	/*cout << "Press B to go back to main menu...";*/
	/*char ch;
	cin >> ch;
	if (ch == 'B') {
		int main();
	}*/
}

void rightPrize(int money) {
	system("CLS");
	name();
	cout << "Right answer :)" << endl;
	cout << "You won " << money << " $.";
	cout << endl << endl;
}

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

void getQuestion(vector <int> getID, vector <string> array, int& prize, int& questions) {
	int now = randomNumber(getID);
	if (now == stoi(array[0])) {
		system("CLS");
		name();
		cout << questions << ". " << array[1] << endl;
		cout << array[2] << endl;
		cout << array[3] << endl;
		cout << array[4] << endl;
		cout << array[5] << endl;
		cout << "Enter your answer: ";
		string answer;
		cin >> answer;
		if (answer == array[6]) {
			prize += 100;
			rightPrize(prize);
			system("pause");
		}
		else {
			wrongPrize(prize, array[6]);
		}
	}

}
void newGame(){
	int prize = 0;
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
	string line;
	vector <string> array;
	vector <int> getID;
	int questions = 1;
		while (1<= questions && questions <= 3) {
			ifstream myFile("easy.txt");
			while (getline(myFile, line)) {
				array = questionArray(line);
				if (stoi(array[7]) == category) {
					getID.push_back(stoi(array[0]));
				}	
				getQuestion(getID, array, prize, questions);
				++questions;
			}
		}
		while (4 <= questions && questions <= 7) {
			ifstream myFile("medium.txt");
			while (getline(myFile, line)) {
				array = questionArray(line);
				if (stoi(array[7]) == category) {
					getID.push_back(stoi(array[0]));
				}
			}
			getQuestion(getID, array, prize, questions);
			++questions;
		}
		while (8 <= questions && questions <= 10) {
			ifstream myFile("hard.txt");
			while (getline(myFile, line)) {
				array = questionArray(line);
				if (stoi(array[7]) == category) {
					getID.push_back(stoi(array[0]));
				}
			}
			getQuestion(getID, array, prize, questions);
			++questions;
		}
	myFile.close();
}