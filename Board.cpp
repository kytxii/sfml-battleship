

#include "Libraries.h"
#include "Board.h"

// Constructor, just calls Radar's constructor, which just calls Grid's contructor
Board::Board() : Radar() {

}

// Prepares the grid to be shown onscreen, puts it onscreen
// Changes the colors according to hits, misses, and ships, highlights squares that the mouse is over
void Board::DrawGrid(sf::RenderWindow& window)
{
	// Ship objects
	Carrier carrier;
	Battleship battleship;
	Cruiser cruiser;
	Submarine submarine;
	Destroyer destroyer;

	// Tracks mouse position in the rendered window
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);

	// Check cell
	//CheckCell(window);

	// Highlighted cell properties
	m_highlightedCell.setSize(sf::Vector2f(m_cellSize, m_cellSize));
	m_highlightedCell.setFillColor(sf::Color(255, 255, 255, 100)); // semi-transparent white
	m_highlightedCell.setOutlineColor(sf::Color::Black);
	m_highlightedCell.setOutlineThickness(2.5);


	// Draws ships according to char grid
	for (int i = 0; i < m_numGrid; i++)
	{
		for (int j = 0; j < m_gridSize; j++)
		{

			char marker = m_charGrid[i][j];

			switch (marker) {

			case '*': // Char grid shows hit

				m_grids[i][j].setFillColor(sf::Color::Red);
				break;

			case 'o': // Char grid shows miss

				m_grids[i][j].setFillColor(sf::Color::White);
				break;

			case 'd': // Char grid shows Destroyer

				m_grids[i][j].setFillColor(sf::Color::Magenta);
				break;

			case 's': // Char grid shows Submarine

				m_grids[i][j].setFillColor(sf::Color::Cyan);
				break;

			case 'r': // Char grid shows Cruiser

				m_grids[i][j].setFillColor(sf::Color::Green);
				break;

			case 'b': // Char grid shows Battleship

				m_grids[i][j].setFillColor(sf::Color::Yellow);
				break;

			case 'c': // Char grid shows Carrier

				m_grids[i][j].setFillColor(sf::Color::Black);
				break;

			default:
				break;
			}

			// Puts the cell onscreen
			sf::RectangleShape& cell = m_grids[i][j];
			window.draw(cell);

			// Highlights the cell the mouse is hovering over
			if (cell.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
			{
				m_highlightedCell.setPosition(cell.getPosition());
				window.draw(m_highlightedCell);
			}
		}
	}
}

// Places a ship onto the board, writes the ship's marker onto the board for its length in the specified direction.
void Board::addShip(int x, int y, char dir, Ship& shp) {

	switch (dir) {

	case 'n':

		for (int i = y; i <= y + shp.getShipSize() - 1; i++) {

			m_charGrid[x][i] = shp.getShipMarker();

		}

		break;

	case 's':

		for (int i = y; i >= y - shp.getShipSize() + 1; i--) {

			m_charGrid[x][i] = shp.getShipMarker();

		}

		break;

	case 'w':

		for (int i = x; i >= x - shp.getShipSize() + 1; i--) {

			m_charGrid[i][y] = shp.getShipMarker();

		}

		break;

	case 'e':

		for (int i = x; i <= x + shp.getShipSize() - 1; i++) {

			m_charGrid[i][y] = shp.getShipMarker();

		}


		break;

	default:
		break;
	}

}


// Checks whether a shot is a hit, whether a ship is at the given coordinates.
bool Board::isHit(int x, int y) {

	char chr = m_charGrid[x][y];

	bool hit = chr == 'c' || chr == 'b' || chr == 'r' ||
		chr == 's' || chr == 'd';

	return hit;

}