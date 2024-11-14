# CK_SudokuSolver

CK_SudokuSolver is a command-line based Sudoku solver written in C++. This program allows users to input a Sudoku puzzle and find its solution using a backtracking algorithm.

## Features

- Accepts dynamic input for Sudoku grids.
- Solves Sudoku puzzles using an efficient backtracking algorithm.
- Provides user-friendly command-line interface.

## Usage

1. Compile the program:
   ```sh
   g++ -o sudoku_solver sudoku_solver.cpp
   ```

2. Run the program:
   ```sh
   ./sudoku_solver
   ```

3. Enter the Sudoku Grid ( Use 0 for empty Cells ) when promted:
   ```sh
    5 3 0 0 7 0 0 0 0
    6 0 0 1 9 5 0 0 0
    0 9 8 0 0 0 0 6 0
    8 0 0 0 6 0 0 0 3
    4 0 0 8 0 3 0 0 1
    7 0 0 0 2 0 0 0 6
    0 6 0 0 0 0 2 8 0
    0 0 0 4 1 9 0 0 5
    0 0 0 0 8 0 0 7 9
   ```

4. The Program will output the solved Sudoku Grid or indicate if no Solution exists.
   ```sh
    5 3 4 6 7 8 9 1 2
    6 7 2 1 9 5 3 4 8
    1 9 8 3 4 2 5 6 7
    8 5 9 7 6 1 4 2 3
    4 2 6 8 5 3 7 9 1
    7 1 3 9 2 4 8 5 6
    9 6 1 5 3 7 2 8 4
    2 8 7 4 1 9 6 3 5
    3 4 5 2 8 6 1 7 9
   ```
