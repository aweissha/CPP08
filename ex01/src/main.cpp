/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aweissha <aweissha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/03 16:38:47 by aweissha		  #+#	#+#			 */
/*   Updated: 2024/11/03 16:39:44 by aweissha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	// Seed for random number generation
	std::srand(std::time(nullptr));

	// Test 1: Basic functionality with a few numbers
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Test 1: Basic Functionality" << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Adding more than capacity should throw an exception
	try
	{
		Span sp = Span(3);
		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(30);
		std::cout << "Test 2: Adding beyond capacity" << std::endl;
		sp.addNumber(40);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 3: Not enough numbers to find a span
	try
	{
		Span sp = Span(2);
		sp.addNumber(10);
		std::cout << "Test 3: Not enough numbers to find a span" << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 4: Large number of elements (e.g., 10,000)
	try
	{
		Span sp = Span(10000);
		for (int i = 0; i < 10000; ++i)
		{
			sp.addNumber(std::rand() % 1000000);
		}
		std::cout << "Test 4: Large number of elements (10,000 numbers)" << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 5: Using addRange to bulk insert numbers
	try
	{
		Span sp = Span(10);
		std::vector<int> range = {1, 3, 5, 7, 9};
		sp.addRange(range.begin(), range.end());

		std::cout << "Test 5: Using addRange to add numbers" << std::endl;
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
