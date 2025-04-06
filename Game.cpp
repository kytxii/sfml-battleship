
#include "Libraries.h"
#include "Game.h"


// Shows the main menu screen, does one of 3 options depending on what button is pressed.
void Game::run() {

	bool running = true;
	while (running) {

		switch (grpc.RunMenuLoop()) {

		case 1:
			playGame();
			break;
		case 2:
			grpc.RulesScreen();
			break;
		case 3:
			// Quit
			running = false;
			break;
		default:
			break;
		}

	}

}


// Handles the proceedings of a single game of Battleship
void Game::playGame() {

	bool playerWin = false;

	srand(time(NULL));

	//player (randomly) places their ships
	p1.setup();

	//cpu randomly places its ships
	cpu.setup();

	//while game isn't over
	bool game_over = false;
	while (!game_over) {


		//p1 takes turn
		playerTurn();

		// If the window is closed, reset and go back to the main menu
		if (p1.getHits() == -1) {

			p1.reset();
			cpu.reset();

			return;

		}

		//check if cpu is dead, if so set winners and set game over bool to true and break 
		if (cpu.checkLoss()) {

			playerWin = true;
			game_over = true;
			break;

		}

		//cpu takes turn, increment the hits counter or misses counter, and also the total shots counter
		cpuTurn();

		//check if p1 is dead, if so set winners and set game over bool to true and break
		if (p1.checkLoss()) {

			playerWin = false;
			game_over = true;
			break;

		}

	}

	// Shows either a You Win or You Lose screen
	if (playerWin) {

		grpc.WinScreen(p1, 1);

	}
	else {

		grpc.WinScreen(p1, 0);

	}

	// Resets for another game
	p1.reset();
	cpu.reset();

	// Exits to main menu

}


// Handles the process of the player's turn
void Game::playerTurn() {

	int row;
	int column;

	// The player clicks a square, we get the coordinates of that square.
	grpc.ShootScreen(p1, row, column);

	// If the window was closed, tells playGame() to go back to the menu
	if (row == -1) {

		// Flag value
		p1.setHits(-1);
		return;

	}

	// Sees if those coordinates are a hit
	bool hit = false;
	hit = cpu.getBoard().isHit(row, column);


	//update the radar board and cpu board, increment the shot counters
	p1.addShot(row, column, hit);
	cpu.takeShot(row, column, hit);

}

// Handles the process of the cpu's turn
void Game::cpuTurn() {

	int row;
	int column;

	// The cpu uses its algorithm to choose coordinates
	cpu.shoot(row, column);

	// Sees if those coordinates are a hit
	bool hit = false;
	hit = p1.getBoard().isHit(row, column);

	//update the radar board and player board, increment the shot counters
	cpu.addShot(row, column, hit);
	p1.takeShot(row, column, hit);

}