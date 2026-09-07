#include "Span.hpp"
#include <ctime>
#include <cstdlib>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	try
	{
		const unsigned int N = 10000;
		std::vector<int> randomNumbers;
		randomNumbers.reserve(N);
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		for (unsigned int i = 0; i < N; ++i)
		{
			randomNumbers.push_back(std::rand() % 1000000 - 2000000);
		}

		Span largeSpan(N);
		largeSpan.addNumber(randomNumbers.begin(), randomNumbers.end());
		std::cout << "Shortest Span: " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << largeSpan.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}