#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <iterator>

class Span
{
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void			addNumber(int num);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;

		template <typename It>
		void			addNumber(It begin, It end)
		{
			if (std::distance(begin, end) + _numbers.size() > _maxSize)
				throw SpanFullException();
			_numbers.insert(_numbers.end(), begin, end);
		}

		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class NotEnoughElementException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif