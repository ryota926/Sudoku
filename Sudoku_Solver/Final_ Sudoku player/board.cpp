/*
 * board.cpp
 *
 *  Created on: Dec 4, 2019
 *      Author: ryota
 */

#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "board.h"
using namespace std;

board::board(){
    done = false;
}


void board::fillDiagonal()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            map[i][j] = 0;
			answer[i][j] = 0;
        }
    }

    for(int k=0;k<9;k+=3){
        int count=0;
        randomize();
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                map[i+k][j+k]=random[count];
                count++;
            }
        }
    }
}


int board::fillRest(int n) //backtracking
{
    // if all done exit
    if (n > 80)
    {

        done = true;
        return 0;
    }
    if (map[n / 9][n % 9] != 0)   // current bucket already filled skip
    {
        fillRest(n + 1);
    }
    else
    {                                    // else start trying
        for (int i = 0; i < 9; i++)
        {
            if (check(n, random[i]) == true)     // if valid filled in
            {
                map[n / 9][n % 9] = random[i];
                fillRest(n + 1);     // keep going to next level
                if (done == true) return 0;
                map[n / 9][n % 9] = 0;// else reset it back to zero, AKA return to previous level
            }
        }
    }
}

int board::countZreo() {
	int countZ = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] == 0) {
				countZ++;
			}
		}
	}
	return countZ;
}

void board::copymap(){
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			answer[i][j] = map[i][j];
		}
	}
}

bool board::userInputCheck(int number,int hposition, int vposition){
	if(answer[hposition][vposition] == number){
		map[hposition][vposition] = number;
		return true;
	}
	else{
		cout<<"Invalid Input"<<endl;
		return false;
	}

}

bool board::check(int n, int key)
{
    // check row
    for (int i = 0; i < 9; i++)
    {
        /* j is y axis*/
        int j = n / 9;
        if (map[j][i] == key) return false;
    }

        // check column
    for (int i = 0; i < 9; i++)
    {
        /* j as x axis*/
        int j = n % 9;
        if (map[i][j] == key) return false;
    }
    // following check grid
    int x = n / 9 / 3 * 3;
    int y = n % 9 / 3 * 3;
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            if (map[i][j] == key) return false;
        }
    }
    return true;
}

void board::deleteNumber(){
	int number = 0;
	int number1 = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){

			int x = rand()%6;
			int y = rand()%6;
			if ((x + i) > 8) {
				number = x+i - 8;
			}
			else {
				number = x + i;
			}
			if (y + j > 8) {
				number1 = x+j - 8;
			}
			else {
				number1 = y + j;
			}
			if(map[number][number1] != 0){
					map[number][number1] = 0;
			 }
			
			
			
		}
			
	}
}


void board::randomize(){
    bool used[9];
    for(int i=0; i<9; i++){
        used[i]=false;
    }
    for(int i=0; i<9; i++){
        bool cont=true;
        while(cont==true){
            int temp=rand()%9+1;
            if(used[temp-1]==false){
                random[i]=temp;
                used[temp-1]=true;
                cont=false;
            }
        }
    }
}



void board::print()
{
    cout << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << map[i][j] << " ";
            if (j % 3 == 2)
            {
                cout << "   ";
            }
        }
        cout << endl;
        if (i % 3 == 2)
        {
            cout << endl;
        }
    }
}
void board::printans(){
	cout << endl;
	    for (int i = 0; i < 9; i++)
	    {
	        for (int j = 0; j < 9; j++)
	        {
	            cout << answer[i][j] << " ";
	            if (j % 3 == 2)
	            {
	                cout << "   ";
	            }
	        }
	        cout << endl;
	        if (i % 3 == 2)
	        {
	            cout << endl;
	        }
	    }
}


