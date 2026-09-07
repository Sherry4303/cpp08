#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : _maxSize(0), _numbers() {}

Span::Span(unsigned int n) : _maxSize(n), _numbers() 
{
	_numbers.reserve(n);
}

Span::Span(const Span& other)
{
	_maxSize = other._maxSize;
	_numbers = other._numbers;
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(num);
}

unsigned int	Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementException();
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	unsigned int min_span = UINT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); ++i)
	{
		unsigned int span;
		span = static_cast<unsigned int>(sortedNumbers[i]) - static_cast<unsigned int>(sortedNumbers[i - 1]);
		if (span < min_span)
			min_span = span;
	}
	return (min_span);
}

unsigned int	Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughElementException();
	std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());

	return (static_cast<unsigned int>(*max_it) - static_cast<unsigned int>(*min_it));
}

const char* Span::SpanFullException::what() const throw()
{
	return "Error: out of the max size range.";
}

const char* Span::NotEnoughElementException::what() const throw()
{
	return "Error: not enough elements to caculate span.";
}