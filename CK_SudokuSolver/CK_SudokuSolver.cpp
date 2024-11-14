#include <iostream>
#include <vector>

#define UNASSIGNED 0
#define N 9

using namespace std;

                                        // Function to check if it is safe to place a number in a cell

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) { // Function to check if it is safe to place a number in a cell
	for (int x = 0; x < N; x++) {                                   // Check if the number is already present in the row or column
		if (grid[row][x] == num || grid[x][col] == num) {           // If the number is already present in the row or column
            return false;
        }
    }
	int startRow = row - row % 3, startCol = col - col % 3;		// Check if the number is already present in the 3x3 grid
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i + startRow][j + startCol] == num) {	    // If the number is already present in the 3x3 grid
                return false;
            }
        }
    }
    return true;
}

                                        // Solves the Sudoku grid using backtracking

bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
	if (row == N - 1 && col == N) {                     // If we have reached the end of the grid
        return true;
    }
	if (col == N) {                                     // If we have reached the end of a row
        row++;
        col = 0;
    }
	if (grid[row][col] != UNASSIGNED) {                 // If the cell is already filled
		return solveSudoku(grid, row, col + 1);         // Move to the next cell
    }
	for (int num = 1; num <= N; num++) {                // Try placing a number in the cell
		if (isSafe(grid, row, col, num)) {              // Check if it is safe to place the number
			grid[row][col] = num;                       // Place the number
			if (solveSudoku(grid, row, col + 1)) {      // Recursively solve the rest of the grid
                return true;
            }
			grid[row][col] = UNASSIGNED;                // If the number doesn't lead to a solution, backtrack
			                                            // Backtracking = Reset the cell to UNASSIGNED and try the next number
        }
    }
    return false;
}

                                        // Function to print the Sudoku grid

void printGrid(vector<vector<int>>& grid) {             // Function to print the Sudoku grid
	cout << "\n\n\n" << "Solution:" << endl;            // Print the solution
	for (int row = 0; row < N; row++) {                 // Traverse each row
		for (int col = 0; col < N; col++) {             // Traverse each column
			cout << grid[row][col] << " ";              // Print the cell value
        }
        cout << endl;
    }
}

                                        // Main Function at the beginning of the program

int main() {
	vector<vector<int>> grid(N, vector<int>(N));
	cout << "Enter the Sudoku grid (use 0 for empty cells):" << endl;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }

	if (solveSudoku(grid, 0, 0)) {              // If True is returned by solveSudoku function
		printGrid(grid);
    }
	else {                                      // If False is returned by solveSudoku function
        cout << "No solution exists" << endl;
    }

    return 0;
}