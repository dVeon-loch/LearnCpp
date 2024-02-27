#pragma once

#include<string>
#include<vector>

struct Seat
{};
class Vehicle
{
private:
	double m_xPos = 0.0;
	double m_yPos = 0.0;
	double m_xVelocity = 0.0;
	double m_yVelocity = 0.0;
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

	virtual void Move(double xDir, double yDir, double distanceMeters) = 0;

	virtual void NonPureVirtual();
};

