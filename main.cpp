//Precompiled headers
#include "stdafx.h"

//Classes
#include "Game.h"

int main()
{
	//Random seed initialization
	std::srand(static_cast<unsigned>(time(NULL)));	

	//Creating Game object
	Game game;

	//Game loop function
	game.run();

	//End of application
	return 0;
}