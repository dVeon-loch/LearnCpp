#include <iostream>
#include <array>

void arrayFuncNoSize(int* intArray)
{
};


int main()
{
	//////// C-Style Arrays

	int intArray[5]; // Allocates memory on the stack for 5 integers sequentially

	int intArray[] = { 1,2,3,4,5 }; // Allocates memory on the stack for 5 integers and assigns them the values listed in the list initialization braces

	int intArray[3] = { 1,2,3 }; // Same as previous but compiler enforces the number of values within the curly braces

	int *intPtr = intArray; // Array square bracket initialization is just syntactic sugar for defining a pointer to a block of memory. 

	// Square brackets require size to be known at compile time

	// We will get into pointer stuff in a later lesson

	// How to pass array into function?

	// How to return array from function?

	// How to instantiate array in function and return it?

	// How to deal with array sizes?


	////// C++ Style Arrays (std::array)

	/// Creation

	/// Passing into functions

	/// Returning from functions

	/// Creating in functions and returning

	/// Dealing with size

	/// Getting raw C-Style array from std::array

	/// Performance impact?

}


