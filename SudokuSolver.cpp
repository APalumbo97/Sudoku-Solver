/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: SudokuSolver.cpp
 * date: 6-3-2017
 * description: Program that is able to solve sudoku puzzles that are given in a file
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Backtracker.h"

#define INPUT_FILE "input_sudoku.txt"
#define INPUT_LENGTH (((SIZE + 2) * 11) + 20)

using namespace std;

/**
 * Entry point to sudoku solver program.
 * @return: EXIT_SUCCESS if run properly, otherwise EXIT_FAILURE
 */
int main() {
    ifstream input(INPUT_FILE);

    if (!input.is_open()) {
        cout << "Cannot open input file named \'" << INPUT_FILE << "\'." << endl;
        return EXIT_FAILURE;
    }

    Grid *g = new Grid();

    char input_buffer;
    int r = 0;
    int c = 0;

    for (int i = 0; i < INPUT_LENGTH && !input.eof(); i++) {
        input >> input_buffer;
        if (input_buffer != '|' && input_buffer != '-') {
            g->setValue(r, c, input_buffer - '0');
            if (c < SIZE - 1) {
                c++;
            } else if (c == SIZE - 1) {
                c = 0;
                r++;
            }
        }
    }

    Grid *b = solve(g);

    cout << "Original:\n" << g->toString() << endl << endl;
    if (b != nullptr) {
        cout << "Solution:\n" << b->toString() << endl;
    } else {
        cout << "No solution." << endl;
    }

    delete g;

    return EXIT_SUCCESS;
}
