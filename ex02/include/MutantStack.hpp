/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 18:04:59 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/05 13:19:53 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	MutantStack();
	MutantStack(const MutantStack& original);
	MutantStack& operator=(const MutantStack& original);
	~MutantStack();
	iterator begin()
	{
		return this->c.begin();
	}
	iterator end()
	{
		return this->c.end();
	}
};

#include "MutantStack.tpp"
	
#endif