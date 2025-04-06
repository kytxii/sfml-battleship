#pragma once

#include "Libraries.h"
#include "Graphics.h"
#include "Player.h"
#include "AI.h"


// Wrapper class for the Battleship game
class Game {

public:

	// Main wrapper function
	void run();

	// Handles the process of one full game
	void playGame();

	// Gameplay functions
	void playerTurn();
	void cpuTurn();

private:

	// Players
	Player p1;
	AI cpu;

	// Graphics implementation
	Graphics grpc;

};