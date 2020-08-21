#include <iostream>


void print_grid(int grid[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << grid[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}
