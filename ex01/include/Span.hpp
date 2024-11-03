/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:38:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/03 16:56:26 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Span
{
	private:
	unsigned int		_maxNumbers;
	std::vector<int>	_numbers;

	public:
	Span();
	Span(unsigned int N);
	Span(const Span& original);
	Span& operator=(const Span& original);
	~Span();

	void addNumber(int number);
	
	template <typename Iterator>
	void addRange(Iterator begin, Iterator end);
	
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;
	class MaxNumbersException : public std::exception
	{
		public:
		const char* what() const throw();
	};
	class NoSpanException : public std::exception
	{
		public:
		const char* what() const throw();
	};
};

template <typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
	if (std::distance(begin, end) + _numbers.size() > _maxNumbers)
		throw MaxNumbersException();
	_numbers.insert(_numbers.end(), begin, end);
}

#endif