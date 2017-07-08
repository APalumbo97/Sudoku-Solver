/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: SudokuSolver.cpp
 * date: 6-3-2017
 * description: Program that is able to solve sudoku puzzles that are given in a file
 */

#include <cstdlib>
#include <iostream>
#include "Backtracker.h"

using namespace std;

int main() {
    cout << "Hello World." << endl;
    Grid a = Grid();
    a.setValue(0, 0, 4);
    a.setValue(0, 1, 3);
    a.setValue(0, 2, 5);
    a.setValue(0, 3, 2);
    a.setValue(0, 4, 6);
    a.setValue(0, 5, 9);
    a.setValue(0, 6, 7);
    a.setValue(0, 7, 8);
    a.setValue(0, 8, 1);

    a.setValue(1, 0, 6);
    a.setValue(1, 1, 8);
    a.setValue(1, 2, 2);
    a.setValue(1, 3, 5);
    a.setValue(1, 4, 7);
    a.setValue(1, 5, 1);
    a.setValue(1, 6, 4);
    a.setValue(1, 7, 9);
    a.setValue(1, 8, 3);

    a.setValue(2, 0, 1);
    a.setValue(2, 1, 9);
    a.setValue(2, 2, 7);
    a.setValue(2, 3, 8);
    a.setValue(2, 4, 3);
    a.setValue(2, 5, 4);
    a.setValue(2, 6, 5);
    a.setValue(2, 7, 6);
    a.setValue(2, 8, 2);

    a.setValue(3, 0, 8);
    a.setValue(3, 1, 2);
    a.setValue(3, 2, 6);
    a.setValue(3, 3, 1);
    a.setValue(3, 4, 9);
    a.setValue(3, 5, 5);
    a.setValue(3, 6, 3);
    a.setValue(3, 7, 4);
    a.setValue(3, 8, 7);

    a.setValue(4, 0, 3);
    a.setValue(4, 1, 7);
    a.setValue(4, 2, 4);
    a.setValue(4, 3, 6);
    a.setValue(4, 4, 8);
    a.setValue(4, 5, 2);
    a.setValue(4, 6, 9);
    a.setValue(4, 7, 1);
    a.setValue(4, 8, 5);

    a.setValue(5, 0, 9);
    a.setValue(5, 1, 5);
    a.setValue(5, 2, 1);
    a.setValue(5, 3, 7);
    a.setValue(5, 4, 4);
    a.setValue(5, 5, 3);
    a.setValue(5, 6, 6);
    a.setValue(5, 7, 2);
    a.setValue(5, 8, 8);

    a.setValue(6, 0, 5);
    a.setValue(6, 1, 1);
    a.setValue(6, 2, 9);
    a.setValue(6, 3, 3);
    a.setValue(6, 4, 2);
    a.setValue(6, 5, 6);
    a.setValue(6, 6, 8);
    a.setValue(6, 7, 7);
    a.setValue(6, 8, 4);

    a.setValue(7, 0, 2);
    a.setValue(7, 1, 4);
    a.setValue(7, 2, 8);
    a.setValue(7, 3, 9);
    a.setValue(7, 4, 5);
    a.setValue(7, 5, 7);
    a.setValue(7, 6, 1);
    a.setValue(7, 7, 3);
    a.setValue(7, 8, 6);

    a.setValue(8, 0, 7);
    a.setValue(8, 1, 6);
    a.setValue(8, 2, 3);
    a.setValue(8, 3, 4);
    a.setValue(8, 4, 1);
    a.setValue(8, 5, 8);
    a.setValue(8, 6, 2);
    a.setValue(8, 7, 5);
    a.setValue(8, 8, 9);

    cout << "Is valid: " << a.isValid() << endl;
    cout << "Is goal: " << a.isGoal() << endl;
    return EXIT_SUCCESS;
}
