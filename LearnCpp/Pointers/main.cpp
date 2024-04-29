#include <iostream>

#include <vector>

void PointerIn(int* intPointerIn) // Passing a memory address into function
{
	std::cout << "input: " << *intPointerIn << '\n';
	*intPointerIn += 5;

	int** intPointerToPointer = &intPointerIn;

	std::cout << "input: " << *intPointerIn << '\n';

}

struct ObjectThing
{
	int integer = 5;
};

void RandomFunction(ObjectThing *thing)
{
	(*thing).integer += 8;
}

// 0x12345 [0x1234]

// 0x1234 [10]

int* VariableIn(int intVarIn)
{
	std::cout << "input: " << intVarIn << '\n';
	intVarIn += 5;

	std::cout << "input: " << intVarIn << '\n';

	// {} = 0x1234 .... 0x1245
	int* i = new int(5);
	
	return i;
}

void ReferenceIn(int& intRefIn)
{

}

int main()
{
	int originalVal = 5;

	std::cout << "OriginalVal: " << originalVal << '\n';

	int* i = VariableIn(originalVal);

	std::cout << "OriginalVal After Var Func: " << originalVal << '\n';

	PointerIn(&originalVal);


	std::cout << "OriginalVal After Pointer Func: " << originalVal << '\n';

	std::cin;
	//std::cout << "OriginalVal: " << originalVal << '\n';
	//std::cout << "OriginalVal: " << originalVal << '\n';


	ObjectThing test;

	//int* i = RandomFunction(test);
}