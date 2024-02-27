#include <iostream>
#include <array>
#include <algorithm>
#include <vector>

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

void cppVectorFunc(const std::vector<int> &stdVector)
{

}

std::array<int, 5> createCppArrayReturn()
{
	std::array<int, 5> stdArray{ 1,2,3,4,5 };

	arrayFuncSize(stdArray.data(), stdArray.size());

	return stdArray;
}

void GetDeviceCapabilities(std::vector<int> &outVec)
{
	std::vector<int> stdVector{ 1,2,3,4,5 };

	outVec = { 1,2,3,4,5 };

	//arrayFuncSize(stdArray.data(), stdArray.size());

	// Return Value Optimisation
	//return stdVector;
}

struct Object
{
	int m_field;

	Object(int field) : m_field(field)
	{};

	Object(const Object& other) : m_field(1)
	{
		std::cout << "Copied!" << "\n";
	};
};

int main()
{
	/// std::vector

	// Initialization
	std::vector<int> vecOfInts;

	std::vector<Object> vecOfObjects;
	
	// Adding elements
	//vecOfInts.push_back(1);

	vecOfObjects.push_back(Object(1));

	vecOfObjects.emplace_back(Object{ 1 }); // When adding objects (classes, structs etc.) to vector, use emplace_back

	//cppVectorFunc(std::move(vecOfInts));

	/*vecOfObjects[0] = { 1 };
	vecOfObjects[1] = Object{ 1 };*/
	// vecOfObjects[5] = Object( 1 ); // Will throw index out of range error, no element exists yet

	//std::vector<Object> vecOfObjects2(100, Object(1)); // Discouraged, use when adapting old code or have no other option
	//vecOfObjects2[5] = Object(1);

	// Removing elements
	//vecOfObjects.erase(vecOfObjects.begin() + 2);
	// Getting front
	//vecOfObjects.begin();
	// Getting back
	//vecOfObjects.back();
	// Getting index/element
	//vecOfObjects[5];
	//vecOfObjects.at(5);
	
	// Query size
	vecOfObjects.size();

	// Memory capacity
	vecOfObjects.capacity();


	std::vector<int> deviCaps;
	GetDeviceCapabilities(deviCaps); // Old style way of making returning vectors more efficient. Passes in mutable reference to vector in outer scope. Don't do this if possible, just return the vector directly and rely on RVO to move the value out of function scope to calling scope

	// Getting Raw C array
	Object *objectsRawArray = vecOfObjects.data();
	// algorithms
	//std::sort(vecOfObjects.begin(), vecOfObjects.end());
	// for each loop
	for (const auto &vecElement : vecOfObjects)
	{

	}
	// Corresponding regular for loop version
	for (int i = 0; i < vecOfObjects.size(); i++)
	{
		auto vecElement = vecOfObjects[i];
	}

	// Improving performance?
	// 1
	// ADD" reallocate
	
	vecOfObjects.reserve(20); // Allocs memory, but doesn't populate with any values and doesn't update size
	//vecOfObjects[19];
	vecOfObjects.shrink_to_fit();

	//1 INSTANTIATE
	//2 RESERVE
	//3 ADD.....
	//4 SHRINK 
	vecOfObjects.resize(20, Object(1)); // Discouraged, not to be confused with reserve. Actually instantiates objects/elements and updates the size
}

/*
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
*/


