#pragma once

#include "Libraries.h"
#include "Ship.h"

// Base class for the players' Boards and Radars, manages an unseen grid of chars and a display grid of RectangleShapes.
class Grid
{
public:

	// Constructor and virtual destructor
	Grid(int numGrid, int gridSize, int cellSize);
	virtual ~Grid();

	// Virtual display function, taken over by Radar and Board
	virtual void DrawGrid(sf::RenderWindow& window);

	// Positions the grid
	void SetGridPosition(int xPos, int yPos);

	// Returns by pointer the grid coordinates of the clicked square.
	void CheckCell(sf::RenderWindow& window, int& x, int& y);

	// Resets both the char grid and the colors on the display grid
	void reset();


	// Char grid stuff

	// Getter for specific point
	char at(int x, int y);

	// Setter for specific point
	void setPoint(int x, int y, char c);

protected:

	// Dimensions
	int m_numGrid;
	int m_gridSize;
	int m_cellSize;

	sf::Font m_font;

	sf::Texture m_backgroundTexture;

	sf::RectangleShape m_highlightedCell;

	vector<vector<sf::RectangleShape>> m_grids;

	// Grid of chars, used to internally manage the game
	char** m_charGrid;

};