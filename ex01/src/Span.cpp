/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:42:06 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/03 16:55:49 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"

Span::Span() : _maxNumbers(0){}

Span::Span(unsigned int N) : _maxNumbers(N){}

Span::Span(const Span& original) : _maxNumbers(original._maxNumbers), _numbers(original._numbers){}

Span& Span::operator=(const Span& original)
{
	if (this != &original)
	{
		_maxNumbers = original._maxNumbers;
		_numbers = original._numbers;
	}
	return (*this);
}

Span::~Span(){}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxNumbers)
		throw MaxNumbersException();
	_numbers.push_back(number);
}

const char* Span::MaxNumbersException::what() const throw()
{
	return ("Exceeds max amount of numbers");
}

const char* Span::NoSpanException::what() const throw()
{
	return ("Not enough numbers for a span");
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	int min = _numbers[0];
	int max = _numbers[0];
	for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++)
	{
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	return (max - min);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	unsigned int shortest = UINT_MAX;
	unsigned int span;
	for (unsigned int i = 0; i < sortedNumbers.size() - 1; i++)
	{
		span = sortedNumbers[i + 1] - sortedNumbers[i];
		shortest = std::min(span, shortest);
	}
	return (shortest);
}
