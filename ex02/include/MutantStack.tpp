/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:18:51 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/05 11:42:07 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& original) : std::stack<T>(original){}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& original)
{
	if (this != &original)
	{
		std::stack<T>::operator=(original);
	}
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(){}
