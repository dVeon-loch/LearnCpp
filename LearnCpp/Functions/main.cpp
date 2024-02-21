#include <iostream>
#include <string>
#include<vector>
int func(int input)
{
	input += 5;
	return input;
}

int funcRef(int& input)
{
	input += 5;
	return input;
}

int funcPoint(int* input)
{
	*input += 5;
	return *input;
}

int funcString(const std::string &string)
{
	return -1;
}
struct Result 
{
	int error2;
};

Result funcArray(const std::vector<int>& intArray) {}

/// <summary>
/// 
/// </summary>
/// <param name="input"></param>
/// <param name="out1">error code</param>
/// <param name="out2"></param>
static void funcBad(int input, int& out1, int& out2){}

Result funcGood(int input)
{
	Result result;
	return result;
}

int main() 
{
	int test = 0;

	std::cout << "test = " << test << "\n";
	int result = funcRef(test);
	std::cout << "test = " << test << "\n";
	std::cout << "result = " << result << "\n";

	funcString("hello world");

	std::vector<int> intVec = { 1, 2, 3, 4, 5 };
	int errorCode;
	funcArray(intVec);

	if (errorCode == -1); //dosomething

	int out1, out2;
	funcBad(1, out1, out2);

	//Result result = funcGood(1);

}