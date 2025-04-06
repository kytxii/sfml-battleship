#include "Libraries.h"
#include "Radar.h"


// Constructor, just calls the Grid constructor
Radar::Radar() : Grid(10, 10, 50) {

}

// Places a hit
void Radar::addHit(int x, int y) {

	m_charGrid[x][y] = '*';

}

// Checks that the given coordinates aren't already hit or missed, places a miss if true.
void Radar::addMiss(int x, int y) {

	if (m_charGrid[x][y] != '*' && m_charGrid[x][y] != 'o') {

		m_charGrid[x][y] = 'o';

	}

}

// Prepares the grid to be shown onscreen, puts it onscreen
// Changes the colors according to hits & misses, highlights squares that the mouse is over
void Radar::DrawGrid(sf::RenderWindow& window)
{

	// Tracks mouse position in the rendered window, used for hovering effects
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	// Highlighted cell properties
	m_highlightedCell.setSize(sf::Vector2f(m_cellSize, m_cellSize));
	m_highlightedCell.setFillColor(sf::Color(255, 255, 255, 100)); // semi-transparent white
	m_highlightedCell.setOutlineColor(sf::Color::Black);
	m_highlightedCell.setOutlineThickness(2.5);

	for (int i = 0; i < m_numGrid; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{
			// Changes the color depending on hits & misses

			char marker = m_charGrid[i][j];

			switch (marker) {

			case '*': // Char grid shows hit

				m_grids[i][j].setFillColor(sf::Color::Red);
				break;
				
			case 'o': // Char grid shows miss

				m_grids[i][j].setFillColor(sf::Color::White); 
				break;

			default:
				break;
			}

			// Puts the cell onscreen
			sf::RectangleShape& cell = m_grids[i][j];
			window.draw(cell);

			// Highlights the square if the mouse is over it
			if (cell.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				m_highlightedCell.setPosition(cell.getPosition());
				window.draw(m_highlightedCell);
			}
		}
	}
}