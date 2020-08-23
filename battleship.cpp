// a battleship game made by Richard, Tej, and Arjun
#include <iostream>
#include <vector>
#include "difficult_AI.hpp"

int main()
{
	int player[8][8];  // a 8 by 8 matrix for the game board for player
	int ai[8][8];  // the grid for AI

	for (int i = 0; i < 8; i++)  // initialize the values for the grid to be 0
	{
		for (int j = 0; j < 8; j++)
		{
			player[i][j] = 0;
			ai[i][j] = 0;
		}
	}
	

	return 0;
}