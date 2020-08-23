// this header creates the difficult AI
#include "grid.hpp"
// #include "randomize_algorithm.hpp"


struct node  // test node
{
	int length;
	struct node* next;
};


// the function gives the permutation number for every possible ships on each square in the grid for AI in hunt mode
int** hunt_pdf(int grid[8][8], node* ship)
{
	int** new_grid = new int*[8];  // give a new grid that's filled with 0, but contains -2 and -4 like it does in the original grid
	
	for (int i = 0; i < 8; i++)
	{
		new_grid[i] = new int[8];
	}
	
	int ship_length;  // the length of the ship, obtained from the linked list
	int max_square;  // the maximum number of ships in a row or a column 
	int condition;  // the condition whether the ship can fit in the square, if a ship can, give 1, if not, 0
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] != -2 && grid[i][j] != -4)
			{
				new_grid[i][j] = 0;
			}
			else
			{
				new_grid[i][j] = grid[i][j];
			}
		}
	}
	
	while (ship != NULL)
	{
		condition = 1;  // assume that the ship can fit in the square
		ship_length = ship -> length;
		max_square = 8 - ship_length + 1;
		
		for (int i = 0; i < 8; i++)  // the first for loop counts for the permutation of the ship that's put horizontally
		{
			for (int j = 0; j < max_square; j++)
			{
				for (int x = j; x < j + ship_length; x++)
				{
					if (new_grid[i][x] == -2 || new_grid[i][x] == -4)
					{
						condition = 0;  // if there's a bomb there or a part of a sunk ship, the ship can't fit in place
					}
				}
				if (condition == 1)
				{
					for (int x = j; x < j + ship_length; x++)
					{
						new_grid[i][x]++;  // if the ship can fit in the square, add the permutation number on the square
					}
				}
				condition = 1;
			}
		}
		
		for (int i = 0; i < max_square; i++)  // the second for loop counts for the permutation of the ship verticallly
		{
			for (int j = 0; j < 8; j++)
			{
				for (int x = i; x < i + ship_length; x++)
				{
					if (new_grid[x][j] == -2 || new_grid[x][j] == -4)  // same thing as above, but vertically
					{
						condition = 0;
					}
				}
				if (condition == 1)
				{
					for (int x = i; x < i + ship_length; x++)
					{
						new_grid[x][j]++;
					}
				}
				condition = 1;
			}
		}
		ship = ship -> next;
	}
	return new_grid;
}


// the function gives the permutation number for every possible ships on each square in the grid for AI in hunt mode
int** destroy_pdf(int grid[8][8], node* ship)
{
	int** new_grid = new int*[8];  // give a new grid for the destroy mode
	
	for (int i = 0; i < 8; i++)
	{
		new_grid[i] = new int[8];
	}
	
	
	int counter;  // a counter to count the number of wounds
	int ship_length;  // the length of the ship, obtained from the linked list
	int max_square;  // the maximum number of ships in a row or a column 
	int condition_a;  // the condition whether the ship can fit in the square, if a ship can, give 1, if not, 0
	int condition_b;  // the condition whether the ship can fit in all the wounded area(3), if it can: 1, if not: 0
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (grid[i][j] == -2 || grid[i][j] == -4)
			{
				new_grid[i][j] = grid[i][j];
			}
			else
			{
				new_grid[i][j] = 0;
			}
		}
	}
	
	int wound_count = int_count(grid, -3);  // the number of -3 in the grip
	std::vector <std::vector <int> > wounded_area = int_list(grid, -3);  // a 2 dimensional vector of all wounded area
	
	while (ship != NULL)
	{
		condition_a = 1;  // assume ship fit in the square
		condition_b = 0;  // assume ship doesn't fit in the wounded area(3)
		ship_length = ship -> length;  
		max_square = 8 - ship_length + 1;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				for (int x = j; x < j + ship_length; x++)
				{
					if (new_grid[i][x] == -2 || new_grid[i][x] == -4)
					{
						condition_a = 0;  // if there's a bomb or a sunk ship, the ship can't be in place
					}
				}
				
				counter = 0;  // set the counter of the wound to 0
				for (int y = 0; y < wound_count; y++)  // for every single number of wound_count
				{
					for (int x = j; x < j + ship_length; x++)  // check if there exists ship component that's in the wounded area
					{
						if (i == wounded_area[y][0] && x == wounded_area[y][1])  // are the rows match, are the columns match
						{
							counter++;
						}
					}
				}
				
				if (counter == wound_count)  // if all the wound match the ship, the ship can fit in the wounded area
				{
					condition_b = 1;
				}
				
				if (condition_a == 1 && condition_b == 1)  // if the ship is not blocked by bullet or other sunk ship and the ship is in wounded area
				{
					for (int x = j; x < j + ship_length; x++)
					{
						new_grid[i][x]++;
					}
				}
				
				condition_a = 1;
				condition_b = 0;
			}
		}
		
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				for (int x = i; x < i + ship_length; x++)
				{
					if (new_grid[x][j] == -2 || new_grid[x][j] == -4)
					{
						condition_a = 0;
					}
				}
				
				counter = 0;  // set the counter of the wound to 0
				for (int y = 0; y < wound_count; y++)  // for every single number of wound_count
				{
					for (int x = i; x < i + ship_length; x++)  // check if there exists ship component that's in the wounded area
					{
						if (x == wounded_area[y][0] && j == wounded_area[y][1])  // are the rows match, are the columns match
						{
							counter++;
						}
					}
				}
				
				if (counter == wound_count)  // if all the wound match the ship, the ship can fit in the wounded area
				{
					condition_b = 1;
				}
				
				if (condition_a == 1 && condition_b == 1)  // if the ship is not blocked by bullet or other sunk ship and the ship is in wounded area
				{
					for (int x = i; x < i + ship_length; x++)
					{
						new_grid[x][j]++;
					}
				}
				
				condition_a = 1;
				condition_b = 0;
			}
		}
		ship = ship -> next;
	}
	
	for (int i = 0; i < wound_count; i++)
	{
			new_grid[wounded_area[i][0]][wounded_area[i][1]] = 0;
	}
	
	return new_grid;
}


// the difficult AI that will play against the player
int* difficult_ai(int grid[8][8], node* ship)
{
	int* coord = new int[2];  // an array for the coordinate
	
	int max = 0;  // set the maximum weight to be 0
	int counter_a = 0;  // the counter will count for the number of maximum numbers
	int counter_b = 0;  // the counter will count max numbers until it reaches the random cardinal number
	int random_cardinal;  // a random number that's generated between 0 to the number of maximum numbers
	
	if (!(int_search(grid, -3)))  // if there's no wounded ships, enter hunt mode
	{
		int** hunt_grid = hunt_pdf(grid, ship);
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (max < hunt_grid[i][j])  // find the maximum number on the grid
				{
					max = hunt_grid[i][j];
				}
			}
		}
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (hunt_grid[i][j] == max)
				{
					counter_a++;  // count the number of maximum on the grid
				}
			}
		}
		
		std::srand(std::time(NULL));  // generate a random number
		random_cardinal = std::rand() % counter_a;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (hunt_grid[i][j] == max)
				{
					if (counter_b == random_cardinal)
					{
						coord[0] = i;
						coord[1] = j;
						
						return coord;
					}
					
					counter_b++;
				}
			}
		}
	}
	else if (int_search(grid, -3))  // if there's wounded ships, enter destroy mode
	{
		int** destroy_grid = destroy_pdf(grid, ship);
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (max < destroy_grid[i][j])  // find the maximum number on the grid
				{
					max = destroy_grid[i][j];
				}
			}
		}
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (destroy_grid[i][j] == max)
				{
					counter_a++;  // count the number of maximum on the grid
				}
			}
		}
		
		std::srand(std::time(NULL));  // generate a random number
		random_cardinal = std::rand() % counter_a;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (destroy_grid[i][j] == max)
				{
					if (counter_b == random_cardinal)
					{
						coord[0] = i;
						coord[1] = j;
						
						return coord;
					}
					
					counter_b++;
				}
			}
		}
	}
}
