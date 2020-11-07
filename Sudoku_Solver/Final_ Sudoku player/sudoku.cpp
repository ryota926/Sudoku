//============================================================================
// Name        : sudiku.cpp
// Author      : Wenyi Cai
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "board.h"

using namespace std;

int main()
{
	srand(time(NULL));
	board demo;
	int NumberofZero;
	int input, hposition, vposition;
	demo.fillDiagonal();
	demo.randomize();
	demo.fillRest(0);
	demo.copymap();
	cout << "Printing Sudoku....." << endl;
	demo.print();

	cout << "--------------------------------------" << endl;
	demo.deleteNumber();
	NumberofZero = demo.countZreo();
	cout << NumberofZero << "left" << endl;
	demo.print();
	cout << "--------------------------------------" << endl;

	while (NumberofZero != 0) {
		cout << "Input:" << endl;
		cin >> input;
		cout << "----" << endl;
		cout << "Horizontal Location:" << endl;
		cin >> vposition; // it is correct! do not change!
		cout << "----" << endl;
		cout << "Vertical Location:" << endl;
		cin >> hposition;//it is correct! do not change !
		cout << "----" << endl;
		bool check = demo.userInputCheck(input, hposition, vposition);
		cout << check << endl;
		if (check) {
			NumberofZero--;
			cout << NumberofZero << "left" << endl;
			demo.userInputCheck(input, hposition, vposition);
			demo.print();
		}
		
		else {
			cout << "Show the Answer" << endl;
			demo.printans();
			break;
		}

	}
}
	


    



