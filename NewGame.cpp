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
* <file with functions to strat new game>
*
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include "NewGame.h"

using namespace std;

int toDigit(string cat) {
	if (cat == "1") {
		return 1;
	}
	else if (cat == "2") {
		return 2;
	}
	else if (cat == "3") {
		return 3;
	}
	else if (cat == "4") {
		return 4;
	}
	else if (cat == "5") {
		return 5;
	}
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

int randomNumber(vector <int> v) {
	srand(time(NULL));
	int random = rand() % v.size();
	int sel_elem = v[random];
	return sel_elem;
}

string randomSymbol(vector <string> v) {
	srand(time(NULL));
	int random = rand() % v.size();
	string sel_elem = v[random];
	return sel_elem;
}

void wrongPrize(int money, string right) {
	cout << "\x1B[2J\x1B[H";
	name();
	cout << "Wrong answer :(" << endl;
	cout << "The right answer was " << right << "." << endl;
	cout << "You won " << money << "$.";
	cout << endl << endl;
}

void rightPrize(int money) {
	cout << "\x1B[2J\x1B[H";
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
	return 1 <= n && n <= 5;
}

void fiftyFifty(vector <string> array) {
	vector <string> options;
	for (int i = 2; i < 6; ++i) {
		if (array[i] != array[6]) {
			options.push_back(array[i]);
		}
	}
	string random1 = randomSymbol(array);
	for (int i = 2; i < 6; ++i) {
		if (random1 == array[i]) {
			options.erase(remove(options.begin(), options.end(), random1), options.end());
		}
	}
	for (auto i : options)
		cout << i << ' ';
	string random2 = randomSymbol(array);
	
}

void getQuestion(vector <int> getID, vector <string> array, int& prize, int& questions) {
	int now = randomNumber(getID);
	if (now == toDigit(array[0])) {
		cout << "\x1B[2J\x1B[H";
		name();
		cout << array[1] << endl;
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
			cout << "\x1B[2J\x1B[H";
		}
		else {
			wrongPrize(prize, array[6]);
		}
	}
}
void newGame(){
	name();
	cout << setfill(' ') << setw(57) << "Choose category" << endl;
	cout << setfill(' ') << setw(55) << "1.Geography" << endl;
	cout << setfill(' ') << setw(53) << "2.History" << endl;
	cout << setfill(' ') << setw(56) << "3.Literature" << endl;
	cout << setfill(' ') << setw(50) << "4.Math" << endl << endl;
	cout << setfill(' ') << setw(60) << "Enter your choice: ";
	int category;
	int questions = 1;
	vector <string> array;
	vector <int> getID;
	string line;
	int prize = 0;
	cin >> category;
	while (!validCat(category)) {
		cout << "Please, enter number from 1 to 4." << " ";
		cin >> category;
	}
	fstream myFile;
	unsigned counter = 0;
	myFile.open("easy.txt");
	while (getline(myFile, line)) {
		array = questionArray(line);
		if (toDigit(array[7]) == category ) {
			getID.push_back(toDigit(array[0]));
			++questions;
		}
		if (questions > 1 && counter < 3)
		{
			getQuestion(getID, array, prize, questions);
			counter++;
		}
		
	}
	myFile.close();
	counter = 0;
	bool forif = false;
	fstream myfile;
	myfile.open("medium.txt");
	while (getline(myfile, line)) {
		array = questionArray(line);
		if (toDigit(array[7]) == category) {
			getID.push_back(toDigit(array[0]));
			++questions;
			forif = true;
		}
		if (questions > 1 && counter < 4&&forif)
		{
			getQuestion(getID, array, prize, questions);
			counter++;
		}
		forif = false;
		
	}
	myfile.close();
	counter = 0;
	fstream File;
	File.open("hard.txt");
	while (getline(File, line)) {
		array = questionArray(line);
		if (toDigit(array[7]) == category) {
			getID.push_back(toDigit(array[0]));
			++questions;
		}
		if (questions > 1 && counter < 3 && forif)
		{
			getQuestion(getID, array, prize, questions);
			counter++;
		}
	}
	File.close();
}

