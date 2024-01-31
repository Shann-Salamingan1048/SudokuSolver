#include "sudokuSolver.h"

const bool sudokuSolver::solveSudoku(std::vector<std::vector<uint16_t>>& Board, uint16_t row, uint16_t col)
{
	// prevent backtracking, this means that it has reached the last cell of the board because if col == size then it becomes 0 and row == Size - 1 (8), will later on becomes 9.see the next if below.
	if(row == Size - 1 && col == Size )
	   return true;
	// if col equal to size(9) then make it zero and increase row, to proceed the next row.
	if(col == Size)
	{
		col = 0;
		row++;
	}
	// if it is occupied then proceed to next column
	if(Board[row][col] > 0)
	   return this->solveSudoku(Board,row,col+1);
	
	for(uint16_t num = 1; num <= this->Size; num++)
	{
		if(this->safeCell(Board, row, col, num))
		{
			Board[row][col] = num;
			// proceed to the next column to be able to solve
			if(solveSudoku(Board, row, col+1))
			return true;
		}
		// if the assumption is wrong then go back to 0, if it cant be solved then it will go back to 0 and will not let the assumed number will be remain
		Board[row][col] = 0;
	}
	return false;
}
// check cell if safe
bool sudokuSolver::safeCell(std::vector<std::vector<uint16_t>>& Board, uint16_t row, uint16_t col,uint16_t num)
{
	return (this->checkCol(Board,col,num) && this->checkRow(Board,row,num)) && this->checkGrid(Board, row,col,num);
}
// bool checkGrid()
bool sudokuSolver::checkGrid(std::vector<std::vector<uint16_t>>&Board, uint16_t row, uint16_t col, uint16_t num)
{
	for(uint16_t i = 0; i < 3; i++)
	{
		for(uint16_t k = 0; k < 3; k++)
		{
			// for example 8 - 8 % 3 = 8 -2= 6 and 6 = 7th(0 index based) row or column. 5 - 5 % 3 = 5 - 2 = 3 = 4th. 2 - 2 % 3 = 2 - 2 = 0 = 1st. etc. it 1st = 0,1,2 . 4th = 3,4,5. 7th = 6,7,8.
			if(Board[i + (row - row % 3)][k + (col - col % 3)] == num)
			{
				return false;
			}
		}
	}
	return true;
}
// bool checkRow()
bool sudokuSolver::checkRow(std::vector<std::vector<uint16_t>>& Board,uint16_t row, uint16_t num)
{
	for(uint16_t i = 0; i < this->Size;i++)
	{
		if(Board[row][i] == num)
		  return false;
	}
	return true;
}
//bool sudokuSolver::checkCol()
bool sudokuSolver::checkCol(std::vector<std::vector<uint16_t>>& Board, uint16_t col, uint16_t num)
{
	for(uint16_t i = 0; i < this->Size;i++)
	{
		if(Board[i][col] == num)
		  return false;
	}
	return true;
}