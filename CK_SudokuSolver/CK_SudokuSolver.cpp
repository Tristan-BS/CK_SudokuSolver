#include <iostream>
#include <stdlib.h>
#include <vector>

#include "CK_Solver.h"

using namespace std;

int main()
{
	int Size;
	cout << "Enter the size of the Sudoku: ";
	cin >> Size;

	vector<vector<int>> Sudoku(Size, vector<int>(Size, 0));

	cout << "Enter the Sudoku: " << endl;
	for (int i = 0; i < Size; i++)
	{
		for (int j = 0; j < Size; j++)
		{
			cin >> Sudoku[i][j];
		}
	}
}