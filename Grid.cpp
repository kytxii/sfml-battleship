#include "Grid.h"
#include "Ship.h"

// Constructor w/ parameters, defines the dimensions and initializes both grids
Grid::Grid(int numGrid, int gridSize, int cellSize)
{
	// Init dimensions
	this->m_numGrid = numGrid;
	this->m_gridSize = gridSize;
	this->m_cellSize = cellSize;

	// Build display grid of RectangleShapes
	for (int i = 0; i < numGrid; i++)
	{
		vector<sf::RectangleShape> row;
		for (int x = 0; x < gridSize; x++)
		{
			for (int y = 0; y < gridSize; y++)
			{
				sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
				cell.setPosition(sf::Vector2f(y * cellSize, x * cellSize));
				cell.setFillColor(sf::Color(50, 100, 200, 255));
				cell.setOutlineColor(sf::Color::Black);
				cell.setOutlineThickness(3);
				row.push_back(cell);
			}
		}
		m_grids.push_back(row);
	}

	//initializing the char grid used in the background code.
	m_charGrid = new char* [10];

	for (int i = 0; i < 10; i++) {

		m_charGrid[i] = new char[10];

		for (int j = 0; j < 10; j++) {

			m_charGrid[i][j] = '~';

		}

	}

}

// Virtual destructor used for charGrid, deletes every array then the array of arrays.
Grid::~Grid() {

	for (int i = 0; i < 10; i++) {

		delete[] m_charGrid[i];

	}

	delete[] m_charGrid;

}


// Getter for specific point
char Grid::at(int x, int y) {

	return m_charGrid[x][y];

}

// Setter for specific point
void Grid::setPoint(int x, int y, char c) {

	m_charGrid[x][y] = c;

}

// Blank def to not give errors with the polymorphism
void Grid::DrawGrid(sf::RenderWindow& window) { };

// Positions the grid in the window
void Grid::SetGridPosition(int xPos, int yPos)
{
	for (int i = 0; i < m_numGrid; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			m_grids[i][j].setPosition(xPos + j * m_cellSize, yPos + i * m_cellSize);
		}
	}
}


// Returns by pointer the grid coordinates of the clicked square
void Grid::CheckCell(sf::RenderWindow& window, int& x, int& y)
{
	// If the mouse was clicked
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		// Check each square for the position where it was clicked
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		for (int i = 0; i < m_numGrid; i++)
		{
			for (int j = 0; j < m_gridSize; j++)
			{
				sf::RectangleShape& cell = m_grids[i][j];
				if (cell.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
				{
					
					// If found, return the square's grid coordinates by pointer

					x = i;
					y = j;

					Sleep(100); // Stalls the program a bit so that it doesn't use the same mouse click as 100 different inputs
					return;

				}
			}
		}
	}
}


// Resets both the char grid and the colors on the display grid
void Grid::reset() {

	for (int i = 0; i < 10; i++) {

		for (int j = 0; j < 10; j++) {

			m_charGrid[i][j] = '~';
			m_grids[i][j].setFillColor(sf::Color(50, 100, 200, 255));

		}

	}

}
