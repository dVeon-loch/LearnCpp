#include "Functions.h"
#include <iostream>


void CommonFunctions::PrintHelloWorld()
{
	PrintCppString("Hello World");
}

void CommonFunctions::PrintCppString(std::string string)
{
	std::cout << string << std::endl;
}

void PrintCppString(std::string string)
{
	CommonFunctions::PrintCppString("Non-namespace! " + string);
}
