#include "grid.hpp"


// a function for the normal AI
int* normal_ai(int grid[8][8])
{
	int* coord = new int[2];  // a row-col coordinate that will be returned by the function
	int target_ignore_num;  // the number of ignored target: the sum of the number of -2 and -4
	int target_num;  // the number of possible target: 64 - target_ignore_num
	int random;  // a random number between 1 and target_num
	int counter;  // counts for numbers until reaching the random number
	int row;  // row number
	int col;  // col number
	
	std::srand(std::time(NULL));
	
	if (!(int_search(grid, -3)))  // enter hunt mode when there are no wounded ships
	{
		target_ignore_num = int_count(grid, -2) + int_count(grid, -4);
		target_num = 64 - target_ignore_num;
		
		random = std::rand() % target_num + 1;
		
		counter = 0;  // set counter to 0
		for (int i = 0; i < 8 && counter != random; i++)
		{
			for (int j = 0; j < 8 && counter != random; j++)
			{
				if (grid[i][j] != -2 && grid[i][j] != -4)
				{
					counter++;
					row = i;
					col = j;
				}
			}
		}
		coord[0] = row;
		coord[1] = col;
		return coord;
	}
	else if (int_search(grid, -3))  // enter destroy mode when there are wounded ships
	{
		std::vector <std::vector <int> > coord_list;  // a list of coordinate
		std::vector <std::vector <int> > wound_list = int_list(grid, -3);  // a list of the wounded area
		int wound_num = wound_list.size();  // the number of wounded area
		
		if (wound_num == 1)
		{
			counter = 0;
			if (wound_list[0][1] > 0)
			{
				coord_list.push_back(std::vector <int> ());
				coord_list[counter].push_back(wound_list[0][0]);
				coord_list[counter].push_back(wound_list[0][1] - 1);
				counter++;
			}
			if (wound_list[0][0] > 0)
			{
				coord_list.push_back(std::vector <int> ());
				coord_list[counter].push_back(wound_list[0][0] - 1);
				coord_list[counter].push_back(wound_list[0][1]);
				counter++;
			}
			if (wound_list[0][1] < 7)
			{
				coord_list.push_back(std::vector <int> ());
				coord_list[counter].push_back(wound_list[0][0]);
				coord_list[counter].push_back(wound_list[0][1] + 1);
				counter++;
			}
			if (wound_list[0][0] < 7)
			{
				coord_list.push_back(std::vector <int> ());
				coord_list[counter].push_back(wound_list[0][0] + 1);
				coord_list[counter].push_back(wound_list[0][1]);
				counter++;
			}
			random = std::rand() % counter;
			coord[0] = coord_list[random][0];
			coord[1] = coord_list[random][1];
			return coord;
		}
		else
		{
			counter = 0;
			if (wound_list[0][0] == wound_list[1][0])
			{
				if (wound_list[0][1] > 0)
				{
					coord_list.push_back(std::vector <int> ());
					coord_list[counter].push_back(wound_list[0][0]);
					coord_list[counter].push_back(wound_list[0][1] - 1);
					counter++;
				}
				if (wound_list[wound_num - 1][1] < 7)
				{
					coord_list.push_back(std::vector <int> ());
					coord_list[counter].push_back(wound_list[0][0]);
					coord_list[counter].push_back(wound_list[0][1] + 1);
					counter++;
				}
			}
			if (wound_list[0][1] == wound_list[1][1])
			{
				if (wound_list[0][0] > 0)
				{
					coord_list.push_back(std::vector <int> ());
					coord_list[counter].push_back(wound_list[0][0] - 1);
					coord_list[counter].push_back(wound_list[0][1]);
					counter++;
				}
				if (wound_list[wound_num - 1][0] < 7)
				{
					coord_list.push_back(std::vector <int> ());
					coord_list[counter].push_back(wound_list[0][0] + 1);
					coord_list[counter].push_back(wound_list[0][1]);
					counter++;
				}
			}
			random = std::rand() % counter;
			coord[0] = coord_list[random][0];
			coord[1] = coord_list[random][1];
			return coord;
		}
	}
}