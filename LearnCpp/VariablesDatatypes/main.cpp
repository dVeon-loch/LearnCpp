#include <iostream>
#include <limits>
#include <vector>

// CALCULATOR
// user input "Enter Number 1:"
// user input "Enter number 2:"
// "Enter operation:"
// +
// - 
// *
// /
// %
// Result: 
// Enter multiple numbers:
// Sum of numbers:
// lowest number:
// Highest number:
// Average:

int main()
{
	int num1; 
	std::cout << "Enter number 1: " << "\n";
	std::cin >> num1;

	int num2;
	std::cout << "Enter number 2: " << "\n";
	std::cin >> num2;

	char operation;
	std::cout << "Enter an operation: " << "\n";
	std::cin >> operation;

	std::cout << "OPERATION " << operation;

	if (true)
	{
		// do something
	}
	else if (true)
	{
		// do something
	}
	else
	{
		// do something
	}

	if(true)
	{
		//dosomething <--- This will be inside if statement
		//dosomething <--- This will not be inside
	}

#pragma region enums
	enum test
	{
		val1 = 0,
		val2 = 1
	};

	enum Direction
	{
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
#pragma endregion

	test val = val1;
	switch (val) 
	{
	case val1:
		// dropthrough
		[[dropthrough]] // Stops compiler warning and shows other programmers that you want to drop through
	case val2:
		break;
	default:
		break;
	}

	int i = true == true ? 0 : 1;

	// LOOPING
	while (true)
	{
		continue; // Go to next loop
		break; // Break out of loop
	}

	do 
	{
	// do something
	} while (true);

	size_t i = 0;
	for (i = 0; i < 10; i++)
	{
		continue;
	}

	std::vector<int> intVec = { 1,2,3,4 };

	for (int element : intVec)
	{
		element = 3;
	}

	for (auto element : intVec)
	{
		element = 3;
	}

	intVec = { 3,3,3,3 };
}

	////unsigned char largest = std::numeric_limits<char>().max();

	////std::cout << "The largest char is: " << static_cast<int>(largest) << std::endl;

	////largest++;

	////std::cout << "The largest char plus one is: " << static_cast<int>(largest) << std::endl;

	////char c = std::numeric_limits<int>().max();

	////// + - / % * 
	////// BITWISE OPERATIONS
	////// >> << & |
	//////		1000 0001 1000 
	//////&		0000 0001 1111 
	//////		0000 0001 1000

	//////		1000 0001 1000
	////// |    0000 0100 0000
	//////      1000 0101 1000

	//////		0100 = 8
	////// <<12 0100 0000 0000 0000 = 32768

	//////		0111 0000 1011 1111
	////// >>12 0111 
	//////		0100 |0000| 0000 0000
	////// >> 8
	//////		0100 0010
	////// &	0000 1111
	//////		0000 0010

	////// CONTROL STRUCTURES
	////// if, else if, else, switch, ternary, 
	////// LOOPS: for, while, do while
	////bool isDone = false;
	////bool correct = false;
	/////*if (true)
	////	{ }
	////else if ()
	////else {}*/

	////TEST testVal;
	////switch (testVal)
	////{
	////case TEST1:
	////	// Dropthrough intentional
	////{
	////	bool testBool = false;
	////}
	////case TEST2:
	////{

	////	break;
	////}
	////case TEST3:
	////	//testBool = true;
	////	break;
	////default:
	////	break;
	////}


	////bool testTwo = 1 - 1 == 0 ? true : false;

	////bool testTwo;
	////if (1 - 1 == 0) { testTwo = true; }
	////else { testTwo = false; }

	//int b = 0;
	//int c = 0;
	//int d = 0;
	//std::cout << b << c << d << "\n";
	//c = b++;
	//std::cout << b << c << d << "\n";
	//d = ++b;

	//std::cout << b << c << d << "\n";

	//// LOOPS
	//for (int i = 0; i < 100; i+= 10)
	//{
	//	std::cout << "HELLO " << i << "\n";
	//}

	//while (true)
	//{
	//	break;
	//}

	//int i = 0;
	//int b = 30;
	//do
	//{
	//	//  i = 10 , b = 20
	//} while (i + b != 30);