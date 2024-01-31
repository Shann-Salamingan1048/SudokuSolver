#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using std::cout;
using std::endl;
using std::setw;

class sudokuSolver
{
	private:
	  const uint16_t Size = 9;
	  // check row if safe
	  bool checkRow(std::vector<std::vector<uint16_t>>& Board, uint16_t row, uint16_t num);
	  // check col if safe
	  bool checkCol(std::vector<std::vector<uint16_t>>& Board, uint16_t col, uint16_t num );
	  // check grid if safe
	  bool checkGrid(std::vector<std::vector<uint16_t>>&Board, uint16_t row, uint16_t col, uint16_t num);
	  // check cell if safe
	  bool safeCell(std::vector<std::vector<uint16_t>>& Board, uint16_t row, uint16_t col,uint16_t num);
	  // start solving
	  const bool solveSudoku(std::vector<std::vector<uint16_t>>& Board, uint16_t row, uint16_t col);
	  
	  // print
	  void printBoard(std::vector<std::vector<uint16_t>>& Board);
	  
	public:
	  void run(std::vector<std::vector<uint16_t>>& Board);
	
};