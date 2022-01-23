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
* <main file>
*
*/

#include <iostream>
#include <iomanip>
#include "Add.h"
#include "Exit.h"
#include "NewGame.h"
#include "Edit.h"

using namespace std;

bool isValid(int n) {
	return 0 <= n && n <= 3;
}

int main()
{
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << "Who wants to be a millionaire";
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << endl << endl;
	cout << setfill(' ') << setw(50) << "0.New game" << endl;
	cout << setfill(' ') << setw(60) << "1.Enter new question" << endl;
	cout << setfill(' ') << setw(64) << "2.Edit existing question" << endl;
	cout << setfill(' ') << setw(46) << "3.Exit" << endl << endl;
	cout << setfill(' ') << setw(59) << "Enter your choice: ";
	int choice;
	cin >> choice;
	while (!isValid(choice)) {
		cout << "Please, enter a number between 0 and 3!";
		cin >> choice;
	}
	switch (choice) {
	case 0:
		cout << "\x1B[2J\x1B[H";
		newGame();
		break;
	case 1:
		cout << "\x1B[2J\x1B[H";
		question();
		break;
	case 2:
		cout << "\x1B[2J\x1B[H";
		EditQuestion();
		break;
	case 3:
		cout << "\x1B[2J\x1B[H";
		gameExit();
	}
	return 0;
}


