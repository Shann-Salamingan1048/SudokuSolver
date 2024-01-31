#include "sudokuSolver.h"
#include <vector>
int main()
{
	std::vector<std::vector<uint16_t>> Board = {
	{0, 5 , 0 ,   8 , 0 , 0 ,   7, 0 , 2},	{0, 0 , 0 ,   0 , 4 , 0 ,   0, 0 , 0},	{0, 0 , 0 ,   0 , 0 , 0 ,   5, 0 , 0},	
	{9, 0 , 0 ,   0 , 7 , 0 ,   1, 0 , 0},	{0, 0 , 5 ,   0 , 9 , 0 ,   0, 8 , 0},
	{0, 0 , 0 ,   0 , 0 , 0 ,   0, 0 , 0},	
	{0, 0 , 0 ,   0 , 0 , 0 ,   4, 1 , 3},
	{0, 4 , 0 ,   0 , 0 , 0 ,   0, 0 , 0},	{0, 0 , 6 ,   0 , 2 , 0 ,   0, 0 , 0}	  };
	
	sudokuSolver ss;
	ss.run(Board);
	
	return 0;
}