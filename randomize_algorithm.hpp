// this section will be able to randomize the ships location on a 8 x 8 grid.

#include "grid.hpp"

struct node{
    int arr1[3];  //4 int arrays represent coordinates
    int arr2[3];
    int arr3[3];
    int arr4[3];
	int length;
    std::string name;
    node* next;
};

node* structure(int carrier[4][2],int battleship[4][2], int submarine[3][2],int cruiser[3][2]){
    // first = carrier, second = battleship, third = submarine, fourth = cruiser 
    node* first = new node;
    node* second = new node;
    node* third = new node;
    node* fourth = new node; 

    first -> next = second;
    second -> next  = third;
    third -> next = fourth;
    fourth -> next =  NULL;
    
    //row 
    first -> arr1[0] = carrier[0][0];
    first -> arr2[0] = carrier[1][0];
    first -> arr3[0] = carrier[2][0];
    first -> arr4[0] = carrier[3][0];

    //cols 
    first -> arr1[1] = carrier[0][1];
    first -> arr2[1] = carrier[1][1];
    first -> arr3[1] = carrier[2][1];
    first -> arr4[1] = carrier[3][1];

    //boolean value if you miss
    first -> arr1[2] =  0;
    first -> arr2[2] =  0;
    first -> arr3[2] =  0;
    first -> arr4[2] =  0;

    //name of ship is carrier
    first -> name = "carrier";

    //rows battleship
    second -> arr1[0] = battleship[0][0];
    second -> arr2[0] = battleship[1][0];
    second -> arr3[0] = battleship[2][0];
    second -> arr4[0] = battleship[3][0];
    //cols battleship
    second -> arr1[1] = battleship[0][1];
    second -> arr2[1] = battleship[1][1];
    second -> arr3[1] = battleship[2][1];
    second -> arr4[1] = battleship[3][1];

    //boolean value if u miss for battleship
    second -> arr1[2] =  0;
    second -> arr2[2] =  0;
    second -> arr3[2] =  0;
    second -> arr4[2] =  0;

    //name
    second -> name = "battleship";

    //row submarine
    third -> arr1[0] = submarine[0][0];
    third -> arr2[0] = submarine[1][0];
    third -> arr3[0] = submarine[2][0];
    third -> arr4[0] = -1;
    //cols sub
    third -> arr1[1] = submarine[0][1];
    third -> arr2[1] = submarine[1][1];
    third -> arr3[1] = submarine[2][1];
    third -> arr4[1] = -1;
    //boolean for miss
    third -> arr1[2] =  0;
    third -> arr2[2] =  0;
    third -> arr3[2] =  0;
    third -> arr4[2] =  1;
    //name
    third -> name =  "submarine";

    //cruiser rows
    fourth -> arr1[0] = cruiser[0][0];
    fourth -> arr2[0] = cruiser[1][0];
    fourth -> arr3[0] = cruiser[2][0];
    fourth -> arr4[0] = -1;
    //cruiser cols
    fourth -> arr1[1] = cruiser[0][1];
    fourth -> arr2[1] = cruiser[1][1];
    fourth -> arr3[1] = cruiser[2][1];
    fourth -> arr4[1] = -1;
    //cruiser boolean if miss
    third -> arr1[2] =  0;
    third -> arr2[2] =  0;
    third -> arr3[2] =  0;
    third -> arr4[2] =  1;
    // name
    fourth -> name = "cruiser";

	first -> length = 4;
	second -> length = 4;
	third -> length = 3;
	fourth -> length = 3;
	
	return first;
}


// the function randomize the ships position
node* randomizer(int new_grid[8][8])
{
	int counter;  // a counter that decides the randomness of the ship
	int max_square;  // the maximum number of ships in a row or column
	int coin_flip;  // either 0 or 1, random. If the flip is 0, then the ship is horiontal. If the flip is 1, then the ship is vertical
	int random_number;  // a random number from 1 to 25 or 1 to 36
	int truth_grid[8][8];  // a grid that will decide whether the ship fits on the new_grid
	int row;  
	int col;
	
	zero_grid(new_grid);
	zero_grid(truth_grid);

	max_square = 8 - 4 + 1;

	std::srand(std::time(NULL));  // flip a fair coin
	coin_flip = std::rand() % 2; 
	
	random_number = std::rand() % 40 + 1;

	if (coin_flip == 0)  // if the flip is 0, then the ship will be placed horrizontal
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				truth_grid[i][j] = 1;
			}
		}
	}
	else if (coin_flip == 1)  // if the flip is 1, then the ship will be placed vertically
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				truth_grid[i][j] = 1;
			}
		}
	}
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	int arr[4][2];  // array_1 of coordinates
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 4; j++)
		{
			new_grid[row][j] = 1;
			arr[j - col][1] = j;
			arr[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 4; i++)
		{
			new_grid[i][col] = 1;
			arr[i - row][0] = i;
			arr[i - row][1] = col;
		}
	}
	
	for (int x = 0; x < 4; x++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				row = arr[x][0] + i;
				col = arr[x][1] + j;
				if ((row < 8 && row >= 0) && (col < 8 && col >= 0) && (!(i == 0 || j == 0)))
				{
					new_grid[row][col] = -1;
				}
				if (x == 0 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == -1 || j == -1))
				{
					new_grid[row][col] = -1;
				}
				if (x == 3 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == 1 || j == 1))
				{
					new_grid[row][col] = -1;
				}
			}
		}
	}
	
	zero_grid(truth_grid);  // refresh the truth grid to a zero grid
	
	int arr_2[4][2];  // array_2 of coordinates for battleship
	int condition;  // condition will equal to 1 if the ship can fit on the grid, else 0
	coin_flip = std::rand() % 2;  // flip a coin again
	
	if (coin_flip == 0)  // same idea above, but this time the code will check if the ship will be touched by another ship
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  // assume that the ship can fit on the grid
				
				for (int x = j; x < j + 4; x++)  // if there's an obstacle in front of the ship, the ship won't fit on the grid
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  // if the ship can fit on the grid, add the info to truth grid
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	else if (coin_flip == 1)  // same idea above
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 4; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	random_number = rand() % int_count(truth_grid, 1) + 1;
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 4; j++)
		{
			new_grid[row][j] = 2;
			arr_2[j - col][1] = j;
			arr_2[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 4; i++)
		{
			new_grid[i][col] = 2;
			arr_2[i - row][0] = i;
			arr_2[i - row][1] = col;
		}
	}
	
	for (int x = 0; x < 4; x++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				row = arr_2[x][0] + i;
				col = arr_2[x][1] + j;
				if ((row < 8 && row >= 0) && (col < 8 && col >= 0) && (!(i == 0 || j == 0)))
				{
					new_grid[row][col] = -1;
				}
				if (x == 0 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == -1 || j == -1))
				{
					new_grid[row][col] = -1;
				}
				if (x == 3 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == 1 || j == 1))
				{
					new_grid[row][col] = -1;
				}
			}
		}
	}
	
	int arr_3[3][2];  // array_3 of coordinate for submarine
	max_square = 8 - 3 + 1;
	coin_flip = std::rand() % 2;
	
	zero_grid(truth_grid);  // refresh truth grid
	
	if (coin_flip == 0)  // same as above, but with a different size ship
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  
				
				for (int x = j; x < j + 3; x++)  
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	else if (coin_flip == 1)  // same idea above
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 3; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	random_number = rand() % int_count(truth_grid, 1) + 1;
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 3; j++)
		{
			new_grid[row][j] = 3;
			arr_3[j - col][1] = j;
			arr_3[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 3; i++)
		{
			new_grid[i][col] = 3;
			arr_3[i - row][0] = i;
			arr_3[i - row][1] = col;
		}
	}
	
	for (int x = 0; x < 3; x++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				row = arr_3[x][0] + i;
				col = arr_3[x][1] + j;
				if ((row < 8 && row >= 0) && (col < 8 && col >= 0) && (!(i == 0 || j == 0)))
				{
					new_grid[row][col] = -1;
				}
				if (x == 0 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == -1 || j == -1))
				{
					new_grid[row][col] = -1;
				}
				if (x == 2 && (row < 8 && row >= 0) && (col < 8 && col >= 0) && (i == 1 || j == 1))
				{
					new_grid[row][col] = -1;
				}
			}
		}
	}
	
	int arr_4[3][2];  // the last array for the cruiser
	coin_flip = std::rand() % 2;
	
	zero_grid(truth_grid);
	
	if (coin_flip == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  
				
				for (int x = j; x < j + 3; x++)  
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	else if (coin_flip == 1)  // same idea above
	{
		for (int i = 0; i < max_square; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 3; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	if (coin_flip == 0 && int_search(truth_grid, 1) == 0)  // if the horrizontal combination is impossible, then do the vertical combination
	{
		zero_grid(truth_grid);  // refresh the zero grid
		coin_flip = 1;  // change the flip of the coin
		
		for (int i = 0; i < max_square; i++)  // make the ship vertical and fit into the grid
		{
			for (int j = 0; j < 8; j++)
			{
				condition = 1;
				
				for (int x = i; x < i + 3; x++)
				{
					if (new_grid[x][j] != 0)
					{
						condition = 0;
					}
				}
				
				if (condition == 1)
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	if (coin_flip == 1 && int_search(truth_grid, 1) == 0)  // same idea as above, but for the vertical combination
	{
		zero_grid(truth_grid);  // refresh the zero grid
		coin_flip = 0;
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < max_square; j++)
			{
				condition = 1;  
				
				for (int x = j; x < j + 3; x++)  
				{
					if (new_grid[i][x] != 0)
					{
						condition = 0;  
					}
				}
				
				if (condition == 1)  
				{
					truth_grid[i][j] = 1;
				}
			}
		}
	}
	
	random_number = rand() % int_count(truth_grid, 1) + 1;
	
	counter = 0;
	for (int i = 0; i < 8 && counter != random_number; i++)
	{
		for (int j = 0; j < 8 && counter != random_number; j++)
		{
			if (truth_grid[i][j] == 1)
			{
				counter++;
				row = i;
				col = j;
			}
		}
	}
	
	if (coin_flip == 0)
	{
		for (int j = col; j < col + 3; j++)
		{
			new_grid[row][j] = 4;
			arr_4[j - col][1] = j;
			arr_4[j - col][0] = row;
		}
	}
	else if (coin_flip == 1)
	{
		for (int i = row; i < row + 3; i++)
		{
			new_grid[i][col] = 4;
			arr_4[i - row][0] = i;
			arr_4[i - row][1] = col;
		}
	}
	
	return structure(arr, arr_2, arr_3, arr_4);
}