/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweissha <aweissha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 11:36:47 by aweissha          #+#    #+#             */
/*   Updated: 2024/11/05 13:22:58 by aweissha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MutantStack.hpp"
#include <list>


int main()
{
MutantStack<int> mstack;
// std::list<int> mstack;
mstack.push(5);
// mstack.push_back(5);
mstack.push(17);
// mstack.push_back(17);
std::cout << mstack.top() << std::endl;
mstack.pop();
std::cout << mstack.size() << std::endl;
mstack.push(3);
mstack.push(5);
mstack.push(737);
// mstack.push_back(3);
// mstack.push_back(5);
// mstack.push_back(737);
//[...]
mstack.push(0);
// mstack.push_back(0);
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();
// std::list<int>::iterator it = mstack.begin();
// std::list<int>::iterator ite = mstack.end();
++it;
--it;
while (it != ite)
{
std::cout << *it << std::endl;
++it;
}
std::stack<int> s(mstack);
return 0;
}