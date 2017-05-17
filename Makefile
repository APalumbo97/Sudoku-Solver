# Makefile for Sudoku-Solver project.
# Author: Anthony Palumbo

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic

CPP_FILES = Sudoku-Solver.cpp Grid.cpp Backtracker.cpp
H_FILES = Grid.h Backtracker.h
OBJFILES = SudokuSolver.o Grid.o Backtracker.o

# Main targets

all: sudoku-solver

sudoku-solver: $(OBJFILES)
	$(CXX) $(CXXFLAGS) $(OBJFILES) -o sudoku-solver

# Dependencies

SudokuSolver.o: SudokuSolver.cpp Grid.h Backtracker.h
	$(CXX) $(CXXFLAGS) SudokuSolver.cpp -c

Grid.o: Grid.cpp Grid.h
	$(CXX) $(CXXFLAGS) Grid.cpp -c

Backtracker.o: Backtracker.cpp Backtracker.h
	$(CXX) $(CXXFLAGS) Backtracker.cpp -c

# Cleaning

clean:
	rm -rf $(OBJFILES)

realclean: clean
	rm -rf sudoku-solver
