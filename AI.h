#pragma once

#include "Libraries.h"
#include "Player.h"

// Inherits Player, replaces some functions to be automatic instead of input
class AI : public Player {

public:

	// Constructor
	AI();

	// Automatic setup
	void setup();
	void placeShip(int n);

	// Automatic shots
	void shoot(int& x, int& y);

};