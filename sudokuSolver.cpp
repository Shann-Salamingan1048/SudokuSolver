#include "sudokuSolver.h"
void sudokuSolver::run(std::vector<std::vector<uint16_t>>& Board)
{
	uint16_t row = 0, col = 0;
	this->printBoard(Board);
	if(this->solveSudoku(Board, row , col))
	   cout << endl << "Solved!" << endl;
	else
	   cout << endl << "Can't be solved!" << endl;
	
	this->printBoard(Board);
}

void sudokuSolver::printBoard(std::vector<std::vector<uint16_t>>& Board)
{
	for(std::vector<uint16_t> i : Board)
	{
		for(uint16_t cell : i)
		{
			cout << cell << ", ";
		}
		cout << endl;
	}	
}

