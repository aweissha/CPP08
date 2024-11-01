/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 16:38:07 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/01 17:42:08 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <stdexcept>

class NoOccurenceFoundException : public std::exception
{
	public:
	const char* what() const throw();
};

const char* NoOccurenceFoundException::what() const throw()
{
	return ("No Occurence found.");
}

template <typename T> 
typename T::iterator easyfind(T& container, int number)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == number)
			return (it);
	}
	throw (NoOccurenceFoundException());
}

#endif