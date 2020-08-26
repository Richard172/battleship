// a battleship game made by Richard, Tej, and Arjun
#include "normal_AI.hpp"

int main()
{
	int player[8][8];  // a 8 by 8 matrix for the game board for player
	int ai[8][8];  // the grid for AI

	zero_grid(player);
	
	int* test = normal_ai(player);
	std::cout << test[0] << ' ' << test[1] << std::endl;
	print_grid(player);
	
	return 0;
}