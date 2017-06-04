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
    Grid *b = new Grid();
    cout << a.toString() << endl;
    cout << b->toString() << endl;
    delete b;
    return EXIT_SUCCESS;
}
