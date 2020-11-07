/*
 * board.h
 *
 *  Created on: Dec 5, 2019
 *      Author: chake
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>

using namespace std;


class board{
    private:
        bool done;
        int map[9][9];
		int answer[9][9];// answer reference
        int random[9];



    public:
        board();
        void fillDiagonal();
        int fillRest(int n);
		int countZreo();
        bool userInputCheck(int number, int hposition, int vposition);
        bool check(int n, int key);
        void randomize();
		void copymap();
        void deleteNumber();
        void print();
        void printans();


};




#endif /* BOARD_H_ */
