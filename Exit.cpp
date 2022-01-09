#include <iostream>
#include <cstdlib>   
#include "Exit.h"
using namespace std;

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
	switch (choice)  {
	case 0: 
		exit(EXIT_FAILURE);
	case 1:
		system("CLS");
		main();
	}
}

