#include <vector>

int main()
{
	std::vector<int> intVecFor = { 1,2,3,4,5 };
	std::vector<int> intVecForEach = { 1,2,3,4,5 };

	for (size_t i = 0; i < intVecFor.size(); i++)
	{
		intVecFor[i] = 3;
	}

	for (auto test1 : intVecForEach)
	{
		test1 = 3;
	}
}