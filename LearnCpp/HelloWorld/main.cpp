#include <iostream>
#include "Functions.h"
int main()
{
	
	CommonFunctions::Hello();
}

void CommonFunctions::Hello()
{
	std::cout << "Hello World!" << std::endl;
}


// Task List:
// 1. Refactor this code out into a function that gets called from main
// 1.1 Where must this function go in the file?
// 1.2 What should we call the function?
// 2. Refactor the function created previously so that it can print any string
// 2.1 How do we pass the string into the function?
// 2.2 c string or string object?
// 2.3 What else can you do to improve the code based on previous issues?
