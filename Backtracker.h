/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: Backtracker.h
 * date: 6-3-2017
 * description: header file for the backtracker
 */

#ifndef _BACKTRACKER_H
#define _BACKTRACKER_H

#include "Grid.h"

/**
 * Solves the sudoku puzzle or returns a null if there is no solution.
 * @param g: a pointer to the starting grid
 * @return: a pointer to the solution
 */
Grid* solve(Grid *g);

#endif
