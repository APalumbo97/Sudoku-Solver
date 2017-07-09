/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: Grid.h
 * date: 6-3-2017
 * description: header file for the Grid class
 */

#ifndef _GRID_H
#define _GRID_H

#include <string>
#include <list>

#define SIZE 9
#define SQUARES 3

class Grid {
private:

    /** 2D array that stores the values of the board. */
    int **grid;

    /** Stores the position of a cursor used for backtracking. */
    int currRow;
    int currCol;

    /**
     * Determines if the cursor can be advanced a position or not.
     * @return: true if the cursor can be moved, false if it is at the last position of the board
     */
    bool canMove();

    /**
     * Moves the cursor to the next position if it is not at the last position of the board.
     * @return: true if the cursor was moved, false if it cannot be moved
     */
    bool moveCursor();

    /**
     * Creates a string for the given row.
     * @param row: the index of the row to generate a string for
     * @return: a string for that row
     */
    std::string rowString(int row);

public:

    /**
     * Constructor for the Grid class.
     */
    Grid();

    /**
     * Destructor for the Grid class.
     */
    ~Grid();

    /**
     * Allocates dynamic memory for a new grid and copies over the contents.
     * @return: a pointer to the new grid object
     */
    Grid* copyGrid();

    /**
     * Getter for any value in the grid.
     * @param row: the index of the row
     * @param col: the index of the column
     * @return: the value at the given row and column indexes
     */
    int getValue(int row, int col);

    /**
     * Setter for any value in the grid.
     * @param row: the index of the row
     * @param col: the index of the column
     * @param value: the value to set at the given row and column
     */
    void setValue(int row, int col, int value);

    /**
     * Creates a list of successors by moving the cursor and setting the next value.
     * @return: a list of the successors
     */
    std::list<Grid*>* getSuccessors();

    /**
     * Determines if the current configuration could be a possible solution.
     * @return: true if it could be a solution, false if not
     */
    bool isValid();

    /**
     * Determines if the current configuration is a solution or not.
     * @return: true if it is a solution, false if not
     */
    bool isGoal();

    /**
     * Creates a string for the given row.
     * @param row: the index of the row to generate a string for
     * @return: a string for that row
     */
    std::string toString();

};

#endif
