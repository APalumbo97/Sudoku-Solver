/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: Grid.cpp
 * date: 6-3-2017
 * description: source file for the Grid class, contains all of the implementation for the class
 */

#include "Grid.h"

/**
 * Constructor for the Grid class.
 */
Grid::Grid() {
    grid = new int*[SIZE];

    for (int i = 0; i < SIZE; i++) {
        grid[i] = new int[SIZE];
    }

    currRow = 0;
    currCol = 0;
}

/**
 * Destructor for the Grid class.
 */
Grid::~Grid() {
    for (int i = 0; i < SIZE; i++) {
        delete[] grid[i];
    }

    delete[] grid;
}

/**
 * Getter for any value in the grid.
 * @param row: the index of the row
 * @param col: the index of the column
 * @return: the value at the given row and column indexes
 */
int Grid::getValue(int row, int col) {
    return grid[row][col];
}

/**
 * Setter for any value in the grid.
 * @param row: the index of the row
 * @param col: the index of the column
 * @param value: the value to set at the given row and column
 */
void Grid::setValue(int row, int col, int value) {
    grid[row][col] = value;
}

/**
 * Allocates dynamic memory for a new grid and copies over the contents.
 * @return: a pointer to the new grid object
 */
Grid* Grid::copyGrid() {
    Grid *copy = new Grid();

    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            copy->setValue(r, c, grid[r][c]);
        }
    }

    copy->currRow = currRow;
    copy->currCol = currCol;

    return copy;
}

/**
 * Creates a list of successors by moving the cursor and setting the next value.
 * @return: a list of the successors
 */
std::list<Grid*>* Grid::getSuccessors() {
    std::list<Grid*> *successors = new std::list<Grid*>();

    if (canMove()) {
        Grid *copy = copyGrid();
        copy->moveCursor();
        if (copy->getValue(currRow, currCol) != 0) {
            successors->push_back(copy);
            return successors;
        } else {
            delete copy;
        }
        for (int i = 0; i < SIZE; i++) {
            copy = copyGrid();
            copy->moveCursor();
            copy->setValue(currRow, currCol, i + 1);
            if (copy->isValid()) {
                successors->push_back(copy);
            } else {
                delete copy;
            }
        }
    }

    return successors;
}

/**
 * Determines if the current configuration could be a possible solution.
 * @return: true if it could be a solution, false if not
 */
bool Grid::isValid() {
    // Checks each row for a duplicate number.
    for (int r = 0; r < SIZE; r++) {
        bool nums[SIZE] = {false * SIZE};
        for (int c = 0; c < SIZE; c++) {
            if ((grid[r][c] > 0) && (!nums[grid[r][c] - 1])) {
                nums[grid[r][c] - 1] = true;
            } else if ((grid[r][c] > 0) && (nums[grid[r][c] - 1])) {
                return false;
            }
        }
    }

    // Checks each column for a duplicate number.
    for (int c = 0; c < SIZE; c++) {
        bool nums[SIZE] = {false * SIZE};
        for (int r = 0; r < SIZE; r++) {
            if ((grid[r][c] > 0) && (!nums[grid[r][c] - 1])) {
                nums[grid[r][c] - 1] = true;
            } else if ((grid[r][c] > 0) && (nums[grid[r][c] - 1])) {
                return false;
            }
        }
    }

    // Checks squares.
    int val;
    for (int sRow = 0; sRow < SQUARES; sRow++) {
        for (int sCol = 0; sCol < SQUARES; sCol++) {
            bool nums[SIZE] = {false * SIZE};
            for (int r = 0; r < SQUARES; r++) {
                for (int c = 0; c < SQUARES; c++) {
                    val = grid[(sRow * 3) + r][(sCol * 3) + c];
                    if ((val > 0) && (!nums[val - 1])) {
                        nums[val - 1] = true;
                    } else if ((val > 0) && (nums[val - 1])) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

/**
 * Determines if the current configuration is a solution or not.
 * @return: true if it is a solution, false if not
 */
bool Grid::isGoal() {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            if (grid[r][c] <= 0 || grid[r][c] > 9) {
                return false;
            }
        }
    }

    return isValid();
}

/**
 * Determines if the cursor can be advanced a position or not.
 * @return: true if the cursor can be moved, false if it is at the last position of the board
 */
bool Grid::canMove() {
    return !((currRow == SIZE - 1) && (currCol == SIZE));
}

/**
 * Moves the cursor to the next position if it is not at the last position of the board.
 * @return: true if the cursor was moved, false if it cannot be moved
 */
bool Grid::moveCursor() {
    if (!canMove()) {
        return false;
    } else {
        if (currCol != SIZE - 1) {
            currCol++;
            return true;
        } else {
            currCol = 0;
            if (currRow == SIZE - 1) {
                return false;
            } else {
                currRow++;
                return true;
            }
        }
    }
}

/**
 * Creates a string for the given row.
 * @param row: the index of the row to generate a string for
 * @return: a string for that row
 */
std::string Grid::rowString(int row) {
    std::string output = "";
    int c;

    for (c = 0; c < 3; c++) {
        output += std::to_string(grid[row][c]) + " ";
    }
    output += "| ";

    for (c = 3; c < 6; c++) {
        output += std::to_string(getValue(row, c)) + " ";
    }
    output += "| ";

    for (c = 6; c < SIZE; c++) {
        output += std::to_string(getValue(row, c)) + " ";
    }

    return output;
}

/**
 * Creates a string representation of the entire grid.
 * @return: a string for the entire grid.
 */
std::string Grid::toString() {
    std::string output = "";

    // TODO remove this
    output += std::to_string(currRow) + "," + std::to_string(currCol) + "\n";

    int r;

    for (r = 0; r < 3; r++) {
        output += rowString(r) + "\n";
    }
    output += "---------------------\n";

    for (r = 3; r < 6; r++) {
        output += rowString(r) + "\n";
    }
    output += "---------------------\n";

    for (r = 6; r < SIZE; r++) {
        output += rowString(r) + "\n";
    }

    return output;
}
