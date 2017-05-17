#ifndef _GRID_H
#define _GRID_H

#define SIZE 9

class Grid {
    private:
        int **grid;
    public:
        Grid();
        ~Grid();
        void printStuff(char c);
};

#endif
