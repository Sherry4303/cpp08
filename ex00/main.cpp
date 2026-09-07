#include "easyfind.hpp"
#include <vector>

int main()
{
	std::vector<int> v;
	v.push_back(75);
	v.push_back(42);
	v.push_back(3);
	v.push_back(68);
	v.push_back(12);
	v.push_back(9);
	v.push_back(128);

	try
	{
		std::cout << "Try to find " << 12 << " in the vector" << std::endl;
		easyfind(v, 12);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "Try to find " << 36 << " in the vector" << std::endl;
		easyfind(v, 36);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: value not found." << std::endl;
	}
	
}