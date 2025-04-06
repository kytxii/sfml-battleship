
#include "Libraries.h"
#include "Player.h"

// Constructor
Player::Player() {

	//Initialize ships to each different subclass
	ships[0] = new Destroyer();
	ships[1] = new Submarine();
	ships[2] = new Cruiser();
	ships[3] = new Battleship();
	ships[4] = new Carrier();

	//Init stats to 0
	shots = 0;
	hits = 0;
	misses = 0;

}

// Deconstructor, deletes each Ship pointer
Player::~Player() {

	for (Ship* shp : ships) {

		delete shp;

	}

}


// Calls placeShip() for every Ship
void Player::setup() {

	for (int i = 0; i < 5; i++) {

		placeShip(i);

	}

}

// Randomly places a given ship onto the Board
void Player::placeShip(int n) {

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

// Modifies the Radar after a new shot, increments stats
// (The player made the shot)
void Player::addShot(int x, int y, bool hit) {

	shots++;

	if (hit) {

		top.addHit(x, y);
		hits++;

	}
	else {

		top.addMiss(x, y);
		misses++;

	}

}

// Modifies the Board after a new shot, reduces health of the ship that was hit
// (The opponent made the shot)
void Player::takeShot(int x, int y, bool hit) {

	if (hit) {

		char marker = bottom.at(x, y);

		for (Ship* shp : ships) {

			if (marker == shp->getShipMarker()) {

				shp->takeHit();

			}

		}

		bottom.addHit(x, y);

	}
	else {

		bottom.addMiss(x, y);

	}

}


// Iterates through every ship to see if any sunk this turn.
// Returns char of sunk ship if found
char Player::checkSunk() {

	char c = '!';

	for (Ship* shp : ships) {

		//If the ship sunk
		if (shp->getShipHealth() == 0) {

			//Set health to flag value that it is sunk
			shp->setShipHealth(-1);
			c = shp->getShipMarker();

		}

	}

	return c;

}

// Checks if the player has any remaining ships
bool Player::checkLoss() {

	for (Ship* shp : ships) {

		if (shp->getShipHealth() > 0) {

			return false;

		}

	}

	return true;

}


// Resets both Grids, the Ships' health, and the stats for a new game
void Player::reset() {

	top.reset();
	bottom.reset();

	for (Ship* shp : ships) {

		shp->setShipHealth(shp->getShipSize());

	}

	shots = 0;
	hits = 0;
	misses = 0;

}

// Accessors
Radar& Player::getRadar() {

	return top;

}

Board& Player::getBoard() {

	return bottom;

}

int Player::getShots() {

	return shots;

}

int Player::getHits() {

	return hits;

}

int Player::getMisses() {

	return misses;

}


void Player::setShots(int i) {

	shots = i;

}

void Player::setHits(int i) {

	hits = i;

}

void Player::setMisses(int i) {

	misses = i;

}