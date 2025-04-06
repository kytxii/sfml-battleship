#pragma once

#include "Libraries.h"

// Pure abstract base class, houses various virtual functions
class Ship
{
public:

	// Constructor
	Ship();

	// Getters
	virtual string getShipName() = 0;
	virtual char getShipMarker() = 0;
	virtual int getShipSize() = 0;
	virtual int getShipHealth() = 0;

	// Setter
	virtual void setShipHealth(int i) = 0;

	// Reduces health
	virtual void takeHit() = 0;

};


// The Ship subclasses are largely the same, but initialize differently in their constructors.

class Carrier : public Ship
{
public:
	Carrier();

	virtual string getShipName() override;
	virtual char getShipMarker() override;
	virtual int getShipSize() override;
	virtual int getShipHealth() override;

	virtual void setShipHealth(int i) override;
	virtual void takeHit() override;

private:

	string m_carrierName;
	char m_carrierMarker;
	int m_carrierSize;
	int m_carrierHealth;

};

class Battleship : public Ship
{
public:
	Battleship();

	virtual string getShipName() override;
	virtual char getShipMarker() override;
	virtual int getShipSize() override;
	virtual int getShipHealth() override;

	virtual void setShipHealth(int i) override;
	virtual void takeHit() override;


private:

	string m_battleshipName;
	char m_battleshipMarker;
	int m_battleshipSize;
	int m_battleshipHealth;
};

class Cruiser : public Ship
{
public:
	Cruiser();

	virtual string getShipName() override;
	virtual char getShipMarker() override;
	virtual int getShipSize() override;
	virtual int getShipHealth() override;

	virtual void setShipHealth(int i) override;
	virtual void takeHit() override;

private:

	string m_cruiserName;
	char m_cruiserMarker;
	int m_cruiserSize;
	int m_cruiserHealth;

};

class Submarine : public Ship
{
public:
	Submarine();

	virtual string getShipName() override;
	virtual char getShipMarker() override;
	virtual int getShipSize() override;
	virtual int getShipHealth() override;

	virtual void setShipHealth(int i) override;
	virtual void takeHit() override;

private:

	string m_submarineName;
	char m_submarineMarker;
	int m_submarineSize;
	int m_submarineHealth;

};

class Destroyer : public Ship
{
public:
	Destroyer();

	virtual string getShipName() override;
	virtual char getShipMarker() override;
	virtual int getShipSize() override;
	virtual int getShipHealth() override;

	virtual void setShipHealth(int i) override;
	virtual void takeHit() override;

private:

	string m_destroyerName;
	char m_destroyerMarker;
	int m_destroyerSize;
	int m_destroyerHealth;

};