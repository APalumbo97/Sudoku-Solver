/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: Backtracker.cpp
 * date: 6-3-2017
 * description: contains the implementation for the backtracking algorithm used to solve the puzzle
 */

#include "Backtracker.h"

/**
 * Solves the sudoku puzzle or returns a null if there is no solution.
 * @param g: a pointer to the starting grid
 * @return: a pointer to the solution
 */
Grid* solve(Grid *g) {
    if (g->isGoal()) {
        return g;
    } else {
        std::list<Grid*> *successors = g->getSuccessors();
        std::list<Grid*>::iterator it;

        for (unsigned int i = 0; i < successors->size(); i++) {
            it = successors->begin();
            std::advance(it, i);

            if ((*it)->isValid()) {
                Grid *solution = solve(*it);
                if (solution != nullptr) {
                    return solution;
                }
            } else {
                delete *it;
                *it = nullptr;
            }
        }
        successors->clear();
        delete successors;
    }

    return nullptr;
}
