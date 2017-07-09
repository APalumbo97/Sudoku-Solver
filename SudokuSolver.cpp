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
    Grid *a = new Grid();
    a->setValue(0, 0, 0);
    a->setValue(0, 1, 2);
    a->setValue(0, 2, 0);
    a->setValue(0, 3, 0);
    a->setValue(0, 4, 0);
    a->setValue(0, 5, 0);
    a->setValue(0, 6, 0);
    a->setValue(0, 7, 0);
    a->setValue(0, 8, 0);

    a->setValue(1, 0, 0);
    a->setValue(1, 1, 0);
    a->setValue(1, 2, 0);
    a->setValue(1, 3, 6);
    a->setValue(1, 4, 0);
    a->setValue(1, 5, 0);
    a->setValue(1, 6, 0);
    a->setValue(1, 7, 0);
    a->setValue(1, 8, 3);

    a->setValue(2, 0, 0);
    a->setValue(2, 1, 7);
    a->setValue(2, 2, 4);
    a->setValue(2, 3, 0);
    a->setValue(2, 4, 8);
    a->setValue(2, 5, 0);
    a->setValue(2, 6, 0);
    a->setValue(2, 7, 0);
    a->setValue(2, 8, 0);

    a->setValue(3, 0, 0);
    a->setValue(3, 1, 0);
    a->setValue(3, 2, 0);
    a->setValue(3, 3, 0);
    a->setValue(3, 5, 0);
    a->setValue(3, 4, 3);
    a->setValue(3, 6, 0);
    a->setValue(3, 7, 0);
    a->setValue(3, 8, 2);

    a->setValue(4, 0, 0);
    a->setValue(4, 1, 8);
    a->setValue(4, 2, 0);
    a->setValue(4, 3, 0);
    a->setValue(4, 4, 4);
    a->setValue(4, 5, 0);
    a->setValue(4, 6, 0);
    a->setValue(4, 7, 1);
    a->setValue(4, 8, 0);

    a->setValue(5, 0, 6);
    a->setValue(5, 1, 0);
    a->setValue(5, 2, 0);
    a->setValue(5, 3, 5);
    a->setValue(5, 4, 0);
    a->setValue(5, 5, 0);
    a->setValue(5, 7, 0);
    a->setValue(5, 6, 0);
    a->setValue(5, 8, 0);

    a->setValue(6, 0, 0);
    a->setValue(6, 1, 0);
    a->setValue(6, 3, 0);
    a->setValue(6, 2, 0);
    a->setValue(6, 5, 1);
    a->setValue(6, 4, 0);
    a->setValue(6, 6, 7);
    a->setValue(6, 7, 8);
    a->setValue(6, 8, 0);

    a->setValue(7, 0, 5);
    a->setValue(7, 1, 0);
    a->setValue(7, 2, 0);
    a->setValue(7, 3, 0);
    a->setValue(7, 4, 0);
    a->setValue(7, 5, 9);
    a->setValue(7, 6, 0);
    a->setValue(7, 7, 0);
    a->setValue(7, 8, 0);

    a->setValue(8, 0, 0);
    a->setValue(8, 1, 0);
    a->setValue(8, 2, 0);
    a->setValue(8, 3, 0);
    a->setValue(8, 4, 0);
    a->setValue(8, 5, 0);
    a->setValue(8, 6, 0);
    a->setValue(8, 7, 4);
    a->setValue(8, 8, 0);

    Grid *b = solve(a);
    if (b != nullptr) {
        cout << "Original:\n" << a->toString() << endl;
        cout << endl;
        cout << "Solution:\n" << b->toString() << endl;
    } else {
        cout << "nullptr encountered" << endl;
    }

    return EXIT_SUCCESS;
}
