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
