#pragma once
#include "Vehicle.h"

class Boat : public Vehicle
{
public:
	// How to call parent class constructor/ 'super' constructor in Java
	Boat() : Vehicle(0.0, 0.0, 0.0, 0.0, 1)
	{};

	void Move(double xDir, double yDir, double distanceMeters) override; // Use override keyword to enforce compiler 

	/*void NonPureVirtual() const override
	{
		std::cout << "Boat class impl" << "\n";
	}*/
};

