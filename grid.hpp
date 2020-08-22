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


char int_to_char(int num)
{
	if (num == 1)
	{
		return 'C';
	}
	else if (num == 2)
	{
		return 'B';
	}
	else if (num == 3)
	{
		return 'c';
	}
	else if (num == 4)
	{
		return 'S';
	}
	else 
	{
		return ' ';
	}
}


void print_game(int grid[8][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+          |          ";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+\n";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "| " << int_to_char(grid[i][j]) << " ";
		}
		
		std::cout << "|          |          ";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "|   ";
		}
		
		std::cout << "|\n";
	}
	
	for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+          |          ";
		
		for (int j = 0; j < 8; j++)
		{
			std::cout << "+---";
		}
		
		std::cout << "+\n";
}


// the function contains the test grid for the player
void player_grid(int grid[8][8])
{
	grid[1][6] = 2;
	grid[2][6] = 2;
	grid[3][6] = 2;
	grid[4][6] = 2;
	
	grid[1][1] = 3;
	grid[1][2] = 3;
	grid[1][3] = 3;
	
	grid[4][0] = 1;
	grid[4][1] = 1;
	grid[4][2] = 1;
	grid[4][3] = 1;
	
	grid[6][5] = 4;
	grid[6][6] = 4;
	grid[6][7] = 4;
}


// the function contains the test grid for the AI
void ai_grid(int grid[8][8])
{
	grid[0][3] = 4;
	grid[0][4] = 4;
	grid[0][5] = 4;
	
	grid[1][1] = 1;
	grid[2][1] = 1;
	grid[3][1] = 1;
	grid[4][1] = 1;
	
	grid[3][3] = 3;
	grid[4][3] = 3;
	grid[5][3] = 3;
	
	grid[2][5] = 2;
	grid[3][5] = 2;
	grid[4][5] = 2;
	grid[5][5] = 2;
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
