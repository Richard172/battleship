// a battleship game made by Richard, Tej, and Arjun
#include <iostream>
#include "grid.hpp"


int main()
{
	int size_ten_grid[8][8];  // a 8 by 8 matrix for the game board

	for (int i = 0; i < 8; i++)  // initialize the values for the grid to be 0
	{
		for (int j = 0; j < 8; j++)
		{
			size_ten_grid[i][j] = 0;
		}
	}
	
	std::cout << "Do you want to fight against a normal AI or a difficult AI?" << std::endl;  // asking the user for normal or difficult difficulty
	
	print_grid(size_ten_grid);

	return 0;
}