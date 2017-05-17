#include <cstdlib>
#include <iostream>
#include "Grid.h"
#include "Backtracker.h"

using namespace std;

int main() {
    cout << "Hello World." << endl;
    Grid a = Grid();
    a.printStuff('a');
    Grid *b = new Grid();
    b->printStuff('b');
    delete b;
    return EXIT_SUCCESS;
}
