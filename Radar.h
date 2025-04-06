#pragma once

#include "Libraries.h"
#include "Grid.h"

// Inherits Grid, only has hits and misses within the grid. The "top" (right) grid.
class Radar : public Grid {

public:

	// Constructor
	Radar();

	// Used with display
	void DrawGrid(sf::RenderWindow& window);

	// Modifiers
	void addHit(int x, int y);
	void addMiss(int x, int y);

};