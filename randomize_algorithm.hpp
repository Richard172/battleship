// this section will be able to randomize the ships location on a 8 x 8 grid.

#include "grid.hpp";

struct node{
    int arr1[3];  //4 int arrays represent coordinates
    int arr2[3];
    int arr3[3];
    int arr4[3];
	int length;
    std::string name;
    node* next;
};

node* structure(int carrier[2][4],int battleship[2][4], int submarine[2][3],int cruiser[2][3]){
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
    first -> arr2[0] = carrier[0][1];
    first -> arr3[0] = carrier[0][2];
    first -> arr4[0] = carrier[0][3];

    //cols 
    first -> arr1[1] = carrier[1][0];
    first -> arr2[1] = carrier[1][1];
    first -> arr3[1] = carrier[1][2];
    first -> arr4[1] = carrier[1][3];

    //boolean value if you miss
    first -> arr1[2] =  0;
    first -> arr2[2] =  0;
    first -> arr3[2] =  0;
    first -> arr4[2] =  0;

    //name of ship is carrier
    first -> name = "carrier";

    //rows battleship
    second -> arr1[0] = battleship[0][0];
    second -> arr2[0] = battleship[0][1];
    second -> arr3[0] = battleship[0][2];
    second -> arr4[0] = battleship[0][3];
    //cols battleship
    second -> arr1[1] = battleship[1][0];
    second -> arr2[1] = battleship[1][1];
    second -> arr3[1] = battleship[1][2];
    second -> arr4[1] = battleship[1][3];

    //boolean value if u miss for battleship
    second -> arr1[2] =  0;
    second -> arr2[2] =  0;
    second -> arr3[2] =  0;
    second -> arr4[2] =  0;

    //name
    second -> name = "battleship";

    //row submarine
    third -> arr1[0] = submarine[0][0];
    third -> arr2[0] = submarine[0][1];
    third -> arr3[0] = submarine[0][2];
    third -> arr4[0] = -1;
    //cols sub
    third -> arr1[1] = submarine[1][0];
    third -> arr2[1] = submarine[1][1];
    third -> arr3[1] = submarine[1][2];
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
    fourth -> arr2[0] = cruiser[0][1];
    fourth -> arr3[0] = cruiser[0][2];
    fourth -> arr4[0] = -1;
    //cruiser cols
    fourth -> arr1[1] = cruiser[1][0];
    fourth -> arr2[1] = cruiser[1][1];
    fourth -> arr3[1] = cruiser[1][2];
    fourth -> arr4[1] = -1;
    //cruiser boolean if miss
    third -> arr1[2] =  0;
    third -> arr2[2] =  0;
    third -> arr3[2] =  0;
    third -> arr4[2] =  1;
    //name
    fourth -> name = "cruiser";

	first -> length = 4;
	second -> length = 4;
	third -> length = 3;
	fourth -> length = 3;
}


node* randomizer(int grid[8][8])
{
	int max_square;  // the maximum number of ships in a row or column
	int coin_flip;  // either 0 or 1, random. If the flip is 0, then the ship is horiontal. If the flip is 1, then the ship is vertical
	
	node* first = new node;  
	first -> length = 4;

	max_square = 8 - 4 + 1;

	std::srand(std::time(NULL));
	coin_flip = (std::rand() * 1000000) % 2; 

	
	if (coin_flip )
	for (int i = 0; i < max_square; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			
		}
	}
}