#include "Ship.h"

// Base class, default constructor
Ship::Ship()
{
}

// Carrier function definitions
Carrier::Carrier() : m_carrierSize(5)
{

    m_carrierName = "Carrier";
    m_carrierMarker = 'c';
    m_carrierSize = 5;
    m_carrierHealth = 5;

}

string Carrier::getShipName()
{
    return m_carrierName;
}
char Carrier::getShipMarker()
{
    return m_carrierMarker;
}
int Carrier::getShipSize()
{
    return m_carrierSize;
}
int Carrier::getShipHealth()
{
    return m_carrierHealth;
}

void Carrier::setShipHealth(int i) {
    m_carrierHealth = i;
}
void Carrier::takeHit() {
    m_carrierHealth--;
}


// Battleship function definitions
Battleship::Battleship() : m_battleshipSize(4)
{

    m_battleshipName = "Battleship";
    m_battleshipMarker = 'b';
    m_battleshipSize = 4;
    m_battleshipHealth = 4;

}

string Battleship::getShipName()
{
    return m_battleshipName;
}
char Battleship::getShipMarker()
{
    return m_battleshipMarker;
}
int Battleship::getShipSize()
{
    return m_battleshipSize;
}
int Battleship::getShipHealth()
{
    return m_battleshipHealth;
}

void Battleship::setShipHealth(int i) {
    m_battleshipHealth = i;
}
void Battleship::takeHit() {
    m_battleshipHealth--;
}

// Cruiser function definitions
Cruiser::Cruiser() : m_cruiserSize(3)
{

    m_cruiserName = "Cruiser";
    m_cruiserMarker = 'r';
    m_cruiserSize = 3;
    m_cruiserHealth = 3;

}

string Cruiser::getShipName()
{
    return m_cruiserName;
}
char Cruiser::getShipMarker()
{
    return m_cruiserMarker;
}
int Cruiser::getShipSize()
{
    return m_cruiserSize;
}
int Cruiser::getShipHealth()
{
    return m_cruiserHealth;
}

void Cruiser::setShipHealth(int i) {
    m_cruiserHealth = i;
}
void Cruiser::takeHit() {
    m_cruiserHealth--;
}

// Submarine function definitions
Submarine::Submarine() : m_submarineSize(3)
{

    m_submarineName = "Submarine";
    m_submarineMarker = 's';
    m_submarineSize = 3;
    m_submarineHealth = 3;

}

string Submarine::getShipName()
{
    return m_submarineName;
}
char Submarine::getShipMarker()
{
    return m_submarineMarker;
}
int Submarine::getShipSize()
{
    return m_submarineSize;
}
int Submarine::getShipHealth()
{
    return m_submarineHealth;
}

void Submarine::setShipHealth(int i) {
    m_submarineHealth = i;
}
void Submarine::takeHit() {
    m_submarineHealth--;
}

// Destroyer function definitions
Destroyer::Destroyer() : m_destroyerSize(2)
{

    m_destroyerName = "Destroyer";
    m_destroyerMarker = 'd';
    m_destroyerSize = 2;
    m_destroyerHealth = 2;

}

string Destroyer::getShipName()
{
    return m_destroyerName;
}
char Destroyer::getShipMarker()
{
    return m_destroyerMarker;
}
int Destroyer::getShipSize()
{
    return m_destroyerSize;
}
int Destroyer::getShipHealth()
{
    return m_destroyerHealth;
}

void Destroyer::setShipHealth(int i) {
    m_destroyerHealth = i;
}
void Destroyer::takeHit() {
    m_destroyerHealth--;
}