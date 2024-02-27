// ObjectOrientedBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Boat.h"

int main()
{
    // Check for why can't create vector of vehicles
    std::vector<Boat> vehicles;
    Boat boat1;
    Boat boat2;
    Boat boat3;
    vehicles.push_back(boat1);
    vehicles.push_back(boat2);
    vehicles.push_back(boat3);

    for (const auto& vehicle : vehicles)
    {
        vehicle.NonPureVirtual();
    }
}
