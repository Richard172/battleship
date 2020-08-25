// a battleship game made by Richard, Tej, and Arjun
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

	player[3][3] = -3;

	node* first = new node;
	node* second = new node;

	first -> length = 3;
	first -> next = NULL;

	second -> length = 4;
	second -> next = NULL;

	int** test = destroy_pdf(player, first);
	int* test2 = difficult_ai(player, first);

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			std::cout << test[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	
	std::cout << "\n" << test2[0] << ' ' << test2[1];
	
	

	return 0;
}