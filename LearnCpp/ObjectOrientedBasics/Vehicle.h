#pragma once

#include<string>
#include<vector>
#include<utility>
#include<iostream>

struct Seat
{};

struct Pos2D
{};

class Vehicle
{
protected:
	double m_xVelocity = 0.0;
	double m_yVelocity = 0.0;
private:
	double m_xPos = 0.0;
	double m_yPos = 0.0;
	std::string name = "default";
	std::vector<Seat> seats;
public:
	Vehicle() = default;

	Vehicle(double xPos, double yPos, double xVelocity, double yVelocity, int numSeats) :
		m_xPos(xPos),
		m_yPos(yPos),
		m_xVelocity(xVelocity),
		m_yVelocity(yVelocity)
	{
		seats.reserve(numSeats);
	}

	virtual void Move(double xDir, double yDir, double distanceMeters) = 0; // Compulsory to implement

	virtual void NonPureVirtual() const { std::cout << "Default impl" << "\n"; }; // Optionally implementable methods 

	// Opt for using accessor/mutator methods to get or modify member variables in child classes
	// Enhances class encapsulation and prevents child classes from having to modify their code when\
	// Changes to member vars occur
	void SetPos(double xPos, double yPos) 
	{
		m_xPos = xPos;
		m_yPos = yPos;
	}

	std::pair<double, double> GetPos() const
	{
		return { m_xPos, m_yPos };
	}
};

