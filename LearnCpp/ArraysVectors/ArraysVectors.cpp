#include <iostream>
#include <array>
#include <algorithm>

void arrayFuncNoSize(int* intArray)
{
	if (!intArray)
		return;
	size_t sizeOfArray = sizeof(intArray);

	std::cout << "Size of Array: " << sizeOfArray << " bytes" << std::endl;
};

void arrayFuncSize(int* intArray, size_t size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << intArray[i] << std::endl;
	}
};

int * createArrayReturn() 
{
	int* listOfThings = new int[5]{1,2,3,4,5};

	arrayFuncSize(listOfThings, 5);

	return listOfThings;
}

void cppArrayFunc(std::array<int,5> stdArray)
{
}

std::array<int, 5> createCppArrayReturn()
{
	std::array<int, 5> stdArray{ 1,2,3,4,5 };

	arrayFuncSize(stdArray.data(), stdArray.size());

	return stdArray;
}


int main()
{
	//////// C-Style Arrays

	int intArray1[5]; // Allocates memory on the stack for 5 integers sequentially

	int intArray2[] = { 1,2,3,4,5, 6, 7 }; // Allocates memory on the stack for 5 integers and assigns them the values listed in the list initialization braces

	//arrayFuncNoSize(intArray2);

	//arrayFuncSize(intArray2, 8);

	int intArray3[3] = { 1,2,3 }; // Same as previous but compiler enforces the number of values within the curly braces

	int *intPtr = intArray1; // Array square bracket initialization is just syntactic sugar for defining a pointer to a block of memory. 



	// Square brackets require size to be known at compile time

	// We will get into pointer stuff in a later lesson

	// How to pass array into function?

	// How to return array from function?
	//int* listOfThings = createArrayReturn();
	//arrayFuncSize(listOfThings, 5);

	//delete[] listOfThings;

	// How to instantiate array in function and return it?

	// How to deal with array sizes?


	////// C++ Style Arrays (std::array)

	/// Creation
	std::array<int, 5> stdArray2;
	std::array<int, 5> stdArray1 = { 1,2,3,4,5 };
	std::array<int, 5> stdArray3 = { 1,2,8,4,5 }; // TODO How to not pass in size?

	std::sort(stdArray3.begin(), stdArray3.end());
	arrayFuncSize(stdArray3.data(), stdArray3.size());

	//std::cout << "Max element: " << stdArray3[std::distance(stdArray3.begin(), maxElement)] << std::endl;


	stdArray1.size();

	/// Passing into functions

	/// Returning from functions
	std::array<int, 5> stdArray = createCppArrayReturn();
	arrayFuncSize(stdArray.data(), stdArray.size());


	/// Creating in functions and returning

	/// Dealing with size

	/// Getting raw C-Style array from std::array

	/// Performance impact?

}


