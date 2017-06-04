/**
 * @author Anthony Palumbo
 * @version 1.0
 * filename: Grid.cpp
 * date: 6-3-2017
 * description: source file for the Grid class, contains all of the implementation for the class
 */

#include "Grid.h"

Grid::Grid() {
    grid = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        grid[i] = new int[SIZE];
    }
}

Grid::~Grid() {
    for (int i = 0; i < SIZE; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

int Grid::getValue(int row, int col) {
    return grid[row][col];
}

void Grid::setValue(int row, int col, int value) {
    grid[row][col] = value;
}

Grid* Grid::copyGrid(Grid *g) {
    Grid *copy = new Grid();
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            copy->setValue(r, c, g->getValue(r, c));
        }
    }
    return copy;
}

std::list<Grid*>* Grid::getSuccessors() {
    // TODO
    return new std::list<Grid*>();
}

bool Grid::isValid() {
    // TODO
    return true;
}

bool Grid::isGoal() {
    // TODO
    return false;
}

std::string Grid::toString() {
    // TODO
    return "<string of grid";
}
