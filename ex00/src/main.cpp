/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.cpp										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: aweissha <aweissha@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/01 17:23:22 by aweissha		  #+#	#+#			 */
/*   Updated: 2024/11/01 17:24:50 by aweissha		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../include/easyfind.hpp"
#include <vector>
#include <list>


int main()
{
	// Test with vector
	std::vector<int> vec = {1,2,3,4,5};
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found " << *it << " in vector." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test with list
	std::list<int> lst = {10,20,30,40,50};
	try
	{
		std::list<int>::iterator it = easyfind(lst, 40);
		std::cout << "Found " << *it << " in list." << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test for value not found
	try
	{
		easyfind(vec, 99);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
