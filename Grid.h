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

class Grid {
private:
    int **grid;
public:
    Grid();
    ~Grid();
    int getValue(int row, int col);
    void setValue(int row, int col, int value);
    Grid* copyGrid(Grid *g);
    std::list<Grid*>* getSuccessors();
    bool isValid();
    bool isGoal();
    std::string toString();
};

#endif
