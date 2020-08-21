// contains the functions to test the grid
#include <iostream>


// the function print out the game board grid
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


// the function checks whether the ships are indeed ramdomly generated on the grid
bool randomizer_check(int grid[8][8])
{
	bool submarine = 0, cruiser = 0, battleship = 0, carrier = 0;  // the occurence of each ship
	unsigned int length_counter = 0;  // counting for the length of each ships
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == 1)
			{
				
			}
		}
	}
	if (submarine == 0 || cruiser == 0 || battleship == 0 || carrier == 0)
	{
		return 0;
	}
	return 1;
}
