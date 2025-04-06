#pragma once

#include "Libraries.h"
#include "Radar.h"
#include "Board.h"
#include "Ship.h"

// Inheritance for player 1/2 and computer
class Player {

public:

	// Constructor & Destructor
	Player();
	~Player();

	// Input functions for setup
	void setup();
	void placeShip(int i);

	// Modifiers for the Board and Radar
	void addShot(int x, int y, bool hit); // You made the shot, modifies Radar
	void takeShot(int x, int y, bool hit); // Opponent made the shot, modifies Board

	// Boardstate evaluation
	char checkSunk();
	bool checkLoss();

	// Resets grids and stats for a new game
	void reset();

	// Getters & Setters
	Radar& getRadar();
	Board& getBoard();

	int getShots();
	int getHits();
	int getMisses();

	void setShots(int i);
	void setHits(int i);
	void setMisses(int i);

protected:

	//Grids
	Radar top;
	Board bottom;

	//Pointers because abstract base class
	Ship* ships[5];

	//Stats
	int shots;
	int hits;
	int misses;

};
