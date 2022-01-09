#include <iostream>
#include <iomanip>
#include "Add.h"
#include "Exit.h"

using namespace std;

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
	switch (choice) {
		case 1:
			system("CLS");
			question();
			break;
		case 3:
			system("CLS");
			gameExit();
	}
	return 0;
}


