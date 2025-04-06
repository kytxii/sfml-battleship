
#include "Libraries.h"
#include "AI.h"

// Constructor, calls the Player constructor and sets the rand seed
AI::AI() : Player() {

	// Establish the rand seed
	srand(time(NULL));

}

// Calls placeShip() for every Ship
void AI::setup() {

	for (int i = 0; i < 5; i++) {

		placeShip(i);

	}

}

// Randomly places a given ship onto the Board
void AI::placeShip(int n) {

	//AUTOMATIC RANDOM PLACEMENT

	Ship* shp = ships[n];

	int real_size = shp->getShipSize() - 1; //Includes the origin point
	char direction;

	int x;
	int y;

	bool final = false;
	while (!final) {

		bool valid = false;

		while (!valid) {

			x = rand() % 10;
			y = rand() % 10;

			valid = bottom.at(x, y) == '~';

		}

		bottom.setPoint(x, y, shp->getShipMarker());

		valid = false;
		int ans;

		while (!valid) {

			ans = rand() % 5 + 1;

			switch (ans) {

			case 1:

				valid = (y + real_size) < 10;
				if (valid) {

					for (int i = y + 1; i <= y + real_size; i++) {

						valid = (bottom.at(x, i) == '~');

						if (!valid) {

							break;

						}

					}

				}

				if (valid) {

					direction = 'n';
					final = true;

				}

				break;

			case 2:

				valid = (y - real_size) >= 0;
				if (valid) {

					for (int i = y - 1; i >= y - real_size; i--) {

						valid = (bottom.at(x, i) == '~');

						if (!valid) {

							break;

						}

					}

				}

				if (valid) {

					direction = 's';
					final = true;

				}

				break;

			case 3:

				valid = (x - real_size) >= 0;
				if (valid) {

					for (int i = x - 1; i >= x - real_size; i--) {

						valid = (bottom.at(i, y) == '~');

						if (!valid) {

							break;

						}

					}

				}

				if (valid) {

					direction = 'w';
					final = true;

				}

				break;

			case 4:

				valid = (x + real_size) < 10;
				if (valid) {

					for (int i = x + 1; i <= x + real_size; i++) {

						valid = (bottom.at(i, y) == '~');

						if (!valid) {

							break;

						}

					}

				}

				if (valid) {

					direction = 'e';
					final = true;

				}

				break;

			case 5:

				bottom.setPoint(x, y, '~');
				valid = true;

				break;

			default:
				break;

			}

		}

	}

	bottom.addShip(x, y, direction, *shp);

}

// Makes semi-random shots
// If it finds a previous hit, it has a 35% chance of shooting near it
// If it skips all hits, it shoots randomly
void AI::shoot(int& x, int& y) {

	int row = 0;
	int column = 0;
	bool hit_found = false;

	for (int i = 0; i < 10; i++) {

		for (int n = 0; n < 10; n++) {

			if (top.at(i, n) == '*' && rand() % 100 + 1 <= 35) {

				hit_found = true;
				row = i;
				column = n;

				break;

			}

		}

		if (hit_found) {

			break;

		}

	}

	if (!hit_found) {

		row = rand() % 10;
		column = rand() % 10;

	}

	bool valid = false;
	int dir = rand() % 4 + 1;
	int bad_dir_counter = 0;

	while (!valid) {

		if (bad_dir_counter >= 100) {

			row = rand() % 10;
			column = rand() % 10;

			bad_dir_counter = 0;

		}

		dir = rand() % 4 + 1;

		switch (dir) {

		case 1:

			valid = (row - 1) >= 0;
			if (valid) {

				valid = (top.at(row - 1, column) != '*' && top.at(row - 1, column) != 'o');

				if (!valid) {

					bad_dir_counter++;

				}

			}

			break;

		case 2:

			valid = (row + 1) < 10;
			if (valid) {

				valid = (top.at(row + 1, column) != '*' && top.at(row + 1, column) != 'o');

				if (!valid) {

					bad_dir_counter++;

				}

			}

			break;

		case 3:

			valid = (column - 1) >= 0;
			if (valid) {

				valid = (top.at(row, column - 1) != '*' && top.at(row, column - 1) != 'o');

				if (!valid) {

					bad_dir_counter++;

				}

			}

			break;

		case 4:

			valid = (column + 1) < 10;
			if (valid) {

				valid = (top.at(row, column + 1) != '*' && top.at(row, column + 1) != 'o');

				if (!valid) {

					bad_dir_counter++;

				}

			}

			break;

		default:
			break;

		}

	}

	switch (dir) {

	case 1:

		x = row - 1;
		y = column;

		break;

	case 2:

		x = row + 1;
		y = column;

		break;

	case 3:

		x = row;
		y = column - 1;

		break;

	case 4:

		x = row;
		y = column + 1;

		break;

	default:
		break;

	}

}