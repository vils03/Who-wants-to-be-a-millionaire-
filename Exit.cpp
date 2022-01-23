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
* <file to functions to exit the program>
*
*/


#include <iostream>
#include <cstdlib>   
#include "Exit.h"
using namespace std;

bool valid(int n) {
	return 0 <= n && n <= 1;
}

void gameExit() {

	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << "Who wants to be a millionaire";
	for (int i = 0; i < 35; ++i) {
		cout << "*";
	}
	cout << endl << endl;
	cout << "Are you sure you want to quit playing?" << endl;
	cout << "0. Yes" << endl << "1. No" << endl;
	int choice;
	cin >> choice;
	while (!valid(choice)) {
		cout << "Please, enter 0 or 1!" << " ";
		cin >> choice;
	}
	switch (choice)  {
	case 0: 
		exit(EXIT_FAILURE);
	case 1:
		cout << "\x1B[2J\x1B[H";
		main();
	}
}

