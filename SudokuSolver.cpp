#include <cstdlib>
#include <iostream>
#include "Grid.h"

using namespace std;

int main() {
    cout << "Hello World." << endl;
    Grid a();
    cout << "Created a grid on the stack." << endl;
    Grid *b = new Grid();
    cout << "Created a grid on the heap." << endl;
    delete b;
    return EXIT_SUCCESS;
}
