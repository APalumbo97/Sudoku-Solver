/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: Backtracker.cpp
 * date: 6-3-2017
 * description: contains the implementation for the backtracking algorithm used to solve the puzzle
 */

#include "Backtracker.h"

/**
 * Clears all dynamic memory in the list.
 * @param lst: the pointer to the list to be cleared
 */
static void clearList(std::list<Grid*> *lst) {
    for (Grid *ptr : *lst) {
        delete ptr;
    }
    delete lst;
}

/**
 * Solves the sudoku puzzle or returns a null if there is no solution.
 * @param g: a pointer to the starting grid
 * @return: a pointer to the solution
 */
Grid* solve(Grid *g) {
    if (g->isGoal()) {
        return g;
    }

    std::list<Grid*> *successors = g->getSuccessors();
    std::list<Grid*>::iterator it;

    for (unsigned int i = 0; i < successors->size(); i++) {
        it = successors->begin();
        std::advance(it, i);

        if ((*it)->isValid()) {
            Grid *solCpy;

            if ((*it)->isGoal()) {
                solCpy = (*it)->copyGrid();
                clearList(successors);
                return solCpy;
            }

            Grid *solution = solve(*it);

            if (solution != nullptr) {
                Grid *solCpy = solution->copyGrid();
                clearList(successors);

                // if (solution != *it) {
                //     delete solution;
                // }

                return solCpy;
            }
        }
    }
    clearList(successors);

    return nullptr;
}
