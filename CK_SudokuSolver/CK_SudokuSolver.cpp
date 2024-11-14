#include <iostream>
#include <vector>

#define UNASSIGNED 0
#define N 9

using namespace std;

bool isSafe(vector<vector<int>>& grid, int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }
    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& grid, int row, int col) {
    if (row == N - 1 && col == N) {
        return true;
    }
    if (col == N) {
        row++;
        col = 0;
    }
    if (grid[row][col] != UNASSIGNED) {
        return solveSudoku(grid, row, col + 1);
    }
    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, row, col + 1)) {
                return true;
            }
            grid[row][col] = UNASSIGNED;
        }
    }
    return false;
}

void printGrid(vector<vector<int>>& grid) {
    cout << "\n\n\n" << "Solution:" << endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid(N, vector<int>(N));
    cout << "Enter the Sudoku grid (use 0 for empty cells):" << endl;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> grid[row][col];
        }
    }

    if (solveSudoku(grid, 0, 0)) {
        printGrid(grid);
    }
    else {
        cout << "No solution exists" << endl;
    }

    return 0;
}