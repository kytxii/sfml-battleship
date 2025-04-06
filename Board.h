#pragma once

#include "Libraries.h"
#include "Radar.h"
#include "Ship.h"


// Inherits Radar for the hit & miss modifiers.
// Handles the players' boards, the "bottom" (left) ones where the ships are placed.
class Board : public Radar {

public:

	// Constructor
	Board();

	// Used with display
	void DrawGrid(sf::RenderWindow& window);

	// Grid Modifier
	void addShip(int x, int y, char dir, Ship& shp);

	// Checks for hit
	bool isHit(int x, int y);

};