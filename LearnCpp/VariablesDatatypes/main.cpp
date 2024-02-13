#include <iostream>
#include <limits>

void DoNothing(double num) {}

int main()
{
	unsigned char largest = std::numeric_limits<char>().max();

	std::cout << "The largest char is: " << static_cast<int>(largest) << std::endl;

	largest++;

	std::cout << "The largest char plus one is: " << static_cast<int>(largest) << std::endl;

	char c{ std::numeric_limits<int>().max() }


}